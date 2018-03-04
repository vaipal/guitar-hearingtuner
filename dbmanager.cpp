#include "dbmanager.h"
static const QString dbPath = "chords.db";
dbManager::dbManager()
{
    initDatabase(dbPath);
}

dbManager::~dbManager()
{
    chordsDb.close();
}

void dbManager::initDatabase(const QString& path_)
{
    chordsDb = QSqlDatabase::addDatabase("QSQLITE");
    chordsDb.setDatabaseName(path_);
    if (!chordsDb.open()) {
        qDebug() << "Error: connection with database fail" << path_;
    } else {
        qDebug() << "Database: connection ok";
    }
}

bool dbManager::addChord(const QString&& name_)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO chords (name) VALUES (:name)");
    query.bindValue(":name", name_);
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "addChord error:  "
                 << query.lastError();
    }

    return success;
}

QStringList dbManager::getChords()
{
    QStringList chordList;
    QSqlQuery query("SELECT * FROM chords");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QString chordName = query.value(idName).toString();
        chordList << chordName;
    }
    return chordList;
}

bool dbManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS chords(id INTEGER PRIMARY KEY, name TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'chords': one might already exist.";
        success = false;
    }

    return success;
}

bool dbManager::dropTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("DROP TABLE IF EXISTS chords;");

    if (!query.exec())
    {
        qDebug() << "Couldn't drop the table 'chords' " << query.lastError();
        success = false;
    }

    return success;
}
void dbManager::closeDatabase()
{
    chordsDb.close();
}

