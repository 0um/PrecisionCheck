#ifndef mainwindow_h
#define mainwindow_h

#include <QMainWindow>
#include <QScopedPointer>

namespace Ui
{
    class MainWindow;
}

class QString;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    private slots:
        void eval();
        void copy();

    signals:
        void evalPressed();
        void copyPressed();
        void lineChanged();

private:
    QScopedPointer<Ui::MainWindow> ui;
    const char format{ 'g' };
    const int precision{ 50 };
    const QString error{ "Error: " };
};

#endif