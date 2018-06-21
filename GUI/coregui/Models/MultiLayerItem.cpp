// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/MultiLayerItem.cpp
//! @brief     Implements class MultiLayerItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "MultiLayerItem.h"
#include "BornAgainNamespace.h"
#include "LayerItem.h"
#include "ParameterTranslators.h"

namespace {
const QString external_field_tooltip =
        "External field (A/m)";
}

const QString MultiLayerItem::P_CROSS_CORR_LENGTH =
        QString::fromStdString(BornAgain::CrossCorrelationLength);
const QString MultiLayerItem::P_EXTERNAL_FIELD = "ExternalField";
const QString MultiLayerItem::T_LAYERS = "Layer tag";

MultiLayerItem::MultiLayerItem()
    : SessionGraphicsItem(Constants::MultiLayerType)
{
    setToolTip(QStringLiteral("A multilayer to hold stack of layers"));
    setItemName(Constants::MultiLayerType);

    addProperty(P_CROSS_CORR_LENGTH, 0.0)->setDecimals(5).setToolTip(
        QStringLiteral("Cross correlation length of roughnesses \n"
                       "between interfaces in nanometers"));
    addGroupProperty(P_EXTERNAL_FIELD, Constants::VectorType)->setToolTip(external_field_tooltip);

    registerTag(T_LAYERS, 0, -1, QStringList() << Constants::LayerType);
    setDefaultTag(T_LAYERS);

    addTranslator(RoughnessTranslator(this));
    addTranslator(VectorParameterTranslator(P_EXTERNAL_FIELD, BornAgain::ExternalField));

    mapper()->setOnChildrenChange(
                [this](SessionItem*)
    {
        updateLayers();
    });
}

void MultiLayerItem::updateLayers()
{
    QVector<SessionItem*> list = getChildrenOfType(Constants::LayerType);
    for(auto it = list.begin(); it != list.end(); ++it) {
        if(it == list.begin())
            (*it)->getItem(LayerItem::P_ROUGHNESS)->setEnabled(false);
        else
            (*it)->getItem(LayerItem::P_ROUGHNESS)->setEnabled(true);

        if(it == list.begin() || it == (list.end()-1)) {
            (*it)->getItem(LayerItem::P_THICKNESS)->setEnabled(false);
            (*it)->setItemValue(LayerItem::P_THICKNESS, 0.0);
        } else {
            (*it)->getItem(LayerItem::P_THICKNESS)->setEnabled(true);
        }

    }
}
