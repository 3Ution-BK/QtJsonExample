#include "Box.h"

#include "utility"

namespace QtJsonExample
{

Box::Box() = default;

Box::Box(qint32 id, QString description)
    : description_{description}, id_{id}, stuff_{}
{
}

void Box::add(const Ball &x) { stuff_.push_back(x); }

void Box::add(Ball &&x) { stuff_.push_back(std::move(x)); }

void Box::add(const QVector<Ball> &x) { stuff_.append(x); }

void Box::clear() { stuff_.clear(); }

void Box::read(const QJsonObject &jsonObject)
{
    if (jsonObject.contains("stuff") && jsonObject["stuff"].isArray())
    {
        QJsonArray stuff = jsonObject["stuff"].toArray();
        stuff_.clear();
        stuff_.reserve(stuff.size());
        for (auto x : stuff)
        {
            Ball ball{x.toObject()};
            stuff_.push_back(ball);
        }
    }

    if (jsonObject.contains("description") &&
        jsonObject["description"].isString())
    {
        description_ = jsonObject["description"].toString();
    }

    if (jsonObject.contains("id") && jsonObject["id"].isDouble())
    {
        id_ = jsonObject["id"].toInt();
    }
}

QString Box::toString() const
{
    QString stuffString;
    QTextStream stuffStream{&stuffString};

    for (auto &x : stuff_)
    {
        stuffStream << x.toString();
    }

    return QString{"Box(id: %1, description: %2, stuff: %3)"}
        .arg(id_)
        .arg(description_)
        .arg(stuffStream.readAll());
}

void Box::write(QJsonObject &jsonObject) const
{
    jsonObject["description"] = description_;
    jsonObject["id"] = id_;

    QJsonArray stuff;
    for (auto &x : stuff_)
    {
        QJsonObject object;
        x.write(object);
        stuff.push_back(object);
    }
    jsonObject["stuff"] = stuff;
}

} // namespace QtJsonExample
