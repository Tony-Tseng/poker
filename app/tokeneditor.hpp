#pragma once

#include <iostream>

#include <QWidget>
#include <QJsonArray>
#include <QString>
#include <QTableWidget>
#include <QVBoxLayout>

#include <QApplication>
#include <QHeaderView>

#include "delegatecell.hpp"

class QTableWidget;

class TokenEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TokenEditor(QWidget *parent = nullptr);
    ~TokenEditor();

    void addItem(int index, const char* text, std::vector<float> ratio);

private:
    QTableWidget *ui_userTokens;
};

int test_table(int argc, char *argv[]);