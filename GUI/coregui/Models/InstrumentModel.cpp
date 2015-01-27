// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/InstrumentModel.cpp
//! @brief     Implements class InstrumentModel
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "InstrumentModel.h"
#include "InstrumentItem.h"

InstrumentModel::InstrumentModel(QObject *parent)
    : SessionModel(SessionXML::InstrumentModelTag, parent)
{

}


InstrumentModel *InstrumentModel::createCopy(ParameterizedItem *parent)
{
    InstrumentModel *result = new InstrumentModel();
    result->initFrom(this, parent);
    return result;
}


//! returns list of Instruments defined in the model
QMap<QString, ParameterizedItem *> InstrumentModel::getInstrumentMap() const
{
    QMap<QString, ParameterizedItem *> result;
    QModelIndex parentIndex;
    for( int i_row = 0; i_row < rowCount( parentIndex); ++i_row) {
         QModelIndex itemIndex = index( i_row, 0, parentIndex );

         if (ParameterizedItem *item = itemForIndex(itemIndex)){
             if(item->modelType() == Constants::InstrumentType) {
                 result[item->itemName()] = item;
             }
         }
    }
    return result;
}


InstrumentItem *InstrumentModel::getInstrumentItem()
{
    InstrumentItem *result(0);

    QMap<QString, ParameterizedItem *> instrumentMap = getInstrumentMap();
    if(instrumentMap.size()) {
        result = dynamic_cast<InstrumentItem *>(instrumentMap.values().at(0));
    }
    return result;
}

