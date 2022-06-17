#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "concreteproducts.h"

#include <QMainWindow>
#include <QStandardItemModel>
#include <QList>
#include <QSortFilterProxyModel>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class tableModel;
class QActionGroup;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered(); //открытие файла
    void on_actionSave_triggered(); //сохранение файла
    void on_actionExit_triggered(); //выход
    void on_actionAboutTheApp_triggered(); //вывод информации о программе
    void on_actionAdd_triggered(); //добавление записи
    void on_actionEdit_triggered(); //редактирование записи
    void on_actionDelete_triggered(); //удаление записи
    void contextMenu(QPoint cMenu); //контекстное меню
    void on_checkBox_stateChanged(int arg1); //включение/отключение сортировки
    void sortingMin();
    void sortingMax();
    void sortingMin(int); //сортировка в порядке возрастания
    void sortingMax(int); //сортировка в порядке убывания
    void searcing(); //поиск
    void on_actionAdd_new_window_triggered(); //добавление нового окна
    void switchLanguage(QAction *action); //изменение языка

private:
    Ui::MainWindow *ui;
    QMainWindow window;

    bool edited; //переменная для отслеживания изменений

    tableModel *model;
    concreteProducts setData(QString line); //для считывания и помещения данных в модель

    QTranslator appTranslator; //перевод приложения
    QTranslator qtTranslator; //перевод стандартных фраз

    QActionGroup *languageActionGroup;

    QString qmPath; //хранение пути к файлам

    void loadFile(const QString &fileName); //чтение данных из файла
    void saveFile(const QString &fileName); //закрузка данных в файл
    void askToSave(); //возникает, если пользователь не сохранял файл и хочет его закрыть
    void notSelected(); //возникает, если пользователь не указал, какую строку он хочет удалить/изменить
    void readSettings(); //настройки
    void writeSettings();
    void createLanguageMenu(); //создание динамического языкового меню

};
#endif // MAINWINDOW_H
