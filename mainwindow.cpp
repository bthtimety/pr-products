#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tablemodel.h"
#include "dialogdelete.h"
#include "dialogedit.h"
#include "dialogredaction.h"
#include "sorting.cpp"
#include "delegates.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QApplication>
#include <iostream>
#include <QTableView>
#include <QMenu>
#include <QSettings>
#include <QLibraryInfo>
#include <QDebug>
#include <QSortFilterProxyModel>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , edited(false)
    , model(new tableModel(this))
{
    ui->setupUi(this);
    setWindowTitle(tr("Concrete products data base"));
    ui->tableView->setModel(model);

    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    //подключение контектного меню
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView,SIGNAL(customContextMenuRequested(QPoint)), this,
            SLOT(contextMenu(QPoint)));
    ui->tableView->setSortingEnabled(true);

    connect(ui->lineEdit_1, &QLineEdit::textChanged, this, &MainWindow::searcing);
    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, &MainWindow::searcing);
    connect(ui->lineEdit_3, &QLineEdit::textChanged, this, &MainWindow::searcing);

    delegates *prodDelegate = new delegates(ui->tableView);
    prodDelegate->setData(QStringList({ "Белоусовский завод"
                                      , "Ивантеевский завод"
                                      , "Рязанский завод"
                                      , "Ржевский завод"
                                      , "Волжский завод"
                                      , "Казанский завод"
                                      , "Московский завод"
                                      , "Очаковский завод"
                                      }));
    ui->tableView->setItemDelegateForColumn(2, prodDelegate);

    for(int i = 0; i < 7 ; i++) {
            ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
            ui->tableView->horizontalHeader()->resizeSection(i, 100);
    }

    readSettings();

    qApp->installTranslator(&appTranslator);
    qApp->installTranslator(&qtTranslator);
    qmPath = qApp->applicationDirPath() + "/tr";
    createLanguageMenu();
}

MainWindow::~MainWindow()
{
    if(edited) askToSave();
    writeSettings();
    delete model;
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    if(edited) askToSave(); //если в предыдущий файл вносились изменения, то программа предложит их сохранить

    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) //проверка, выбрал ли пользователь какой-нибудь файл
        loadFile(fileName);
}

void MainWindow::loadFile(const QString &fileName)
{
    model->list.clear(); //очищает то что было
    if(edited) edited = false;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,
                             tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file); //создание потока на чтение

    QApplication::setOverrideCursor(Qt::WaitCursor); //вид часов ожидания для указателя мыши

    while (!in.atEnd()) { //считывание данных
             QString line = in.readLine();
             if(line.isEmpty()) continue;
             model->list << setData(line);
    }
    model->newModel();
    file.close();

    QApplication::restoreOverrideCursor(); //возвращаем прежний вид курсора

    ui->actionEdit->setEnabled(model); //делаем кнопки "изменить" и "удалить" кликабельными
    ui->actionDelete->setEnabled(model);
}


void MainWindow::on_actionSave_triggered()
{

    if(edited) edited = false;
    QString fileName = QFileDialog::getSaveFileName(this);
    if(!fileName.isEmpty())
        saveFile(fileName);
}

void MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this,
                                 tr("Application"),
                                 tr("Cannot write file %1:\n%2.")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return;
        }

        QTextStream out(&file); //создание потока на запись

        for(int i=0; i<model->list.length(); i++) {
            out << model->list[i].getID() << ";"
                        << model->list[i].getName() << ";"
                        << model->list[i].getProducer() << ";"
                        << model->list[i].getArticle() << ";"
                        << model->list[i].getSum() << ";"
                        << model->list[i].getWeight() << ";"
                        << model->list[i].getPrice() << ";"
                        << Qt::endl;
        }
        file.close();
}

void MainWindow::askToSave()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  tr("Save this file?"),
                                  tr("Do you want to save changes?"),
                                  QMessageBox::Yes |
                                  QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        on_actionSave_triggered();
    }
    else return;
}


void MainWindow::on_actionExit_triggered()
{
    if(edited) askToSave(); //если в файл вносились изменения, то программа предложит их сохранить
    edited = false;
    this->close();
}


void MainWindow::on_actionAboutTheApp_triggered()
{
    QMessageBox::about(this, tr("About the app"),
                             tr("This program was developed for the accounting of concrete products.\n"
                                "Developer: the student of ICTMS-2-8 Zaytseva Anastasia Alekseevna."));
}

concreteProducts MainWindow::setData(QString line)
{
    const int col = 7;
    concreteProducts data;
    QString arr[col];
    int index[col+1];
    index[0] = -1;
    int j = 1;
    for(int i=0; i < (int)line.length(); i++) {
        if(line[i] == ';') {
            index[j]=i;
            j++;
        }
    }
    for(int i=0; i<col; i++) {
        arr[i] = line.mid(index[i]+1, index[i+1]-index[i]-1);
    }
    data.setID(arr[0].toInt());
    data.setName(arr[1]);
    data.setProducer(arr[2]);
    data.setArticle(arr[3]);
    data.setSum(arr[4].toInt());
    data.setWeight(arr[5].toInt());
    data.setPrice(arr[6].toInt());
    return data;
}

void MainWindow::on_actionAdd_triggered()
{
    dialogRedaction add(this);
    add.exec();
    if(add.result() == dialogRedaction::Rejected)
        return;
    model->list << add.getRow();
    model->newModel();
    edited = true;
}


void MainWindow::on_actionEdit_triggered()
{
    dialogEdit select;
    bool check = false;
    int selected;
    while(check == false) {
        if(select.exec())
            selected = select.num()-1;
        if(select.result() == dialogEdit::Rejected) return;
        if(selected < 0 || selected >= model->list.count()) {
            notSelected();
            check = false;
        }
        else check = true;
    }
    dialogRedaction edit(this);
    edit.exec();
    if(edit.result() == dialogRedaction::Rejected)
        return;
    model->list.replace(selected, edit.getRow());
    model->newModel();
    edited = true;
}


void MainWindow::on_actionDelete_triggered()
{
    dialogDelete select;
    bool check = false;
    int selected;
    while(check == false) {
        if(select.exec())
            selected = select.num()-1;
        if(select.result() == dialogDelete::Rejected) return;
        if(selected < 0 || selected >= model->list.count()) {
            notSelected();
            check = false;
        }
        else check = true;
    }
    model->list.removeAt(selected);
    model->newModel();
    edited = true;
}

void MainWindow::notSelected()
{
        QMessageBox message;
        QMessageBox::StandardButton reply;
        reply = QMessageBox::critical(this,
                                      tr("Error"),
                                      tr("Selected row doesn't exist! Please, try again."),
                                      QMessageBox::Ok |
                                      QMessageBox::Cancel);

        message.setDefaultButton(QMessageBox::Ok);
        if(reply == QMessageBox::Ok) return;
        else return;
}

void MainWindow::readSettings()
{
    QSettings settings("Home","pr-products");
    settings.beginGroup("MainWindowGeometry");
    resize(settings.value("Size", QSize(1000, 800)).toSize()); //сброс размеров окна
    move(settings.value("Position", QPoint(800, 500 )).toPoint()); //сброс положения левой верхней точки
}

void MainWindow::writeSettings()
{
    QSettings settings("Home","pr-products");
    settings.beginGroup("MainWindowGeometry");
    settings.setValue("Size", size());
    settings.setValue("Position", pos());
    settings.endGroup();
}

void MainWindow::contextMenu(QPoint cMenu)
{
    QMenu *menu = new QMenu(this);
    menu->addAction(ui->actionAdd);
    menu->addAction(ui->actionEdit);
    menu->addAction(ui->actionDelete);
    menu->popup(ui->tableView->viewport()->mapToGlobal(cMenu));
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1) {
        QSortFilterProxyModel *proxymodel= new QSortFilterProxyModel(this);
        proxymodel->setSourceModel(model);
        ui->tableView->setModel(proxymodel);
    }
    else
        ui->tableView->setModel(model);
}

void MainWindow::sortingMin()
{
    sortingMin(ui->tableView->currentIndex().column());
}

void MainWindow::sortingMax()
{
    sortingMax(ui->tableView->currentIndex().column());
}

void MainWindow::sortingMin(int column) {
    switch(column)   {
    case 0: std::sort(model->list.begin(),model->list.end(),sortIDMin);
        break;
    case 1: std::sort(model->list.begin(),model->list.end(),sortNameMin);
        break;
    case 2: std::sort(model->list.begin(),model->list.end(),sortProducerMin);
        break;
    case 3: std::sort(model->list.begin(),model->list.end(),sortArticleMin);
        break;
    case 4: std::sort(model->list.begin(),model->list.end(),sortSumMin);
        break;
    case 5: std::sort(model->list.begin(),model->list.end(),sortWeightMin);
        break;
    case 6: std::sort(model->list.begin(),model->list.end(),sortPriceMin);
        break;
    }
}

void MainWindow::sortingMax(int column)
{
    switch(column) {
    case 0: std::sort(model->list.begin(),model->list.end(),sortIDMax);
        break;
    case 1: std::sort(model->list.begin(),model->list.end(),sortNameMax);
        break;
    case 2: std::sort(model->list.begin(),model->list.end(),sortProducerMax);
        break;
    case 3: std::sort(model->list.begin(),model->list.end(),sortArticleMax);
        break;
    case 4: std::sort(model->list.begin(),model->list.end(),sortSumMax);
        break;
    case 5: std::sort(model->list.begin(),model->list.end(),sortWeightMax);
        break;
    case 6: std::sort(model->list.begin(),model->list.end(),sortPriceMax);
        break;
    }
}

void MainWindow::searcing()
{
    QString searchID = ui->lineEdit_1->text(); //поиск по ID
    QString searchName = ui->lineEdit_2->text(); //поиск по наименованию
    QString searchProducer = ui->lineEdit_3->text(); //поиск по производителю

    int rows = ui->tableView->model()->rowCount();
    for (int i=0; i<rows; i++) {
        QAbstractItemModel *abstractModel = ui->tableView->model();
        QString id = abstractModel->data(abstractModel->index( i, 0, QModelIndex())).toString();
        QString name = abstractModel->data(abstractModel->index( i, 1, QModelIndex())).toString();
        QString producer = abstractModel->data(abstractModel->index( i, 2, QModelIndex())).toString();

        bool flag = true;

        if(searchID == "" || id.contains(searchID)) flag&=true; else flag&=false;
        if(searchName == "" || name.contains(searchName)) flag&=true; else flag&=false;
        if(searchProducer == "" || producer.contains(searchProducer)) flag&=true; else flag&=false;
        if(flag)
            ui->tableView->showRow(i); //показывает то, что удовлетворяет поиску
        else
            ui->tableView->hideRow(i); //и скрывает то, что не удовлетворяет
    }
}


void MainWindow::on_actionAdd_new_window_triggered()
{
    MainWindow * k = new MainWindow;
    k->show();
}

void MainWindow::switchLanguage(QAction *action)
{
    QString locale = action->data().toString();
    appTranslator.load("pr-products_" + locale + ".qm", qmPath);
    locale.chop(3);
    qtTranslator.load("qt_" + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    ui->retranslateUi(this);
    setWindowTitle(tr("Concrete products data base"));
}

void MainWindow::createLanguageMenu()
{
    languageActionGroup = new QActionGroup(this);
    connect(languageActionGroup, &QActionGroup::triggered, this, &MainWindow::switchLanguage);

    QDir dir(qmPath);

    QStringList fileNames = dir.entryList(QStringList("pr-products_*.qm"));
    for (int i = 0; i < fileNames.size(); i++) {
        QString locale = fileNames[i];
        locale.remove(0, locale.indexOf('_') + 1);
        locale.truncate(locale.lastIndexOf('.'));
        QTranslator translator;
        translator.load(fileNames[i], qmPath);

        QString language = translator.translate("MainWindow", "English");
        QAction *action = new QAction(tr("&%1 %2").arg(i + 1).arg(language), this);

        action->setCheckable(true);
        action->setData(locale);

        ui->menuLanguage->addAction(action);
        languageActionGroup->addAction(action);

        if (language == "English")
            action->setChecked(true);
    }
}
