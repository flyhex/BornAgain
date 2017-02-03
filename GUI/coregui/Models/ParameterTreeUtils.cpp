// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/ParameterTreeUtils.cpp
//! @brief     Implements ParameterTreeUtils namespace
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "ParameterTreeUtils.h"
#include "FitParameterHelper.h"
#include "GroupItem.h"
#include "JobItem.h"
#include "ModelPath.h"
#include "MultiLayerItem.h"
#include "ParameterTreeItems.h"
#include "SampleModel.h"
#include "ScientificDoubleProperty.h"
#include "GUIHelpers.h"
#include "FitParameterHelper.h"
#include "SampleModel.h"
#include <QStack>
#include <QDebug>

namespace {
    void handleItem(SessionItem* tree, const SessionItem* source);
}

void ParameterTreeUtils::createParameterTree(JobItem* jobItem)
{
    SessionItem* container = jobItem->model()->insertNewItem(Constants::ParameterContainerType,
        jobItem->index(), -1, JobItem::T_PARAMETER_TREE);

    populateParameterContainer(container, jobItem->getItem(JobItem::T_SAMPLE));

    populateParameterContainer(container, jobItem->getItem(JobItem::T_INSTRUMENT));

#ifndef NDEBUG
    // Provides all items in "JobItem/Parameter Tree Container" with domain links already
    // at the stage of ParameterTree creation. It is necessary for validation, in Release mode
    // it will lead for unnecessary large project files.
    ParameterTreeUtils::populateDomainLinks(container);
#endif
}

//! Populates ParameterContainer with ParameterItem's corresponding to all properties found
//! in a source item.

void ParameterTreeUtils::populateParameterContainer(SessionItem* container,
                                                    const SessionItem* source)
{
    if(container->modelType() != Constants::ParameterContainerType)
        throw GUIHelpers::Error("ParameterTreeUtils::populateParameterContainer() -> Error. "
                                "Not a ParameterContainerType.");

    SessionItem* sourceLabel
        = container->model()->insertNewItem(Constants::ParameterLabelType, container->index());

    handleItem(sourceLabel, source);
}

//! Visit all ParameterItem in container and execute user function.

void ParameterTreeUtils::visitParameterContainer(SessionItem* container,
                                                 std::function<void(ParameterItem*)> fun)
{
    SessionItem* current(container);
    QStack<SessionItem*> stack;
    stack.push(current);
    while (!stack.empty()) {
        current = stack.pop();
        if (current->modelType() == Constants::ParameterLabelType
            || current->modelType() == Constants::ParameterContainerType) {
            for (SessionItem* child : current->getItems())
                stack.push(child);
        } else {
            if (ParameterItem* parItem = dynamic_cast<ParameterItem*>(current))
                fun(parItem);
        }
    }
}

//! Creates list with parameter names of source item.

QStringList ParameterTreeUtils::parameterTreeNames(const SessionItem* source)
{
    Q_ASSERT(source);
    QStringList result;

    SampleModel model;
    SessionItem* container = model.insertNewItem(Constants::ParameterContainerType);

    populateParameterContainer(container, source);

    visitParameterContainer(container, [&](ParameterItem* parItem)
    {
        result.push_back(FitParameterHelper::getParameterItemPath(parItem));
    });

    std::reverse(result.begin(), result.end());

    return result;
}

//! Creates domain translated list of parameter names for source item.

QStringList ParameterTreeUtils::translatedParameterTreeNames(const SessionItem* source)
{
    Q_ASSERT(source);
    QStringList result;

    SampleModel model;
    SessionItem* container = model.insertNewItem(Constants::ParameterContainerType);

    populateParameterContainer(container, source);

    visitParameterContainer(container, [&](ParameterItem* parItem)
    {
        QString relPath = source->displayName() + "/"
                + parItem->getItemValue(ParameterItem::P_LINK).toString();
        SessionItem *linkedItem = ModelPath::getItemFromPath(relPath, source);
        result.push_back(ModelPath::itemPathTranslation(*linkedItem, source->parent()));
    });

    std::reverse(result.begin(), result.end());

    return result;

}


//! For every ParameterItem in a container creates a link to the domain.

void ParameterTreeUtils::populateDomainLinks(SessionItem* container)
{
    if(container->modelType() != Constants::ParameterContainerType)
        throw GUIHelpers::Error("ParameterTreeUtils::populateParameterContainer() -> Error. "
                                "Not a ParameterContainerType.");

    visitParameterContainer(container, [container](ParameterItem* parItem)
    {
        QString translation = "*/" + ModelPath::itemPathTranslation(*parItem->linkedItem(),
                                                                    container->parent());
        parItem->setItemValue(ParameterItem::P_DOMAIN, translation);
    });
}

namespace {

void handleItem(SessionItem* tree, const SessionItem* source)
{
    if (tree->modelType() == Constants::ParameterLabelType) {
        tree->setDisplayName(source->itemName());

    }

    else if (tree->modelType() == Constants::ParameterType) {
        tree->setDisplayName(source->itemName());

        double sourceValue = source->value().toDouble();
        if (source->value().typeName() == Constants::ScientificDoublePropertyType) {
            ScientificDoubleProperty intensity = source->value().value<ScientificDoubleProperty>();
            sourceValue = intensity.getValue();
        }

        tree->setValue(QVariant(sourceValue));
        QString path = ModelPath::getPathFromIndex(source->index());
        int firstSlash = path.indexOf('/');
        path = path.mid(firstSlash + 1);
        tree->setItemValue(ParameterItem::P_LINK, path);
        tree->setItemValue(ParameterItem::P_BACKUP, sourceValue);
        return;
    }

    else {
        return;
    }

    for (SessionItem* child : source->childItems()) {
        if (child->isVisible() && child->isEnabled()) {
            if (child->modelType() == Constants::PropertyType) {
                if (child->value().type() == QVariant::Double) {
                    SessionItem* branch
                        = tree->model()->insertNewItem(Constants::ParameterType, tree->index());
                    handleItem(branch, child);
                } else if (child->value().typeName() == Constants::ScientificDoublePropertyType) {
                    SessionItem* branch
                        = tree->model()->insertNewItem(Constants::ParameterType, tree->index());
                    handleItem(branch, child);
                }

            } else if (child->modelType() == Constants::GroupItemType) {
                SessionItem* currentItem = dynamic_cast<GroupItem*>(child)->currentItem();
                if (currentItem && currentItem->rowCount() > 0) {
                    SessionItem* branch = tree->model()->insertNewItem(
                        Constants::ParameterLabelType, tree->index());
                    handleItem(branch, currentItem);
                }
            } else {
                SessionItem* branch
                    = tree->model()->insertNewItem(Constants::ParameterLabelType, tree->index());
                handleItem(branch, child);
            }
        }
    }
}

} // namespace



