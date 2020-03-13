#include "Randomizer.h"

#include "DataType/Ball/Ball.h"

#include <QRandomGenerator>

namespace QtJsonExample
{

namespace
{

Ball randomBall(qint32 id);
bool randomBool();
double randomDouble();
qint32 randomInt();
QString randomString(int min = 5, int max = 20);

const char charSet[]{"0123456789"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "abcdefghijklmnopqrstuvwxyz"};

constexpr int maxSize{100};

Ball randomBall(qint32 id)
{
    return Ball{id, randomDouble(), randomString(), randomBool()};
}

bool randomBool() { return randomInt() % 2; }

double randomDouble() { return QRandomGenerator::global()->generateDouble(); }

qint32 randomInt() { return QRandomGenerator::global()->generate(); }

QString randomString(int min, int max)
{
    QString str;
    int length = QRandomGenerator::global()->bounded(min, max);

    for (int iter = 0; iter < length; ++iter)
    {
        str.append(charSet[QRandomGenerator::global()->bounded(
            static_cast<int>(sizeof(charSet) - 1))]);
    }
    return str;
}

} // namespace

Box randomBox(qint32 id)
{
    Box box{id, randomString()};
    qint32 size{QRandomGenerator::global()->bounded(maxSize)};

    for (qint32 iter{0}; iter < size; ++iter)
    {
        Ball ball{randomBall(iter)};
        box.add(ball);
    }

    return box;
}

} // namespace QtJsonExample
