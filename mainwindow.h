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


/**
 * @brief The MainWindow class - класс главного окна
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Конструктор MainWindow
     * @param parent - указатель на родителя объекта
     */

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /**
     * @brief on_actionOpen_triggered - функция открытия файла
     */

    void on_actionOpen_triggered(); //открытие файла

    /**
     * @brief on_actionSave_triggered - функция сохранения файла
     */

    void on_actionSave_triggered(); //сохранение файла

    /**
     * @brief on_actionExit_triggered - функция выхода из программы
     */

    void on_actionExit_triggered(); //выход

    /**
     * @brief on_actionAboutTheApp_triggered - функция вывода информации о программе
     */

    void on_actionAboutTheApp_triggered(); //вывод информации о программе

    /**
     * @brief on_actionAdd_triggered - функция добавления записи в файл
     */

    void on_actionAdd_triggered(); //добавление записи

    /**
     * @brief on_actionEdit_triggered - функция редактирования записи в файле
     */

    void on_actionEdit_triggered(); //редактирование записи

    /**
     * @brief on_actionDelete_triggered - функция удаления записи из файла
     */

    void on_actionDelete_triggered(); //удаление записи

    /**
     * @brief contextMenu - функция контектного меню
     * @param cMenu - указатель на меню
     */

    void contextMenu(QPoint cMenu); //контекстное меню

    /**
     * @brief on_checkBox_stateChanged - функция включения/отключения сортировки
     * @param arg1 - указатель на переключение
     */

    void on_checkBox_stateChanged(int arg1); //включение/отключение сортировки

    /**
     * @brief sortingMin - функция выбора колонки для сортировки в порядке возрастания
     */

    void sortingMin();

    /**
     * @brief sortingMax - функция выбора колонки для сортировки в порядке убывания
     */

    void sortingMax();

    /**
     * @brief sortingMin - функция сортировки в порядке возрастания
     */

    void sortingMin(int); //сортировка в порядке возрастания

    /**
     * @brief sortingMax - функция сортировки в порядке убывания
     */

    void sortingMax(int); //сортировка в порядке убывания

    /**
     * @brief searcing - функция поиска
     */

    void searcing(); //поиск

    /**
     * @brief on_actionAdd_new_window_triggered - функция добавления нового окна
     */

    void on_actionAdd_new_window_triggered(); //добавление нового окна

    /**
     * @brief switchLanguage - функция смены языка
     * @param action - переменная класса QAction
     */

    void switchLanguage(QAction *action); //изменение языка

private:
    Ui::MainWindow *ui;
    QMainWindow window;

    /**
     * @brief edited - переменная для отслеживания изменений в файле
     */

    bool edited; //переменная для отслеживания изменений

    /**
     * @brief model - указатель на класс tableModel
     */

    tableModel *model;

    /**
     * @brief setData - функция для помещения данных в моедль
     * @param line - переменная строки
     * @return данные для таблицы
     */

    concreteProducts setData(QString line); //для считывания и помещения данных в модель

    /**
     * @brief appTranslator - для перевода приложения
     */

    QTranslator appTranslator; //перевод приложения

    /**
     * @brief qtTranslator - для перевода стандартных фразы
     */

    QTranslator qtTranslator; //перевод стандартных фраз


    /**
     * @brief languageActionGroup - для перевода
     */

    QActionGroup *languageActionGroup;

    /**
     * @brief qmPath - хранение пути к файлам
     */

    QString qmPath; //хранение пути к файлам

    /**
     * @brief loadFile - функция чтения данных из файла
     * @param fileName - параметр для файла
     */

    void loadFile(const QString &fileName); //чтение данных из файла

    /**
     * @brief saveFile - функция выгрузки данных в файл
     * @param fileName - параметр для файла
     */

    void saveFile(const QString &fileName); //закрузка данных в файл

    /**
     * @brief askToSave - предложение сохранить файл
     */

    void askToSave(); //возникает, если пользователь не сохранял файл и хочет его закрыть

    /**
     * @brief notSelected - предупреждение о том, что пользователь не выбрал
     * строку для удаления или редактирования
     */

    void notSelected(); //возникает, если пользователь не указал, какую строку он хочет удалить/изменить

    /**
     * @brief readSettings - функция для настроек
     */

    void readSettings(); //настройки

    /**
     * @brief writeSettings - функция для установки настроек
     */

    void writeSettings();

    /**
     * @brief createLanguageMenu - функция для создания языкового меню
     */

    void createLanguageMenu(); //создание динамического языкового меню
};
#endif // MAINWINDOW_H
