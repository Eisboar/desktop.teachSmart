#ifndef READER_H
#define READER_H

//QT
#include <QString>

//STL
#include <vector>

//project
#include <data/questionsheet.h>
#include <data/question.h>
#include <data/answer.h>
#include <data/multiplechoicequestion.h>


class Reader
{
public:
    Reader();
    vector<QuestionSheet> parseSheets(QString jsonString);
    vector<Question>* parseQuestions(QString jsonString);

};

#endif // READER_H
