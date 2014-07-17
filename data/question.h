#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QMap>

class Question
{
protected:
    QString type;
    QString questionText;
    int position;
    QMap<int, int> *userAnswers = 0;

private:



public:
    Question();
    int getPosition();
    void setPosition(int);
    QString getType();
    QString getQuestionText();
    QMap<int, int>* getUserAnswers();
    void setType(QString);
    void setQuestionText(QString);
    void setUserAnswers(QMap<int, int>*);
};

#endif // QUESTION_H
