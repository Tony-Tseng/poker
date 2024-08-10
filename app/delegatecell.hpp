#pragma once

#include <QApplication>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QTableWidget>
#include <QBrush>
#include <QRect>

#include <iostream>

class DelegateCell : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit DelegateCell(QObject* parent);
    ~DelegateCell();

    void paint( QPainter* painter, const QStyleOptionViewItem& option, 
                const QModelIndex& index ) const;
    void SetRatio(std::vector<float> ratio);

private:
    QTableWidget* tableWidget;
    std::vector<float> ratio = {0.3, 0.7, 0.0};
};