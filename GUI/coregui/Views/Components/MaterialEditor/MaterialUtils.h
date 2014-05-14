#ifndef MATERIALUTILS_H
#define MATERIALUTILS_H

#include <QColor>
#include <QString>
#include "MaterialItem.h"
#include "MaterialProperties.h"

class IMaterial;

namespace MaterialUtils
{

QColor suggestMaterialColor(const QString &name);
MaterialProperty getMaterialProperty(MaterialItem *material);

MaterialColorProperty suggestMaterialColorProperty(const QString &name);


IMaterial *createDomainMaterial(const MaterialItem *material);
IMaterial *createDomainMaterial(const QString &name);

}


#endif