#ifndef ABSTRACTSERIALIZATOR_H
#define ABSTRACTSERIALIZATOR_H

#include <QtXml/QtXml>
#include <QtXmlPatterns/QtXmlPatterns>
#include <QString>
#include <QList>
#include <QStringList>
#include <QFile>

#include "../DataClasses/dataclasses.h"

class AbstractSerializator
{
public:
    AbstractSerializator();

protected:
    QXmlSchema xmlSchema;

    virtual QDomDocument loadXml(const QString &filename) throw (Exception);
    virtual void loadXmlSchema(const QString &file) throw (Exception);
    virtual bool checkXml(const QDomDocument &xml) const;

    virtual QStringList getElementsContent(const QDomElement &element, const QString &tagname);
    virtual QDomDocumentFragment setElementsContent(const QStringList &elements, const QString &tagname);

    QDomDocument resultXml;
};

#endif // ABSTRACTSERIALIZATOR_H
