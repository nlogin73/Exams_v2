#include "reviewedtestserializator.h"

ReviewedTestSerializator::ReviewedTestSerializator()
{
}

ReviewedTest ReviewedTestSerializator::loadTest(const QString &filename)
{
    QDomDocument xml;
    try
    {
        loadXmlSchema(":/xsd/xsd/reviewedtestconfig.xsd");

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

    QString title = xml.elementsByTagName("title").at(0).toElement().text();
    QString version = xml.elementsByTagName("testVersion").at(0).toElement().text();

    ReviewedTest test(title, version);

    QDomNodeList tasks = xml.elementsByTagName("task");

    for (int i = 0; i < tasks.length(); i++)
    {
        test.addTask(getTask(tasks.at(i)));
    }

    return test;
}

ReviewedTestTask ReviewedTestSerializator::getTask(const QDomNode &taskNode)
{
    QDomElement currentElement = taskNode.toElement();

    QString taskId = currentElement.attribute("taskId");

    QStringList innerCodes = FieldsChecker::parseCodes(getElementsContent(currentElement, "innerCode"));
    QStringList outerCodes = FieldsChecker::parseCodes(getElementsContent(currentElement, "outerCode"));

    QString source = currentElement.firstChildElement("source").text();

    QStringList xmlTestTasks = getElementsContent(currentElement, "testTaskXml");

    return ReviewedTestTask(taskId, innerCodes, outerCodes, source, xmlTestTasks);
}

void ReviewedTestSerializator::saveTest(const ReviewedTest &test, const QString &filename) throw (Exception)
{
    QFile xmlFile(filename);

    if (!xmlFile.open(QIODevice::WriteOnly))
    {
        throw Exception(Exception::FileOperationError, QString("Couldn't open file - " + filename));
    }

    xmlFile.write(getTestXML(test).toByteArray());

    xmlFile.close();
}

QDomElement ReviewedTestSerializator::getTaskXML(const ReviewedTestTask &task)
{
    QDomElement result = resultXml.createElement("task");
    result.setAttribute("taskId", task.getTaskId());

    result.appendChild(setElementsContent(task.getInnerCodes(), "innerCode"));
    result.appendChild(setElementsContent(task.getOuterCodes(), "outerCode"));

    QDomElement source = resultXml.createElement("source");
    source.appendChild(resultXml.createTextNode(task.getHtmlSource()));

    result.appendChild(source);

    result.appendChild(setElementsContent(task.getXmlTestTasks(), "testTaskXml"));

    return result;
}

QDomDocument ReviewedTestSerializator::getTestXML(const ReviewedTest &test)
{
    resultXml.clear();

    QDomElement root = resultXml.createElement("root");
    resultXml.appendChild(root);

    QDomElement title = resultXml.createElement("title");
    title.appendChild(resultXml.createTextNode(test.getTestTitle()));
    root.appendChild(title);

    QDomElement version = resultXml.createElement("version");
    version.appendChild(resultXml.createTextNode(test.getTestVersion()));
    root.appendChild(version);

    for(int i = 0; i < test.getTasksCount(); i++)
    {
        root.appendChild(getTaskXML(test.getTask(i)));
    }

    return resultXml;
}

