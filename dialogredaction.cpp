#include "dialogredaction.h"
#include "ui_dialogredaction.h"

dialogRedaction::dialogRedaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogRedaction)
{
    ui->setupUi(this);
    setWindowTitle(tr("Redaction"));
}

dialogRedaction::~dialogRedaction()
{
    delete ui;
}

void dialogRedaction::newData()
{
    ui->lineEditID->setText(QString::number(Row.getID()));
    ui->lineEditName->setText(Row.getName());
    ui->lineEditProducer->setText(Row.getProducer());
    ui->lineEditArticle->setText(Row.getArticle());
    ui->lineEditSum->setText(QString::number(Row.getSum()));
    ui->lineEditWeight->setText(QString::number(Row.getWeight()));
    ui->lineEditPrice->setText(QString::number(Row.getPrice()));
}

void dialogRedaction::setRow(const concreteProducts lRow)
{
    Row = lRow;
}

concreteProducts dialogRedaction::getRow() const
{
    return Row;
}

void dialogRedaction::on_pushButtonOk_clicked()
{
    Row.setID(ui->lineEditID->text().toInt());
    Row.setName(ui->lineEditName->text());
    Row.setProducer(ui->lineEditProducer->text());
    Row.setArticle(ui->lineEditArticle->text());
    Row.setSum(ui->lineEditSum->text().toInt());
    Row.setWeight(ui->lineEditWeight->text().toInt());
    Row.setPrice(ui->lineEditPrice->text().toInt());

    this->accept();
}


void dialogRedaction::on_pushButtonCancel_clicked()
{
    this->reject();
}

