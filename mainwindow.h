#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

#include "window_find.h"
#include "window_expose.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow  *ui;   
    WindowFind      *window_find;
    WindowExpose    *window_expose;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_find_button_clicked();
    void on_expose_button_clicked();
};

#endif // MAINWINDOW_H
