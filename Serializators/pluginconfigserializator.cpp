#include "pluginconfigserializator.h"

PluginConfigSerializator::PluginConfigSerializator()
{
}


PluginInfo PluginConfigSerializator::loadPluginConfig(const QString &filename)
{
    QDomDocument xml;
    try
    {
        loadXmlSchema(":/xsd/xsd/pluginconfig.xsd");

        xml = loadXml(filename);

        if (!checkXml(xml))
        {
            throw Exception(Exception::BadXMLFile, QString("Bad XML file - " + filename));
        }
    }
    catch (const Exception &err)
    {
        throw;
    }
    QDomNodeList globals = xml.elementsByTagName("globals");

    QString title = globals.at(0).toElement().elementsByTagName("title").at(0).toElement().text();
    QString version = globals.at(0).toElement().elementsByTagName("version").at(0).toElement().text();
    QString startCode = globals.at(0).toElement().elementsByTagName("startCode").at(0).toElement().text();
    QString author = globals.at(0).toElement().elementsByTagName("author").at(0).toElement().text();

    QDomNodeList units = xml.elementsByTagName("unit");
    QStringList codes;
    for (int i = 0; i < units.length(); i++)
    {
        codes.push_back(units.at(i).toElement().attribute("code"));
        codes.push_back(units.at(i).toElement().elementsByTagName("title").at(0).toElement().text());
        codes.push_back(units.at(i).toElement().elementsByTagName("practiceFile").at(0).toElement().text());
        codes.push_back(units.at(i).toElement().elementsByTagName("testFile").at(0).toElement().text());
    }

    PluginInfo info(title, version, startCode, author, codes);
    return info;
}

void PluginConfigSerializator::savePluginConfig(PluginInfo info, const QString &filename) throw (Exception)
{
    QFile xmlFile(filename);

    if (!xmlFile.open(QIODevice::WriteOnly))
    {
        throw Exception(Exception::FileOperationError, QString("Couldn't open file - " + filename));
    }

    xmlFile.write(getPluginConfigXML(info).toByteArray());

    xmlFile.close();
}

QDomDocument PluginConfigSerializator::getPluginConfigXML(PluginInfo info)
{
    //QDomDocument xml;

    resultXml.clear();

    QDomElement root = resultXml.createElement("root");


    QDomElement globals = resultXml.createElement("globals");

    QDomElement title = resultXml.createElement("title");
    title.appendChild(resultXml.createTextNode(info.getTitle()));
    globals.appendChild(title);

    QDomElement version = resultXml.createElement("version");
    version.appendChild(resultXml.createTextNode(info.getVersion()));
    globals.appendChild(version);

    QDomElement startCode = resultXml.createElement("startCode");
    startCode.appendChild(resultXml.createTextNode(info.getDescription()));
    globals.appendChild(startCode);

    QDomElement author = resultXml.createElement("author");
    author.appendChild(resultXml.createTextNode(info.getAuthor()));
    globals.appendChild(author);

    root.appendChild(globals);
    resultXml.appendChild(root);

    for(int i = 0; i < info.getCodes().length(); i++)
    {
        QDomElement unit = resultXml.createElement("unit");
        unit.setAttribute("code", info.getCodes().at(i));

        QDomElement title = resultXml.createElement("title");
        title.appendChild(resultXml.createTextNode(info.getCodes().at(i + 1)));
        unit.appendChild(title);

        QDomElement practiceFile = resultXml.createElement("practiceFile");
        practiceFile.appendChild(resultXml.createTextNode(info.getCodes().at(i + 2)));
        unit.appendChild(practiceFile);

        QDomElement testFile = resultXml.createElement("testFile");
        testFile.appendChild(resultXml.createTextNode(info.getCodes().at(i + 3)));
        unit.appendChild(testFile);

        root.appendChild(unit);
    }

    return resultXml;

    //return xml;
}
