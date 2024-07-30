#ifndef CONCRETEPRODUCTS_H
#define CONCRETEPRODUCTS_H

#include <iostream>
#include <QString>

/**
 * @brief The concreteProducts class - класс для инициализации значений
 */

class concreteProducts //класс с данными по железобетонным изделиям
{
    int id; //ID
    QString name; //название
    QString producer; //производитель
    QString article; //артикул
    int sum; //кол-во
    int weight; //вес
    int price; //цена

public:
    concreteProducts();

    /**
     * @brief concreteProducts - конструктор класса для инициализации значений
     * @param lid - уникальный индентификатор
     * @param lname - название
     * @param lproducer - производитель
     * @param larticle - артикул
     * @param lsum - количество
     * @param lweight - вес одного изделия
     * @param lprice - цена за одно изделие
     */

    concreteProducts(const int lid,
                     const QString lname,
                     const QString lproducer,
                     const QString larticle,
                     const int lsum,
                     const int lweight,
                     const int lprice);
    ~concreteProducts();

    //методы для задания новых значений

    /**
     * @brief setID - принимает значение индентификатора
     * @param lid - индентификатор
     */
    void setID(const int lid);

    /**
     * @brief setName - принимает название
     * @param lname - название
     */

    void setName(const QString &lname);

    /**
     * @brief setProducer - принимает производителя
     * @param lproducer - производитель
     */

    void setProducer(const QString &lproducer);

    /**
     * @brief setArticle - принимает артикул
     * @param larticle - артикул
     */

    void setArticle(const QString &larticle);

    /**
     * @brief setSum - принимает количество
     * @param lsum - количество
     */

    void setSum(const int lsum);

    /**
     * @brief setWeight - устанавливает вес одного изделия
     * @param lweight - вес одного изделия
     */

    void setWeight(const int lweight);

    /**
     * @brief setPrice - принимает значение цены за одно изделие
     * @param lprice - цена за одно изделие
     */

    void setPrice(const int lprice);

    //методы для получения существующих значений

    /**
     * @brief getID - возвращает значение индентификатора
     * @return индентификатор
     */

    int getID() const;

    /**
     * @brief getName - возвращает название
     * @return название
     */

    QString getName() const;

    /**
     * @brief getProducer - возвращает производителя
     * @return производитель
     */

    QString getProducer() const;

    /**
     * @brief getArticle - возвращает артикул
     * @return артикул
     */

    QString getArticle() const;

    /**
     * @brief getSum - возвращает количество
     * @return количество
     */

    int getSum() const;

    /**
     * @brief getWeight - возвращает вес одного изделия
     * @return вес одного изделия
     */

    int getWeight() const;

    /**
     * @brief getPrice - возвращает цену за одно изделие
     * @return цена за одно изделие
     */

    int getPrice() const;

};

#endif // CONCRETEPRODUCTS_H
