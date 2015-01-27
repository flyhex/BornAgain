// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/MagneticFieldItem.h
//! @brief     Defines class MagneticFieldItem
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef MAGNETICFIELDITEM_H
#define MAGNETICFIELDITEM_H


#include "ParameterizedItem.h"

class BA_CORE_API_ MagneticFieldItem : public ParameterizedItem
{
    Q_OBJECT
public:
    static const QString P_BX;
    static const QString P_BY;
    static const QString P_BZ;
    explicit MagneticFieldItem(ParameterizedItem *parent=0);
    ~MagneticFieldItem(){}
    QString getItemLabel() const;
};



#endif

