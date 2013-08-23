// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "FormFactorEllipsoid.pypp.h"

namespace bp = boost::python;

struct FormFactorEllipsoid_wrapper : FormFactorEllipsoid, bp::wrapper< FormFactorEllipsoid > {

    FormFactorEllipsoid_wrapper(double radius, double width, double height, double alpha )
    : FormFactorEllipsoid( radius, width, height, alpha )
      , bp::wrapper< FormFactorEllipsoid >(){
        // constructor
    
    }

    virtual ::FormFactorEllipsoid * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorEllipsoid::clone(  );
        }
    }
    
    ::FormFactorEllipsoid * default_clone(  ) const  {
        return FormFactorEllipsoid::clone( );
    }

    virtual ::complex_t evaluate_for_q( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate_for_q = this->get_override( "evaluate_for_q" ) )
            return func_evaluate_for_q( boost::ref(q) );
        else{
            return this->FormFactorEllipsoid::evaluate_for_q( boost::ref(q) );
        }
    }
    
    ::complex_t default_evaluate_for_q( ::cvector_t const & q ) const  {
        return FormFactorEllipsoid::evaluate_for_q( boost::ref(q) );
    }

    virtual double getHeight(  ) const  {
        if( bp::override func_getHeight = this->get_override( "getHeight" ) )
            return func_getHeight(  );
        else{
            return this->FormFactorEllipsoid::getHeight(  );
        }
    }
    
    double default_getHeight(  ) const  {
        return FormFactorEllipsoid::getHeight( );
    }

    virtual int getNumberOfStochasticParameters(  ) const  {
        if( bp::override func_getNumberOfStochasticParameters = this->get_override( "getNumberOfStochasticParameters" ) )
            return func_getNumberOfStochasticParameters(  );
        else{
            return this->FormFactorEllipsoid::getNumberOfStochasticParameters(  );
        }
    }
    
    int default_getNumberOfStochasticParameters(  ) const  {
        return FormFactorEllipsoid::getNumberOfStochasticParameters( );
    }

    virtual double getRadius(  ) const  {
        if( bp::override func_getRadius = this->get_override( "getRadius" ) )
            return func_getRadius(  );
        else{
            return this->FormFactorEllipsoid::getRadius(  );
        }
    }
    
    double default_getRadius(  ) const  {
        return FormFactorEllipsoid::getRadius( );
    }

    virtual double getVolume(  ) const  {
        if( bp::override func_getVolume = this->get_override( "getVolume" ) )
            return func_getVolume(  );
        else{
            return this->FormFactorEllipsoid::getVolume(  );
        }
    }
    
    double default_getVolume(  ) const  {
        return FormFactorEllipsoid::getVolume( );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else{
            this->IParameterized::clearParameterPool(  );
        }
    }
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
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

    virtual void createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::size_t nbr_samples ) const  {
        if( bp::override func_createDistributedFormFactors = this->get_override( "createDistributedFormFactors" ) )
            func_createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
        else{
            this->IFormFactor::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
        }
    }
    
    void default_createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::size_t nbr_samples ) const  {
        IFormFactor::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual ::complex_t evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, double alpha_i, double alpha_f ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(k_i), boost::ref(k_f_bin), alpha_i, alpha_f );
        else{
            return this->IFormFactorBorn::evaluate( boost::ref(k_i), boost::ref(k_f_bin), alpha_i, alpha_f );
        }
    }
    
    ::complex_t default_evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, double alpha_i, double alpha_f ) const  {
        return IFormFactorBorn::evaluate( boost::ref(k_i), boost::ref(k_f_bin), alpha_i, alpha_f );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ISample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ISample::getCompositeSample( );
    }

    virtual bool isDistributedFormFactor(  ) const  {
        if( bp::override func_isDistributedFormFactor = this->get_override( "isDistributedFormFactor" ) )
            return func_isDistributedFormFactor(  );
        else{
            return this->IFormFactor::isDistributedFormFactor(  );
        }
    }
    
    bool default_isDistributedFormFactor(  ) const  {
        return IFormFactor::isDistributedFormFactor( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< FormFactorEllipsoid_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else{
            return this->IParameterized::setParameterValue( name, value );
        }
    }
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_FormFactorEllipsoid_class(){

    { //::FormFactorEllipsoid
        typedef bp::class_< FormFactorEllipsoid_wrapper, bp::bases< IFormFactorBorn >, boost::noncopyable > FormFactorEllipsoid_exposer_t;
        FormFactorEllipsoid_exposer_t FormFactorEllipsoid_exposer = FormFactorEllipsoid_exposer_t( "FormFactorEllipsoid", bp::init< double, double, double, double >(( bp::arg("radius"), bp::arg("width"), bp::arg("height"), bp::arg("alpha") )) );
        bp::scope FormFactorEllipsoid_scope( FormFactorEllipsoid_exposer );
        { //::FormFactorEllipsoid::clone
        
            typedef ::FormFactorEllipsoid * ( ::FormFactorEllipsoid::*clone_function_type )(  ) const;
            typedef ::FormFactorEllipsoid * ( FormFactorEllipsoid_wrapper::*default_clone_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "clone"
                , clone_function_type(&::FormFactorEllipsoid::clone)
                , default_clone_function_type(&FormFactorEllipsoid_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorEllipsoid::evaluate_for_q
        
            typedef ::complex_t ( ::FormFactorEllipsoid::*evaluate_for_q_function_type )( ::cvector_t const & ) const;
            typedef ::complex_t ( FormFactorEllipsoid_wrapper::*default_evaluate_for_q_function_type )( ::cvector_t const & ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "evaluate_for_q"
                , evaluate_for_q_function_type(&::FormFactorEllipsoid::evaluate_for_q)
                , default_evaluate_for_q_function_type(&FormFactorEllipsoid_wrapper::default_evaluate_for_q)
                , ( bp::arg("q") ) );
        
        }
        { //::FormFactorEllipsoid::getHeight
        
            typedef double ( ::FormFactorEllipsoid::*getHeight_function_type )(  ) const;
            typedef double ( FormFactorEllipsoid_wrapper::*default_getHeight_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "getHeight"
                , getHeight_function_type(&::FormFactorEllipsoid::getHeight)
                , default_getHeight_function_type(&FormFactorEllipsoid_wrapper::default_getHeight) );
        
        }
        { //::FormFactorEllipsoid::getNumberOfStochasticParameters
        
            typedef int ( ::FormFactorEllipsoid::*getNumberOfStochasticParameters_function_type )(  ) const;
            typedef int ( FormFactorEllipsoid_wrapper::*default_getNumberOfStochasticParameters_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "getNumberOfStochasticParameters"
                , getNumberOfStochasticParameters_function_type(&::FormFactorEllipsoid::getNumberOfStochasticParameters)
                , default_getNumberOfStochasticParameters_function_type(&FormFactorEllipsoid_wrapper::default_getNumberOfStochasticParameters) );
        
        }
        { //::FormFactorEllipsoid::getRadius
        
            typedef double ( ::FormFactorEllipsoid::*getRadius_function_type )(  ) const;
            typedef double ( FormFactorEllipsoid_wrapper::*default_getRadius_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::FormFactorEllipsoid::getRadius)
                , default_getRadius_function_type(&FormFactorEllipsoid_wrapper::default_getRadius) );
        
        }
        { //::FormFactorEllipsoid::getVolume
        
            typedef double ( ::FormFactorEllipsoid::*getVolume_function_type )(  ) const;
            typedef double ( FormFactorEllipsoid_wrapper::*default_getVolume_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::FormFactorEllipsoid::getVolume)
                , default_getVolume_function_type(&FormFactorEllipsoid_wrapper::default_getVolume) );
        
        }
        { //::FormFactorEllipsoid::getWidth
        
            typedef double ( ::FormFactorEllipsoid::*getWidth_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "getWidth"
                , getWidth_function_type( &::FormFactorEllipsoid::getWidth ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( FormFactorEllipsoid_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            FormFactorEllipsoid_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&FormFactorEllipsoid_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( FormFactorEllipsoid_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            FormFactorEllipsoid_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&FormFactorEllipsoid_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type )(  ) const;
            typedef ::ISample * ( FormFactorEllipsoid_wrapper::*default_cloneInvertB_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&FormFactorEllipsoid_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IFormFactor::createDistributedFormFactors
        
            typedef void ( ::IFormFactor::*createDistributedFormFactors_function_type )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::size_t ) const;
            typedef void ( FormFactorEllipsoid_wrapper::*default_createDistributedFormFactors_function_type )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::size_t ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "createDistributedFormFactors"
                , createDistributedFormFactors_function_type(&::IFormFactor::createDistributedFormFactors)
                , default_createDistributedFormFactors_function_type(&FormFactorEllipsoid_wrapper::default_createDistributedFormFactors)
                , ( bp::arg("form_factors"), bp::arg("probabilities"), bp::arg("nbr_samples") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( FormFactorEllipsoid_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&FormFactorEllipsoid_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IFormFactorBorn::evaluate
        
            typedef ::complex_t ( ::IFormFactorBorn::*evaluate_function_type )( ::cvector_t const &,::Bin1DCVector const &,double,double ) const;
            typedef ::complex_t ( FormFactorEllipsoid_wrapper::*default_evaluate_function_type )( ::cvector_t const &,::Bin1DCVector const &,double,double ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::IFormFactorBorn::evaluate)
                , default_evaluate_function_type(&FormFactorEllipsoid_wrapper::default_evaluate)
                , ( bp::arg("k_i"), bp::arg("k_f_bin"), bp::arg("alpha_i"), bp::arg("alpha_f") ) );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ISample::*getCompositeSample_function_type )(  ) const;
            typedef ::ICompositeSample const * ( FormFactorEllipsoid_wrapper::*default_getCompositeSample_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&FormFactorEllipsoid_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IFormFactor::isDistributedFormFactor
        
            typedef bool ( ::IFormFactor::*isDistributedFormFactor_function_type )(  ) const;
            typedef bool ( FormFactorEllipsoid_wrapper::*default_isDistributedFormFactor_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "isDistributedFormFactor"
                , isDistributedFormFactor_function_type(&::IFormFactor::isDistributedFormFactor)
                , default_isDistributedFormFactor_function_type(&FormFactorEllipsoid_wrapper::default_isDistributedFormFactor) );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( FormFactorEllipsoid_wrapper::*default_printParameters_function_type )(  ) const;
            
            FormFactorEllipsoid_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&FormFactorEllipsoid_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            FormFactorEllipsoid_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &FormFactorEllipsoid_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( FormFactorEllipsoid_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            FormFactorEllipsoid_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&FormFactorEllipsoid_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( FormFactorEllipsoid_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            FormFactorEllipsoid_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&FormFactorEllipsoid_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
