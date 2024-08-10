#include "delegatecell.hpp"

DelegateCell::DelegateCell(QObject* parent) : 
    QStyledItemDelegate(parent),
    tableWidget(qobject_cast<QTableWidget*>(parent)){};

DelegateCell::~DelegateCell(){};

void DelegateCell::paint( QPainter* painter, const QStyleOptionViewItem& option, 
                          const QModelIndex& index) const
{
  painter->save();
  QBrush brush[3] = {Qt::green, Qt::red, Qt::blue};
  float accum = 0.0f;

  QStyleOptionViewItem opt = option;
  initStyleOption(&opt, index);

  for(int i=0;i<3;i++)
  {
    QRect rect = QRect(opt.rect.left() + opt.rect.width() * accum, opt.rect.top(),
                  opt.rect.width() * ratio[i], opt.rect.height());
    painter->fillRect(rect, brush[i]);
    accum += ratio[i];
  }

  opt.backgroundBrush = QBrush(Qt::NoBrush);
  QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &opt, painter);
  // QStyledItemDelegate::paint(painter, opt, index);
  painter->restore();

  // int progress = ratio[0];

  // QStyleOptionProgressBar progressBarOption;
  // progressBarOption.rect = option.rect;
  // progressBarOption.minimum = 0;
  // progressBarOption.maximum = 100;
  // progressBarOption.progress = progress;
  // progressBarOption.text = QString::number(progress) + "%";
  // progressBarOption.textVisible = true;

  // QApplication::style()->drawControl(QStyle::CE_ProgressBar,
  //                                     &progressBarOption, painter);
}

void DelegateCell::SetRatio(std::vector<float> ratio)
{
  this->ratio = ratio;
}