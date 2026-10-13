#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->tempDial, SIGNAL (valueChanged(int)), ui->setTempLCD, SLOT (display(int)));
    connect(ui->tempIncreaseButton, SIGNAL (pressed()), this, SLOT (slotSetTempIncreasePressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slotSetTempIncreasePressed()
{
    int currTempDisplayed = ui->setTempLCD->intValue();
    // Increment setTempLCD
    ui->setTempLCD->display(currTempDisplayed+1);
    // Update tempDial
    ui->tempDial->setValue(currTempDisplayed+1);
    // TODO: Update OperatingParamters
}

void MainWindow::slotSetTempDecreasePressed()
{
    int currTempDisplayed = ui->setTempLCD->intValue();
    // Increment setTempLCD
    ui->setTempLCD->display(currTempDisplayed-1);
    // Update tempDial
    ui->tempDial->setValue(currTempDisplayed-1);
    // TODO: Update OperatingParamters
}

// class NumericButton extends QPushButton
//     private void addToNumber(int value):
//         // ...

//     reimplement base.keyPressEvent(QKeyEvent event):
//         if(event.key == up)
//             this.addToNumber(1)
//         else if(event.key == down)
//             this.addToNumber(-1)
//         else
//             base.keyPressEvent(event)

