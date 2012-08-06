#include "MultiLayerRoughnessDWBASimulation.h"
#include "MultiLayer.h"
#include "OpticalFresnel.h"
#include "DWBADiffuseReflection.h"

MultiLayerRoughnessDWBASimulation::MultiLayerRoughnessDWBASimulation(const MultiLayer *p_multi_layer)
{
    mp_multi_layer = p_multi_layer->clone();
    mp_T_function.resize(mp_multi_layer->getNumberOfLayers(), 0);
    mp_R_function.resize(mp_multi_layer->getNumberOfLayers(), 0);
}


MultiLayerRoughnessDWBASimulation::~MultiLayerRoughnessDWBASimulation()
{
    for(size_t i=0; i<mp_T_function.size(); ++i) delete mp_T_function[i];
    for(size_t i=0; i<mp_R_function.size(); ++i) delete mp_R_function[i];
    delete mp_multi_layer;
}


void MultiLayerRoughnessDWBASimulation::setTAndRFunctions(int i_layer,
        const IDoubleToComplexFunction& T_function,
        const IDoubleToComplexFunction& R_function)
{
    delete mp_T_function[i_layer];
    mp_T_function[i_layer] = T_function.clone();

    delete mp_R_function[i_layer];
    mp_R_function[i_layer] = R_function.clone();
}



void MultiLayerRoughnessDWBASimulation::run()
{
    double lambda = 2.0*M_PI/m_ki.mag();
    m_dwba_intensity.setAllTo(0.0);
    m_dwba_intensity.resetIndex();
    while (m_dwba_intensity.hasNext())
    {
        double phi_f = m_dwba_intensity.getCurrentValueOfAxis<double>("phi_f");
        double alpha_f = m_dwba_intensity.getCurrentValueOfAxis<double>("alpha_f");
        kvector_t k_f;
        phi_f = 0.0;
        k_f.setLambdaAlphaPhi(lambda, alpha_f, phi_f);
        m_dwba_intensity.next() = evaluate(m_ki, k_f);
    }

}


double MultiLayerRoughnessDWBASimulation::evaluate(kvector_t k_i, kvector_t k_f)
{
    kvector_t q = k_f - k_i;
    double autocorr(0);
    complex_t crosscorr(0);

    std::vector<complex_t > rterm;
    rterm.resize( mp_multi_layer->getNumberOfLayers() );
    std::vector<complex_t > sterm;
    sterm.resize( mp_multi_layer->getNumberOfLayers() );

    for(size_t i=0; i<mp_multi_layer->getNumberOfLayers()-1; i++){
        rterm[i] = get_refractive_term(i);
        sterm[i] = get_sum4terms(i, k_i, k_f);
    }


    for(size_t i=0; i<mp_multi_layer->getNumberOfLayers()-1; i++){
        const LayerRoughness *rough = mp_multi_layer->getLayerBottomInterface(i)->getRoughness();
        //std::cout << " " << i << " " << rterm[i] << " " << sterm[i] << " " << rough->getSpectralFun(q) << std::endl;
        if(rough) {
            autocorr += std::norm( rterm[i] ) * std::norm( sterm[i] ) * rough->getSpectralFun(q);
        } else {
            std::cout << "MultiLayerRoughnessDWBASimulation::evaluate() -> No roughness for layer " << i << std::endl;
        }
    }

    // cross correlation between layers
    if( mp_multi_layer->getCrossCorrLength() != 0.0 ) {
        for(size_t j=0; j<mp_multi_layer->getNumberOfLayers()-1; j++){
            for(size_t k=0; k<mp_multi_layer->getNumberOfLayers()-1; k++) {
                if(j==k) continue;
                crosscorr += rterm[j]*sterm[j]*rterm[k]*mp_multi_layer->getCrossCorrSpectralFun(q,j,k)*std::conj(sterm[k]);
            }
        }
    }

    return (autocorr+crosscorr.real())*k_i.mag2()/16./M_PI;
}


complex_t MultiLayerRoughnessDWBASimulation::get_refractive_term(int ilayer)
{
    complex_t n1 = mp_multi_layer->getLayer(ilayer)->getRefractiveIndex();
    complex_t n2 = mp_multi_layer->getLayer(ilayer+1)->getRefractiveIndex();
    return n1*n1-n2*n2;
}



complex_t MultiLayerRoughnessDWBASimulation::get_sum4terms(int ilayer, kvector_t k_i, kvector_t k_f)
{
    double alpha_i = -std::asin(k_i.z()/k_i.mag());
    double alpha_f = std::asin(k_f.z()/k_f.mag());

    double qz1 =  k_i.z() + k_f.z();
    double qz2 =  k_i.z() - k_f.z();
    double qz3 = -k_i.z() + k_f.z();
    double qz4 = -k_i.z() - k_f.z();

    complex_t Ti = mp_T_function[ilayer+1]->evaluate(alpha_i);
    complex_t Tf = mp_T_function[ilayer+1]->evaluate(alpha_f);
    complex_t Ri = mp_R_function[ilayer+1]->evaluate(alpha_i);
    complex_t Rf = mp_R_function[ilayer+1]->evaluate(alpha_f);

    double sigma = mp_multi_layer->getLayerBottomInterface(ilayer)->getRoughness()->getSigma();
    double sigma2 = -0.5*sigma*sigma;
    complex_t term1 = Ti * Tf * std::exp( sigma2*qz1*qz1 );
    complex_t term2 = Ti * Rf * std::exp( sigma2*qz2*qz2 );
    complex_t term3 = Ri * Tf * std::exp( sigma2*qz3*qz3 );
    complex_t term4 = Ri * Rf * std::exp( sigma2*qz4*qz4 );

//        OpticalFresnel calculator;
//        OpticalFresnel::MultiLayerCoeff_t m_fcoeff_i;
//        OpticalFresnel::MultiLayerCoeff_t m_fcoeff_f;
//        calculator.execute(*mp_multi_layer, k_i, m_fcoeff_i);
//        calculator.execute(*mp_multi_layer, k_f, m_fcoeff_f);
//    complex_t TTi = m_fcoeff_i[ilayer+1].T;
//    complex_t TTf = m_fcoeff_f[ilayer+1].T;
//    complex_t TRi = m_fcoeff_i[ilayer+1].R;
//    complex_t TRf = m_fcoeff_f[ilayer+1].R;
//    complex_t term1 = TTi * TTf * std::exp( sigma2*qz1*qz1 );
//    complex_t term2 = TTi * TRf * std::exp( sigma2*qz2*qz2 );
//    complex_t term3 = TRi * TTf * std::exp( sigma2*qz3*qz3 );
//    complex_t term4 = TRi * TRf * std::exp( sigma2*qz4*qz4 );
//        complex_t diff1 = TRi - Ri;
//        complex_t diff2 = TRf - Rf;
//        complex_t diff3 = TTi - Ti;
//        complex_t diff4 = TTf - Tf;
//        double m_qz1 = std::pow(k_i.z() + k_f.z(), 2);
//        double m_qz2 = std::pow(k_i.z() - k_f.z(), 2);
//        double m_qz3 = std::pow(-k_i.z() + k_f.z(), 2);
//        double m_qz4 = std::pow(-k_i.z() - k_f.z(), 2);
//    double sigma2 = -0.5*std::pow(mp_multi_layer->getLayerBottomInterface(ilayer)->getRoughness()->getSigma(), 2);
//    complex_t term1 = m_fcoeff_i[ilayer+1].T * m_fcoeff_f[ilayer+1].T * std::exp( sigma2*m_qz1 );
//    complex_t term2 = m_fcoeff_i[ilayer+1].T * m_fcoeff_f[ilayer+1].R * std::exp( sigma2*m_qz2 );
//    complex_t term3 = m_fcoeff_i[ilayer+1].R * m_fcoeff_f[ilayer+1].T * std::exp( sigma2*m_qz3 );
//    complex_t term4 = m_fcoeff_i[ilayer+1].R * m_fcoeff_f[ilayer+1].R * std::exp( sigma2*m_qz4 );
//    if(ilayer==0) {
//        if( std::norm(diff1)>0.0001 || std::norm(diff2)>0.0001 || std::norm(diff3)>0.0001 || std::norm(diff4)>0.0001) {
//        std::cout << " " << ilayer << " " << std::endl;
//        std::cout << " diff:" << std::norm(diff1) << " " << std::norm(diff2) << " " << std::norm(diff3) << " " << std::norm(diff4) << std::endl;
//        std::cout << "Ti:"<< TTi << " " << Ti << std::endl;
//        std::cout << "Tf:"<< TTf << " " << Tf << std::endl;
//        std::cout << "Ri:"<< TRi << " " << Ri << std::endl;
//        std::cout << "Rf:"<< TRf << " " << Rf << std::endl;
//        }
//        std::cout << k_i << " " << k_f << std::endl;
//        std::cout << alpha_i << " " << alpha_f << std::endl;
//        std::cout << Ti << " " << Tf << " " << Ri << " " << Rf << std::endl;
//        std::cout << ilayer << " " << term1 << " " << term2 << " " << term3 << " " << term4 << std::endl;
//    }

    return term1 + term2 + term3 + term4;
}

