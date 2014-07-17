#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <network/httpsclient.h>
#include <QMainWindow>
#include <QString>
#include <network/networkinterface.h>
#include <data/diagramm.h>
#include <data/questionsheet.h>
#include <vector>
#include <network/httpsclient.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public NetworkInterface
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setSheetList(QString);
    ~MainWindow();
    virtual void NetworkCallback(QString task, QString string){
        if (task=="getSheets")
            setSheetList(string);
        if (task=="getSheet")
            updateQuestionList(string);
    }

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void addJSObject();
    void on_comboBox_currentIndexChanged(int index);
    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

private:
    //HttpsClient *httpsClient;
    Ui::MainWindow *ui;
    Diagramm *diagramm;
    QNetworkAccessManager * m_network;
    QNetworkDiskCache * m_cache;
    std::vector<QuestionSheet> questionsSheets;
    vector<Question> *currentQuestionSet;
    Question *activeQuestion;
    int activeIndex = -1;

    void updateQuestionList(QString string);
    void updateSheetList();
    void updateDiagramm();
    void refreshDiagramm();
};

#endif // MAINWINDOW
