// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tools/inc/Numeric.h
//! @brief     Defines constants and "almost equal" in namespace Numeric.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke 
//
// ************************************************************************** //

#ifndef NUMERIC_H_
#define NUMERIC_H_

#include <limits>
#include <cmath>

//! Floating-point epsilon, tolerances, almost-equal.

namespace Numeric {

static const double required_precision = 1.e-4;

static const double double_epsilon = std::numeric_limits<double>::epsilon();
static const double double_min = std::numeric_limits<double>::min();

//! threshold on probability value during calculation of weighted form factor
static const double probthreshold = 0.0000000001; 

//! compare two doubles
inline bool areAlmostEqual(double a, double b, double tolerance_factor=1.0)
    { return std::abs(a-b) < tolerance_factor*Numeric::double_epsilon; }
}

#endif /* NUMERIC_H_ */
