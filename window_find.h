#ifndef WINDOW_FIND_H
#define WINDOW_FIND_H

#include <QDialog>
#include <QSqlQueryModel>

#include "database.h"

namespace Ui { class WindowFind; }

class WindowFind : public QDialog {
    Q_OBJECT

public:
    explicit WindowFind(QWidget *parent = nullptr);
    ~WindowFind();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WindowFind      *ui;
    DataBase            *db;
    QSqlQueryModel      *query_model;
};

#endif // WINDOW_FIND_H
