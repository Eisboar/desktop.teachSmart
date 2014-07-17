#-------------------------------------------------
#
# Project created by QtCreator 2014-05-30T18:38:55
#
#-------------------------------------------------

QT       += core gui concurrent
QT += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9



SOURCES += main.cpp \
    ui/mainwindow.cpp \
    network/httpsclient.cpp \
    data/QuestionSheet.cpp \
    data/answer.cpp \
    json/writer.cpp \
    json/reader.cpp \
    data/question.cpp \
    ui/questioneditor.cpp \
    data/ratingquestion.cpp \
    data/multiplechoicequestion.cpp \
    ui/questionsheeteditor.cpp \
    ui/answereditor.cpp \
    network/networkinterface.cpp \
    data/diagramm.cpp \
    data/useranswer.cpp


HEADERS  += ui/mainwindow.h \
    network/httpsclient.h \
    data/answer.h \
    json/writer.h \
    json/reader.h \
    data/question.h \
    data/questionsheet.h \
    ui/questioneditor.h \
    data/ratingquestion.h \
    data/multiplechoicequestion.h \
    ui/questionsheeteditor.h \
    ui/answereditor.h \
    network/networkinterface.h \
    data/diagramm.h \
    data/useranswer.h

FORMS    += ui/mainwindow.ui \
    ui/questioneditor.ui \
    ui/questioneditor_multi.ui \
    ui/questionsheeteditor.ui \
    ui/answereditor.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Qt/5.3/clang_64/lib/release/ -lQtNetwork
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Qt/5.3/clang_64/lib/debug/ -lQtNetwork
else:mac: LIBS += -F$$PWD/../Qt/5.3/clang_64/lib/ -framework QtNetwork
else:unix: LIBS += -L$$PWD/../Qt/5.3/clang_64/lib/ -lQtNetwork

INCLUDEPATH += $$PWD/../Qt/5.3/clang_64/include
DEPENDPATH += $$PWD/../Qt/5.3/clang_64/include

OTHER_FILES += \
    images/refresh.jpeg \
    html/current.html \
    html/piechart_template.html

RESOURCES += \
    resources.qrc
