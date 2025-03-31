#ifndef SYSTEMTREEJSONPLUGIN_H
#define SYSTEMTREEJSONPLUGIN_H

#include <QObject>
#include <QTreeWidget>
#include "cubegui/CubePlugin.h"
#include "cubegui/PluginServices.h"

class SystemTreeJsonPlugin : public QObject, public cubepluginapi::CubePlugin
{
    Q_OBJECT
    Q_INTERFACES(cubepluginapi::CubePlugin)
    Q_PLUGIN_METADATA(IID "cubepluginapi::CubePlugin/1.0")

public:
    SystemTreeJsonPlugin(QObject* parent = nullptr) : QObject(parent) {}

    QString name() const override { return "JSON Viewer"; }

    void version(int& major, int& minor, int& bugfix) const override {
        major = 1; minor = 0; bugfix = 0;
    }

    void opened(cubepluginapi::PluginServices* service);

private:
    void loadSystemTree(QTreeWidget* tree);
};

#endif

