#ifndef WINDOW_EXPOSE_H
#define WINDOW_EXPOSE_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"

namespace Ui { class WindowExpose; }

class WindowExpose : public QDialog {
    Q_OBJECT

public:
    explicit WindowExpose(QWidget *parent = nullptr);   
    ~WindowExpose();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WindowExpose    *ui;
    DataBase            *db;

    bool if_error();
};

#endif // WINDOW_EXPOSE_H
