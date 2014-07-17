#ifndef ANSWER_H
#define ANSWER_H

#include <QString>

class Answer
{
private:
    QString answerText;
    int position;

public:
    Answer();
    void setAnswerText(QString);
    QString getAnswerText();
    void setPosition(int position);
    int getPosition();
};

#endif // ANSWER_H
