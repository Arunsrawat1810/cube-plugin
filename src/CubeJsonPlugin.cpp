#include "CubeJsonPlugin.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include <Constants.h>     // for cubegui::SYSTEM
#include <TabInterface.h>  // for cubegui::TabInterface

// Define a wrapper that satisfies TabInterface requirements
class JsonTabInterface : public QWidget, public cubegui::TabInterface {
    public:
        JsonTabInterface(QWidget* parent = nullptr) : QWidget(parent) {}
    
        QString label() const override {
            return "System Tree JSON";
        }
    
        QWidget* widget() override {
            return this;
        }
    };

QString CubeJsonPlugin::name() const {
    return "System Tree JSON Viewer";
}

void CubeJsonPlugin::version(int& major, int& minor, int& bugfix) const {
    major = 1;
    minor = 0;
    bugfix = 0;
}

QString CubeJsonPlugin::getHelpText() const {
    return "This plugin shows system tree data from a JSON file.";
}

QWidget* CubeJsonPlugin:: widget(){
    return widget_;
}

QString CubeJsonPlugin::label() const{
    return "System Tree JSON";
}

bool CubeJsonPlugin::cubeOpened(cubepluginapi::PluginServices* service) {
    QTextEdit* textEdit = new QTextEdit;
    textEdit->setReadOnly(true);

    QFile file("json_sample/system_tree_example.json");
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        textEdit->setText(doc.toJson(QJsonDocument::Indented));
    } else {
        textEdit->setText("Could not load JSON file.");
    }

    JsonTabInterface* tab = new JsonTabInterface;
    QVBoxLayout* layout = new QVBoxLayout(tab);
    layout->addWidget(textEdit);
    tab->setLayout(layout);

    service->addTab(cubegui::SYSTEM, tab);
    return true;
}

extern "C" cubepluginapi::CubePlugin* cubeplugin_get_instance()
{
    return new CubeJsonPlugin();
}