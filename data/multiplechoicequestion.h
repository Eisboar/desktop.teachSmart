#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H
#include <data/question.h>
#include <data/answer.h>
#include <vector>
#include <QString>

class MultipleChoiceQuestion: public Question
{
private:
    std::vector<Answer> *answers;

public:
    MultipleChoiceQuestion();
    void setAnswers(std::vector<Answer>*);
    std::vector<Answer>* getAnswers();
};

#endif // MULTIPLECHOICEQUESTION_H
