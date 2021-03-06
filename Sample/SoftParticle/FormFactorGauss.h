// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/SoftParticle/FormFactorGauss.h
//! @brief     Defines class FormFactorGaussSphere.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_SAMPLE_SOFTPARTICLE_FORMFACTORGAUSS_H
#define BORNAGAIN_SAMPLE_SOFTPARTICLE_FORMFACTORGAUSS_H

#include "Sample/Scattering/IFormFactorBorn.h"

//! The form factor of a Gaussian sphere.
//! @ingroup softParticle

class FormFactorGaussSphere : public IFormFactorBorn
{
public:
    FormFactorGaussSphere(const std::vector<double> P);
    FormFactorGaussSphere(double mean_radius);

    FormFactorGaussSphere* clone() const override final
    {
        return new FormFactorGaussSphere(m_mean_radius);
    }
    void accept(INodeVisitor* visitor) const override final { visitor->visit(this); }

    double getMeanRadius() const { return m_mean_radius; }

    double radialExtension() const override final { return m_mean_radius; }

    complex_t evaluate_for_q(cvector_t q) const override final;

protected:
    void onChange() override final{};

private:
    const double& m_mean_radius;
    void initialize();
};

#endif // BORNAGAIN_SAMPLE_SOFTPARTICLE_FORMFACTORGAUSS_H
