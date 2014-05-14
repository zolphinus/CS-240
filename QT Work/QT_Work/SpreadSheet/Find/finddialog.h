#ifndef FINDDIALOG_H
#define FINDDIALOG_H


//This should work for QT4, but I have QT5 installed and have yet to make changes

#include <QDialog>
#include <QCheckBox>    //class QCheckBox;
#include <QLabel>       //class QLabel;
#include <QLineEdit>    //class QLineEdit;
#include <QPushButton>  //class QPushButton;
#include <QHBoxLayout>   //in the finddialog.cpp
#include <QVBoxLayout>   //in the finddialog.cpp

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;



class FindDialog : public QDialog
{
    //needed for slots/signals
    Q_OBJECT
public:
    FindDialog(QWidget *parent = 0);

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;

};

#endif // FINDDIALOG_H
