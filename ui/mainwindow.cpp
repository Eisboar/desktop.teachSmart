#include <ui/mainwindow.h>
#include <ui/questionsheeteditor.h>
#include "ui_mainwindow.h"

//testing stuff
#include <data/questionsheet.h>
#include <QJsonObject>
#include <QJsonDocument>
#include <iostream>
#include <json/reader.h>
#include <QInputDialog>
#include <QWebFrame>
#include <QWebElementCollection>
#include <QNetworkDiskCache>
#include <QStandardPaths>

#include <json/writer.h>

#include <fstream>
#include <QFile>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //httpsClient = new HttpsClient(this);
    ui->setupUi(this);
    //ui->label->setText("hu");

    //create dummy data;
    QuestionSheet *questionSheet = new QuestionSheet();
    questionSheet->setName("testName");
    questionSheet->setID(1);
    questionSheet->setTimestamp("anytime");

    //ui->label->setText(questionSheet->getName());

//    //write to json
//    QJsonObject qJsonObject;
//    qJsonObject.begin();
//    qJsonObject.insert("ID",QString::number(questionSheet->getID()));
//    qJsonObject.insert("name",questionSheet->getName());
//    qJsonObject.insert("create_data",questionSheet->getTimestamp());
//    qJsonObject.end();

//    QJsonDocument doc(qJsonObject);
//    QString result(doc.toJson(QJsonDocument::Indented));
//    ui->label->setText(result);

//    //get data
    updateSheetList();

    updateDiagramm();

}

void
MainWindow::updateSheetList(){
    HttpsClient *httpsClient = new HttpsClient(this);
    httpsClient->setTask("getSheets");
    httpsClient->execute();
}

void
MainWindow::setSheetList(QString jsonString){

    //delete httpsClient;

    //std::cout << "lala" << std::endl;
    Reader reader;
    questionsSheets = (reader.parseSheets(jsonString));
    std::cout << "setquestionsheetlist with size :" << questionsSheets.size() << std::endl;
    QStringListModel *model = new QStringListModel(this);
    QStringList nameList;
    for (QuestionSheet & element : questionsSheets) {
        nameList.push_back(element.getName());
    }
    model->setStringList(nameList);
    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    bool ok=true;
    QString sheetTitle= QInputDialog::getText(this, tr("Neuer Fragebogen"),tr("Titel:"), QLineEdit::Normal,"", &ok);
    if (ok){
        QuestionSheetEditor* questionSheetEditor = new QuestionSheetEditor(this);
        questionSheetEditor->setTitle(sheetTitle);
        questionSheetEditor->show();
    }

}

void MainWindow::on_pushButton_clicked()
{
    updateSheetList();
}


void
MainWindow::updateDiagramm(){
    m_network = new QNetworkAccessManager(this);
    m_cache = new QNetworkDiskCache(this);
    m_cache->setCacheDirectory(QStandardPaths::writableLocation(QStandardPaths::CacheLocation ) + "/imageanalyzer");
    m_cache->setMaximumCacheSize(1000000); //set the cache to 10megs
    m_network->setCache(m_cache);
    ui->webView->page()->setNetworkAccessManager(m_network);


    ui->webView->page()->setNetworkAccessManager(m_network);

    //! The object we will expose to JavaScript engine:
    diagramm = new Diagramm();
   // diagramm->progressStatus(0);

    // Signal is emitted before frame loads any web content:
    QObject::connect(ui->webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                     this, SLOT(addJSObject()));

    // qrc:// URLs refer to resources. See imagenalayzer.qrc
    QUrl startURL = QUrl("qrc:/html/current.html");

    // Load web content now!
    ui->webView->setUrl(startURL);
    //diagramm->draw();
    ui->webView->show();

}

void
MainWindow::addJSObject() {
    // Add pAnalyzer to JavaScript Frame as member "imageAnalyzer".
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject(QString("diagramm"), diagramm);
}


void
MainWindow::on_comboBox_currentIndexChanged(int index){
    QuestionSheet questionSheet = questionsSheets.at(index);

    std::cout<< "ID: " <<  questionSheet.getName().toStdString() << std::endl;

    Writer writer;

    HttpsClient *httpsClient = new HttpsClient(this);
    httpsClient->setTask("getSheet");
    httpsClient->setJsonRequest(writer.writeQuestionSheetID(&questionSheet));

    httpsClient->execute();
    std::cout<< index <<  std::endl;
}

void
MainWindow::updateQuestionList(QString jsonString){

    //std::cout << "uddate QuestionList" << std::endl;
    Reader reader;
    //ui->comboBox_2->clear();
    if (currentQuestionSet != 0)
        delete currentQuestionSet;
    currentQuestionSet = (reader.parseQuestions(jsonString));

    std::cout << "uddate QuestionList with size: " << currentQuestionSet->size() << std::endl;

    QStringListModel *model = new QStringListModel(this);
    QStringList nameList;

    int count = 1;

    for (Question & element : *currentQuestionSet) {
        std::cout << element.getQuestionText().toStdString() << std::endl;
        QString caption = QString::number(count) + ")  " + element.getQuestionText();
        nameList.push_back(caption);
        count++;
    }

    model->setStringList(nameList);
    ui->comboBox_2->setModel(model);

    if ( activeIndex != -1){
            ui->comboBox_2->setCurrentIndex(activeIndex);
            activeIndex =-1;
    }

}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    activeQuestion = &currentQuestionSet->at(index);
    std::cout << "pos: " << activeQuestion->getType().toStdString() << std::endl;
    //updateDiagramm();
    diagramm->setQuestion(activeQuestion);
    diagramm->draw();
}

void MainWindow::on_pushButton_3_clicked()
{
    refreshDiagramm();
}

void
MainWindow::refreshDiagramm(){
     int currentQuestionIndex = ui->comboBox_2->currentIndex();
     activeIndex = currentQuestionIndex;


     QuestionSheet questionSheet = questionsSheets.at(ui->comboBox->currentIndex());

    // std::cout<< "ID: " <<  questionSheet.getName().toStdString() << std::endl;

     Writer writer;

     HttpsClient *httpsClient = new HttpsClient(this);
     httpsClient->setTask("getSheet");
     httpsClient->setJsonRequest(writer.writeQuestionSheetID(&questionSheet));

     httpsClient->execute();
     //std::cout<< index <<  std::endl;



}
