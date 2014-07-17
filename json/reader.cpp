#include "json/reader.h"

//QT
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QMap>
#include <iostream>

Reader::Reader()
{
}

vector<QuestionSheet> Reader::parseSheets(QString jsonString){
    vector<QuestionSheet> questionSheets;
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject jsonObj = doc.object();
    QJsonArray jsonArray = jsonObj["questionSheets"].toArray();
    foreach(QJsonValue questionSheetJson, jsonArray)
        {
            QuestionSheet questionSheet;
            QJsonObject questionSheetJsonObject =  questionSheetJson.toObject();
            // the QJsonValue encapsulates the person QJsonObject
            questionSheet.setID(questionSheetJsonObject["ID"].toString().toInt());
            questionSheet.setName(questionSheetJsonObject["name"].toString());
            questionSheet.setTimestamp(questionSheetJsonObject["create_date"].toString());
            //std::cout<< "ID-reader: " <<  questionSheet.getID() << std::endl;
            questionSheets.push_back(questionSheet);

        }
    return questionSheets;
}

vector<Question>*
Reader::parseQuestions(QString jsonString){
    vector<Question> *questions = new vector<Question>();
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject jsonObj = doc.object();
    QJsonObject questionSheetObj = jsonObj["questionSheet"].toObject();
    QJsonArray questionArray = questionSheetObj["questions"].toArray();
    foreach(QJsonValue questionJson, questionArray)
        {
            Question question;
            QJsonObject questionJsonObject =  questionJson.toObject();
            // the QJsonValue encapsulates the person QJsonObject
            question.setType(questionJsonObject["type"].toString());
            question.setPosition(questionJsonObject["position"].toString().toInt());
            question.setQuestionText(questionJsonObject["questionText"].toString());
            std::cout << "insert1111!!!!!" << std::endl;
            if (question.getType()=="multiple_choice"){
                 std::cout << "insert222!!!!!" << std::endl;
                vector<Answer>* answers = new vector<Answer>();
                QJsonArray answerArray = questionJsonObject["answers"].toArray();
                foreach(QJsonValue answerJson, answerArray){
                    Answer answer;
                    QJsonObject answerJsonObject =  answerJson.toObject();
                    answer.setPosition(answerJsonObject["position"].toString().toInt());
                    answer.setAnswerText(answerJsonObject["answerText"].toString());
                   std::cout << "insert-answer!!!!!" << std::endl;
                    answers->push_back(answer);
                }
                ((MultipleChoiceQuestion*) &question)->setAnswers(answers);

                //TODO: redundant ...... just position and rating ..
                QMap<int,int>* results = new QMap<int, int>();
                QJsonArray userAnswerArray = questionJsonObject["user_answers"].toArray();
                foreach(QJsonValue userAnswerJson, userAnswerArray){
                    int position;
                    int count;
                    QJsonObject userAnswerJsonObject =  userAnswerJson.toObject();
                    position = userAnswerJsonObject["position"].toString().toInt();
                    count = userAnswerJsonObject["count"].toString().toInt();
                    std::cout << "insert!!!!!" << std::endl;

                    results->insert(position,count);
                }
                question.setUserAnswers(results);
            } else if (question.getType()=="rating"){
                 std::cout << "inse3333!!!!!" << std::endl;
                QMap<int,int>* results = new QMap<int, int>();
                QJsonArray userAnswerArray = questionJsonObject["user_answers"].toArray();
                foreach(QJsonValue userAnswerJson, userAnswerArray){
                    int rating;
                    int count;
                    QJsonObject userAnswerJsonObject =  userAnswerJson.toObject();
                    rating = userAnswerJsonObject["rating"].toString().toInt();
                    count = userAnswerJsonObject["count"].toString().toInt();
                    results->insert(rating,count);
                }
                question.setUserAnswers(results);
            }
            questions->push_back(question);
        }
    return questions;
}
