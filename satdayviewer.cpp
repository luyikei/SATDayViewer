#include "satdayviewer.h"
#include "ui_satdayviewer.h"
#include <QDate>
SATDayViewer::SATDayViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SATDayViewer)
{
    ui->setupUi(this);
    ui->calendarWidget->setMaximumDate(QDate::currentDate());
}

SATDayViewer::~SATDayViewer()
{
    delete ui;
}

void SATDayViewer::on_calendarWidget_clicked(const QDate &date)
{
    ui->webView->setUrl(QUrl(QString("https://sat.collegeboard.org/practice/sat-question-of-the-day?questionId=%1&oq=1")
                             .arg(date.toString("yyyyMMdd"))
                             ));
    ui->statusBar->showMessage(QString("Loading the page of %1 ...").arg(date.toString("yyyyMMdd")), 2000);
}

void SATDayViewer::on_backButton_clicked()
{
    QDate now = ui->calendarWidget->selectedDate();
    QDate before = now.addDays(-1);
    ui->webView->setUrl(QUrl(QString("https://sat.collegeboard.org/practice/sat-question-of-the-day?questionId=%1&oq=1")
                             .arg(before.toString("yyyyMMdd"))
                             ));
    ui->calendarWidget->setSelectedDate(before);
    ui->statusBar->showMessage("Loading the previous page...", 2000);
}

void SATDayViewer::on_nextButton_clicked()
{
    QDate now = ui->calendarWidget->selectedDate();
    QDate after = now.addDays(1);
    ui->webView->setUrl(QUrl(QString("https://sat.collegeboard.org/practice/sat-question-of-the-day?questionId=%1&oq=1")
                             .arg(after.toString("yyyyMMdd"))
                             ));
    ui->calendarWidget->setSelectedDate(after);
    ui->statusBar->showMessage("Loading the next page...", 2000);
}

void SATDayViewer::on_webView_loadFinished(bool arg1)
{
    ui->statusBar->showMessage("Loading finished.", 2000);
    ui->progressBar->setVisible(false);
}

void SATDayViewer::on_webView_loadStarted()
{
    ui->progressBar->setVisible(true);
}
