#include "abstractserializator.h"

AbstractSerializator::AbstractSerializator()
{
}

void AbstractSerializator::loadXmlSchema(const QString &file) throw (Exception)
{
    QFile xsdFile(file);

    if (!xsdFile.open(QIODevice::ReadOnly))
    {
        throw Exception(Exception::FileOperationError, QString("Couldn't open file - " + file));
    }

    if (!xmlSchema.load(&xsdFile))
    {
        throw Exception(Exception::BadXMLFile, QString("Bad XML file - " + file));
    }

    if (!xmlSchema.isValid()) {
        throw Exception(Exception::BadXMLFile, "Bad XML file - " + file);
    }

    xsdFile.close();
}

bool AbstractSerializator::checkXml(const QDomDocument &xml) const
{
    QXmlSchemaValidator validator(xmlSchema);
    if (!validator.validate(xml.toByteArray())) {
        return false;
    }
    return true;
}

QStringList AbstractSerializator::getElementsContent(const QDomElement &element, const QString &tagname)
{
    QStringList result;

    QDomNodeList tags = element.elementsByTagName(tagname);

    for (int i = 0; i < tags.length(); i++)
    {
        result.append(tags.at(i).toElement().text());
    }

    return result;
}


QDomDocument AbstractSerializator::loadXml(const QString &filename) throw (Exception)
{
    QFile xmlFile(filename);
    QDomDocument result;

    if (!xmlFile.open(QIODevice::ReadOnly))
    {
        throw Exception(Exception::FileOperationError, QString("Couldn't open file - " + filename));
    }

    if (!result.setContent(&xmlFile))
    {
        throw Exception(Exception::BadXMLFile, QString("Bad XML file - " + filename));
    }

    xmlFile.close();
    return result;
}

QDomDocumentFragment AbstractSerializator::setElementsContent(const QStringList &elements, const QString &tagname)
{
    QDomDocumentFragment result = resultXml.createDocumentFragment();

    for (int i = 0; i < elements.length(); i++)
    {
        QDomElement element = resultXml.createElement(tagname);
        element.appendChild(resultXml.createTextNode(elements.at(i)));

        result.appendChild(element);
    }

    return result;
}
