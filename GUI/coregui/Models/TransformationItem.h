// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/TransformationItem.h
//! @brief     Defines class TransformationItem
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef TRANSFORMATIONITEM_H
#define TRANSFORMATIONITEM_H

#include "ParameterizedGraphicsItem.h"
#include <QVector>

class TransformationItem : public ParameterizedGraphicsItem
{
    Q_OBJECT
public:
    static const QString P_POS, P_ROT;
    explicit TransformationItem(ParameterizedItem *parent=0);
    ~TransformationItem(){}
};


#endif // TRANSFORMATIONITEM_H

