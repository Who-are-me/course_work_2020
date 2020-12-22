#include "window_expose.h"
#include "ui_window_expose.h"

WindowExpose::WindowExpose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowExpose)
{
    ui->setupUi(this);

    db = new DataBase;
    db->connectToDataBase();

    QPalette palette;
    palette.setColor(QPalette::Base, Qt::yellow);
    palette.setColor(QPalette::Text, Qt::black);

    ui->lineEdit_1->setPalette(palette);
    ui->lineEdit_2->setPalette(palette);
    ui->lineEdit_3->setPalette(palette);
    ui->lineEdit_4->setPalette(palette);
    ui->lineEdit_5->setPalette(palette);
    ui->lineEdit_6->setPalette(palette);
    ui->lineEdit_7->setPalette(palette);
    ui->lineEdit_8->setPalette(palette);
    ui->lineEdit_9->setPalette(palette);

    QPixmap pix(":/img/img/work.jpeg");
    int w = ui->label->width();
    int h = ui->label->height();

    ui->label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

WindowExpose::~WindowExpose() {
    delete ui;
    db->closeDataBase();
}

bool WindowExpose::if_error() {
    if (ui->lineEdit_9->text() == "" ) {
        QMessageBox::critical(this, "Error", "Error input data in lineEdit invalidity!");
        return false;
    }
    else if (ui->lineEdit_8->text() == ""  ) {
        QMessageBox::critical(this, "Error", "Error input data in lineEdit primery education!");
        return false;
    }
    else if (ui->lineEdit_7->text() == "" ) {
        QMessageBox::critical(this, "Error", "Error input data in lineEdit higher education!");
        return false;
    }
    else if (ui->lineEdit_6->text() == "" ) {
        QMessageBox::critical(this, "Error", "Error input data in lineEdit salary!");
        return false;
    }
    else if (ui->lineEdit_5->text() == "" ) {
        QMessageBox::critical(this, "Error", "Error input data in lineEdit experiense!");
        return false;
    }
    else if (ui->lineEdit_4->text() == "" ) {
        QMessageBox::critical(this, "Error", "Error input data in lineEdit number!");
        return false;
    }
    else if (ui->lineEdit_3->text() == "" ) {
        QMessageBox::critical(this, "Error", "Error input data in lineEdit position!");
        return false;
    }
    else if (ui->lineEdit_2->text() == "" ) {
        QMessageBox::critical(this, "Error", "Error input data in lineEdit branch!");
        return false;
    }
    else if (ui->lineEdit_1->text() == "" ) {
        QMessageBox::critical(this, "Error", "Error input data in lineEdit city!");
        return false;
    }
    else {
        return true;
    }
}

void WindowExpose::on_pushButton_clicked() {
    if (if_error()) {
        QVariantList data;

        data.append(ui->lineEdit_1->text());
        data.append(ui->lineEdit_2->text());
        data.append(ui->lineEdit_3->text());
        data.append(ui->lineEdit_4->text());
        data.append(ui->lineEdit_5->text());
        data.append(ui->lineEdit_6->text());
        data.append(ui->lineEdit_7->text());
        data.append(ui->lineEdit_8->text());
        data.append(ui->lineEdit_9->text());

        db->inserIntoTable(data);
        QMessageBox::information(this, "Information",
                                 "Ваканція додана!");
    }
    else {
        qDebug() << "Error insert database " << TABLE;
    }
}



























