#include "SystemTreeJsonPlugin.h"
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTreeWidgetItem>
#include "SystemTreeTab.h"

void SystemTreeJsonPlugin::opened(cubepluginapi::PluginServices* service)
{
    auto* tab = new SystemTreeTab();
    service->addTab(cubepluginapi::SYSTEM, tab);
}

