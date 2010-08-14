/* 
Copyright 2010 Keywan Tonekaboni, Florian Fusco, Stefanie Schirmer, Alexander Lenhardt, Erik Weitnauer <eweitnauer at gmail.com>

This file is part of Soldering Skaters Nokia Push Project.

Soldering Skaters Nokia Push Project is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Soldering Skaters Nokia Push Project is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Soldering Skaters Nokia Push Project. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TRAINWIDGET_H
#define TRAINWIDGET_H

#include <QWidget>
#include <QtGui>
#include "buttons.h"

class RecordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RecordWidget(QWidget *parent = 0);

signals:
    void trickTrained();

public slots:
    void startClicked();

protected slots:
    void checkInput(const QString&);
    void addData(QString);

protected:
    bool trainTrick();
    void showEvent ( QShowEvent * event );
    void extractTrick();

private:
    QGridLayout* capGrid;
    ShinyButton* startBtn;
    QLineEdit* nameEdit;
    QList<QList<int> > recordedData;
    QLabel* statusLabel;
};

class TrainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TrainWidget(QWidget *parent = 0);

signals:
    void backPressed();
    void startCapture();

public slots:
    void updateTrickList();
    void deleteTrick();

private:
    QListWidget* listWidget;
    QGridLayout* gridLayout;
    ShinyButton* buttonAdd;
    ShinyButton* buttonDel;
    ShinyButton* buttonBack;

};

#endif // TRAINWIDGET_H
