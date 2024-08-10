#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

  QWidget *centralWidget = new QWidget(this);   
  layout = new QGridLayout();
  centralWidget->setLayout(layout);

  table = new TokenEditor();
  table->setMinimumHeight(650);
  table->setMinimumWidth(700);

  layout->addWidget(table);
  setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
	delete ui;
  delete table;
  delete layout;
}

void MainWindow::AddItem(int index, const char* text, std::vector<float> ratio)
{
    table->addItem(index, text, ratio);
}

int test_window(int argc, char *argv[])
{ 
  QApplication a(argc, argv);
  MainWindow w;

  w.show(); 
  return a.exec();
}