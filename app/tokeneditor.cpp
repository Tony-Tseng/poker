#include "tokeneditor.hpp"

TokenEditor::TokenEditor(QWidget *parent) :
    QWidget(parent),
    ui_userTokens(new QTableWidget)
{
    auto layout = new QVBoxLayout(this);
    layout->addWidget(ui_userTokens);

    ui_userTokens->setRowCount(13);
    ui_userTokens->setColumnCount(13);
    ui_userTokens->setHorizontalHeaderLabels({"A","K","Q","J","T","9","8","7","6","5","4","3","2"});
    ui_userTokens->setVerticalHeaderLabels({"A","K","Q","J","T","9","8","7","6","5","4","3","2"});
    
    QHeaderView *verticalHeader = ui_userTokens->verticalHeader();
    verticalHeader->setDefaultSectionSize(45);

    QHeaderView *horizontalHeader = ui_userTokens->horizontalHeader();
    horizontalHeader->setDefaultSectionSize(50);
}

TokenEditor::~TokenEditor()
{
}

void TokenEditor::addItem(int index, const char* text, std::vector<float> ratio)
{
    int r = index / 13;
    int c = index % 13;
    
    auto *it = new QTableWidgetItem(text);
    DelegateCell *delegate = new DelegateCell(this);
    delegate->SetRatio(ratio);

    ui_userTokens->setItem(r, c, it);
    ui_userTokens->setItemDelegateForColumn(0, delegate);

    ui_userTokens->setItemDelegateForRow(0, delegate);
}

int test_table(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TokenEditor T;
    T.show(); 
    return a.exec();
}