#ifndef CUNITTRANSFORM_H
#define CUNITTRANSFORM_H


class CUnitTransform
{
public:
    CUnitTransform();
    ~CUnitTransform();
    
    static double DollarToYuan(double dbDollar, double dbRate);
    static double YuanToDollar(double dbYuan, double dbRate);
};

#endif // CUNITTRANSFORM_H
