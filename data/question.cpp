#include "question.h"

Question::Question()
{
}

void
Question::setQuestionText(QString questionText){
    this->questionText=questionText;
}

void
Question::setType(QString type){
    this->type=type;
}

QString
Question::getQuestionText(){
    return this->questionText;
}

QString
Question::getType(){
    return this->type;
}

int
Question::getPosition(){
    return this->position;
}

void
Question::setPosition(int position){
    this->position=position;
}

QMap<int, int>*
Question::getUserAnswers(){
    return this->userAnswers;
}

void
Question::setUserAnswers(QMap<int, int>* userAnswers){
    this->userAnswers = userAnswers;
}
