#include "AccountCode.h"
#include "ui_AccountCode.h"
#include <QMessageBox>

AccountCode::AccountCode(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AccountCode)
{
    ui->setupUi(this);

    //int codeFromClient = [integer] 4 digits


    /*

    int sendInt = send(int socket, void *data, size_t len, int flag);
    -1 -> something wrong
    0  -> no bytes received
    n  -> received n bytes

    int *accountCodeFromClient;

    int receiveInt = recv(int socket, *accountCodeFromClient, size_t len, int flag);

    */
}

AccountCode::~AccountCode()
{
    delete ui;
}

void AccountCode::on_pushButton_submitCode_clicked()
{
    if (ui->lineEdit_code->text().length() != 4)
    {
        QMessageBox::critical(this, "Incorrect Length", "Submitted code is not the correct length.");
    }
    else
    {
        bool ok;
        QString codeInText = ui->lineEdit_code->text();
        int codeInInteger = codeInText.toInt(&ok, 10);
        //QString codeInTextFromInteger = QString::number(codeInInteger);
        if (codeInInteger < 0)
        {
            QMessageBox::critical(this, "Sign Error", "Submitted code is negative.");
        }
        else if (codeInInteger == 0)
        {
            QMessageBox::critical(this, "Incorrect Format", "Submitted code is not a number.");
        }

        /*

        int sendInt = send(int socket, void *data, size_t len, int flag);

        int *accountCodeFromClient;

        int receiveInt = recv(int socket, *accountCodeFromClient, size_t len, int flag);

        if (codeInInteger == accountCodeFromClient)
        {
            QMessageBox::information(this, "Code Confirmed", "Your account has been verified and you can now login!");
            // send confirmation to client
        }

        */
    }
}