#include "dbasewindow.h"

#include <QTextEdit>
#include <QVBoxLayout>

using namespace dBase::Internal;

dBaseWindow::dBaseWindow(QWidget *parent)
   : QWidget(parent)
{
    QBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QTextEdit(tr("Focus me to activate my context!")));
    setWindowTitle(tr("dBase, world!"));
}
