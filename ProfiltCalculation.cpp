#include "ProfiltCalculation.h"

CProfiltCalculation::CProfiltCalculation()
{
}

CProfiltCalculation::~CProfiltCalculation()
{
    
}

//计算赢利  
double CProfiltCalculation::ProfiltCalculation(double dbSelling, double dbPurchase, double dbFeeRate)
{
    //return dbSelling * (1 - dbFeeRate) - dbPurchase * (1 + dbFeeRate);
    return dbSelling - dbPurchase - dbFeeRate * (dbSelling + dbPurchase);
}

double CProfiltCalculation::FeeCalculation(double dbPrice, double dbFeeRate)
{
    return dbPrice * dbFeeRate;
}

double CProfiltCalculation::ShortsProfiltCalculation(double dbSelling, double dbProfile, double dbFeeRate)
{
    return (dbSelling * (1 - dbFeeRate) - dbProfile) / (1 + dbFeeRate);
}

double CProfiltCalculation::LongProfilteCalculation(double dbPurchase, double dbProfile, double dbFeeRate)
{
    return (dbProfile + dbPurchase * (1 + dbFeeRate)) / (1 - dbFeeRate);
}
