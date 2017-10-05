// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Tools/PyImport.cpp
//! @brief     Implements PyImport namespace
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "PyImport.h"
#include "PyEmbeddedUtils.h"
#include "MultiLayer.h"

std::unique_ptr<MultiLayer> PyImport::createFromPython(const std::string& script,
                                                       const std::string& functionName,
                                                       const std::string& path)
{
    PyEmbeddedUtils::import_bornagain(path);

    PyObject* pCompiledFn = Py_CompileString( script.c_str() , "" , Py_file_input ) ;
    if (!pCompiledFn)
        throw std::runtime_error("Can't compile a function");

    // create a module
    PyObject* pModule = PyImport_ExecCodeModule((char *)"test" , pCompiledFn ) ;
    if (!pModule)
        throw std::runtime_error("Can't exec module");

    // locate the "get_simulation" function (it's an attribute of the module)
    PyObject* pAddFn = PyObject_GetAttrString( pModule , functionName.c_str() ) ;
    if (!pAddFn)
        throw std::runtime_error("Can't locate compiled functione");

    PyObject *instance =  PyObject_CallFunctionObjArgs(pAddFn, NULL);
    if (!instance)
        throw std::runtime_error("Can't call function");

    // clean up
    Py_DecRef( pAddFn ) ;
    Py_DecRef( pModule ) ;
    Py_DecRef( pCompiledFn ) ;

    void *argp1 = 0;
    swig_type_info * pTypeInfo = SWIG_TypeQuery("MultiLayer *");

    const int res = SWIG_ConvertPtr(instance, &argp1,pTypeInfo, 0);
    if (!SWIG_IsOK(res))
        throw std::runtime_error("SWIG failed extract object");

    MultiLayer* multilayer = reinterpret_cast<MultiLayer*>(argp1);
    std::unique_ptr<MultiLayer> result(multilayer->clone());

    return result;
}

std::vector<std::string> PyImport::listOfFunctions(const std::string& script,
                                                   const std::string& path)
{
    PyEmbeddedUtils::import_bornagain(path);

    PyObject* pCompiledFn = Py_CompileString( script.c_str() , "" , Py_file_input ) ;
    if (!pCompiledFn)
        throw std::runtime_error("Can't compile a function");

    // create a module
    PyObject* pModule = PyImport_ExecCodeModule((char *)"test" , pCompiledFn ) ;
    if (!pModule) {
        std::stringstream buf;
        buf << "Can't exec module" << "\n";
        buf << PyEmbeddedUtils::pythonStackTrace() << "\n";
        PyErr_Print(); // to terminal
        throw std::runtime_error(buf.str());
    }

     PyObject *dict = PyModule_GetDict(pModule);
     if (!dict)
         throw std::runtime_error("Can't get dictionary from module");

     std::vector<std::string> result;
     PyObject *key, *value;
     Py_ssize_t pos = 0;
     while (PyDict_Next(dict, &pos, &key, &value)) {
         if(PyCallable_Check(value)) {
            std::string func_name = PyEmbeddedUtils::toString(key);
            if (func_name.find("__") == std::string::npos)
                 result.push_back(func_name);
         }
     }

     Py_DecRef( dict ) ;
     Py_DecRef( pModule ) ;
     Py_DecRef( pCompiledFn ) ;

     return result;
}
