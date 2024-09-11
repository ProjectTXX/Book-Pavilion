#include "success.h"
#include "ui_success.h"

Success::Success(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Success)
{
    ui->setupUi(this);
    timer=new QTimer();
    timer->setInterval(2000);//每两秒执行一次
    timer->start();
    ui->vVolume->setVisible(false);//音量条不可见
    QString filename="C:\\Users\\Pluto\\Desktop\\music";
    QDir dir(filename);//获取文件名或目录
    QStringList namefilters;//过滤器
    namefilters<<"*.mps";//过滤不是以.mp3结尾的文件
    QStringList files=dir.entryList(namefilters,QDir::Readable|QDir::Files,QDir::Name);
    //限定了条件
    //1、必须是过滤器过滤过的
    //2、必须是文件且可读
    //3、必须是以名称排序存储到files里的
    ui->listWidget->addItems(files);
    m_playpath=filename;
    QString pix=":/D:/picture/e0a07cd80e09495ea59e715ad48eee7a.png";
    ui->playinandpasue->setStyleSheet("QPushButton{ border-image: url("+pix+");}");
}

Success::~Success()
{
    delete ui;
}

void Success::on_playinandpasue_clicked()
{
     QString playingic=":/D:/picture/f58832cf01bd4177a00fbd0e2ebf7d6a (1).png";
      QString pausepic=":/D:/picture/e0a07cd80e09495ea59e715ad48eee7a.png";
    if(m_mediaplayer.state()==QMediaPlayer::PlayingState)//播放状态
    {
        m_mediaplayer.pause();

        ui->playinandpasue->setStyleSheet("QPushButton{ border-image: url("+pausepic+");}");
    }
    else {
        m_mediaplayer.play();

        ui->playinandpasue->setStyleSheet("QPushButton{ border-image: url("+playingic+");}");
    }
}



void Success::on_hprogress_sliderMoved(int position)
{
   m_mediaplayer.setPosition(m_mediaplayer.duration()*position/100);
}

void Success::on_vVolume_sliderMoved(int position)
{
     m_mediaplayer.setVolume(position);//设置音量的大小
}

void Success::on_btnadd_clicked()
{
    QString filename=QFileDialog::getExistingDirectory(NULL,"Select Music Dir",".",NULL);
    QDir dir(filename);
    QStringList namefilters;
    namefilters<<"*.mp3";
    QStringList files=dir.entryList(namefilters,QDir::Files|QDir::Readable,QDir::Name);
    //跟上面一样的
    ui->listWidget->addItems(files);
    this->m_playpath=filename;
}

void Success::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //这是一个双击播放音乐的函数
    //先获取row的数据
    this->Playrow=ui->listWidget->row(item);//更新索引
    m_mediaplayer.stop();//停止音乐的播放
    m_mediaplayer.setMedia(QUrl::fromLocalFile(this->m_playpath+"/"+item->text()));
    //设置了媒体源，在m_playpath目录下获取item文件
    m_mediaplayer.play();//播放这个双击了的歌
    ui->hprogress->setValue(m_mediaplayer.position());
    //将m_mediaplayer播放的位置返回给滑动条，让滑动条显示出来
    //下面设置控制播放时长以及进度的槽函数
    connect(timer,SIGNAL(timeout()),this,SLOT(setSliderValue()));
    connect(&m_mediaplayer,SIGNAL(durationChanged(qint64)),this,SLOT(getduration()));
    connect(&m_mediaplayer,SIGNAL(positionChanged(qint64)),this,SLOT(setPlayTime()));
}
void Success::setSliderValue()
{
    ui->hprogress->setValue(m_mediaplayer.position()*100/m_mediaplayer.duration());
    if(m_mediaplayer.position()>=m_mediaplayer.duration())
    {
        on_btnNext_clicked();
    }
}

void Success::on_btnPre_clicked()
{
    if(this->Playrow==0)
    {
        this->Playrow=ui->listWidget->count()-1;//如果是第一个索引的话，回退到目录的最后一个
    }
    else {
       this->Playrow--;//不是的话就-1；
    }
    //更新设计里的索引
    QListWidgetItem *item=ui->listWidget->item(Playrow);
    item->setSelected(true);//设置成选中状态
    m_mediaplayer.stop();//停止播放
    m_mediaplayer.setMedia(QUrl::fromLocalFile(this->m_playpath+"/"+item->text()));
    //设置媒体源为当前索引所在的歌曲
    m_mediaplayer.play();//播放
}

void Success::on_btnNext_clicked()
{
    if(this->Playrow==ui->listWidget->count()-1)//最后一首
    {
        this->Playrow=0;//回退到第一首
        //这里索引的性质与数组下标的性质是一样的
    }
    else {
       this->Playrow++;
    }
    QListWidgetItem *item=ui->listWidget->item(Playrow);
    item->setSelected(true);
    m_mediaplayer.stop();
    m_mediaplayer.setMedia(QUrl::fromLocalFile(m_playpath+"/"+item->text()));
    m_mediaplayer.play();
}
void Success::getduration()
{
    this->Playtime=m_mediaplayer.duration();
    ui->lblplaytime->setText(settime(Playtime));
}
void Success::setPlayTime()
{
    ui->lblmusictime->setText(settime(m_mediaplayer.position()));
}
QString Success::settime(int time)
{
    int h,m,s;
    time/=1000;
    h=time/3600;
    m=(time-h*3600)/60;
    s=time-h*3600-m*60;
    return QString("%1:%2:%3").arg(h).arg(m).arg(s);
}

void Success::on_btnvolume_clicked()
{
   if(ui->vVolume->isVisible())
   {
       ui->vVolume->setVisible(false);
   }
   else {
       ui->vVolume->setVisible(true);
   }
}

void Success::on_vVolume_sliderReleased()
{
    ui->vVolume->setVisible(false);
}
