// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/InstrumentWidgets/EnvironmentEditor.h
//! @brief     Defines class EnvironmentEditor
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef ENVIRONMENTEDITOR_H
#define ENVIRONMENTEDITOR_H

#include "SessionItemWidget.h"

class ComponentEditor;
class QGridLayout;
class GISASInstrumentItem;
class ColumnResizer;

//! Environment editor (i.e. background) for GISASInstrumentEditor.
//! Operates on GISASInstrumentItem.

class BA_CORE_API_ EnvironmentEditor : public SessionItemWidget
{
    Q_OBJECT
public:
    EnvironmentEditor(ColumnResizer* columnResizer, QWidget* parent = nullptr);
    ~EnvironmentEditor();

protected:
    void subscribeToItem();
    void unsubscribeFromItem();

private:
    GISASInstrumentItem* instrumentItem();
    ColumnResizer* m_columnResizer;
    ComponentEditor* m_backgroundEditor;
    QGridLayout* m_gridLayout;
};

#endif  // ENVIRONMENTEDITOR_H
