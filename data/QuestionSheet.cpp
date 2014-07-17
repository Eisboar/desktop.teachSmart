#include "data/questionsheet.h"

QuestionSheet::QuestionSheet()
{}

void
QuestionSheet::setID(int ID){
    this->ID = ID;
}

void
QuestionSheet::setName(QString name){
    this->name = name;
}

void
QuestionSheet::setTimestamp(QString timestamp){
    this->timestamp = timestamp;
}

int
QuestionSheet::getID(){
    return ID;
}

QString&
QuestionSheet::getName(){
    return name;
}

QString&
QuestionSheet::getTimestamp(){
    return timestamp;
}

vector<Question*>*
QuestionSheet::getQuestions(){
    return questions;
}

void
QuestionSheet::setQuestions(vector<Question*> *questions){
    this->questions=questions;
}

