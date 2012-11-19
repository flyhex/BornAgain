#include "FitSuiteKit.h"



/* ************************************************************************* */
// KitItem c-tors
/* ************************************************************************* */
FitSuiteKit::KitItem::KitItem(Experiment *experiment, const OutputData<double > *real_data, const IChiSquaredModule *chi2_module)
    : m_experiment(experiment)
    , m_real_data(0)
    , m_chi2_module(0)
{
    if(real_data) m_real_data = real_data->clone();
    if(chi2_module) {
        m_chi2_module = chi2_module->clone();
    } else {
        m_chi2_module = new ChiSquaredModule();
    }
}

FitSuiteKit::KitItem::~KitItem()
{
    delete m_real_data;
    delete m_chi2_module;
}


/* ************************************************************************* */
// clear all data
/* ************************************************************************* */
void FitSuiteKit::clear()
{
    for(KitItemVector_t::iterator it = m_kit.begin(); it!= m_kit.end(); ++it) delete (*it);
    m_kit.clear();
}


/* ************************************************************************* */
// add to kit pair of (experiment, real data) for consecutive simulation and chi2 module
/* ************************************************************************* */
void FitSuiteKit::add(Experiment *experiment, const OutputData<double > *real_data, const IChiSquaredModule *chi2_module)
{
    m_kit.push_back(new KitItem(experiment, real_data, chi2_module));
}


/* ************************************************************************* */
// loop through all defined experiments and run they simulation
/* ************************************************************************* */
void FitSuiteKit::runSimulation()
{
    for(KitItemVector_t::iterator it = m_kit.begin(); it!= m_kit.end(); ++it) {
        (*it)->m_experiment->runSimulation();
        (*it)->m_experiment->normalize();
    }
}


/* ************************************************************************* */
// loop through all defined experiments and run they simulation
/* ************************************************************************* */
double FitSuiteKit::getChiSquaredValue()
{
    double chi_squared(0);
    for(size_t i_exp = 0; i_exp<m_kit.size(); ++i_exp) {
        const OutputData<double> *simulated_data = getSimulatedData(i_exp);
        const OutputData<double> *real_data = getRealData(i_exp);

        IChiSquaredModule *chi2_module = getChiSquaredModule(i_exp);

        chi2_module->setRealData(*real_data);
        chi_squared += chi2_module->calculateChiSquared(simulated_data);
    }
    return chi_squared;
}

