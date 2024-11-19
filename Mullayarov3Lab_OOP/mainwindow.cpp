#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mywidget.h"
#include "Group.h"
#include "dialog.h"

#include <QFileDialog>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    ui->scrollArea->setWidgetResizable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_actionSave_triggered()
{
    if(fileName.isEmpty())
        on_actionSaveAs_triggered();
    else
        save();
}

void MainWindow::on_actionOpen_triggered()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath(), tr("Текстовый файл (*.txt)"));
    if (!fileName.isEmpty()){
        ui->myWidget->load(fileName);

    }
}

void MainWindow::on_actionNew_triggered()
{
    ui->myWidget->clean();
    fileName = "";
}


void MainWindow::on_actionSaveAs_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Открыть"), QDir::currentPath(), tr("Текстовый файл (*.txt)"));
    if (!fileName.isEmpty())
        save();
}

void MainWindow::save()
{
    ui->myWidget->save(fileName);
}
//errrrorrrrrrrrr

void MainWindow::on_actionMain_dialog_triggered()
{
    auto dialog = new Dialog(this);
    dialog->setWidget(ui->myWidget);
    dialog->FillBox(0);
    int result = dialog->exec();
    // try {
    //     delete dialog;
    //     dialog = nullptr;
    // } catch (const std::exception& e) {
    //     std::cerr << "Error deleting dialog: " << e.what() << std::endl;
    // }
}
