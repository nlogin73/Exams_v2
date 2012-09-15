#include "ExamsTestSerializator.h"

ExamsTestSerializator::ExamsTestSerializator()
{
}

ExamsTest ExamsTestSerializator::loadTest(const QString &filename)
{
    QDomDocument xml;
    try
    {
        loadXmlSchema(":/xsd/xsd/examstestconfig.xsd");

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

    ExamsTest test(title, version);

    QDomNodeList tasks = xml.elementsByTagName("task");

    for (int i = 0; i < tasks.length(); i++)
    {
        test.addTask(getTask(tasks.at(i)));
    }

    return test;
}

TestTask ExamsTestSerializator::getTask(const QDomNode &taskNode)
{
    QDomElement currentElement = taskNode.toElement();

    QString taskId = currentElement.attribute("taskId");
    TestTask::AnswerType taskType = TestTask::fromStringType(currentElement.attribute("taskType"));

    QStringList innerCodes = FieldsChecker::parseCodes(getElementsContent(currentElement, "innerCode"));
    QStringList outerCodes = FieldsChecker::parseCodes(getElementsContent(currentElement, "outerCode"));

    QString content = currentElement.firstChildElement("content").text();
    QString answer = currentElement.firstChildElement("answer").text();

    QStringList images = getElementsContent(currentElement, "image");

    double cost = 0;
    QString answerHtml;

    QDomNodeList costs = currentElement.elementsByTagName("cost");
    if (costs.length() != 0)
    {
        bool ok = true;
        cost = costs.at(0).toElement().text().toDouble(&ok);
    }
    QDomNodeList answers = currentElement.elementsByTagName("answerHTML");
    if (answers.length() != 0)
    {
        answerHtml = answers.at(0).toElement().text();
    }

    return TestTask(taskId, taskType, innerCodes, outerCodes, content, answer, images, cost, answerHtml);
}

void ExamsTestSerializator::saveTest(const ExamsTest &test, const QString &filename) throw (Exception)
{
    QFile xmlFile(filename);

    if (!xmlFile.open(QIODevice::WriteOnly))
    {
        throw Exception(Exception::FileOperationError, QString("Couldn't open file - " + filename));
    }

    xmlFile.write(getTestXML(test).toByteArray());

    xmlFile.close();
}

QDomElement ExamsTestSerializator::getTaskXML(const TestTask &task)
{
    QDomElement result = resultXml.createElement("task");
    result.setAttribute("taskId", task.getTaskId());
    result.setAttribute("taskType", TestTask::toStringType(task.getAnswerType()));

    result.appendChild(setElementsContent(task.getInnerCodes(), "innerCode"));
    result.appendChild(setElementsContent(task.getOuterCodes(), "outerCode"));

    QDomElement content = resultXml.createElement("content");
    content.appendChild(resultXml.createTextNode(task.getTaskContent()));

    result.appendChild(content);

    result.appendChild(setElementsContent(task.getImageLinks(), "image"));

    QDomElement answer = resultXml.createElement("answer");
    answer.appendChild(resultXml.createTextNode(task.getRightAnswer()));

    result.appendChild(answer);

    if (task.getTaskCost() != 0)
    {
        QDomElement cost = resultXml.createElement("cost");
        cost.appendChild(resultXml.createTextNode(QString::number(task.getTaskCost(), 'f', 2)));

        result.appendChild(cost);
    }

    if (task.getAnswerHtml() != "")
    {
        QDomElement answerHtml = resultXml.createElement("answerHtml");
        answerHtml.appendChild(resultXml.createTextNode(task.getAnswerHtml()));

        result.appendChild(answerHtml);
    }

    return result;
}

QDomDocument ExamsTestSerializator::getTestXML(const ExamsTest &test)
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

