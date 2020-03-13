#include "Ball.h"

#include <QVariant>

namespace QtJsonExample
{

Ball::Ball() = default;

Ball::Ball(qint32 id, double radius, QString description, bool isUseable)
    : description_{description}, id_{id}, isUseable_{isUseable}, radius_{radius}
{
}

Ball::Ball(QJsonObject object) { read(object); }

void Ball::read(const QJsonObject &jsonObject)
{
    if (jsonObject.contains("description") &&
        jsonObject["description"].isString())
    {
        description_ = jsonObject["description"].toString();
    }

    if (jsonObject.contains("id") && jsonObject["id"].isDouble())
    {
        id_ = jsonObject["id"].toInt();
    }

    if (jsonObject.contains("isUseable") && jsonObject["isUseable"].isBool())
    {
        isUseable_ = jsonObject["isUseable"].toBool();
    }
    if (jsonObject.contains("radius") && jsonObject["radius"].isDouble())
    {
        radius_ = jsonObject["radius"].toDouble();
    }
}

QString Ball::toString() const
{
    return QString{"Ball(id: %1, radius: %2, description: %3, isUseable: %4)"}
        .arg(id_)
        .arg(radius_)
        .arg(description_)
        .arg(QVariant{isUseable_}.toInt());
}

void Ball::write(QJsonObject &jsonObject) const
{
    jsonObject["description"] = description_;
    jsonObject["id"] = id_;
    jsonObject["isUseable"] = isUseable_;
    jsonObject["radius"] = radius_;
}

} // namespace QtJsonExample
