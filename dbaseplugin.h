#pragma once

#include <extensionsystem/iplugin.h>

namespace dBase {
namespace Internal {

class dBasePlugin
  : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.kallup.plugins.dBase" FILE "dbase.json")

public:
    dBasePlugin();
    ~dBasePlugin();

    bool initialize(const QStringList &arguments, QString *errorMessage);

    void extensionsInitialized();

private:
    void sayHelloWorld();
};

} // namespace Internal
} // namespace dBase
