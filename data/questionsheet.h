#ifndef QUESTIONSHEET_H
#define QUESTIONSHEET_H

#include <QString>
#include <data/question.h>
#include <vector>

using namespace std;

class QuestionSheet
{

private:
    int ID;
    QString timestamp;
    QString name;
    vector<Question*> *questions;

public:
    QuestionSheet();

    int getID();
    void setID(int ID);

    QString& getTimestamp();
    void setTimestamp(QString timestamp);

    QString& getName();
    void setName(QString name);

    vector<Question*>* getQuestions();
    void setQuestions(vector<Question*>*);
};
#endif // QUESTIONSHEET_H
