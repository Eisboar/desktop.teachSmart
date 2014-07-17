#ifndef ANSWEREDITOR_H
#define ANSWEREDITOR_H

#include <QDialog>

namespace Ui {
class AnswerEditor;
}

class AnswerEditor : public QDialog
{
    Q_OBJECT

public:
    explicit AnswerEditor(QWidget *parent = 0);
    ~AnswerEditor();

private:
    Ui::AnswerEditor *ui;
};

#endif // ANSWEREDITOR_H
