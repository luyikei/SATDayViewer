#ifndef SATDAYVIEWER_H
#define SATDAYVIEWER_H

#include <QMainWindow>

namespace Ui {
class SATDayViewer;
}

class SATDayViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit SATDayViewer(QWidget *parent = 0);
    ~SATDayViewer();

private slots:
    void on_calendarWidget_clicked(const QDate &date);

    void on_backButton_clicked();

    void on_nextButton_clicked();

    void on_webView_loadFinished(bool arg1);

    void on_webView_loadStarted();

private:
    Ui::SATDayViewer *ui;

};

#endif // SATDAYVIEWER_H
