// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/PyCore/persistence/PyPersistenceTest.h
//! @brief     Defines class PyPersistenceTest
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PYPERSISTENCETEST_H
#define PYPERSISTENCETEST_H

#include "IReferencedTest.h"
#include "OutputData.h"
#include <map>
#include <string>

namespace YAML {
    class Node;
}

//! @class PyPersistenceTest
//! @ingroup standard_samples
//! @brief A functional test that runs a Python script and compares its output with a reference.
//!   Invoked from RunPyPersistenceTest.

class PyPersistenceTest : public IReferencedTest
{
public:
    PyPersistenceTest(const std::string& directory, const std::string& name);
    ~PyPersistenceTest() final {}

    bool runTest() final;

private:
    std::string m_directory;

    static std::map<const std::string, const std::string>
        glob2map(const std::string& dir, const std::string& stem);

    bool compareFileMaps(
        const std::map<const std::string, const std::string>& dat,
        const std::map<const std::string, const std::string>& ref);
    static bool compareFilePair(
        const std::string& dat_fname, const std::string& ref_fname);
    static bool compareIntensityPair(
        const std::string& dat_fname, const std::string& ref_fname);
    static bool compareYamlPair(
        const std::string& dat_fname, const std::string& ref_fname);
    static bool compareYamlNode(
        const YAML::Node& dat, const YAML::Node& ref);
};

#endif // PYPERSISTENCETEST_H