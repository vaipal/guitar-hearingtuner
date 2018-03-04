#pragma once
#include <QtSql>

class dbManager
{
public:
    dbManager();
    ~dbManager();
    void initDatabase(const QString &path_);
    void closeDatabase();
    QStringList getChords();

private:
    QSqlDatabase chordsDb;

    bool addChord(const QString &&);
    bool createTable();
    bool dropTable();
};

