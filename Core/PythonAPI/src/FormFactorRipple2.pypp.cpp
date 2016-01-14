// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "FormFactorRipple2.pypp.h"

namespace bp = boost::python;

struct FormFactorRipple2_wrapper : FormFactorRipple2, bp::wrapper< FormFactorRipple2 > {

    FormFactorRipple2_wrapper(double length, double width, double height, double asymetry )
    : FormFactorRipple2( length, width, height, asymetry )
      , bp::wrapper< FormFactorRipple2 >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FormFactorRipple2 * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorRipple2::clone(  );
        }
    }
    
    ::FormFactorRipple2 * default_clone(  ) const  {
        return FormFactorRipple2::clone( );
    }

    virtual ::complex_t evaluate_for_q( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate_for_q = this->get_override( "evaluate_for_q" ) )
            return func_evaluate_for_q( boost::ref(q) );
        else{
            return this->FormFactorRipple2::evaluate_for_q( boost::ref(q) );
        }
    }
    
    ::complex_t default_evaluate_for_q( ::cvector_t const & q ) const  {
        return FormFactorRipple2::evaluate_for_q( boost::ref(q) );
    }

    virtual double getAsymmetry(  ) const  {
        if( bp::override func_getAsymmetry = this->get_override( "getAsymmetry" ) )
            return func_getAsymmetry(  );
        else{
            return this->FormFactorRipple2::getAsymmetry(  );
        }
    }
    
    double default_getAsymmetry(  ) const  {
        return FormFactorRipple2::getAsymmetry( );
    }

    virtual double getHeight(  ) const  {
        if( bp::override func_getHeight = this->get_override( "getHeight" ) )
            return func_getHeight(  );
        else{
            return this->FormFactorRipple2::getHeight(  );
        }
    }
    
    double default_getHeight(  ) const  {
        return FormFactorRipple2::getHeight( );
    }

    virtual double getLength(  ) const  {
        if( bp::override func_getLength = this->get_override( "getLength" ) )
            return func_getLength(  );
        else{
            return this->FormFactorRipple2::getLength(  );
        }
    }
    
    double default_getLength(  ) const  {
        return FormFactorRipple2::getLength( );
    }

    virtual double getWidth(  ) const  {
        if( bp::override func_getWidth = this->get_override( "getWidth" ) )
            return func_getWidth(  );
        else{
            return this->FormFactorRipple2::getWidth(  );
        }
    }
    
    double default_getWidth(  ) const  {
        return FormFactorRipple2::getWidth( );
    }

    virtual ::ISample * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->ISample::cloneInvertB(  );
        }
    }
    
    ::ISample * default_cloneInvertB(  ) const  {
        return ISample::cloneInvertB( );
    }

    virtual bool containsMagneticMaterial(  ) const  {
        if( bp::override func_containsMagneticMaterial = this->get_override( "containsMagneticMaterial" ) )
            return func_containsMagneticMaterial(  );
        else{
            return this->ISample::containsMagneticMaterial(  );
        }
    }
    
    bool default_containsMagneticMaterial(  ) const  {
        return ISample::containsMagneticMaterial( );
    }

    virtual ::complex_t evaluate( ::WavevectorInfo const & wavevectors ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(wavevectors) );
        else{
            return this->IFormFactorBorn::evaluate( boost::ref(wavevectors) );
        }
    }
    
    ::complex_t default_evaluate( ::WavevectorInfo const & wavevectors ) const  {
        return IFormFactorBorn::evaluate( boost::ref(wavevectors) );
    }

    virtual ::std::vector< const ISample* > getChildren(  ) const  {
        if( bp::override func_getChildren = this->get_override( "getChildren" ) )
            return func_getChildren(  );
        else{
            return this->ISample::getChildren(  );
        }
    }
    
    ::std::vector< const ISample* > default_getChildren(  ) const  {
        return ISample::getChildren( );
    }

    virtual double getRadius(  ) const  {
        if( bp::override func_getRadius = this->get_override( "getRadius" ) )
            return func_getRadius(  );
        else{
            return this->IFormFactor::getRadius(  );
        }
    }
    
    double default_getRadius(  ) const  {
        return IFormFactor::getRadius( );
    }

    virtual double getVolume(  ) const  {
        if( bp::override func_getVolume = this->get_override( "getVolume" ) )
            return func_getVolume(  );
        else{
            return this->IFormFactor::getVolume(  );
        }
    }
    
    double default_getVolume(  ) const  {
        return IFormFactor::getVolume( );
    }

    virtual void printSampleTree(  ) {
        if( bp::override func_printSampleTree = this->get_override( "printSampleTree" ) )
            func_printSampleTree(  );
        else{
            this->ISample::printSampleTree(  );
        }
    }
    
    void default_printSampleTree(  ) {
        ISample::printSampleTree( );
    }

    virtual void setAmbientMaterial( ::IMaterial const & material ) {
        if( bp::override func_setAmbientMaterial = this->get_override( "setAmbientMaterial" ) )
            func_setAmbientMaterial( boost::ref(material) );
        else{
            this->IFormFactor::setAmbientMaterial( boost::ref(material) );
        }
    }
    
    void default_setAmbientMaterial( ::IMaterial const & material ) {
        IFormFactor::setAmbientMaterial( boost::ref(material) );
    }

    virtual ::std::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ISample::size(  );
        }
    }
    
    ::std::size_t default_size(  ) const  {
        return ISample::size( );
    }

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_FormFactorRipple2_class(){

    { //::FormFactorRipple2
        typedef bp::class_< FormFactorRipple2_wrapper, bp::bases< IFormFactorBorn >, std::auto_ptr< FormFactorRipple2_wrapper >, boost::noncopyable > FormFactorRipple2_exposer_t;
        FormFactorRipple2_exposer_t FormFactorRipple2_exposer = FormFactorRipple2_exposer_t( "FormFactorRipple2", "The formfactor for a triangular ripple.", bp::init< double, double, double, double >(( bp::arg("length"), bp::arg("width"), bp::arg("height"), bp::arg("asymetry") ), "Ripple2 constructor.\n\n:Parameters:\n  - 'length' - of Ripple2\n  - 'width' - of triangular cross section\n  - 'height' - of triangular cross section\n  - 'asymmetry' - length of triangular cross section\n") );
        bp::scope FormFactorRipple2_scope( FormFactorRipple2_exposer );
        { //::FormFactorRipple2::clone
        
            typedef ::FormFactorRipple2 * ( ::FormFactorRipple2::*clone_function_type)(  ) const;
            typedef ::FormFactorRipple2 * ( FormFactorRipple2_wrapper::*default_clone_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "clone"
                , clone_function_type(&::FormFactorRipple2::clone)
                , default_clone_function_type(&FormFactorRipple2_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorRipple2::evaluate_for_q
        
            typedef ::complex_t ( ::FormFactorRipple2::*evaluate_for_q_function_type)( ::cvector_t const & ) const;
            typedef ::complex_t ( FormFactorRipple2_wrapper::*default_evaluate_for_q_function_type)( ::cvector_t const & ) const;
            
            FormFactorRipple2_exposer.def( 
                "evaluate_for_q"
                , evaluate_for_q_function_type(&::FormFactorRipple2::evaluate_for_q)
                , default_evaluate_for_q_function_type(&FormFactorRipple2_wrapper::default_evaluate_for_q)
                , ( bp::arg("q") ) );
        
        }
        { //::FormFactorRipple2::getAsymmetry
        
            typedef double ( ::FormFactorRipple2::*getAsymmetry_function_type)(  ) const;
            typedef double ( FormFactorRipple2_wrapper::*default_getAsymmetry_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "getAsymmetry"
                , getAsymmetry_function_type(&::FormFactorRipple2::getAsymmetry)
                , default_getAsymmetry_function_type(&FormFactorRipple2_wrapper::default_getAsymmetry) );
        
        }
        { //::FormFactorRipple2::getHeight
        
            typedef double ( ::FormFactorRipple2::*getHeight_function_type)(  ) const;
            typedef double ( FormFactorRipple2_wrapper::*default_getHeight_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "getHeight"
                , getHeight_function_type(&::FormFactorRipple2::getHeight)
                , default_getHeight_function_type(&FormFactorRipple2_wrapper::default_getHeight) );
        
        }
        { //::FormFactorRipple2::getLength
        
            typedef double ( ::FormFactorRipple2::*getLength_function_type)(  ) const;
            typedef double ( FormFactorRipple2_wrapper::*default_getLength_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "getLength"
                , getLength_function_type(&::FormFactorRipple2::getLength)
                , default_getLength_function_type(&FormFactorRipple2_wrapper::default_getLength) );
        
        }
        { //::FormFactorRipple2::getWidth
        
            typedef double ( ::FormFactorRipple2::*getWidth_function_type)(  ) const;
            typedef double ( FormFactorRipple2_wrapper::*default_getWidth_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "getWidth"
                , getWidth_function_type(&::FormFactorRipple2::getWidth)
                , default_getWidth_function_type(&FormFactorRipple2_wrapper::default_getWidth) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type)(  ) const;
            typedef ::ISample * ( FormFactorRipple2_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&FormFactorRipple2_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( FormFactorRipple2_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&FormFactorRipple2_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IFormFactorBorn::evaluate
        
            typedef ::complex_t ( ::IFormFactorBorn::*evaluate_function_type)( ::WavevectorInfo const & ) const;
            typedef ::complex_t ( FormFactorRipple2_wrapper::*default_evaluate_function_type)( ::WavevectorInfo const & ) const;
            
            FormFactorRipple2_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::IFormFactorBorn::evaluate)
                , default_evaluate_function_type(&FormFactorRipple2_wrapper::default_evaluate)
                , ( bp::arg("wavevectors") ) );
        
        }
        { //::ISample::getChildren
        
            typedef ::std::vector< const ISample* > ( ::ISample::*getChildren_function_type)(  ) const;
            typedef ::std::vector< const ISample* > ( FormFactorRipple2_wrapper::*default_getChildren_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "getChildren"
                , getChildren_function_type(&::ISample::getChildren)
                , default_getChildren_function_type(&FormFactorRipple2_wrapper::default_getChildren) );
        
        }
        { //::IFormFactor::getRadius
        
            typedef double ( ::IFormFactor::*getRadius_function_type)(  ) const;
            typedef double ( FormFactorRipple2_wrapper::*default_getRadius_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::IFormFactor::getRadius)
                , default_getRadius_function_type(&FormFactorRipple2_wrapper::default_getRadius) );
        
        }
        { //::IFormFactor::getVolume
        
            typedef double ( ::IFormFactor::*getVolume_function_type)(  ) const;
            typedef double ( FormFactorRipple2_wrapper::*default_getVolume_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::IFormFactor::getVolume)
                , default_getVolume_function_type(&FormFactorRipple2_wrapper::default_getVolume) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( FormFactorRipple2_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            FormFactorRipple2_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&FormFactorRipple2_wrapper::default_printSampleTree) );
        
        }
        { //::IFormFactor::setAmbientMaterial
        
            typedef void ( ::IFormFactor::*setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            typedef void ( FormFactorRipple2_wrapper::*default_setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            
            FormFactorRipple2_exposer.def( 
                "setAmbientMaterial"
                , setAmbientMaterial_function_type(&::IFormFactor::setAmbientMaterial)
                , default_setAmbientMaterial_function_type(&FormFactorRipple2_wrapper::default_setAmbientMaterial)
                , ( bp::arg("material") ) );
        
        }
        { //::ISample::size
        
            typedef ::std::size_t ( ::ISample::*size_function_type)(  ) const;
            typedef ::std::size_t ( FormFactorRipple2_wrapper::*default_size_function_type)(  ) const;
            
            FormFactorRipple2_exposer.def( 
                "size"
                , size_function_type(&::ISample::size)
                , default_size_function_type(&FormFactorRipple2_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( FormFactorRipple2_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            FormFactorRipple2_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&FormFactorRipple2_wrapper::default_transferToCPP) );
        
        }
    }

}
