#ifndef WRITER_H
#define WRITER_H

#include <data/questionsheet.h>

class Writer
{
public:
    Writer();
    QString writeQuestionSheet(QuestionSheet*);
    QString writeQuestionSheetID(QuestionSheet*);
};

#endif // WRITER_H
