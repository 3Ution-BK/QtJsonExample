#include "DataType/Ball/Ball.h"
#include "DataType/Box/Box.h"
#include "Randomizer/Randomizer.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QtGlobal>

#include <cstdlib>

void read(QtJsonExample::Box &box, QString fileName);
void write(const QtJsonExample::Box &box, QString fileName);

int main(int argc, char *argv[])
{
    QString fileName{((argc < 2) ? "Box.json" : argv[1])};

    QtJsonExample::Box foo{QtJsonExample::randomBox(0)};
    write(foo, fileName);

    QtJsonExample::Box bar;
    read(bar, fileName);

    qInfo() << qUtf8Printable(bar.toString());

    return 0;
}

void read(QtJsonExample::Box &box, QString fileName)
{
    QFile fileObject{fileName};
    if (!fileObject.open(QIODevice::ReadOnly))
    {
        qWarning() << "Read file failed: Cannot open file";
        exit(EXIT_FAILURE);
    }

    QJsonDocument jsonDocument{QJsonDocument::fromJson(fileObject.readAll())};

    box.read(jsonDocument.object());
}

void write(const QtJsonExample::Box &box, QString fileName)
{
    QJsonObject jsonObject;
    box.write(jsonObject);

    QJsonDocument jsonDocument{jsonObject};
    QFile fileObject{fileName};

    if (!fileObject.open(QIODevice::WriteOnly))
    {
        qWarning() << "Write file failed: Cannot open file";
        exit(EXIT_FAILURE);
    }

    fileObject.write(jsonDocument.toJson());
    fileObject.close();
}
