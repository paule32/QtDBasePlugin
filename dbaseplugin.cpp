#include "dbaseplugin.h"

#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/icore.h>
#include <coreplugin/imode.h>
#include <coreplugin/modemanager.h>
#include <coreplugin/id.h>

#include <QDebug>
#include <QtPlugin>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QPushButton>

namespace dBase {
namespace Internal {

/*!  A mode with a push button based on BaseMode.  */

class dBaseMode : public Core::IMode
{
public:
    dBaseMode()
    {
        setWidget(new QPushButton(tr("World PushButton!")));
        setContext(Core::Context("dBase.MainView"));
        setDisplayName(tr("dBase!!!"));
        setIcon(QIcon());
        setPriority(0);
        setId("dBase.dBaseMode");
        setContextHelpId(QString());
    }
};


/*! Constructs the Hello World plugin. Normally plugins don't do anything in
    their constructor except for initializing their member variables. The
    actual work is done later, in the initialize() and extensionsInitialized()
    functions.
*/
dBasePlugin::dBasePlugin()
{
}

/*! Plugins are responsible for deleting objects they created on the heap, and
    to unregister objects from the plugin manager that they registered there.
*/
dBasePlugin::~dBasePlugin()
{
}

/*! Initializes the plugin. Returns true on success.
    Plugins want to register objects with the plugin manager here.

    \a errorMessage can be used to pass an error message to the plugin system,
       if there was any.
*/
bool dBasePlugin::initialize(const QStringList &arguments, QString *errorMessage)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorMessage)

    // Create a unique context for our own view, that will be used for the
    // menu entry later.
    Core::Context context("dBase.MainView");

    // Create an action to be triggered by a menu entry
    QAction *dbase_Action = new QAction(tr("Say \"&dBase Mode...\""), this);
    connect(dbase_Action, &QAction::triggered, this, &dBasePlugin::sayHelloWorld);

    // Register the action with the action manager
    Core::Command *command =
            Core::ActionManager::registerAction(
                    dbase_Action, "dBase.dBaseAction", context);

    // Create our own menu to place in the Tools menu
    Core::ActionContainer *dBaseMenu =
            Core::ActionManager::createMenu("dBase.dBaseMenu");
    QMenu *menu = dBaseMenu->menu();
    menu->setTitle(tr("&dBase Module ..."));
    menu->setEnabled(true);

    // Add the Hello World action command to the menu
    dBaseMenu->addAction(command);

    // Request the Tools menu and add the Hello World menu to it
    Core::ActionContainer *toolsMenu =
            Core::ActionManager::actionContainer(Core::Constants::M_TOOLS);
    toolsMenu->addMenu(dBaseMenu);

    // Add a mode with a push button based on BaseMode. Like the BaseView,
    // it will unregister itself from the plugin manager when it is deleted.
    Core::IMode *dBase_Mode = new dBaseMode;
    addAutoReleasedObject(dBase_Mode);

    return true;
}

/*! Notification that all extensions that this plugin depends on have been
    initialized. The dependencies are defined in the plugins .json(.in) file.

    Normally this function is used for things that rely on other plugins to have
    added objects to the plugin manager, that implement interfaces that we're
    interested in. These objects can now be requested through the
    PluginManager.

    The HelloWorldPlugin doesn't need things from other plugins, so it does
    nothing here.
*/
void dBasePlugin::extensionsInitialized()
{
}

void dBasePlugin::sayHelloWorld()
{
    // When passing 0 for the parent, the message box becomes an
    // application-global modal dialog box
    QMessageBox::information(
            0, tr("Hello dbase World!"), tr("Halle Weltid! Beautiful day today, isn't it?"));
}

} // namespace Internal
} // namespace dBase
