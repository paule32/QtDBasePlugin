import qbs 1.0

QtcPlugin {
    name: "dBase"

    Depends { name: "Core" }
    Depends { name: "Qt"; submodules: ["widgets", "xml", "network"] }

    files: [
        "dbaseplugin.cpp",
        "dbaseplugin.h",
        "dbasewindow.cpp",
        "dbasewindow.h",
    ]
}

