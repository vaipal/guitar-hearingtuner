#include "mainview.h"
#include "ui_mainview.h"
#include "Model/chords.h"
#include <QtDebug>
#include <QStringListModel>
#include <iostream>
MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    Chords chords;
    ui->setupUi(this);
    chordModel = new QStringListModel(chords.getChordList());
    populateAvailBox();
}

MainView::~MainView()
{
    delete ui;
}

void MainView::populateAvailBox()
{
    ui->chordsAvailList->setModel(chordModel);
}
