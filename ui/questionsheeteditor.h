#ifndef QUESTIONSHEETEDITOR_H
#define QUESTIONSHEETEDITOR_H

#include <QDialog>
#include <data/question.h>;
#include <QStringListModel>
#include <vector>
#include <data/questionsheet.h>
#include <network/networkinterface.h>

namespace Ui {
class QuestionSheetEditor;
}

class QuestionSheetEditor : public QDialog, public NetworkInterface
{
    Q_OBJECT

public:
    explicit QuestionSheetEditor(QWidget *parent = 0);
    ~QuestionSheetEditor();
    void addQuestion(Question*);
    void setTitle(QString);
    virtual void NetworkCallback(QString task, QString string){
        //do sth
    }

private slots:
    void on_pushButton_clicked();


    void on_buttonBox_accepted();

private:
    std::vector<Question*> *questions;
    QStringListModel *model;
    QStringList *stringList;
    Ui::QuestionSheetEditor *ui;
    QuestionSheet *questionsheet;
};

#endif // QUESTIONSHEETEDITOR_H
