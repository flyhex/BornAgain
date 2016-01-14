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
#include "FormFactorTruncatedCube.pypp.h"

namespace bp = boost::python;

struct FormFactorTruncatedCube_wrapper : FormFactorTruncatedCube, bp::wrapper< FormFactorTruncatedCube > {

    FormFactorTruncatedCube_wrapper(double length, double removed_length )
    : FormFactorTruncatedCube( length, removed_length )
      , bp::wrapper< FormFactorTruncatedCube >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FormFactorTruncatedCube * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorTruncatedCube::clone(  );
        }
    }
    
    ::FormFactorTruncatedCube * default_clone(  ) const  {
        return FormFactorTruncatedCube::clone( );
    }

    virtual double getLength(  ) const  {
        if( bp::override func_getLength = this->get_override( "getLength" ) )
            return func_getLength(  );
        else{
            return this->FormFactorTruncatedCube::getLength(  );
        }
    }
    
    double default_getLength(  ) const  {
        return FormFactorTruncatedCube::getLength( );
    }

    virtual double getRemovedLength(  ) const  {
        if( bp::override func_getRemovedLength = this->get_override( "getRemovedLength" ) )
            return func_getRemovedLength(  );
        else{
            return this->FormFactorTruncatedCube::getRemovedLength(  );
        }
    }
    
    double default_getRemovedLength(  ) const  {
        return FormFactorTruncatedCube::getRemovedLength( );
    }

    virtual void setLength( double length ) {
        if( bp::override func_setLength = this->get_override( "setLength" ) )
            func_setLength( length );
        else{
            this->FormFactorTruncatedCube::setLength( length );
        }
    }
    
    void default_setLength( double length ) {
        FormFactorTruncatedCube::setLength( length );
    }

    virtual void setRemovedLength( double removed_length ) {
        if( bp::override func_setRemovedLength = this->get_override( "setRemovedLength" ) )
            func_setRemovedLength( removed_length );
        else{
            this->FormFactorTruncatedCube::setRemovedLength( removed_length );
        }
    }
    
    void default_setRemovedLength( double removed_length ) {
        FormFactorTruncatedCube::setRemovedLength( removed_length );
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

    virtual double getHeight(  ) const  {
        if( bp::override func_getHeight = this->get_override( "getHeight" ) )
            return func_getHeight(  );
        else{
            return this->IFormFactor::getHeight(  );
        }
    }
    
    double default_getHeight(  ) const  {
        return IFormFactor::getHeight( );
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

void register_FormFactorTruncatedCube_class(){

    { //::FormFactorTruncatedCube
        typedef bp::class_< FormFactorTruncatedCube_wrapper, bp::bases< IFormFactorBorn >, std::auto_ptr< FormFactorTruncatedCube_wrapper >, boost::noncopyable > FormFactorTruncatedCube_exposer_t;
        FormFactorTruncatedCube_exposer_t FormFactorTruncatedCube_exposer = FormFactorTruncatedCube_exposer_t( "FormFactorTruncatedCube", "The formfactor of a truncated cube.", bp::init< double, double >(( bp::arg("length"), bp::arg("removed_length") ), "Truncated cube constructor.\n\n:Parameters:\n  - 'side' - length of the full cube\n  - 'side' - length of the trirectangular tetrahedron removed from each vertex of the cube\n") );
        bp::scope FormFactorTruncatedCube_scope( FormFactorTruncatedCube_exposer );
        { //::FormFactorTruncatedCube::clone
        
            typedef ::FormFactorTruncatedCube * ( ::FormFactorTruncatedCube::*clone_function_type)(  ) const;
            typedef ::FormFactorTruncatedCube * ( FormFactorTruncatedCube_wrapper::*default_clone_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "clone"
                , clone_function_type(&::FormFactorTruncatedCube::clone)
                , default_clone_function_type(&FormFactorTruncatedCube_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorTruncatedCube::getLength
        
            typedef double ( ::FormFactorTruncatedCube::*getLength_function_type)(  ) const;
            typedef double ( FormFactorTruncatedCube_wrapper::*default_getLength_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "getLength"
                , getLength_function_type(&::FormFactorTruncatedCube::getLength)
                , default_getLength_function_type(&FormFactorTruncatedCube_wrapper::default_getLength) );
        
        }
        { //::FormFactorTruncatedCube::getRemovedLength
        
            typedef double ( ::FormFactorTruncatedCube::*getRemovedLength_function_type)(  ) const;
            typedef double ( FormFactorTruncatedCube_wrapper::*default_getRemovedLength_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "getRemovedLength"
                , getRemovedLength_function_type(&::FormFactorTruncatedCube::getRemovedLength)
                , default_getRemovedLength_function_type(&FormFactorTruncatedCube_wrapper::default_getRemovedLength) );
        
        }
        { //::FormFactorTruncatedCube::setLength
        
            typedef void ( ::FormFactorTruncatedCube::*setLength_function_type)( double ) ;
            typedef void ( FormFactorTruncatedCube_wrapper::*default_setLength_function_type)( double ) ;
            
            FormFactorTruncatedCube_exposer.def( 
                "setLength"
                , setLength_function_type(&::FormFactorTruncatedCube::setLength)
                , default_setLength_function_type(&FormFactorTruncatedCube_wrapper::default_setLength)
                , ( bp::arg("length") ) );
        
        }
        { //::FormFactorTruncatedCube::setRemovedLength
        
            typedef void ( ::FormFactorTruncatedCube::*setRemovedLength_function_type)( double ) ;
            typedef void ( FormFactorTruncatedCube_wrapper::*default_setRemovedLength_function_type)( double ) ;
            
            FormFactorTruncatedCube_exposer.def( 
                "setRemovedLength"
                , setRemovedLength_function_type(&::FormFactorTruncatedCube::setRemovedLength)
                , default_setRemovedLength_function_type(&FormFactorTruncatedCube_wrapper::default_setRemovedLength)
                , ( bp::arg("removed_length") ) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type)(  ) const;
            typedef ::ISample * ( FormFactorTruncatedCube_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&FormFactorTruncatedCube_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( FormFactorTruncatedCube_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&FormFactorTruncatedCube_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IFormFactorBorn::evaluate
        
            typedef ::complex_t ( ::IFormFactorBorn::*evaluate_function_type)( ::WavevectorInfo const & ) const;
            typedef ::complex_t ( FormFactorTruncatedCube_wrapper::*default_evaluate_function_type)( ::WavevectorInfo const & ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::IFormFactorBorn::evaluate)
                , default_evaluate_function_type(&FormFactorTruncatedCube_wrapper::default_evaluate)
                , ( bp::arg("wavevectors") ) );
        
        }
        { //::ISample::getChildren
        
            typedef ::std::vector< const ISample* > ( ::ISample::*getChildren_function_type)(  ) const;
            typedef ::std::vector< const ISample* > ( FormFactorTruncatedCube_wrapper::*default_getChildren_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "getChildren"
                , getChildren_function_type(&::ISample::getChildren)
                , default_getChildren_function_type(&FormFactorTruncatedCube_wrapper::default_getChildren) );
        
        }
        { //::IFormFactor::getHeight
        
            typedef double ( ::IFormFactor::*getHeight_function_type)(  ) const;
            typedef double ( FormFactorTruncatedCube_wrapper::*default_getHeight_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "getHeight"
                , getHeight_function_type(&::IFormFactor::getHeight)
                , default_getHeight_function_type(&FormFactorTruncatedCube_wrapper::default_getHeight) );
        
        }
        { //::IFormFactor::getRadius
        
            typedef double ( ::IFormFactor::*getRadius_function_type)(  ) const;
            typedef double ( FormFactorTruncatedCube_wrapper::*default_getRadius_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::IFormFactor::getRadius)
                , default_getRadius_function_type(&FormFactorTruncatedCube_wrapper::default_getRadius) );
        
        }
        { //::IFormFactor::getVolume
        
            typedef double ( ::IFormFactor::*getVolume_function_type)(  ) const;
            typedef double ( FormFactorTruncatedCube_wrapper::*default_getVolume_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::IFormFactor::getVolume)
                , default_getVolume_function_type(&FormFactorTruncatedCube_wrapper::default_getVolume) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( FormFactorTruncatedCube_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            FormFactorTruncatedCube_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&FormFactorTruncatedCube_wrapper::default_printSampleTree) );
        
        }
        { //::IFormFactor::setAmbientMaterial
        
            typedef void ( ::IFormFactor::*setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            typedef void ( FormFactorTruncatedCube_wrapper::*default_setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            
            FormFactorTruncatedCube_exposer.def( 
                "setAmbientMaterial"
                , setAmbientMaterial_function_type(&::IFormFactor::setAmbientMaterial)
                , default_setAmbientMaterial_function_type(&FormFactorTruncatedCube_wrapper::default_setAmbientMaterial)
                , ( bp::arg("material") ) );
        
        }
        { //::ISample::size
        
            typedef ::std::size_t ( ::ISample::*size_function_type)(  ) const;
            typedef ::std::size_t ( FormFactorTruncatedCube_wrapper::*default_size_function_type)(  ) const;
            
            FormFactorTruncatedCube_exposer.def( 
                "size"
                , size_function_type(&::ISample::size)
                , default_size_function_type(&FormFactorTruncatedCube_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( FormFactorTruncatedCube_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            FormFactorTruncatedCube_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&FormFactorTruncatedCube_wrapper::default_transferToCPP) );
        
        }
    }

}
