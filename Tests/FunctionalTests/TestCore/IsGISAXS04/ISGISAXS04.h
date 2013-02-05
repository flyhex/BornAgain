#ifndef FUNCTIONALTESTS_ISGISAXS04_H
#define FUNCTIONALTESTS_ISGISAXS04_H

#include <string>
#include "OutputData.h"

class MultiLayer;
class GISASExperiment;


namespace FunctionalTests {

class IsGISAXS04
{
public:
    IsGISAXS04();
    ~IsGISAXS04() { delete m_result; }
    void run();
    int analyseResults();
    const OutputData<double> *getOutputData() { return m_result;}
private:
    std::string m_name;
    std::string m_description;
    OutputData<double> *m_result;

   /* struct CompareStruct
    {
        CompareStruct(std::string _isginame, std::string _thisname, std::string _descr) : isginame(_isginame), thisname(_thisname), descr(_descr){}
        std::string isginame;
        std::string thisname;
        std::string descr;
    };*/
};


}


#endif
