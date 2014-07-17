#include "answereditor.h"
#include "ui_answereditor.h"

AnswerEditor::AnswerEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnswerEditor)
{
    ui->setupUi(this);
}

AnswerEditor::~AnswerEditor()
{
    delete ui;
}
