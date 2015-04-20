#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bindrawer.h"
#include "packagedrawer.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->maximumSize());
    binScene = new QGraphicsScene(this);
    packageScene = new QGraphicsScene(this);
    ui->graphicsViewBin->setScene(binScene);
    ui->graphicsViewBin->setRenderHint(QPainter::Antialiasing);
    ui->graphicsViewPackage->setScene(packageScene);
    ui->graphicsViewPackage->setRenderHint(QPainter::Antialiasing);
    binScene->setSceneRect(10,10, ui->graphicsViewBin->width() - 20, ui->graphicsViewBin->height() - 20);
    packageScene->setSceneRect(5,5, ui->graphicsViewPackage->width() - 5, ui->graphicsViewPackage->height() - 5);
    BinDrawer *drawer = new BinDrawer(binScene->width()/4, binScene->height()/4);
    PackageDrawer *packageDrawer = new PackageDrawer(0,0,0);
    Bin *bin = new Bin(100, 100, 1);
    drawer->setBin(bin);
    binScene->addItem(drawer);
    packageScene->addItem(packageDrawer);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), binScene, SLOT(update()));
    connect(timer, SIGNAL(timeout()), binScene, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), packageScene, SLOT(update()));
    connect(timer, SIGNAL(timeout()), packageScene, SLOT(advance()));

    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
