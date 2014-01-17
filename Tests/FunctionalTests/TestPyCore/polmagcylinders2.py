# Magnetic cylinders in DWBA with zero magnetic field
import sys
import os
import numpy
import gzip
from utils import get_difference
from utils import get_reference_data

sys.path.append(os.path.abspath(
                os.path.join(os.path.split(__file__)[0],
                '..', '..', '..', 'lib')))


from libBornAgainCore import *


# ----------------------------------
# describe sample and run simulation
# ----------------------------------
def RunSimulation():
    # defining materials
    mAmbience = MaterialManager.getHomogeneousMaterial("Air", 0.0, 0.0)
    mSubstrate = MaterialManager.getHomogeneousMaterial("Substrate", 15e-6, 0.0)

    magnetic_field = kvector_t(0, 1, 0)

    magParticle = MaterialManager.getHomogeneousMagneticMaterial("magParticle", 5e-6, 0.0, magnetic_field )
    # collection of particles
    cylinder_ff = FormFactorCylinder(5*nanometer, 5*nanometer)
    cylinder = Particle(magParticle, cylinder_ff)
    
    particle_decoration = ParticleDecoration()
    particle_decoration.addParticle(cylinder, 0.0, 1.0)
    interference = InterferenceFunctionNone()
    particle_decoration.addInterferenceFunction(interference)

    # air layer with particles and substrate form multi layer
    air_layer = Layer(mAmbience)
    air_layer.setDecoration(particle_decoration)
    substrate_layer = Layer(mSubstrate, 0)
    multi_layer = MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(substrate_layer)

    # build and run experiment
    simulation = Simulation()
    simulation.setDetectorParameters(100, -1*degree, 1.0*degree, 100, 0.0*degree, 2.0*degree, True)
    simulation.setBeamParameters(1.0*angstrom, 0.2*degree, 0.0*degree)
    simulation.setSample(multi_layer)
    simulation.setBeamIntensity(1e7)
    simulation.runSimulation()
    simulation.normalize()
    return simulation


# --------------------------------------------------------------
# run test and analyse test results
# --------------------------------------------------------------
def run_test():
    simulation = RunSimulation()

    diff = 0.0
    diff += get_difference(simulation.getPolarizedIntensityData(0, 0).getArray(), get_reference_data('magcyl2_reference_00.txt.gz').getArray())
    diff += get_difference(simulation.getPolarizedIntensityData(0, 1).getArray(), get_reference_data('magcyl2_reference_01.txt.gz').getArray())
    diff += get_difference(simulation.getPolarizedIntensityData(1, 0).getArray(), get_reference_data('magcyl2_reference_10.txt.gz').getArray())
    diff += get_difference(simulation.getPolarizedIntensityData(1, 1).getArray(), get_reference_data('magcyl2_reference_11.txt.gz').getArray())
    diff /= 4.0
    status = "OK"
    if diff > 2e-10:
        status = "FAILED"
    return "PolarizedDWBAZeroMag", "functional test: polarized DWBA with non-zero magnetic field", status


if __name__ == '__main__':
    name, description, status = run_test()
    print name, description, status
    if "FAILED" in status:
        exit(1)