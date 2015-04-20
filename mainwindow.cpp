#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bindrawer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->maximumSize());
    scene = new QGraphicsScene(this);
    ui->graphicsViewBin->setScene(scene);
    ui->graphicsViewBin->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(5,5, ui->graphicsViewBin->width() - 5, ui->graphicsViewBin->height() - 5);
    BinDrawer *drawer = new BinDrawer(scene->width()/4, scene->height()/4);
    Bin *bin = new Bin(100, 100, 1);
    drawer->setBin(bin);
    scene->addItem(drawer);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(update()));
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));

    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
