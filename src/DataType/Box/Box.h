#ifndef QTJSONEXAMPLE_DATATYPE_BOX_H_
#define QTJSONEXAMPLE_DATATYPE_BOX_H_

#include "DataType/Ball/Ball.h"
#include "Jsonable/JsonReadWriteable.h"

#include <QDataStream>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QTextStream>
#include <QVector>
#include <QtGlobal>

namespace QtJsonExample
{

class Box : public JsonReadWriteable
{
public:
    explicit Box();
    explicit Box(qint32 id, QString description);

    void add(const Ball &x);
    void add(Ball &&x);
    void add(const QVector<Ball> &x);
    void clear();
    Q_DECL_CONSTEXPR QString &description();
    Q_DECL_CONSTEXPR const QString &description() const;
    Q_DECL_CONSTEXPR qint32 &id();
    Q_DECL_CONSTEXPR const qint32 &id() const;
    void read(const QJsonObject &jsonObject) override;
    void setDescription(QString description);
    void setId(qint32 id);
    Q_DECL_CONSTEXPR QVector<Ball> &stuff();
    Q_DECL_CONSTEXPR const QVector<Ball> &stuff() const;
    QString toString() const;
    void write(QJsonObject &jsonObject) const override;

    friend QDataStream &operator<<(QDataStream &out, const Box &box);

private:
    QString description_;
    qint32 id_;
    QVector<Ball> stuff_;
};

Q_DECL_CONSTEXPR inline QString &Box::description() { return description_; }

Q_DECL_CONSTEXPR inline const QString &Box::description() const
{
    return description_;
}

Q_DECL_CONSTEXPR inline qint32 &Box::id() { return id_; }

Q_DECL_CONSTEXPR inline const qint32 &Box::id() const { return id_; }

inline void Box::setDescription(QString description)
{
    description_ = description;
}

inline void Box::setId(qint32 id) { id_ = id; }

Q_DECL_CONSTEXPR inline QVector<Ball> &Box::stuff() { return stuff_; }

Q_DECL_CONSTEXPR inline const QVector<Ball> &Box::stuff() const
{
    return stuff_;
}

inline QDataStream &operator<<(QDataStream &out, const Box &box)
{
    out << box.toString();

    return out;
}

} // namespace QtJsonExample

#endif // QTJSONEXAMPLE_DATATYPE_BOX_H_
