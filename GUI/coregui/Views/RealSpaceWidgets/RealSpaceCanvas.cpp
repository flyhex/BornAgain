// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/RealSpaceWidgets/RealSpaceScene.cpp
//! @brief     Implements class RealSpaceScene
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "RealSpaceCanvas.h"
#include "SampleModel.h"
#include "RealSpaceView.h"
#include "RealSpaceBuilder.h"
#include "RealSpaceModel.h"
#include <QVBoxLayout>
#include <QDebug>

RealSpaceCanvas::RealSpaceCanvas(QWidget* parent)
    : QWidget(parent)
    , m_model(nullptr)
    , m_view(new RealSpaceView)
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_view);
    setLayout(layout);

}

RealSpaceCanvas::~RealSpaceCanvas()
{

}

void RealSpaceCanvas::setModel(SampleModel* model)
{
    if (model != m_model) {

        if (m_model)
            setConnected(m_model, false);

        m_model = model;

        if (m_model)
            setConnected(m_model, true);
    }
    updateScene();
}

void RealSpaceCanvas::onSelectionChanged(const QModelIndex& selected)
{
    qDebug() << "RealSpaceCanvas::onSelectionChanged";
    if(!selected.isValid())
        return;

    m_currentSelection = selected;

    m_realSpaceModel.reset(new RealSpaceModel);

    SessionItem* item = m_model->itemForIndex(selected);

    Q_ASSERT(item);
    RealSpaceBuilder::populate(m_realSpaceModel.get(), *item);

    m_view->setModel(m_realSpaceModel.get());
}

void RealSpaceCanvas::updateScene()
{
    onSelectionChanged(m_currentSelection);
}

void RealSpaceCanvas::resetScene()
{
    m_realSpaceModel.reset();
    m_view->setModel(nullptr);
    m_currentSelection = QModelIndex();
}

void RealSpaceCanvas::setConnected(SampleModel* model, bool makeConnected)
{
    if(!model)
        return;

    if(makeConnected) {
        connect(model, SIGNAL(rowsInserted(QModelIndex, int, int)),
                this, SLOT(updateScene()));
        connect(model, SIGNAL(rowsRemoved(QModelIndex, int, int)),
                this, SLOT(updateScene()));
        connect(model, SIGNAL(dataChanged(QModelIndex, QModelIndex, QVector<int>)),
                this, SLOT(updateScene()));
        connect(model, SIGNAL(modelReset()),
                this, SLOT(resetScene()));
    } else {
        disconnect(model, SIGNAL(rowsInserted(QModelIndex, int, int)),
                   this, SLOT(updateScene()));
        disconnect(model, SIGNAL(rowsRemoved(QModelIndex, int, int)),
                   this, SLOT(updateScene()));
        disconnect(model, SIGNAL(dataChanged(QModelIndex, QModelIndex, QVector<int>)),
                   this, SLOT(updateScene()));
        disconnect(model, SIGNAL(modelReset()),
                   this, SLOT(resetScene()));
    }

}
