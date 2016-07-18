// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/FitWidgets/GUIFitObserver.cpp
//! @brief     Implements class GUIFitObserver
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "GUIFitObserver.h"
#include "FitSuite.h"
#include "IntensityDataItem.h"
#include "FitParameter.h"
#include "FitSuiteParameters.h"
#include "FitProgressInfo.h"
#include "GUIHelpers.h"
#include <QVector>
#include <QDebug>


GUIFitObserver::GUIFitObserver(QObject *parent)
    : QObject(parent)
    , IFitObserver(1)
    , m_block_update_plots(false)
    , m_update_interval(1)
{}

GUIFitObserver::~GUIFitObserver()
{

}

void GUIFitObserver::update(FitSuite *subject)
{
    // discard data after interruption
    if (subject->isInterrupted())
        return;

//    if(canUpdateProgressInfo(subject)) {
//        FitProgressInfo info;
//        info.m_chi2 = subject->getChi2();
//        info.m_iteration_count = (int)subject->getNumberOfIterations();
//        info.m_values = GUIHelpers::fromStdVector(subject->getFitParameters()->getValues());
//        qDebug() << "Emitting progressInfoUpdate" << info.m_iteration_count;
//        emit progressInfoUpdate(info);
//    }

//    if(canUpdatePlots(subject)) {
//        m_block_update_plots = true;
//        m_simData.reset(subject->getSimulationOutputData()->clone());
//        emit plotsUpdate();
//    }

    if(subject->getNumberOfIterations() % m_update_interval == 0) {
        if(m_block_update_plots) {
            qDebug() << "GUI is busy with plotting, skipping iteration "
                     << subject->getNumberOfIterations();
        }
    }


    if(canUpdatePlots(subject)) {
        m_block_update_plots = true;

        FitProgressInfo info;
        info.m_chi2 = subject->getChi2();
        info.m_iteration_count = (int)subject->getNumberOfIterations();
        info.m_values = GUIHelpers::fromStdVector(subject->getFitParameters()->getValues());
        qDebug() << "Emitting progressInfoUpdate" << info.m_iteration_count;
        emit progressInfoUpdate(info);

        m_simData.reset(subject->getSimulationOutputData()->clone());
        emit plotsUpdate();
    }


    if (subject->isLastIteration()) {
        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
        subject->printResults();
        std::string text = buffer.str();
        emit logInfoUpdate(QString::fromStdString(text));
        std::cout.rdbuf(old);
    }

}

void GUIFitObserver::setInterval(int val)
{
    m_update_interval = val;
}

//! Returns true if it is time to update plots.

bool GUIFitObserver::canUpdatePlots(FitSuite *fitSuite)
{
    if(m_block_update_plots) return false;
    if(fitSuite->getNumberOfIterations() % m_update_interval == 0) return true;
    if(fitSuite->isLastIteration()) return true;
    return false;
}

//! Returns true if it is time to update progress. Follow same rules as for plots update,
//! or in the case of last iteration
bool GUIFitObserver::canUpdateProgressInfo(FitSuite *fitSuite)
{
    if(fitSuite->getNumberOfIterations() == 0) return true;
    if(fitSuite->getNumberOfIterations() % m_update_interval == 0) return true;
    if(fitSuite->isLastIteration()) return true;
    return false;
}

//! Informs observer that FitSuiteWidget has finished plotting and is ready for next plot
void GUIFitObserver::finishedPlotting()
{
    m_block_update_plots = false;
}

const OutputData<double> *GUIFitObserver::simulationData() const
{
    return m_simData.get();
}

//const OutputData<double> *GUIFitObserver::chiSquaredData() const
//{
//    return m_chiData.get();
//}
