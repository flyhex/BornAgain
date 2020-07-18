// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Fit/Minimizer/MinimizerTest.cpp
//! @brief     Defines class MinimizerTest
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Tests/Functional/Fit/Minimizer/MinimizerTest.h"
#include "Tests/Functional/Fit/Minimizer/FunctionTestPlanFactory.h"

MinimizerTest::MinimizerTest(const std::string& minimizer_name, const std::string& algorithm_name,
                             const std::string& fit_plan_name, const std::string& options)
    : IMinimizerTest(minimizer_name, algorithm_name, fit_plan_name, options)
{
}

std::unique_ptr<MinimizerTestPlan> MinimizerTest::createPlan() const
{
    return FunctionTestPlanFactory().createItemPtr(m_fit_plan_name);
}
