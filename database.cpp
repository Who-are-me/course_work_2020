#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent) {}

DataBase::~DataBase() { this->closeDataBase();}

void DataBase::connectToDataBase() {
    if (!QFile(DATABASE_NAME).exists() ) {
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool DataBase::restoreDataBase() {
    if (this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Error: is not create database";
        return false;
    }

    return false;
}

bool DataBase::openDataBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);

    if (db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase() {
    db.close();
}

bool DataBase::createTable() {
    QSqlQuery query;
    if (!query.exec( "CREATE TABLE " TABLE " ( id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            TABLE_CITY              " TEXT              NOT NULL, "
                            TABLE_BRANCH            " TEXT              NOT NULL, "
                            TABLE_POSITION          " TEXT              NOT NULL, "
                            TABLE_NUMBER            " TEXT              NOT NULL, "
                            TABLE_EXPERIENSE        " INT               NOT NULL, "
                            TABLE_SALARY            " INT               NOT NULL, "
                            TABLE_HIGH_EDU          " TEXT              NOT NULL, "
                            TABLE_PRIM_EDU          " TEXT              NOT NULL, "
                            TABLE_INVALIDITY        " TEXT              NOT NULL ) "
    )) {
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }

    return false;
}

bool DataBase::inserIntoTable(const QVariantList &data) {

    QSqlQuery query;

    query.prepare(" INSERT INTO " TABLE " ( " TABLE_CITY " , "
                                             TABLE_BRANCH " , "
                                             TABLE_POSITION " , "
                                             TABLE_NUMBER " , "
                                             TABLE_EXPERIENSE " , "
                                             TABLE_SALARY " , "
                                             TABLE_HIGH_EDU " , "
                                             TABLE_PRIM_EDU " , "
                                             TABLE_INVALIDITY " ) "
    " VALUES ( :city, :branch, :position, :number, :experiense, :salary, :high_edu, :primery_edu, :invalidity ) " );

    query.bindValue(":city",                data[0] );
    query.bindValue(":branch",              data[1] );
    query.bindValue(":position",            data[2] );
    query.bindValue(":number",              data[3] );
    query.bindValue(":experiense",          data[4].toInt() );
    query.bindValue(":salary",              data[5].toInt() );
    query.bindValue(":high_edu",            data[6] );
    query.bindValue(":primery_edu",         data[7] );
    query.bindValue(":invalidity",          data[8] );


    if (!query.exec()) {
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }

    return false;
}
