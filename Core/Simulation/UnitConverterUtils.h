// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Simulation/UnitConverterUtils.h
//! @brief     Declares utilities for unit converters.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_SIMULATION_UNITCONVERTERUTILS_H
#define BORNAGAIN_CORE_SIMULATION_UNITCONVERTERUTILS_H

#include "Device/Unit/IUnitConverter.h"

class Instrument;
class ISimulation;
template <class T> class OutputData;

//! Namespace enclosing a number of utilities/helpers for unit converters

namespace UnitConverterUtils
{

//! Returns zero-valued output data array in specified units
std::unique_ptr<OutputData<double>> createOutputData(const IUnitConverter& converter,
                                                     Axes::Units units);

//! Helper factory function to use in GISASSimulation. Depending on the type of detector,
//! returns either RectangularConverter or SphericalConverter.
std::unique_ptr<IUnitConverter> createConverterForGISAS(const Instrument& instrument);

std::unique_ptr<IUnitConverter> createConverter(const ISimulation& simulation);
} // namespace UnitConverterUtils

#endif // BORNAGAIN_CORE_SIMULATION_UNITCONVERTERUTILS_H
