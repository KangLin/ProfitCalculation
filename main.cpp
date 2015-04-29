#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    QString szLocale = QLocale::system().name();
    QString szTranslationFile = ":/translatioins/app_" + szLocale + ".qm";
    //本地化程序资源 
    QTranslator myappTranslator;
    //把翻译文件放在了程序资源中 
    myappTranslator.load(szTranslationFile);
    a.installTranslator(&myappTranslator);

    MainWindow w;
    w.show();
    
    return a.exec();
}
