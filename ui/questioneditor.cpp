#include "questioneditor.h"
#include "ui_questioneditor.h"
#include <data/question.h>
#include <data/multiplechoicequestion.h>
#include <data/ratingquestion.h>
#include <ui/questionsheeteditor.h>
#include <iostream>

QuestionEditor::QuestionEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionEditor)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    stringList = new QStringList();
    //model->setStringList(*stringList);
    ui->listView->setModel(model);
    ui->stackedWidget->setCurrentIndex(0);
    answers = new std::vector<Answer>;
}

QuestionEditor::~QuestionEditor()
{
    delete ui;
}

void
QuestionEditor::setTitle(QString title){
    this->setWindowTitle(title.toUtf8());
}

void QuestionEditor::on_buttonBox_accepted()
{
    if (ui->textEdit->toPlainText() == ""){
            enableParent();
            return;
    }
    Question *question;
    QString questionType = ui->comboBox->currentText();
    if (questionType == "Multiple Choice"){
        std::cout << "create multiple choice" << std::endl;
        MultipleChoiceQuestion* multipleChoiceQuestion = new MultipleChoiceQuestion();
        multipleChoiceQuestion->setAnswers(answers);
        multipleChoiceQuestion->setQuestionText(ui->textEdit->toPlainText());
        question = multipleChoiceQuestion;
        MultipleChoiceQuestion* multipleChoiceQuestion1 = (MultipleChoiceQuestion *) question;
        std::cout << question->getType().toStdString() << std::endl;
        std::cout << "Answercount: " << answers->size() << std::endl;
        std::cout << "Answercount1: " << multipleChoiceQuestion->getAnswers()->size() << std::endl;
    } else if (questionType == "Star Rating"){
        question = new RatingQuestion();
        question->setQuestionText(ui->textEdit->toPlainText());
    }
    std::cout << question->getType().toStdString() << std::endl;
    QuestionSheetEditor *questionSheetEdtor = (QuestionSheetEditor*) parentWidget();
    questionSheetEdtor->addQuestion(question);
    enableParent();
}

void
QuestionEditor::enableParent(){
    parentWidget()->setEnabled(true);
    parentWidget()->show();
    parentWidget()->raise();
    parentWidget()->activateWindow();
}

void QuestionEditor::on_buttonBox_rejected()
{
    enableParent();
}

void QuestionEditor::on_QuestionEditor_finished(int result)
{
    enableParent();
}

void QuestionEditor::on_comboBox_activated(const QString &arg1)
{
    std::cout << arg1.toStdString() <<std::endl;
}

void QuestionEditor::on_comboBox_activated(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

//add answer to the list
void QuestionEditor::on_pushButton_clicked()
{
    if (ui->textEdit_2->toPlainText() == "")
        return;
    Answer answer;
    answer.setAnswerText(ui->textEdit_2->toPlainText());
    answer.setPosition(stringList->size()+1);
    stringList->push_back(answer.getAnswerText());
    model->setStringList(*stringList);
    ui->listView->update();
    answers->push_back(answer);
    ui->textEdit_2->setText("");
}
