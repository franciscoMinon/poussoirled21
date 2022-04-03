#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void handlePbLed1();
    bool bLed = false;
    void PbLed1Rouge();
    void PbLed1Bleu();
};

#endif // MAINWINDOW_H
