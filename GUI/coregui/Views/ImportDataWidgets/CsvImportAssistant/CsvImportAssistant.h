// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/ImportDataWidgets/CsvImportAssistant/CsvImportAssistant.h
//! @brief     Defines class CsvImportAssistant
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_GUI_COREGUI_VIEWS_IMPORTDATAWIDGETS_CSVIMPORTASSISTANT_CSVIMPORTASSISTANT_H
#define BORNAGAIN_GUI_COREGUI_VIEWS_IMPORTDATAWIDGETS_CSVIMPORTASSISTANT_CSVIMPORTASSISTANT_H

#include "Device/InputOutput/DataFormatUtils.h"
#include "GUI/coregui/Views/ImportDataWidgets/CsvImportAssistant/CsvDataColumn.h"
#include "GUI/coregui/Views/ImportDataWidgets/CsvImportAssistant/CsvReader.h"
#include "GUI/coregui/utils/ImportDataInfo.h"
#include <QStringList>
#include <QWidget>
#include <memory>
#include <set>

class csvSelectionState
{
public:
    csvSelectionState()
        : m_intensityColNum(-1)
        , m_intensityMultiplier(1.)
        , m_coordinateColNum(-1)
        , m_coordinateMultiplier(1.)
        , m_firstRow(-1)
        , m_lastRow(-1)
        , m_units(Axes::Units::NBINS)
    {
    }

    int m_intensityColNum;
    double m_intensityMultiplier;
    int m_coordinateColNum;
    double m_coordinateMultiplier;
    int m_firstRow;
    int m_lastRow;
    Axes::Units m_units;

    bool availableData() { return m_intensityColNum > -1; }
};

//! Logic for importing intensity data from csv files
class CsvImportAssistant : public QObject
{
    Q_OBJECT
public:
    CsvImportAssistant(const QString& file, const bool useGUI = false, QWidget* parent = nullptr);
    ImportDataInfo getData() { return m_dataAvailable ? fillData() : ImportDataInfo(); }
    static void showErrorMessage(std::string message);
    void setIntensityColumn(int iCol, double multiplier = 1.0);
    void setCoordinateColumn(int iCol, Axes::Units units, double multiplier = 1.0);
    void setFirstRow(int iRow);
    void setLastRow(int iRow);
    size_t columnCount() { return m_csvArray[0].size(); }
    char separator() { return m_separator; }

private:
    bool loadCsvFile();
    ImportDataInfo fillData();
    bool hasEqualLengthLines(csv::DataArray& dataArray);
    char guessSeparator() const;
    void removeBlankColumns();
    void removeMultipleWhiteSpaces();
    void runDataSelector(QWidget* parent);
    void getValuesFromColumns(std::vector<double>& intensityVals, std::vector<double>& coordVals);
    void resetSelection();
    void resetAssistant();

    QString m_fileName;
    std::unique_ptr<CSVFile> m_csvFile;
    csv::DataArray m_csvArray;
    char m_separator;
    int m_intensityColNum;
    double m_intensityMultiplier;
    int m_coordinateColNum;
    double m_coordinateMultiplier;
    int m_firstRow;
    int m_lastRow;
    std::set<int> m_rowsToDiscard;
    Axes::Units m_units;
    bool m_dataAvailable;
};
#endif // BORNAGAIN_GUI_COREGUI_VIEWS_IMPORTDATAWIDGETS_CSVIMPORTASSISTANT_CSVIMPORTASSISTANT_H
