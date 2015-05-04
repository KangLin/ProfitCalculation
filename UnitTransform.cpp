#include "UnitTransform.h"

CUnitTransform::CUnitTransform()
{
}

CUnitTransform::~CUnitTransform()
{
}

double CUnitTransform::DollarToYuan(double dbDollar, double dbRate)
{
    double dbUnit = 31.1035; // 1 盎司 = 31.1035 克  
    return dbDollar * dbRate / dbUnit;
}

double CUnitTransform::YuanToDollar(double dbYuan, double dbRate)
{
    double dbUnit = 31.1035; // 1 盎司 = 31.1035 克  
    return (dbYuan / dbRate) * dbUnit;
}
