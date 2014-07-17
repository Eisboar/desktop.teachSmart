#include "multiplechoicequestion.h"
#include <iostream>

MultipleChoiceQuestion::MultipleChoiceQuestion()
{
    this->setType("multiple_choice");
}

void
MultipleChoiceQuestion::setAnswers(std::vector<Answer>* answers)
{
    this->answers=answers;
    std::cout << "size: "<< answers->size() << std::endl;
}

std::vector<Answer>*
MultipleChoiceQuestion::getAnswers(){
    std::cout << "size: "<< answers->size() << std::endl;
    return answers;
}
