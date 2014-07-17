#include "answer.h"

Answer::Answer()
{
}

void
Answer::setAnswerText(QString answerText){
    this->answerText=answerText;
}


QString
Answer::getAnswerText(){
    return answerText;
}

void
Answer::setPosition(int position){
    this->position = position;
}

int
Answer::getPosition(){
    return position;
}
