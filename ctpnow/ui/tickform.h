#ifndef TICKFORM_H
#define TICKFORM_H

#include <QMap>
#include <QTimer>
#include <QWidget>

namespace Ui {
class TickForm;
}

class TickForm : public QWidget {
    Q_OBJECT

public:
    explicit TickForm(QWidget* parent = 0);
    ~TickForm();
    void init();
    void shutdown();

private slots:
    void onGotInstruments(QStringList ids);
    void onGotTick(void* curTick, void* preTick);
    void onTradeWillBegin();
    void onUpdateTick();

    void on_pushButtonSendOrder_clicked();
    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::TickForm* ui;
    QTimer* updateTickTimer_ = nullptr;

    QMap<QString, int> table_row_;
    QStringList table_col_;
};

#endif // TICKFORM_H
