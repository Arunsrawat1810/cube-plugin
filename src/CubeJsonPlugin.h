#ifndef CUBE_JSON_PLUGIN_H
#define CUBE_JSON_PLUGIN_H

#include <CubePlugin.h>
#include <PluginServices.h>
// #include <CubeProxy.h>
#include <QWidget>

class CubeJsonPlugin : public QObject, public cubepluginapi::CubePlugin, public cubegui:: TabInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "de.fz-juelich.cubeplugin")
    Q_INTERFACES(cubepluginapi::CubePlugin)

public:
    QString name() const override;
    void version(int& major, int& minor, int& bugfix) const override;
    QString getHelpText() const override;
    bool cubeOpened(cubepluginapi::PluginServices* service) override;
    QWidget* widget() override;
    QString label() const override;
private:
    QWidget* widget_;
};

#endif // CUBE_JSON_PLUGIN_H