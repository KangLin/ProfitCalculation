#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ProfiltCalculation.h"
#include "UnitTransform.h"

#include <QSettings>
#include <QStandardPaths>
#include <QDir>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSettings set(getConfigureFile(), QSettings::IniFormat);
    double value = set.value("Count", 1).toDouble();
    ui->dbCount->setValue(value);
    value = set.value("FeeRate", 0.0008).toDouble();
    ui->dbFeeRate->setValue(value);
    value = set.value("MarginRate", 0.11).toDouble();
    ui->dbMarginRate->setValue(value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lePurchase_editingFinished()
{
    double dbFeeRate = ui->dbFeeRate->value();
    double dbPurchase = ui->lePurchase->text().toDouble();
    double dbCount = ui->dbCount->text().toDouble();
    double dbPurchaseFee = CProfiltCalculation::FeeCalculation(dbPurchase, dbFeeRate) * dbCount;
    ui->lePurchaseFee->setText(QString::number(dbPurchaseFee));
    double dbMarginRate = ui->dbMarginRate->value();
    double dbMargin = dbMarginRate * dbPurchase * dbCount;
    ui->lePurchasMargin->setText(QString::number(dbMargin));
    ProfilteCalculation();
}

void MainWindow::on_leSelling_editingFinished()
{
    double dbFeeRate = ui->dbFeeRate->value();
    double dbSelling = ui->leSelling->text().toDouble();
    double dbCount = ui->dbCount->text().toDouble();
    double dbSellingFee = CProfiltCalculation::FeeCalculation(dbSelling, dbFeeRate) * dbCount;
    ui->leSellingFee->setText(QString::number(dbSellingFee));

    double dbMarginRate = ui->dbMarginRate->value();
    double dbMargin = dbMarginRate * dbSelling * dbCount;
    ui->leSellingMargin->setText(QString::number(dbMargin));

    ProfilteCalculation();
}

int MainWindow::ProfilteCalculation()
{
    if(ui->lePurchase->text().isEmpty() || ui->leSelling->text().isEmpty())
    {
        ui->leProfilt->clear();
        ui->leProfiltFee->clear();
        return -1;
    }

    double dbFee = ui->dbFeeRate->value();
    double dbPurchase = ui->lePurchase->text().toDouble();
    double dbSelling = ui->leSelling->text().toDouble();
    double dbCount = ui->dbCount->text().toDouble();
    double dbProfilt = CProfiltCalculation::ProfiltCalculation(dbSelling, dbPurchase, dbFee) * dbCount;

    ui->leProfilt->setText(QString::number(dbProfilt));
    double dbProfiltFee = CProfiltCalculation::FeeCalculation(dbPurchase + dbSelling, dbFee) * dbCount;
    ui->leProfiltFee->setText(QString::number(dbProfiltFee));
    return 0;
}

void MainWindow::on_leShort_Selling_editingFinished()
{
    double dbFeeRate = ui->dbFeeRate->value();
    double dbSelling = ui->leShort_Selling->text().toDouble();
    double dbCount = ui->dbCount->text().toDouble();
    double dbSellingFee = CProfiltCalculation::FeeCalculation(dbSelling, dbFeeRate) * dbCount;
    ui->leShorts_SellingFee->setText(QString::number(dbSellingFee));

    double dbMarginRate = ui->dbMarginRate->value();
    double dbMargin = dbMarginRate * dbSelling * dbCount;
    ui->leShorts_SellingMargin->setText(QString::number(dbMargin));

    ShortProfilteCalculation();
}

void MainWindow::on_leShorts_Profilt_editingFinished()
{
    ShortProfilteCalculation();
}

int MainWindow::ShortProfilteCalculation()
{
    if(ui->leShort_Selling->text().isEmpty() || ui->leShorts_Profilt->text().isEmpty())
    {
        ui->leShorts_ProfiltFee->clear();
        ui->leShorts_Purchase->clear();
        return -1;
    }

    double dbFeeRate = ui->dbFeeRate->value();
    double dbSelling = ui->leShort_Selling->text().toDouble();
    double dbCount = ui->dbCount->text().toDouble();
    double dbProfilt = ui->leShorts_Profilt->text().toDouble() / dbCount; //每手获得  
    double dbPurchase = CProfiltCalculation::ShortsProfiltCalculation(dbSelling, dbProfilt, dbFeeRate);
    ui->leShorts_Purchase->setText(QString::number(dbPurchase));

    double dbMarginRate = ui->dbMarginRate->value();
    double dbMargin = dbMarginRate * dbPurchase * dbCount;
    ui->leShorts_PurchaseMargin->setText(QString::number(dbMargin));
    
    double dbPurchaseFee = CProfiltCalculation::FeeCalculation(dbPurchase, dbFeeRate) * dbCount;
    ui->leShorts_PurchaseFee->setText(QString::number(dbPurchaseFee));

    double dbProfiltFee = CProfiltCalculation::FeeCalculation(dbSelling + dbPurchase, dbFeeRate) * dbCount;
    ui->leShorts_ProfiltFee->setText(QString::number(dbProfiltFee));

    return 0;
}

void MainWindow::on_leLong_Purchase_editingFinished()
{
    double dbFee = ui->dbFeeRate->value();
    double dbPurchase = ui->leLong_Purchase->text().toDouble();
    double dbCount = ui->dbCount->text().toDouble();
    double dbPurchaseFee = CProfiltCalculation::FeeCalculation(dbPurchase, dbFee) * dbCount;
    ui->leLong_PurchaseFee->setText(QString::number(dbPurchaseFee));

    double dbMarginRate = ui->dbMarginRate->value();
    double dbMargin = dbMarginRate * dbPurchase * dbCount;
    ui->leLong_PurchaseMargin->setText(QString::number(dbMargin));

    LongProfilteCalculation();
}

void MainWindow::on_leLong_Profilt_editingFinished()
{
    LongProfilteCalculation();
}

int MainWindow::LongProfilteCalculation()
{
    if(ui->leLong_Purchase->text().isEmpty() || ui->leLong_Profilt->text().isEmpty())
    {
        ui->leLong_ProfiltFee->clear();
        ui->leLong_Selling->clear();
        return -1;
    }

    double dbFee = ui->dbFeeRate->value();
    double dbPurchase = ui->leLong_Purchase->text().toDouble();
    double dbCount = ui->dbCount->text().toDouble();
    double dbProfilt = ui->leLong_Profilt->text().toDouble() / dbCount; //每手获得  
    double dbSelling = CProfiltCalculation::LongProfilteCalculation(dbPurchase, dbProfilt, dbFee);
    ui->leLong_Selling->setText(QString::number(dbSelling));

    double dbMarginRate = ui->dbMarginRate->value();
    double dbMargin = dbMarginRate * dbSelling * dbCount;
    ui->leLong_SellingMargin->setText(QString::number(dbMargin));

    double dbSellingFee = CProfiltCalculation::FeeCalculation(dbSelling, dbFee) * dbCount;
    ui->leLong_SellingFee->setText(QString::number(dbSellingFee));
    
    double dbProfiltFee = CProfiltCalculation::FeeCalculation(dbSelling + dbPurchase, dbFee) * dbCount;
    ui->leLong_ProfiltFee->setText(QString::number(dbProfiltFee));

    return 0;
}

void MainWindow::on_dbCount_valueChanged(double value)
{
    QSettings set(getConfigureFile(), QSettings::IniFormat);
    set.setValue("Count", value);
    RecalculationAll();
}

void MainWindow::on_dbFeeRate_valueChanged(double value)
{
    QSettings set(getConfigureFile(), QSettings::IniFormat);
    set.setValue("FeeRate", value);
    RecalculationAll();
}

void MainWindow::on_dbMarginRate_valueChanged(double value)
{
    QSettings set(getConfigureFile(), QSettings::IniFormat);
    set.setValue("MarginRate", value);
    RecalculationAll();
}

void MainWindow::on_leInputDollar_editingFinished()
{
    double dbRate = ui->dbExchangRate->value();
    double dbDollar = ui->leInputDollar->text().toDouble();
    double outputYuan = CUnitTransform::DollarToYuan(dbDollar, dbRate);
    ui->leOutputYuan->setText(QString::number(outputYuan));
}

void MainWindow::on_leInputYuan_editingFinished()
{
    double dbRate = ui->dbExchangRate->value();
    double dbYuan = ui->leInputYuan->text().toDouble();
    double outputDollar = CUnitTransform::YuanToDollar(dbYuan, dbRate);
    ui->leOutputDollar->setText(QString::number(outputDollar));
}

int MainWindow::RecalculationAll()
{
    on_lePurchase_editingFinished();
    on_leSelling_editingFinished();
    on_leShort_Selling_editingFinished();
    on_leShorts_Profilt_editingFinished();
    on_leLong_Purchase_editingFinished();
    on_leLong_Profilt_editingFinished();
    return 0;
}

QString MainWindow::getConfigureFile()
{
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
            + QDir::separator()
            + "Rabbit"
            + QDir::separator()
            + QApplication::applicationName()
            + QDir::separator()
            + QApplication::applicationName()
            + ".conf";
}
