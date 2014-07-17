#include "questionsheeteditor.h"
#include "ui_questionsheeteditor.h"
#include "ui/questioneditor.h"
#include "json/writer.h"
#include "network/httpsclient.h"

QuestionSheetEditor::QuestionSheetEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionSheetEditor)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    stringList = new QStringList();
    //model->setStringList(*stringList);
    ui->listView->setModel(model);
    questions = new std::vector<Question*>;
    questionsheet = new QuestionSheet();
}

QuestionSheetEditor::~QuestionSheetEditor()
{
    delete ui;
}

//add question button pressed
void QuestionSheetEditor::on_pushButton_clicked(){
    QuestionEditor* questionEditor = new QuestionEditor(this);
    questionEditor->setTitle(this->windowTitle());
    this->setDisabled(true);
    questionEditor->setEnabled(true);
    questionEditor->show();
}

void
QuestionSheetEditor::setTitle(QString title){
    this->setWindowTitle(title.toUtf8());
    questionsheet->setName(title);
}

void
QuestionSheetEditor::addQuestion(Question* question){
    questions->push_back(question);
    stringList->push_back(question->getQuestionText());
    model->setStringList(*stringList);
   ui->listView->update();
}

//try to add questionsheet
void QuestionSheetEditor::on_buttonBox_accepted()
{
    questionsheet->setQuestions(questions);
    Writer writer;
    QString jsonRequest = writer.writeQuestionSheet(questionsheet);
    HttpsClient *httpsClient = new HttpsClient(this);
    httpsClient->setTask("addSheet");
    httpsClient->setJsonRequest(jsonRequest);
    httpsClient->execute();
}
