// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/ImportDataWidgets/ImportDataAssistant.cpp
//! @brief     Implements class ImportDataAssistant
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "ImportDataAssistant.h"
#include "AppSvc.h"
#include "projectmanager.h"
#include "IntensityDataIOFactory.h"
#include <QFileDialog>
#include <QFileInfo>
#include "GUIHelpers.h"
#include <QMessageBox>
#include <QDebug>

namespace {
const QString filter_string = "Intensity File (*.int *.int.gz *.tif *.tif.gz *.txt *.txt.gz);;"
        "Other (*)";
}

OutputData<double> *ImportDataAssistant::importData()
{
    QString dirname = AppSvc::projectManager()->userImportDir();
    QString fileName = QFileDialog::getOpenFileName(0,
            QStringLiteral("Open Intensity File"), dirname, filter_string);

    if(fileName.isEmpty())
        return nullptr;

    QString newImportDir = GUIHelpers::fileDir(fileName);
    if(newImportDir != dirname)
        AppSvc::projectManager()->setImportDir(newImportDir);



    OutputData<double> *result(0);

//    try {
//        result = IntensityDataIOFactory::readOutputData(fileName.toStdString());
//    } catch (std::exception& ex) {
//        QString message(QStringLiteral("Real data can not be loaded\n\n"));
//        message += QString::fromStdString(std::string(ex.what()));
//        QMessageBox::warning(0, "IO Problem", message);
//    }

    qDebug() << "AAA importData  fileName:" << fileName;
    qDebug() << "AAA importData  dirname:" << dirname;
    qDebug() << "AAA importData  newImportDir:" << newImportDir;

    return result;
}


