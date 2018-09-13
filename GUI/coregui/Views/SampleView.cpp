// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/SampleView.cpp
//! @brief     Implements class SampleView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "SampleView.h"
#include "ApplicationModels.h"
#include "SampleDesigner.h"
#include "SampleToolBar.h"
#include "SampleTreeWidget.h"
#include "SampleViewDocks.h"
#include "mainwindow.h"

SampleView::SampleView(MainWindow* mainWindow)
    : Manhattan::FancyMainWindow(mainWindow), m_models(mainWindow->models()),
      m_docks(new SampleViewDocks(this)), m_toolBar(nullptr)
{
    setObjectName("SampleView");
    connectSignals();
}

ApplicationModels* SampleView::models() { return m_models; }

void SampleView::connectSignals()
{
    connect(this, SIGNAL(resetLayout()), this, SLOT(resetToDefaultLayout()));

    // toolBar should be initialized after MaterialBrowser
    m_toolBar = new SampleToolBar(models()->sampleModel(), selectionModel(), this);
    connect(m_toolBar, SIGNAL(deleteItems()), sampleDesigner()->getView(),
            SLOT(deleteSelectedItems()));
    connect(m_toolBar, SIGNAL(selectionMode(int)), sampleDesigner()->getView(),
            SLOT(onSelectionMode(int)));
    connect(sampleDesigner()->getView(), SIGNAL(selectionModeChanged(int)), m_toolBar,
            SLOT(onViewSelectionMode(int)));
    connect(m_toolBar, SIGNAL(centerView()), sampleDesigner()->getView(), SLOT(onCenterView()));
    connect(m_toolBar, SIGNAL(smartAlign()), sampleDesigner(), SLOT(onSmartAlign()));
    connect(m_toolBar, SIGNAL(changeScale(double)), sampleDesigner()->getView(),
            SLOT(onChangeScale(double)));

    connect(m_toolBar, SIGNAL(zoomOut()), sampleDesigner()->getView(), SLOT(zoomOut()));
    connect(m_toolBar, SIGNAL(zoomIn()), sampleDesigner()->getView(), SLOT(zoomIn()));

    connect(sampleDesigner()->getScene(), SIGNAL(selectionModeChangeRequest(int)),
            sampleDesigner()->getView(), SLOT(onSelectionMode(int)));

    addToolBar(m_toolBar);
}

QItemSelectionModel* SampleView::selectionModel()
{
    return m_docks->treeWidget()->treeView()->selectionModel();
}

SampleDesigner* SampleView::sampleDesigner()
{
    return m_docks->sampleDesigner();
}
