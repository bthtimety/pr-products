/*класс для обеспечения модели данных для решения пользователем
 * практической задачи учёта */

#ifndef CONCRETEPRODUCTS_H
#define CONCRETEPRODUCTS_H

#include <iostream>
#include <QString>

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
    concreteProducts(const int lid,
                     const QString lname,
                     const QString lproducer,
                     const QString larticle,
                     const int lsum,
                     const int lweight,
                     const int lprice);
    ~concreteProducts();

    //методы для задания новых значений
    void setID(const int lid);
    void setName(const QString &lname);
    void setProducer(const QString &lproducer);
    void setArticle(const QString &larticle);
    void setSum(const int lsum);
    void setWeight(const int lweight);
    void setPrice(const int lprice);

    //методы для получения существующих значений
    int getID() const;
    QString getName() const;
    QString getProducer() const;
    QString getArticle() const;
    int getSum() const;
    int getWeight() const;
    int getPrice() const;

};

#endif // CONCRETEPRODUCTS_H
