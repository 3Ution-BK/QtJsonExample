#ifndef QTJSONEXAMPLE_JSONACTION_JSONREADABLE_H_
#define QTJSONEXAMPLE_JSONACTION_JSONREADABLE_H_

#include <QJsonObject>

namespace QtJsonExample
{

class JsonReadable
{
public:
    virtual void read(const QJsonObject &jsonObject) = 0;
};

} // namespace QtJsonExample

#endif // QTJSONEXAMPLE_JSONACTION_JSONREADABLE_H_
