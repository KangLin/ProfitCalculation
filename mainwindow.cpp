#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ProfiltCalculation.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lePurchase_editingFinished()
{
    double dbFee = ui->dbFeeRate->value();
    double dbPurchase = ui->lePurchase->text().toDouble();
    ui->lePurchaseFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbPurchase, dbFee)));
    ProfilteCalculation();
}

void MainWindow::on_leSelling_editingFinished()
{
    double dbFee = ui->dbFeeRate->value();
    double dbSelling = ui->leSelling->text().toDouble();
    ui->leSellingFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbSelling, dbFee)));
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
    double dbProfilt = CProfiltCalculation::ProfiltCalculation(dbSelling, dbPurchase, dbFee);
    qDebug() << "ProfilteCalculation:fee:" << dbFee << ";purchase:" << dbPurchase << ";selling:" << dbSelling << ";profilte:" << dbProfilt;
    ui->leProfilt->setText(QString::number(dbProfilt));
    ui->leProfiltFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbPurchase + dbSelling, dbFee)));
    return 0;
}

void MainWindow::on_leShort_Selling_editingFinished()
{
    double dbFee = ui->dbFeeRate->value();
    double dbSelling = ui->leShort_Selling->text().toDouble();
    ui->leShorts_SellingFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbSelling, dbFee)));
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
    double dbFee = ui->dbFeeRate->value();
    double dbSelling = ui->leShort_Selling->text().toDouble();
    double dbProfilt = ui->leShorts_Profilt->text().toDouble();
    double dbPurchase = CProfiltCalculation::ShortsProfiltCalculation(dbSelling, dbProfilt, dbFee);
    ui->leShorts_Purchase->setText(QString::number(dbPurchase));
    ui->leShorts_ProfiltFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbSelling + dbPurchase, dbFee)));
    return 0;
}

void MainWindow::on_leShorts_Purchase_editingFinished()
{
    double dbFee = ui->dbFeeRate->value();
    double dbPurchase = ui->leShorts_Purchase->text().toDouble();
    ui->leShorts_PurchaseFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbPurchase, dbFee)));
}

void MainWindow::on_leShorts_Purchase_textChanged(const QString &arg1)
{
    double dbFee = ui->dbFeeRate->value();
    double dbPurchase = arg1.toDouble();
    ui->leShorts_PurchaseFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbPurchase, dbFee)));
}

void MainWindow::on_leLong_Purchase_editingFinished()
{
    double dbFee = ui->dbFeeRate->value();
    double dbPurchase = ui->leLong_Purchase->text().toDouble();
    ui->leLong_PurchaseFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbPurchase, dbFee)));
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
    double dbProfilt = ui->leLong_Profilt->text().toDouble();
    double dbSelling = CProfiltCalculation::LongProfilteCalculation(dbPurchase, dbProfilt, dbFee);
    ui->leLong_Selling->setText(QString::number(dbSelling));
    ui->leLong_ProfiltFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbSelling + dbPurchase, dbFee)));
    return 0;
}

void MainWindow::on_leLong_Selling_editingFinished()
{
    double dbFee = ui->dbFeeRate->value();
    double dbSelling = ui->leLong_Selling->text().toDouble();
    ui->leLong_SellingFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbSelling, dbFee)));
}

void MainWindow::on_leLong_Selling_textChanged(const QString &arg1)
{
    double dbFee = ui->dbFeeRate->value();
    double dbSelling = arg1.toDouble();
    ui->leLong_SellingFee->setText(QString::number(CProfiltCalculation::FeeCalculation(dbSelling, dbFee)));
}
