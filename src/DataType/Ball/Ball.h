#ifndef QTJSONEXAMPLE_DATATYPE_BALL_BALL_H_
#define QTJSONEXAMPLE_DATATYPE_BALL_BALL_H_

#include "Jsonable/JsonReadWriteable.h"

#include <QDataStream>
#include <QJsonObject>
#include <QString>
#include <QtGlobal>

namespace QtJsonExample
{

class Ball : public JsonReadWriteable
{
public:
    explicit Ball();
    explicit Ball(qint32 id, double radius, QString description,
                  bool isUseable);
    explicit Ball(QJsonObject object);

    Q_DECL_CONSTEXPR QString &description();
    Q_DECL_CONSTEXPR const QString &description() const;
    Q_DECL_CONSTEXPR qint32 &id();
    Q_DECL_CONSTEXPR const qint32 &id() const;
    Q_DECL_CONSTEXPR bool &isUseable();
    Q_DECL_CONSTEXPR const bool &isUseable() const;
    Q_DECL_CONSTEXPR double &radius();
    Q_DECL_CONSTEXPR const double &radius() const;
    void read(const QJsonObject &jsonObject) override;
    void setDescription(QString description);
    void setId(qint32 id);
    void setRadius(double radius);
    QString toString() const;
    void write(QJsonObject &jsonObject) const override;

    friend QDataStream &operator<<(QDataStream &out, const Ball &ball);

private:
    QString description_;
    qint32 id_;
    bool isUseable_;
    double radius_;
};

Q_DECL_CONSTEXPR
inline QString &Ball::description() { return description_; }

Q_DECL_CONSTEXPR
inline const QString &Ball::description() const { return description_; }

Q_DECL_CONSTEXPR
inline qint32 &Ball::id() { return id_; }

Q_DECL_CONSTEXPR
inline const qint32 &Ball::id() const { return id_; }

Q_DECL_CONSTEXPR inline bool &Ball::isUseable() { return isUseable_; }

Q_DECL_CONSTEXPR inline const bool &Ball::isUseable() const
{
    return isUseable_;
}

Q_DECL_CONSTEXPR
inline double &Ball::radius() { return radius_; }

Q_DECL_CONSTEXPR
inline const double &Ball::radius() const { return radius_; }

inline void Ball::setDescription(QString description)
{
    description_ = description;
}

inline void Ball::setId(qint32 id) { id_ = id; }

inline void Ball::setRadius(double radius) { radius_ = radius; }

inline QDataStream &operator<<(QDataStream &out, const Ball &ball)
{
    out << ball.toString();

    return out;
}

} // namespace QtJsonExample

#endif // QTJSONEXAMPLE_DATATYPE_BALL_BALL_H_
