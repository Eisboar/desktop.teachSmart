#include "writer.h"
#include <QJsonObject>
#include <QJsonArray>
#include <iostream>
#include <QJsonDocument>
#include <data/question.h>
#include <data/multiplechoicequestion.h>
#include <data/answer.h>

Writer::Writer()
{
}

QString
Writer::writeQuestionSheet(QuestionSheet *questionSheet){
     //write to json
    QJsonObject qJsonObject;
    qJsonObject.begin();

    qJsonObject.insert("name",questionSheet->getName());
    QJsonArray questionArray;

    std::vector<Question*> *questions = questionSheet->getQuestions();
    for (std::vector<Question*>::iterator it = questions->begin(); it != questions->end(); ++it){
    Question* question = *it;
        //for (Question question: questionSheet->getQuestions()){
        QJsonObject questionJsonObject;
        questionJsonObject.begin();
        questionJsonObject.insert("type", question->getType());
        questionJsonObject.insert("questionText",question->getQuestionText());
        if (question->getType() == "multiple_choice"){
            QJsonArray answersArray;
            //MultipleChoiceQuestion *multipleChoiceQuestion = static_cast<MultipleChoiceQuestion*>(&question);
            //Child *pChild =  (Child *) &parent;
            //Question *question = it.base();
            MultipleChoiceQuestion* multipleChoiceQuestion = (MultipleChoiceQuestion *)  question;;

            std::vector<Answer> *answers = multipleChoiceQuestion->getAnswers();

            std::cout << answers->size() << std::endl;
           for (std::vector<Answer>::iterator answerIt = answers->begin() ; answerIt != answers->end(); ++answerIt)
            {
                QJsonObject answerJsonObject;
                answerJsonObject.begin();
                answerJsonObject.insert("position", QString::number(answerIt->getPosition()));
                answerJsonObject.insert("answerText",answerIt->getAnswerText());
                answerJsonObject.end();
                answersArray.append(answerJsonObject);
            }

            questionJsonObject.insert("answers",answersArray);
        }
        questionJsonObject.end();
        questionArray.append(questionJsonObject);
    }

    qJsonObject.insert("questions",questionArray);
    //qJsonObject.
    qJsonObject.end();

    QJsonDocument doc(qJsonObject);
    QString result(doc.toJson(QJsonDocument::Indented));

    //    ui->label->setText(result);
    std::cout << result.toStdString() << std::endl;
    return result;
}

QString
Writer::writeQuestionSheetID(QuestionSheet *questionSheet){
    QJsonObject qJsonObject;
    qJsonObject.begin();

    qJsonObject.insert("id",QString::number(questionSheet->getID()));
    qJsonObject.insert("with_answers","all");

    qJsonObject.end();

    QJsonDocument doc(qJsonObject);
    QString result(doc.toJson(QJsonDocument::Indented));

    std::cout << "Retrieving QuestionSheet with request:" << std::endl;
    std::cout << result.toStdString() << std::endl;
    return result;
}

