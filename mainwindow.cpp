#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "work.h"
#include "QString"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    Work *workk = new Work();
    QString toSetText;
    using namespace std::chrono;

    int num = ui->textEdit->toPlainText().toInt();

    auto start = std::chrono::high_resolution_clock::now();
        workk->clear();
    auto res1 = workk->recursiveAlg(num);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = stop-start;
    ui->label_7->setText(toSetText.setNum(res1));
    ui->label_4->setText(toSetText.setNum(elapsed.count()));
    workk->clear();
    start = std::chrono::high_resolution_clock::now();
    auto res2 = workk->iterAlg(num);
    stop = std::chrono::high_resolution_clock::now();
    elapsed = stop-start;
    ui->label_8->setText(toSetText.setNum(res2));
    ui->label_6->setText(toSetText.setNum(elapsed.count()));
}

