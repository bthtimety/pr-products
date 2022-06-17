#include "concreteproducts.h"

concreteProducts::concreteProducts():
    id(),
    name(),
    producer(),
    article(),
    sum(),
    weight(),
    price()
{

}

concreteProducts::concreteProducts(const int lid,
                                   const QString lname,
                                   const QString lproducer,
                                   const QString larticle,
                                   const int lsum,
                                   const int lweight,
                                   const int lprice):
    id(lid),
    name(lname),
    producer(lproducer),
    article(larticle),
    sum(lsum),
    weight(lweight),
    price(lprice)
{

}

concreteProducts::~concreteProducts()
{

}

void concreteProducts::setID(const int lid)
{
    id = lid;
}

void concreteProducts::setName(const QString &lname)
{
    name = lname;
}

void concreteProducts::setProducer(const QString &lproducer)
{
    producer = lproducer;
}

void concreteProducts::setArticle(const QString &larticle)
{
    article = larticle;
}

void concreteProducts::setSum(const int lsum)
{
    sum = lsum;
}

void concreteProducts::setWeight(const int lweight)
{
    weight = lweight;
}

void concreteProducts::setPrice(const int lprice)
{
    price = lprice;
}

int concreteProducts::getID() const
{
    return id;
}

QString concreteProducts::getName() const
{
    return name;
}

QString concreteProducts::getProducer() const
{
    return producer;
}

QString concreteProducts::getArticle() const
{
    return article;
}

int concreteProducts::getSum() const
{
    return sum;
}

int concreteProducts::getWeight() const
{
    return weight;
}

int concreteProducts::getPrice() const
{
    return price;
}
