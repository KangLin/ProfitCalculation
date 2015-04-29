#ifndef CPROFILTCALCULATION_H
#define CPROFILTCALCULATION_H

class CProfiltCalculation
{
public:
    CProfiltCalculation();
    ~CProfiltCalculation();

    //计算赢利
    static double ProfiltCalculation(double dbSelling, double dbPurchase, double dbFeeRate);
    //计算最低赢利价
    static double MinProfilePrice(double dbPurchase, double dbFeeRate);
    //计算手续费
    static double FeeCalculation(double dbPrice, double dbFeeRate);
    //空头赢利价
    static double ShortsProfiltCalculation(double dbSelling, double dbProfile, double dbFeeRate);
    //多头赢利价
    static double LongProfilteCalculation(double dbPurchase, double dbProfile, double dbFeeRate);

};

#endif // CPROFILTCALCULATION_H
