#pragma once 
#include <QMainWindow>
#include <QApplication>
#include <QVBoxLayout>

#include "tokeneditor.hpp"

int test_window(int argc, char *argv[]);

namespace Ui 
{ 
  class MainWindow; 
}

class MainWindow : public QMainWindow
{ 
  Q_OBJECT 

public:
  explicit MainWindow(QWidget *parent=nullptr);
  ~MainWindow();

  void AddItem(int index, const char* text, std::vector<float> ratio);

private: 
  Ui::MainWindow *ui;
  TokenEditor *table;
  QGridLayout *layout;
};