#include "window_find.h"
#include "ui_window_find.h"

WindowFind::WindowFind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowFind)
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
}

WindowFind::~WindowFind() {
    delete ui;
    db->closeDataBase();
}

void WindowFind::on_pushButton_clicked() {
    query_model = new QSqlQueryModel;

    QString where = " WHERE ";

    if (ui->lineEdit_1->text() != "") {
        where = where + TABLE_CITY " = '" + ui->lineEdit_1->text() + "' AND ";
    }
    if (ui->lineEdit_2->text() != "") {
        where = where + TABLE_BRANCH " LIKE '%" + ui->lineEdit_2->text() + "%' AND ";
    }
    if (ui->lineEdit_3->text() != "") {
        where = where + TABLE_POSITION " LIKE '%" + ui->lineEdit_3->text() + "%' AND ";
    }
    if (ui->lineEdit_4->text() != "") {
        where = where + TABLE_NUMBER " = '" + ui->lineEdit_4->text() + "' AND ";
    }
    if (ui->lineEdit_5->text() != "") {
        where = where + TABLE_EXPERIENSE " <= " + ui->lineEdit_5->text() + " AND ";
    }
    if (ui->lineEdit_6->text() != "") {
        where = where + TABLE_SALARY " >= " + ui->lineEdit_6->text() + " AND ";
    }
    if (ui->lineEdit_7->text() != "") {
        where = where + TABLE_HIGH_EDU " = '" + ui->lineEdit_7->text() + "' AND ";
    }
    if (ui->lineEdit_8->text() != "") {
        where = where + TABLE_PRIM_EDU " = '" + ui->lineEdit_8->text() + "' AND ";
    }
    if (ui->lineEdit_9->text() != "") {
        where = where + TABLE_INVALIDITY " = '" + ui->lineEdit_9->text() + "' AND ";
    }

    where = where + " id > 0 ";

    query_model->setQuery("SELECT * FROM " TABLE + where );

    query_model->setHeaderData(0,Qt::Horizontal,  tr("id"));
    query_model->setHeaderData(1,Qt::Horizontal,  tr("City"));
    query_model->setHeaderData(2,Qt::Horizontal,  tr("Branch"));
    query_model->setHeaderData(3,Qt::Horizontal,  tr("Position"));
    query_model->setHeaderData(4,Qt::Horizontal,  tr("Phone number"));
    query_model->setHeaderData(5,Qt::Horizontal,  tr("Experiense"));
    query_model->setHeaderData(6,Qt::Horizontal,  tr("Salary"));
    query_model->setHeaderData(7,Qt::Horizontal,  tr("Higher education"));
    query_model->setHeaderData(8,Qt::Horizontal,  tr("Primery education"));
    query_model->setHeaderData(9,Qt::Horizontal,  tr("Invalidity"));

    ui->tableView->setModel(query_model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}
