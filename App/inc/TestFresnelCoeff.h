#ifndef TESTFRESNELCOEFF_H
#define TESTFRESNELCOEFF_H
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   TestFresnelCoeff.h
//! @brief  Definition of TestFresnelCoeff class for tests of Fresnel coeffs
//! @author Scientific Computing Group at FRM II
//! @date   02.05.2012

#include "IFunctionalTest.h"
#include "OpticalFresnel.h"
#include "MultiLayer.h"
#include "OutputData.h"


//- -------------------------------------------------------------------
//! @class TestFresnelCoeff
//! @brief Calculate Fresnel coefficients for several typical multilayer
//! samples and produce validation plots
//- -------------------------------------------------------------------
class TestFresnelCoeff : public IFunctionalTest
{
public:
    TestFresnelCoeff();

    void execute();

private:
    //! calculate fresnel coefficients .vs. alpha_i for several standard samples
    void test_standard_samples();
    //! draw results of the test
    void draw_standard_samples();

    //! calculate fresnel coefficients .vs. alpha_i for set of roughnesses
    void test_roughness_set();
    //! draw result of the test
    void draw_roughness_set();

    MultiLayer *m_sample; //!< pointer to multilayer sample
    OutputData<OpticalFresnel::MultiLayerCoeff_t  > *m_coeffs; //!< output data structure
};








#endif // TESTFRESNELCOEFF_H
