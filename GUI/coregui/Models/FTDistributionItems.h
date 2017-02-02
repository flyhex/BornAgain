// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/FTDistributionItems.h
//! @brief     Defines FTDistribution1DItem's classes
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef FTDISTRIBUTIONITEMS_H
#define FTDISTRIBUTIONITEMS_H

#include "SessionItem.h"
#include "FTDistributions1D.h"
#include "FTDistributions2D.h"

class BA_CORE_API_ FTDistribution1DItem : public SessionItem
{
public:
    static const QString P_OMEGA;
    explicit FTDistribution1DItem(const QString& name);
    virtual std::unique_ptr<IFTDistribution1D> createFTDistribution() const=0;
    virtual ~FTDistribution1DItem(){}
};

class BA_CORE_API_ FTDistribution1DCauchyItem : public FTDistribution1DItem
{
public:
    FTDistribution1DCauchyItem();
    std::unique_ptr<IFTDistribution1D> createFTDistribution() const;
};

class BA_CORE_API_ FTDistribution1DGaussItem : public FTDistribution1DItem
{
public:
    FTDistribution1DGaussItem();
    std::unique_ptr<IFTDistribution1D> createFTDistribution() const;
};

class BA_CORE_API_ FTDistribution1DGateItem : public FTDistribution1DItem
{
public:
    FTDistribution1DGateItem();
    std::unique_ptr<IFTDistribution1D> createFTDistribution() const;
};

class BA_CORE_API_ FTDistribution1DTriangleItem : public FTDistribution1DItem
{
public:
    FTDistribution1DTriangleItem();
    std::unique_ptr<IFTDistribution1D> createFTDistribution() const;
};

class BA_CORE_API_ FTDistribution1DCosineItem : public FTDistribution1DItem
{
public:
    FTDistribution1DCosineItem();
    std::unique_ptr<IFTDistribution1D> createFTDistribution() const;
};

class BA_CORE_API_ FTDistribution1DVoigtItem : public FTDistribution1DItem
{
public:
    static const QString P_ETA;
    FTDistribution1DVoigtItem();
    std::unique_ptr<IFTDistribution1D> createFTDistribution() const;
};

// --------------------------------------------------------------------------------------------- //

class BA_CORE_API_ FTDistribution2DItem : public SessionItem
{
public:
    static const QString P_COHER_LENGTH_X;
    static const QString P_COHER_LENGTH_Y;
    static const QString P_GAMMA;
    static const QString P_DELTA;
    explicit FTDistribution2DItem(const QString& name);
    virtual std::unique_ptr<IFTDistribution2D> createFTDistribution() const=0;
    virtual ~FTDistribution2DItem(){}
protected:
    void add_properties();
};

class BA_CORE_API_ FTDistribution2DCauchyItem : public FTDistribution2DItem
{
public:
    FTDistribution2DCauchyItem();
    std::unique_ptr<IFTDistribution2D> createFTDistribution() const;
};

class BA_CORE_API_ FTDistribution2DGaussItem : public FTDistribution2DItem
{
public:
    FTDistribution2DGaussItem();
    std::unique_ptr<IFTDistribution2D> createFTDistribution() const;
};

class BA_CORE_API_ FTDistribution2DGateItem : public FTDistribution2DItem
{
public:
    FTDistribution2DGateItem();
    std::unique_ptr<IFTDistribution2D> createFTDistribution() const;
};

class BA_CORE_API_ FTDistribution2DConeItem : public FTDistribution2DItem
{
public:
    FTDistribution2DConeItem();
    std::unique_ptr<IFTDistribution2D> createFTDistribution() const;
};

class BA_CORE_API_ FTDistribution2DVoigtItem : public FTDistribution2DItem
{

public:
    static const QString P_ETA;
    FTDistribution2DVoigtItem();
    std::unique_ptr<IFTDistribution2D> createFTDistribution() const;
};

#endif // FTDISTRIBUTIONITEMS_H
