// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/PropertyEditor/ComponentTreeView.h
//! @brief     Defines class ComponentTreeView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef COMPONENTTREEVIEW_H
#define COMPONENTTREEVIEW_H

#include "ComponentView.h"
#include <memory>

class QTreeView;
class SessionModel;
class SessionModelDelegate;
class ComponentProxyModel;
class QModelIndex;
class SessionItem;
class QStandardItemModel;
class RightMouseButtonEater;
class ComponentTreeActions;

//! Component property tree for SessionItems.
//! Shows only PropertyItems and current items of GroupProperties.

class BA_CORE_API_ ComponentTreeView : public ComponentView
{
    Q_OBJECT
public:
    ComponentTreeView(QWidget* parent = nullptr);

    void setItem(SessionItem* item);
    void clearEditor();

    void setShowHeader(bool show);
    void setShowRootItem(bool show);

private slots:
    void onCustomContextMenuRequested(const QPoint &pos);

private:
    void setModel(SessionModel* model);
    void setRootIndex(const QModelIndex& index, bool show_root_item = true);

    QTreeView* m_tree;
    SessionModelDelegate* m_delegate;
    ComponentProxyModel* m_proxyModel;
    QStandardItemModel* m_placeHolderModel;
    std::unique_ptr<RightMouseButtonEater> m_eventFilter;
    ComponentTreeActions* m_actions;
    bool m_show_root_item; //!< Tree will starts from item itself, if true.
};

#endif  //  COMPONENTTREEVIEW_H
