/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Designer of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "widgetbox.h"
#include "widgetboxtreewidget.h"
#include "widgetbox_dnditem.h"

#include <QtDesigner/QDesignerFormEditorInterface>
#include <QtDesigner/QDesignerFormWindowManagerInterface>

#include <qdesigner_utils_p.h>
//#include <filterwidget_p.h>

#include <QtGui/QDropEvent>
//#include <QtWidgets/QVBoxLayout>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QToolBar>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QApplication>
#include <QToolBar>
#include <QDrag>

#include <QtGui/QIcon>

#include "SampleDesigner.h"

#include "DesignerMimeData.h"

#include <iostream>
QT_BEGIN_NAMESPACE

namespace qdesigner_internal {

class WidgetBoxFilterLineEdit : public QLineEdit {
public:
    explicit WidgetBoxFilterLineEdit(QWidget *parent = 0) : QLineEdit(parent), m_defaultFocusPolicy(focusPolicy())
        { setFocusPolicy(Qt::NoFocus); }

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *e);

private:
    const Qt::FocusPolicy m_defaultFocusPolicy;
};

void WidgetBoxFilterLineEdit::mousePressEvent(QMouseEvent *e)
{
    if (!hasFocus()) // Explicitly focus on click.
        setFocus(Qt::OtherFocusReason);
    QLineEdit::mousePressEvent(e);
}

void WidgetBoxFilterLineEdit::focusInEvent(QFocusEvent *e)
{
    // Refuse the focus if the mouse it outside. In addition to the mouse
    // press logic, this prevents a re-focussing which occurs once
    // we actually had focus
    const Qt::FocusReason reason = e->reason();
    if (reason == Qt::ActiveWindowFocusReason || reason == Qt::PopupFocusReason) {
        const QPoint mousePos = mapFromGlobal(QCursor::pos());
        const bool refuse = !geometry().contains(mousePos);
        if (refuse) {
            e->ignore();
            return;
        }
    }
    QLineEdit::focusInEvent(e);
}







//WidgetBox::WidgetBox(QDesignerFormEditorInterface *core, QWidget *parent, Qt::WindowFlags flags)
WidgetBox::WidgetBox(SampleDesignerInterface *core, QWidget *parent, Qt::WindowFlags flags)
    : QDesignerWidgetBox(parent, flags),
      m_core(core),
      m_view(new WidgetBoxTreeWidget(m_core))
{
    QVBoxLayout *l = new QVBoxLayout(this);
    l->setMargin(0);
    l->setSpacing(0);

    // Prevent the filter from grabbing focus since Our view has Qt::NoFocus
    QToolBar *toolBar = new QToolBar(this);
    QLineEdit *filterWidget = new WidgetBoxFilterLineEdit(toolBar);
    filterWidget->setPlaceholderText(tr("Filter"));
    filterWidget->setClearButtonEnabled(true);
    connect(filterWidget, SIGNAL(textChanged(QString)), m_view, SLOT(filter(QString)));
    toolBar->addWidget(filterWidget);
    l->addWidget(toolBar);

    // View
    connect(m_view, SIGNAL(pressed(QString,QString,QPoint)),
            this, SLOT(handleMousePress(QString,QString,QPoint)));
    l->addWidget(m_view);

    setAcceptDrops (true);


//    QVBoxLayout *l = new QVBoxLayout(this);
//    l->setMargin(0);
//    l->setSpacing(0);

//    // Prevent the filter from grabbing focus since Our view has Qt::NoFocus
//    FilterWidget *filterWidget = new FilterWidget(0, FilterWidget::LayoutAlignNone);
//    filterWidget->setRefuseFocus(true);
//    connect(filterWidget, SIGNAL(filterChanged(QString)), m_view, SLOT(filter(QString)));

//    QToolBar *toolBar = new QToolBar(this);
//    toolBar->addWidget(filterWidget);
//    l->addWidget(toolBar);

//    // View
//    connect(m_view, SIGNAL(pressed(QString,QString,QPoint)),
//            this, SLOT(handleMousePress(QString,QString,QPoint)));
//    l->addWidget(m_view);

//    setAcceptDrops (true);
}

WidgetBox::~WidgetBox()
{
}

//QDesignerFormEditorInterface *WidgetBox::core() const
//{
//    return m_core;
//}

SampleDesignerInterface *WidgetBox::core() const
{
    return m_core;
}


void WidgetBox::handleMousePress(const QString &name, const QString &xml, const QPoint &global_mouse_pos)
{
    Q_UNUSED(global_mouse_pos);
    if (QApplication::mouseButtons() != Qt::LeftButton) return;

    std::cout << "WidgetBox::handleMousePress() -> name:" << name.toStdString() << std::endl;
    DesignerMimeData::execDrag(name, xml, this );
}

int WidgetBox::categoryCount() const
{
    return m_view->categoryCount();
}

QDesignerWidgetBoxInterface::Category WidgetBox::category(int cat_idx) const
{
    return m_view->category(cat_idx);
}

void WidgetBox::addCategory(const Category &cat)
{
    m_view->addCategory(cat);
}

void WidgetBox::removeCategory(int cat_idx)
{
    m_view->removeCategory(cat_idx);
}

int WidgetBox::widgetCount(int cat_idx) const
{
    return m_view->widgetCount(cat_idx);
}

QDesignerWidgetBoxInterface::Widget WidgetBox::widget(int cat_idx, int wgt_idx) const
{
    return m_view->widget(cat_idx, wgt_idx);
}

void WidgetBox::addWidget(int cat_idx, const Widget &wgt)
{
    m_view->addWidget(cat_idx, wgt);
}

void WidgetBox::removeWidget(int cat_idx, int wgt_idx)
{
    m_view->removeWidget(cat_idx, wgt_idx);
}

void WidgetBox::dropWidgets(const QList<QDesignerDnDItemInterface*> &item_list, const QPoint&)
{
    m_view->dropWidgets(item_list);
}

void WidgetBox::setFileName(const QString &file_name)
{
    m_view->setFileName(file_name);
}

QString WidgetBox::fileName() const
{
    return m_view->fileName();
}

bool WidgetBox::load()
{
    //std::cout << "WidgetBox::load() -> We are here" << std::endl;
    return m_view->load(loadMode());
}

bool WidgetBox::loadContents(const QString &contents)
{
    return m_view->loadContents(contents);
}

bool WidgetBox::save()
{
    return m_view->save();
}

static const QDesignerMimeData *checkDragEvent(QDropEvent * event,
                                               bool acceptEventsFromWidgetBox)
{
    std::cout << "QDesignerMimeData *checkDragEvent() -> ?" << std::endl;
    const QDesignerMimeData *mimeData = qobject_cast<const QDesignerMimeData *>(event->mimeData());
    if (!mimeData) {
        event->ignore();
        return 0;
    }
    // If desired, ignore a widget box drag and drop, where widget==0.
    if (!acceptEventsFromWidgetBox) {
        const bool fromWidgetBox = !mimeData->items().first()->widget();
        if (fromWidgetBox) {
            event->ignore();
            return 0;
        }
    }

    mimeData->acceptEvent(event);
    return mimeData;
}

void WidgetBox::dragEnterEvent (QDragEnterEvent * event)
{
    // We accept event originating from the widget box also here,
    // because otherwise Windows will not show the DnD pixmap.
    checkDragEvent(event, true);
}

void WidgetBox::dragMoveEvent(QDragMoveEvent * event)
{
    checkDragEvent(event, true);
}

void WidgetBox::dropEvent(QDropEvent * event)
{
    const QDesignerMimeData *mimeData = checkDragEvent(event, false);
    if (!mimeData)
        return;

    dropWidgets(mimeData->items(), event->pos());
    QDesignerMimeData::removeMovedWidgetsFromSourceForm(mimeData->items());
}

QIcon WidgetBox::iconForWidget(const QString &className, const QString &category) const
{
    Widget widgetData;
    if (!findWidget(this, className, category, &widgetData))
        return QIcon();
    return m_view->iconForWidget(widgetData.iconName());
}

}  // namespace qdesigner_internal

QT_END_NAMESPACE
