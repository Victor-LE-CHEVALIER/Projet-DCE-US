#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QRadioButton>
#include <QTabWidget>
#include <QDialog>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
class QFileInfo;
class QTabWidget;
QT_END_NAMESPACE


class AccTab : public QWidget
{
    Q_OBJECT

public:
    explicit AccTab(const QFileInfo &fileInfo, QWidget *parent = nullptr);

private:
    //layout 1
    QPushButton *m_charger_fichier;
    QPushButton *m_play;
    QPushButton *m_pause;
    QLineEdit *m_fichier;
    QSlider *m_slider;

    //layout 2
    QPushButton *m_Draw_ROI;
    QPushButton *m_Load_ROI;
    QPushButton *m_Save_ROI;

    //layout 3
    QPushButton *m_Generate_Curves;
    QPushButton *m_Generate_Maps;

    //layout local 4
    QPushButton *m_Fit_Raw;
    QPushButton *m_Fit_Average;
    QPushButton *m_Fit_IGR;


};


class TicTab : public QWidget
{
    Q_OBJECT

public:
    explicit TicTab(const QFileInfo &fileInfo, QWidget *parent = nullptr);

private:

    // Bouton Save
    QPushButton *m_Save_Tic;

    //Parameters
    QTextEdit *m_Raw_Parameters;
    QTextEdit *m_Average_Parameters;
    QTextEdit *m_IGR_Parameters;

};



class ParamTab : public QWidget
{
    Q_OBJECT

public:
    explicit ParamTab(const QFileInfo &fileInfo, QWidget *parent = nullptr);

private:

    //Boutons Save

    QPushButton *m_Save_Raw;
    QPushButton *m_Save_Average;
    QPushButton *m_Save_IGR;


};



class MaFenetre : public QDialog
{
    Q_OBJECT

public:
    explicit MaFenetre(const QString &fileName, QWidget *parent = nullptr);

private:
    QTabWidget *m_tabWidget;
    QPushButton *m_bouton_quitter;
};


#endif // FENETRE_H
