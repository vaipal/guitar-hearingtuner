#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QStringListModel>

namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private:
    Ui::MainView *ui;
    QStringListModel* chordModel = nullptr;
    void populateAvailBox();
};

#endif // MAINVIEW_H
