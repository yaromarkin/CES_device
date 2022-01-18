#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsView>
#include <QTimer>
#include <QStandardItemModel>
//#include <QStandardItem>

#define TIMEOUT 5 * 1000

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_powerButton_clicked();
    void changeFrequency();
    void changeWaveform();
    void changeTime();
    void increaseCurrent();
    void decreaseCurrent();
    void on_checkBox_stateChanged(int arg1);
    void autoChangeBattery();
    void chargeBattery();
    void changeBattery();
    void addRecording();
    void loadRecording();
    void on_currentFaultButton_clicked();

private:
    Ui::MainWindow *ui;
    bool powerStatus;
    QString currentFrequency;
    QString currentWaveform;
    QString timeCountDown;
    QGraphicsScene *scene;
    int currentTime;
    QString tempCountDown;
    int current;
    bool skinContact;
    bool treatment;
    QTimer *circuitTimer;
    QTimer *autoTimer;
    QTimer *countdownTimer;
    QTimer *currentTimer;
    QTimer *batteryTimer;
    void changePowerStatus();
    void toggleSkinContact(bool);
    void toggleTreatment();
    void restartAutoTimer();
    void updateTimer();
    void startTreatment();
    void shutdownCheck();
    void pauseTimer();
    void resumeTimer();
    void checkCurrent();
    QStandardItemModel *records;
    int numRecords;
    bool recordsLoaded;
    double currentBattery;
};
#endif // MAINWINDOW_H
