// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      ParameterizedItem.h
//! @brief     Defines class ParameterizedItem.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ParameterizedItem.h"
#include "Exceptions.h"
#include "MaterialBrowser.h"

#include <QEvent>
#include <QDynamicPropertyChangeEvent>
#include <QDebug>
#include <QMetaEnum>



ParameterizedItem::~ParameterizedItem()
{
    qDeleteAll(m_children);
}

ParameterizedItem *ParameterizedItem::takeChildItem(int row)
{
    ParameterizedItem *item = m_children.takeAt(row);
    item->m_parent = 0;
    return item;
}

bool ParameterizedItem::acceptsAsChild(const QString &child_name) const
{
    return m_valid_children.contains(child_name);
}

// emmits signal on property change
bool ParameterizedItem::event(QEvent * e )
{
    if(e->type() == QEvent::DynamicPropertyChange) {
        QDynamicPropertyChangeEvent *propertyEvent = dynamic_cast<QDynamicPropertyChangeEvent *>(e);
        Q_ASSERT(e);
        QString name(propertyEvent->propertyName());
        emit propertyChanged(name);
    }
    return QObject::event(e);
}

void ParameterizedItem::addSubItem(QString name, ParameterizedItem *item)
{
    if (!item) return;
    const char *name_str = name.toUtf8().constData();
    setProperty(name_str, item->modelType());
    if (m_sub_items.contains(name)) {
        delete m_sub_items[name];
    }
    m_sub_items[name] = item;
}

ParameterizedItem::ParameterizedItem(const QString &model_type,
                                     ParameterizedItem *parent)
    : m_model_type(model_type)
    , m_parent(parent)
{
    if (m_parent) {
        m_parent->addChildItem(this);
    }
    setItemName(m_model_type);
}

void ParameterizedItem::setMaterialProperty()
{
    MaterialProperty material = MaterialBrowser::getDefaultMaterialProperty();
    QVariant mat_var;
    mat_var.setValue(material);
    setProperty("Material", mat_var);
}

void ParameterizedItem::addFormFactorProperty(const char *name, QString value)
{
    QStringList enum_names;
    const QMetaObject *meta_object = this->metaObject();
    FormFactorEnum enum_value;
    QMetaEnum enumType = meta_object->enumerator(
                meta_object->indexOfEnumerator("FormFactorEnum"));
    bool found = false;
    for(int i=0; i < enumType.keyCount(); ++i) {
        QString item = QString::fromAscii(enumType.key(i));
        enum_names << item;
        if (item == value) {
            enum_value = (FormFactorEnum)enumType.value(i);
            found = true;
        }
    }
    if (found) {
        QVariant enum_var;
        enum_var.setValue(enum_value);
        setProperty(name, enum_var);
        m_enum_names_map[QString(name)] = enum_names;
    }
}
