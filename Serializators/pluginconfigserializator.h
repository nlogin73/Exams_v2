#ifndef PLUGINCONFIGSERIALIZATOR_H
#define PLUGINCONFIGSERIALIZATOR_H

#include "../DataClasses/dataclasses.h"
#include "../DataClasses/exception.h"
#include "abstractserializator.h"
#include "../Plugins/plugininfo.h"
#include "fieldschecker.h"

class PluginConfigSerializator : public AbstractSerializator
{
public:
    PluginConfigSerializator();

    PluginInfo loadPluginConfig(const QString &filename);
    void savePluginConfig(PluginInfo info, const QString &filename) throw (Exception);
private:
    QDomDocument getPluginConfigXML(PluginInfo info);
};

#endif // PLUGINCONFIGSERIALIZATOR_H
