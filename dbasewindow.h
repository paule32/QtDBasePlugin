#pragma once

#include <QWidget>

namespace dBase {
namespace Internal {

class dBaseWindow : public QWidget
{
    Q_OBJECT

public:
    dBaseWindow(QWidget *parent = 0);
};

} // namespace Internal
} // namespace dBase
