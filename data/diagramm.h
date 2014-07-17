#include <QFutureWatcher>
#include <QtGui>
#include <QMap>
#include <data/question.h>

QT_BEGIN_NAMESPACE
class QNetworkAccessManager;
class QNetworkReply;
class QNetworkDiskCache;
QT_END_NAMESPACE

//! [ ImageAnalyzer - public interface ]
class Diagramm : public QObject
{
    Q_OBJECT
public:
    Diagramm();

    QMap<QString, QVariant> getValues();
    QString getTitle();

    Q_PROPERTY(QMap values READ getValues);
    Q_PROPERTY(QString title READ getTitle);
    ~Diagramm();
    void draw();

public slots:
    /*! initiates analysis of all the urls in the list */
    void startAnalysis(const QStringList & urls);
    void setQuestion(Question *question);


signals:
    void updateProgress(int completed);

private slots:
    void progressStatus(int);

private:
    QFutureWatcher<QRgb> * m_watcher;

    QString title;
    QMap<QString, QVariant> *values = 0;

    void createDummyData();
};
