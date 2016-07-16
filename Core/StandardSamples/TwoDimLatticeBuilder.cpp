// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/TwoDimLatticeBuilder.cpp
//! @brief     Implements class IsGISAXS06Builder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "TwoDimLatticeBuilder.h"
#include "FormFactorCylinder.h"
#include "HomogeneousMaterial.h"
#include "InterferenceFunction2DLattice.h"
#include "MultiLayer.h"
#include "Particle.h"
#include "ParticleComposition.h"
#include "ParticleLayout.h"

// -----------------------------------------------------------------------------
// lattice #1:
// -----------------------------------------------------------------------------
ISample *SquareLatticeBuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);
    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial substrate_material("Substrate", 6e-6, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    std::unique_ptr<InterferenceFunction2DLattice> P_interference_function{
        InterferenceFunction2DLattice::createSquare(10.0 * Units::nanometer) };
    FTDecayFunction2DCauchy pdf(300.0*Units::nanometer/2.0/Units::PI,
                               100.0*Units::nanometer/2.0/Units::PI);
    P_interference_function->setDecayFunction(pdf);

    // particles
    ParticleLayout particle_layout;
    FormFactorCylinder ff_cyl(5.0*Units::nanometer, 5.0*Units::nanometer);
    Particle particle(particle_material, ff_cyl);
    particle_layout.addParticle(particle, 1.0);

    particle_layout.addInterferenceFunction(*P_interference_function);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}


// -----------------------------------------------------------------------------
// lattice #2: centered
// -----------------------------------------------------------------------------
ISample *CenteredSquareLatticeBuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);
    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial substrate_material("Substrate", 6e-6, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    InterferenceFunction2DLattice interference_function(10.0*Units::nanometer,
            10.0*Units::nanometer, Units::PI/2.0);
    FTDecayFunction2DCauchy pdf(300.0*Units::nanometer/2.0/Units::PI,
                               100.0*Units::nanometer/2.0/Units::PI);
    interference_function.setDecayFunction(pdf);

    FormFactorCylinder ff_cyl(5.0*Units::nanometer, 5.0*Units::nanometer);
    Particle cylinder(particle_material, ff_cyl);
    std::vector<kvector_t > positions;
    kvector_t position_1(0.0, 0.0, 0.0);
    kvector_t position_2(5.0*Units::nanometer, -5.0*Units::nanometer, 0.0);
    positions.push_back(position_1);
    positions.push_back(position_2);
    ParticleComposition basis;
    basis.addParticles(cylinder, positions);

    ParticleLayout particle_layout;
    particle_layout.addParticle(basis);
    particle_layout.addInterferenceFunction(interference_function);
    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}


// -----------------------------------------------------------------------------
// lattice #3: rotated
// -----------------------------------------------------------------------------
ISample *RotatedSquareLatticeBuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);
    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial substrate_material("Substrate", 6e-6, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    std::unique_ptr<InterferenceFunction2DLattice> P_interference_function{
        InterferenceFunction2DLattice::createSquare(10.0 * Units::nanometer, 30.0 * Units::degree)};
    FTDecayFunction2DCauchy pdf(300.0*Units::nanometer/2.0/Units::PI,
                               100.0*Units::nanometer/2.0/Units::PI);
    pdf.setGamma(30.0*Units::degree);
    P_interference_function->setDecayFunction(pdf);

    ParticleLayout particle_layout;
    // particle
    FormFactorCylinder ff_cyl(5.0*Units::nanometer, 5.0*Units::nanometer);
    kvector_t position(0.0, 0.0, 0.0);
    Particle p(particle_material, ff_cyl);
    p.setPosition(position);
    particle_layout.addParticle(p);
    particle_layout.addInterferenceFunction(*P_interference_function);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}
