#include "diagramm.h"



#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QtConcurrent>
#include <QVariant>

#include <iostream>

//! [ ImageAnalyzer - Constructor ]

void
Diagramm::createDummyData(){

    values = new QMap<QString, QVariant>;
    values->insert("Antwort ", 2);
    values->insert("Antwort 2", 3);
    values->insert("Antwort 3", 4);
}


Diagramm::Diagramm()
{

    createDummyData();

    //QObject::connect(m_watcher, SIGNAL(progressValueChanged(int)),
    //                 this, SLOT(progressStatus(int)));
}

Diagramm::~Diagramm()
{
    delete(m_watcher);
}

QMap<QString, QVariant> Diagramm::getValues() {return *values;}

void Diagramm::progressStatus(int newstat)
{
    emit updateProgress(newstat);
}


void Diagramm::startAnalysis(const QStringList & urls)
{
    if ( values->contains("lala")){
        QVariant value =(*values)["lala"] ;
        int intValue = value.toInt();
        intValue++;
        (*values)["lala"]=QVariant(intValue);
    }
    //m_URLQueue = urls;
    //fetchURLs();
}

void
Diagramm::draw(){
    if ( values->contains("Antwort ")){
        QVariant value =(*values)["Antwort "] ;
        int intValue = value.toInt();
        intValue++;
        (*values)["Antwort "]=QVariant(intValue);
    }

    progressStatus(0);
}

void
Diagramm::setQuestion(Question *question){
    //delete values;

    std::cout << "set_question: " <<
                 question->getType().toStdString() << "\n";
    //std::cout << "size:" << question->getUserAnswers()->size() << "\n";
    std::cout.flush();

    title = "";
    title.append(QString::number(question->getPosition()));
    title.append(")  ");
    title.append(question->getQuestionText());

    //std::cout <<question->getType().toStdString() << '\n';

    if (question->getUserAnswers()==0)
        return;


    std::cout << "size:" << question->getUserAnswers()->size() << "\n";
    std::cout.flush();

    if (values!=0)
        delete values;
    values = new QMap<QString, QVariant>;
    //std::cout << question->getType().toStdString() << "\n";
    if (question->getType()=="multiple_choice"){
        std::cout << "lala" << "\n";
        QMap<int, int> *userAnswers = question->getUserAnswers();

         for( QMap<int,int>::iterator it = userAnswers->begin(); it != userAnswers->end(); )
         {
               values->insert(QString::number(it.key()),it.value());
               it++;
//             if( it->value == something )
//             {
//                 map.insert(it.key()+10,it.value());
//                 it = map.erase(it);
//             } else {
//                 ++it;
//             }
         }

    } else if (question->getType()=="rating"){
        std::cout << "lala" << "\n";
        QMap<int, int> *userAnswers = question->getUserAnswers();
        //std::cout << "size:" << userAnswers->size() << "\n";
         for( QMap<int,int>::iterator it = userAnswers->begin(); it != userAnswers->end(); ) {
             std::cout << "insert" << "\n";
             values->insert(QString::number(it.key()),it.value());
             it++;
         }
    }
}

QString
Diagramm::getTitle(){
    return title;
}
