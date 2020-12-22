#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "DataBase.db"

#define TABLE                       "TableVacansia"
#define TABLE_CITY                  "city"
#define TABLE_BRANCH                "branch"
#define TABLE_POSITION              "position"
#define TABLE_NUMBER                "number"
#define TABLE_EXPERIENSE            "experiense"
#define TABLE_SALARY                "salary"
#define TABLE_HIGH_EDU              "higher_edu"
#define TABLE_PRIM_EDU              "primary_edu"
#define TABLE_INVALIDITY            "invalidity"

class DataBase : public QObject {
    Q_OBJECT

private:
    QSqlDatabase db;

    bool openDataBase();
    bool restoreDataBase();
    bool createTable();

public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();
    void closeDataBase();
    bool inserIntoTable(const QVariantList &data);
};

#endif // DATABASE_H
