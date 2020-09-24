#include "fenetre.h"
#include <QApplication>
#include <QtWidgets>
#include <QFormLayout>
#include <QGroupBox>
#include <QDate>
#include<QTabWidget>
#include<QSlider>


MaFenetre::MaFenetre(const QString &fileName, QWidget *parent)
    : QDialog(parent)
{
    QFileInfo fileInfo(fileName);

    m_tabWidget = new QTabWidget;
    m_tabWidget->addTab(new AccTab(fileInfo), tr("Accueil"));
    m_tabWidget->addTab(new TicTab(fileInfo), tr("TIC"));
    m_tabWidget->addTab(new ParamTab(fileInfo), tr("Cartes parametriques"));



    m_bouton_quitter = new QPushButton("Quitter");
    m_bouton_quitter->setStyleSheet("background-color: rgb(255,53,53);");

    setFixedSize(1500, 1000);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_tabWidget);
    mainLayout->addWidget(m_bouton_quitter);
    setLayout(mainLayout);

    setWindowTitle(tr("DCE-US"));

    connect(m_bouton_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}


AccTab::AccTab(const QFileInfo &fileInfo, QWidget *parent)
    : QWidget(parent)
{


    //layout local 1

    m_charger_fichier = new QPushButton("Load File");
    m_play = new QPushButton("Play");
    m_pause = new QPushButton("Pause");
    m_fichier = new QLineEdit;
    m_fichier->setFixedWidth(100);
    m_slider = new QSlider(Qt::Horizontal);

    QGridLayout *Layout_local_1 = new QGridLayout;
    Layout_local_1->addWidget(m_charger_fichier,0,0);
    Layout_local_1->addWidget(m_fichier,0,1);
    Layout_local_1->addWidget(m_play,1,0);
    Layout_local_1->addWidget(m_pause,1,1);
    Layout_local_1->addWidget(m_slider,2,0,1,2);


    QGroupBox *groupe_Gestion_Affichage = new QGroupBox("Gestion Affichage");
    groupe_Gestion_Affichage->setLayout(Layout_local_1);




    //layout local 2

    m_Draw_ROI = new QPushButton("Draw");
    m_Load_ROI = new QPushButton("Load");
    m_Save_ROI = new QPushButton("Save");

    QHBoxLayout *Layout_local_2 = new QHBoxLayout;
    Layout_local_2->addWidget(m_Draw_ROI);
    Layout_local_2->addWidget(m_Load_ROI);
    Layout_local_2->addWidget(m_Save_ROI);

    QGroupBox *groupe_Gestion_ROI = new QGroupBox("Region of Interest");
    groupe_Gestion_ROI->setLayout(Layout_local_2);


    //layout local 3

    m_Generate_Curves = new QPushButton("Generate Curves");
    m_Generate_Maps = new QPushButton("Generate Maps");


    QHBoxLayout *Layout_local_3 = new QHBoxLayout;
    Layout_local_3->addWidget(m_Generate_Curves);
    Layout_local_3->addWidget(m_Generate_Maps);

    QGroupBox *groupe_Generation_Results = new QGroupBox("Generate Results");
    groupe_Generation_Results->setLayout(Layout_local_3);

    //layout local 4

    m_Fit_Raw = new QPushButton("Raw");
    m_Fit_Average = new QPushButton("Moving Average");
    m_Fit_IGR = new QPushButton("IGR");

    QHBoxLayout *Layout_local_4 = new QHBoxLayout;
    Layout_local_4->addWidget(m_Fit_Raw);
    Layout_local_4->addWidget(m_Fit_Average);
    Layout_local_4->addWidget(m_Fit_IGR);

    QGroupBox *groupe_Choice_Fit = new QGroupBox("Generate Results");
    groupe_Choice_Fit->setLayout(Layout_local_4);


    //groupBox courbes
    QGroupBox *groupe_Images_Generated = new QGroupBox("Images Loaded");

    //layout global

    QGridLayout *layoutGlobal = new QGridLayout;
    layoutGlobal->addWidget(groupe_Gestion_Affichage,0,0,1,2);
    layoutGlobal->addWidget(groupe_Gestion_ROI,1,0,1,2);
    layoutGlobal->addWidget(groupe_Generation_Results,3,0,1,2);
    layoutGlobal->addWidget(groupe_Choice_Fit,2,0,1,2);
    layoutGlobal->addWidget(groupe_Images_Generated,0,2,4,20);

    setLayout(layoutGlobal);

}


TicTab::TicTab(const QFileInfo &fileInfo, QWidget *parent)
    : QWidget(parent)
{

    // Bouton Save

    m_Save_Tic = new QPushButton("Save TIC");

    //AUC Raw

    QGroupBox *groupe_AUC_Raw = new QGroupBox("AUC Raw");

    //AUC Moving Average

    QGroupBox *groupe_AUC_Moving_Average = new QGroupBox("AUC Moving Average");

    //AUC IGR

    QGroupBox *groupe_AUC_IGR = new QGroupBox("AUC IGR");

    //Parameters

    m_Raw_Parameters = new QTextEdit("Raw Parameters");
    m_Average_Parameters = new QTextEdit("Raw Parameters");
    m_IGR_Parameters = new QTextEdit("IGR Parameters");


    //layout global

   QGridLayout *layoutGlobal = new QGridLayout;

   layoutGlobal->addWidget(groupe_AUC_Raw,0,0,5,1);
   layoutGlobal->addWidget(groupe_AUC_Moving_Average,0,1,5,1);
   layoutGlobal->addWidget(groupe_AUC_IGR,0,2,5,1);
   layoutGlobal->addWidget(m_Raw_Parameters,6,0,2,1);
   layoutGlobal->addWidget(m_Average_Parameters,6,1,2,1);
   layoutGlobal->addWidget(m_IGR_Parameters,6,2,2,1);
   layoutGlobal->addWidget(m_Save_Tic,8,2,1,1);


   setLayout(layoutGlobal);

}

ParamTab::ParamTab(const QFileInfo &fileInfo, QWidget *parent)
    : QWidget(parent)
{

    //Boutons Save

    m_Save_Raw = new QPushButton("Save");
    m_Save_Average = new QPushButton("Save");
    m_Save_IGR = new QPushButton("Save");

    //RAW

    QGroupBox *groupe_Raw_AUC = new QGroupBox("AUC");
    QGroupBox *groupe_Raw_PI = new QGroupBox("PI");
    QGroupBox *groupe_Raw_Transit = new QGroupBox("Transit");

    //AVERAGE

    QGroupBox *groupe_Average_AUC = new QGroupBox("AUC");
    QGroupBox *groupe_Average_PI = new QGroupBox("PI");
    QGroupBox *groupe_Average_Transit = new QGroupBox("Transit");

    //IGR

    QGroupBox *groupe_IGR_AUC = new QGroupBox("AUC");
    QGroupBox *groupe_IGR_PI = new QGroupBox("PI");
    QGroupBox *groupe_IGR_Transit = new QGroupBox("Transit");

    //Layout local 1

    QGridLayout *Layout_local_1 = new QGridLayout;
    Layout_local_1->addWidget(m_Save_Raw,2,0,1,1);
    Layout_local_1->addWidget(groupe_Raw_AUC,0,1,5,5);
    Layout_local_1->addWidget(groupe_Raw_PI,0,6,5,5);
    Layout_local_1->addWidget(groupe_Raw_Transit,0,11,5,5);

    //Layout local 2
    QGridLayout *Layout_local_2 = new QGridLayout;
    Layout_local_2->addWidget(m_Save_Average,2,0,1,1);
    Layout_local_2->addWidget(groupe_Average_AUC,0,1,5,5);
    Layout_local_2->addWidget(groupe_Average_PI,0,6,5,5);
    Layout_local_2->addWidget(groupe_Average_Transit,0,11,5,5);

    //Layout local 3
    QGridLayout *Layout_local_3 = new QGridLayout;
    Layout_local_3->addWidget(m_Save_IGR,2,0,1,1);
    Layout_local_3->addWidget(groupe_IGR_AUC,0,1,5,5);
    Layout_local_3->addWidget(groupe_IGR_PI,0,6,5,5);
    Layout_local_3->addWidget(groupe_IGR_Transit,0,11,5,5);


    //GroupBox Layout 1

    QGroupBox *groupe_RAW_Global = new QGroupBox("RAW");
    groupe_RAW_Global->setLayout(Layout_local_1);

    //GroupBox Layout 2

    QGroupBox *groupe_Average_Global = new QGroupBox("Moving Average");
    groupe_Average_Global->setLayout(Layout_local_2);

    //GroupBox Layout 3

    QGroupBox *groupe_IGR_Global = new QGroupBox("IGR");
    groupe_IGR_Global->setLayout(Layout_local_3);

    //Layout Gloabal
    QGridLayout *layoutGlobal = new QGridLayout;
    layoutGlobal->addWidget(groupe_RAW_Global);
    layoutGlobal->addWidget(groupe_Average_Global);
    layoutGlobal->addWidget(groupe_IGR_Global);

    setLayout(layoutGlobal);

}
