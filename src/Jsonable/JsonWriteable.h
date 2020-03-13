#ifndef QTJSONEXAMPLE_JSONACTION_JSONWRITEABLE_H_
#define QTJSONEXAMPLE_JSONACTION_JSONWRITEABLE_H_

#include <QJsonObject>

namespace QtJsonExample
{

class JsonWriteable
{
public:
    virtual void write(QJsonObject &jsonObject) const = 0;
};

} // namespace QtJsonExample

#endif // QTJSONEXAMPLE_JSONACTION_JSONWRITEABLE_H_
