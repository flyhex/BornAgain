// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/SampleDesigner/PropertyVariantFactory.cpp
//! @brief     Implements class PropertyVariantFactory
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "PropertyVariantFactory.h"
#include "PropertyVariantManager.h"
#include "PropertyBrowserUtils.h"
#include <QDebug>


PropertyVariantFactory::~PropertyVariantFactory()
{
    QList<MaterialPropertyEdit *> mat_editors =
            m_material_editor_to_property.keys();
    QListIterator<MaterialPropertyEdit *> mat_it(mat_editors);
    while (mat_it.hasNext())
        delete mat_it.next();

    QList<ColorPropertyEdit *> color_editors =
            m_color_editor_to_property.keys();
    QListIterator<ColorPropertyEdit *> color_it(color_editors);
    while (color_it.hasNext())
        delete color_it.next();

    QList<ScientificDoublePropertyEdit *> scdouble_editors =
            m_scdouble_editor_to_property.keys();
    QListIterator<ScientificDoublePropertyEdit *> scdouble_it(scdouble_editors);
    while (scdouble_it.hasNext())
        delete scdouble_it.next();

    QList<FancyGroupPropertyEdit *> fancy_editors =
            m_fancygroup_editor_to_property.keys();
    QListIterator<FancyGroupPropertyEdit *> fancy_it(fancy_editors);
    while (fancy_it.hasNext())
        delete fancy_it.next();

    QList<ComboPropertyEdit *> combo_editors =
            m_combo_editor_to_property.keys();
    QListIterator<ComboPropertyEdit *> combo_it(combo_editors);
    while (combo_it.hasNext())
        delete combo_it.next();
}

void PropertyVariantFactory::connectPropertyManager(
        QtVariantPropertyManager *manager)
{
    connect(manager, SIGNAL(valueChanged(QtProperty *, const QVariant &)),
                this, SLOT(slotPropertyChanged(QtProperty *,
                                               const QVariant &)));
    connect(manager, SIGNAL(attributeChanged(QtProperty *, const QString &,
                                             const QVariant &)),
                this, SLOT(slotPropertyAttributeChanged(QtProperty *,
                                    const QString &, const QVariant &)));
    QtVariantEditorFactory::connectPropertyManager(manager);
}


QWidget *PropertyVariantFactory::createEditor(QtVariantPropertyManager *manager,
        QtProperty *property, QWidget *parent)
{
    if (manager->propertyType(property) ==
            PropertyVariantManager::materialTypeId()) {
        MaterialPropertyEdit *editor = new MaterialPropertyEdit(parent);
        QVariant var = manager->value(property);
        MaterialProperty mat = var.value<MaterialProperty>();
        editor->setMaterialProperty(mat);

        m_property_to_material_editors[property].append(editor);
        m_material_editor_to_property[editor] = property;

        connect(editor, SIGNAL(materialPropertyChanged(const MaterialProperty &)),
                this, SLOT(slotSetValue(const MaterialProperty &)));
        connect(editor, SIGNAL(destroyed(QObject *)),
                this, SLOT(slotEditorDestroyed(QObject *)));
        return editor;
    }

    if (manager->propertyType(property) ==
            PropertyVariantManager::colorPropertyTypeId()) {
        ColorPropertyEdit *editor = new ColorPropertyEdit(parent);
        QVariant var = manager->value(property);
        ColorProperty mat = var.value<ColorProperty>();
        editor->setColorProperty(mat);

        m_property_to_color_editors[property].append(editor);
        m_color_editor_to_property[editor] = property;

        connect(editor, SIGNAL(colorPropertyChanged(const ColorProperty &)),
                this, SLOT(slotSetValue(const ColorProperty &)));
        connect(editor, SIGNAL(destroyed(QObject *)),
                this, SLOT(slotEditorDestroyed(QObject *)));
        return editor;
    }

    if (manager->propertyType(property) ==
            PropertyVariantManager::scientificDoubleTypeId()) {
        ScientificDoublePropertyEdit *editor = new ScientificDoublePropertyEdit(parent);
        QVariant var = manager->value(property);
        ScientificDoubleProperty sc = var.value<ScientificDoubleProperty>();
        editor->setScientificDoubleProperty(sc);

        m_property_to_scdouble_editors[property].append(editor);
        m_scdouble_editor_to_property[editor] = property;

        connect(editor,
                SIGNAL(scientificDoublePropertyChanged(const ScientificDoubleProperty &)),
                this, SLOT(slotSetValue(const ScientificDoubleProperty &)));
        connect(editor, SIGNAL(destroyed(QObject *)),
                this, SLOT(slotEditorDestroyed(QObject *)));
        return editor;
    }

    if (manager->propertyType(property) ==
            PropertyVariantManager::fancyGroupTypeId()) {
        FancyGroupPropertyEdit *editor = new FancyGroupPropertyEdit(parent);
        QVariant var = manager->value(property);
        FancyGroupProperty_t ff = var.value<FancyGroupProperty_t>();
        editor->setFancyGroupProperty(ff);

        m_property_to_fancygroup_editors[property].append(editor);
        m_fancygroup_editor_to_property[editor] = property;

        connect(editor,
                SIGNAL(fancyGroupPropertyChanged(FancyGroupProperty_t)),
                this, SLOT(slotSetValue(FancyGroupProperty_t)));

        connect(editor, SIGNAL(destroyed(QObject *)),
                this, SLOT(slotEditorDestroyed(QObject *)));
        return editor;
    }

    if (manager->propertyType(property) ==
            PropertyVariantManager::comboPropertyTypeId()) {
        ComboPropertyEdit *editor = new ComboPropertyEdit(parent);
        QVariant var = manager->value(property);
        ComboProperty combo = var.value<ComboProperty>();
        editor->setComboProperty(combo);

        m_property_to_combo_editors[property].append(editor);
        m_combo_editor_to_property[editor] = property;

        connect(editor, SIGNAL(comboPropertyChanged(const ComboProperty &)),
                this, SLOT(slotSetValue(const ComboProperty &)));
        connect(editor, SIGNAL(destroyed(QObject *)),
                this, SLOT(slotEditorDestroyed(QObject *)));
        return editor;
    }

    return QtVariantEditorFactory::createEditor(manager, property, parent);
}


void PropertyVariantFactory::disconnectPropertyManager(
        QtVariantPropertyManager *manager)
{
    disconnect(manager, SIGNAL(valueChanged(QtProperty *, const QVariant &)),
               this, SLOT(slotPropertyChanged(QtProperty *, const QVariant &)));
    disconnect(manager, SIGNAL(attributeChanged(QtProperty *, const QString &,
                                     const QVariant &)),
                this, SLOT(slotPropertyAttributeChanged(QtProperty *,
                                     const QString &, const QVariant &)));
    QtVariantEditorFactory::disconnectPropertyManager(manager);
}


void PropertyVariantFactory::slotPropertyChanged(QtProperty *property,
                const QVariant &value)
{
    if (m_property_to_material_editors.contains(property)) {
        QList<MaterialPropertyEdit *> editors =
                m_property_to_material_editors[property];
        QListIterator<MaterialPropertyEdit *> itEditor(editors);
        while (itEditor.hasNext()) {
            MaterialProperty mat = value.value<MaterialProperty>();
            itEditor.next()->setMaterialProperty(mat);
        }
    }
    else if (m_property_to_color_editors.contains(property)) {
        QList<ColorPropertyEdit *> editors =
                m_property_to_color_editors[property];
        QListIterator<ColorPropertyEdit *> itEditor(editors);
        while (itEditor.hasNext()) {
            ColorProperty mat = value.value<ColorProperty>();
            itEditor.next()->setColorProperty(mat);
        }
    }
    else if (m_property_to_scdouble_editors.contains(property)) {
        QList<ScientificDoublePropertyEdit *> editors =
                m_property_to_scdouble_editors[property];
        QListIterator<ScientificDoublePropertyEdit *> itEditor(editors);
        while (itEditor.hasNext()) {
            ScientificDoubleProperty mat = value.value<ScientificDoubleProperty>();
            itEditor.next()->setScientificDoubleProperty(mat);
        }
    }
    else if (m_property_to_fancygroup_editors.contains(property)) {
        QList<FancyGroupPropertyEdit *> editors =
                m_property_to_fancygroup_editors[property];
        QListIterator<FancyGroupPropertyEdit *> itEditor(editors);
        while (itEditor.hasNext()) {
            FancyGroupProperty_t mat = value.value<FancyGroupProperty_t>();
            itEditor.next()->setFancyGroupProperty(mat);
        }
    }
    else if (m_property_to_combo_editors.contains(property)) {
        QList<ComboPropertyEdit *> editors =
                m_property_to_combo_editors[property];
        QListIterator<ComboPropertyEdit *> itEditor(editors);
        while (itEditor.hasNext()) {
            ComboProperty combo = value.value<ComboProperty>();
            itEditor.next()->setComboProperty(combo);
        }
    }
}


void PropertyVariantFactory::slotSetValue(const MaterialProperty &value)
{
    qDebug() << "PropertyVariantFactory::slotSetValue(const MaterialProperty &value)";
    QObject *object = sender();
    QMap<MaterialPropertyEdit *, QtProperty *>::ConstIterator itEditor =
                m_material_editor_to_property.constBegin();
    while (itEditor != m_material_editor_to_property.constEnd()) {
        if (itEditor.key() == object) {
            QtProperty *property = itEditor.value();
            QtVariantPropertyManager *manager = propertyManager(property);
            if (!manager) return;
            QVariant var;
            var.setValue(value);
            manager->setValue(property, var);
            // FIXME g.p. Is it the right place to delete?
            object->deleteLater();
            return;
        }
        itEditor++;
    }
}

void PropertyVariantFactory::slotSetValue(const ColorProperty &value)
{
    QObject *object = sender();
    QMap<ColorPropertyEdit *, QtProperty *>::ConstIterator itEditor =
                m_color_editor_to_property.constBegin();
    while (itEditor != m_color_editor_to_property.constEnd()) {
        if (itEditor.key() == object) {
            QtProperty *property = itEditor.value();
            QtVariantPropertyManager *manager = propertyManager(property);
            if (!manager) return;
            QVariant var;
            var.setValue(value);
            manager->setValue(property, var);
            // FIXME g.p. Is it the right place to delete?
            object->deleteLater();
            return;
        }
        itEditor++;
    }
}

void PropertyVariantFactory::slotSetValue(const ScientificDoubleProperty &value)
{
    QObject *object = sender();
    QMap<ScientificDoublePropertyEdit *, QtProperty *>::ConstIterator itEditor =
                m_scdouble_editor_to_property.constBegin();
    while (itEditor != m_scdouble_editor_to_property.constEnd()) {
        if (itEditor.key() == object) {
            QtProperty *property = itEditor.value();
            QtVariantPropertyManager *manager = propertyManager(property);
            if (!manager) return;
            QVariant var;
            var.setValue(value);
            manager->setValue(property, var);
            return;
        }
        itEditor++;
    }
}

void PropertyVariantFactory::slotSetValue(const FancyGroupProperty_t &value)
{
    QObject *object = sender();
    QMap<FancyGroupPropertyEdit *, QtProperty *>::ConstIterator itEditor =
                m_fancygroup_editor_to_property.constBegin();
    while (itEditor != m_fancygroup_editor_to_property.constEnd()) {
        if (itEditor.key() == object) {
            QtProperty *property = itEditor.value();
            QtVariantPropertyManager *manager = propertyManager(property);
            if (!manager) return;
            QVariant var;
            var.setValue(value);
            manager->setValue(property, var);
            return;
        }
        itEditor++;
    }
}

void PropertyVariantFactory::slotSetValue(const ComboProperty &value)
{
    QObject *object = sender();
    QMap<ComboPropertyEdit *, QtProperty *>::ConstIterator itEditor =
                m_combo_editor_to_property.constBegin();
    while (itEditor != m_combo_editor_to_property.constEnd()) {
        if (itEditor.key() == object) {
            QtProperty *property = itEditor.value();
            QtVariantPropertyManager *manager = propertyManager(property);
            if (!manager) return;
            QVariant var;
            var.setValue(value);
            manager->setValue(property, var);
            // FIXME g.p. Is it the right place to delete?
            object->deleteLater();
            return;
        }
        itEditor++;
    }
}

void PropertyVariantFactory::slotEditorDestroyed(QObject *object)
{
    QMap<MaterialPropertyEdit *, QtProperty *>::ConstIterator mat_it_editor =
                m_material_editor_to_property.constBegin();
    while (mat_it_editor != m_material_editor_to_property.constEnd()) {
        if (mat_it_editor.key() == object) {
            MaterialPropertyEdit *editor = mat_it_editor.key();
            QtProperty *property = mat_it_editor.value();
            m_material_editor_to_property.remove(editor);
            m_property_to_material_editors[property].removeAll(editor);
            if (m_property_to_material_editors[property].isEmpty())
                m_property_to_material_editors.remove(property);
            return;
        }
        mat_it_editor++;
    }

    QMap<ColorPropertyEdit *, QtProperty *>::ConstIterator color_it_editor =
                m_color_editor_to_property.constBegin();
    while (color_it_editor != m_color_editor_to_property.constEnd()) {
        if (color_it_editor.key() == object) {
            ColorPropertyEdit *editor = color_it_editor.key();
            QtProperty *property = color_it_editor.value();
            m_color_editor_to_property.remove(editor);
            m_property_to_color_editors[property].removeAll(editor);
            if (m_property_to_color_editors[property].isEmpty())
                m_property_to_color_editors.remove(property);
            return;
        }
        color_it_editor++;
    }

    QMap<ScientificDoublePropertyEdit *, QtProperty *>::ConstIterator scdouble_it_editor =
                m_scdouble_editor_to_property.constBegin();
    while (scdouble_it_editor != m_scdouble_editor_to_property.constEnd()) {
        if (scdouble_it_editor.key() == object) {
            ScientificDoublePropertyEdit *editor = scdouble_it_editor.key();
            QtProperty *property = scdouble_it_editor.value();
            m_scdouble_editor_to_property.remove(editor);
            m_property_to_scdouble_editors[property].removeAll(editor);
            if (m_property_to_scdouble_editors[property].isEmpty())
                m_property_to_scdouble_editors.remove(property);
            return;
        }
        scdouble_it_editor++;
    }

    QMap<FancyGroupPropertyEdit *, QtProperty *>::ConstIterator fancygroup_editor_it =
                m_fancygroup_editor_to_property.constBegin();
    while (fancygroup_editor_it != m_fancygroup_editor_to_property.constEnd()) {
        if (fancygroup_editor_it.key() == object) {
            FancyGroupPropertyEdit *editor = fancygroup_editor_it.key();
            QtProperty *property = fancygroup_editor_it.value();
            m_fancygroup_editor_to_property.remove(editor);
            m_property_to_fancygroup_editors[property].removeAll(editor);
            if (m_property_to_fancygroup_editors[property].isEmpty())
                m_property_to_fancygroup_editors.remove(property);
            return;
        }
        fancygroup_editor_it++;
    }

    QMap<ComboPropertyEdit *, QtProperty *>::ConstIterator combo_it_editor =
                m_combo_editor_to_property.constBegin();
    while (combo_it_editor != m_combo_editor_to_property.constEnd()) {
        if (combo_it_editor.key() == object) {
            ComboPropertyEdit *editor = combo_it_editor.key();
            QtProperty *property = combo_it_editor.value();
            m_combo_editor_to_property.remove(editor);
            m_property_to_combo_editors[property].removeAll(editor);
            if (m_property_to_combo_editors[property].isEmpty())
                m_property_to_combo_editors.remove(property);
            return;
        }
        combo_it_editor++;
    }
}

void PropertyVariantFactory::slotPropertyAttributeChanged(QtProperty *, const QString &, const QVariant &)
{

}
