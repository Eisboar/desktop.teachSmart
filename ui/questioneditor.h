#ifndef QUESTIONEDITOR_H
#define QUESTIONEDITOR_H

#include <QDialog>
#include <QStringListModel>
#include <vector>
#include <data/answer.h>

namespace Ui {
class QuestionEditor;
}

class QuestionEditor : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionEditor(QWidget *parent = 0);
    ~QuestionEditor();
    void setTitle(QString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_QuestionEditor_finished(int result);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::QuestionEditor *ui;
    QStringListModel *model;
    QStringList *stringList;
    void enableParent();
    std::vector<Answer> *answers;
};

#endif // QUESTIONEDITOR_H
