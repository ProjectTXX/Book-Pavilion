#ifndef SUCCESS_H
#define SUCCESS_H

#include <QWidget>
#include<QtMultimedia/QMediaPlayer>
#include<QTimer>
#include<QFileDialog>
#include<QListWidget>
#include<QPushButton>
#include<QString>

namespace Ui {
class Success;
}

class Success : public QWidget
{
    Q_OBJECT

public:
    explicit Success(QWidget *parent = 0);
    ~Success();
    QString settime(int time);

private slots:
    void on_playinandpasue_clicked();
    void setSliderValue();
    void on_hprogress_sliderMoved(int position);
    void on_vVolume_sliderMoved(int position);
    void on_btnadd_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_btnPre_clicked();
    void on_btnNext_clicked();
    void getduration();
    void setPlayTime();
    void on_btnvolume_clicked();
    void on_vVolume_sliderReleased();

private:
    Ui::Success *ui;
    QMediaPlayer m_mediaplayer;
    QTimer *timer;
    QString m_playpath;   //文件路径
    int Playtime;
    int Playrow;    //索引
};

#endif // SUCCESS_H
