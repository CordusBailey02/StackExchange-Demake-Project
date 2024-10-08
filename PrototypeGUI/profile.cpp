#include "profile.h"
#include "ui_profile.h"
#include <QPixmap>
#include <QIcon>

Profile::Profile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Profile)
{
    ui->setupUi(this);

    QPixmap pix3("C:/Users/ldura/Pictures/Bacc Pics/ae.jpg");
    QIcon ButtonIcon(pix3);
    ui->pushButton_profilePic->setIcon(ButtonIcon);
    ui->pushButton_profilePic->setIconSize(QSize(150,150));
    //ui->pushButton_profilePic->setPixmap(pix3.scaled(100,100,Qt::KeepAspectRatio));
}

Profile::~Profile()
{
    delete ui;
}

void Profile::on_listWidget_postsFromProfile_itemDoubleClicked(QListWidgetItem *item)
{
    item->text();
    post_3 = new Post_1(this);
    post_3->show();
}


void Profile::on_listWidget_commentsFromProfile_itemDoubleClicked(QListWidgetItem *item)
{
    item->text();
    comment_3 = new comment_1(this);
    comment_3->show();
}

