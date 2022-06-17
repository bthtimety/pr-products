/* класс, обеспечивающий сортировку данных */

#include "concreteproducts.h"

bool sortIDMin(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getID() < v2.getID();
}

bool sortIDMax(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getID() > v2.getID();
}

bool sortNameMin(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getName() < v2.getName();
}

bool sortNameMax(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getName() > v2.getName();
}

bool sortProducerMin(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getProducer() < v2.getProducer();
}

bool sortProducerMax(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getProducer() > v2.getProducer();
}

bool sortArticleMin(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getArticle() < v2.getArticle();
}

bool sortArticleMax(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getArticle() > v2.getArticle();
}

bool sortSumMin(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getSum() < v2.getSum();
}

bool sortSumMax(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getSum() > v2.getSum();
}

bool sortWeightMin(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getWeight() < v2.getWeight();
}

bool sortWeightMax(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getWeight() > v2.getWeight();
}

bool sortPriceMin(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getPrice() < v2.getPrice();
}

bool sortPriceMax(const concreteProducts &v1, const concreteProducts &v2)
{
    return v1.getPrice() > v2.getPrice();
}
