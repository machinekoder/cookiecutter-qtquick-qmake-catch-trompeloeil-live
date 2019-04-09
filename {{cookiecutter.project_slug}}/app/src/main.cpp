
#include <QCommandLineParser>
#include <QFile>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "calculator.h"

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setOrganizationName("{{cookiecutter.organization_name}}");
    app.setOrganizationDomain("{{cookiecutter.organization_domain}}");
    app.setApplicationName("{{cookiecutter.project_name}}");
    app.setApplicationDisplayName("{{cookiecutter.project_name}}");

    QCommandLineParser parser;
    parser.setApplicationDescription("{{cookiecutter.project_short_description}}");
    parser.addHelpOption();
#ifdef QT_DEBUG
    QCommandLineOption liveOption(QStringList() << "l"
                                                << "live",
        QCoreApplication::translate("live", "Start live coding mode."));
    parser.addOption(liveOption);
#endif
    parser.process(app);

    QString fileName = QStringLiteral("main.qml");
#ifdef QT_DEBUG
    if (parser.isSet(liveOption)) {
        fileName = QStringLiteral("live.qml");
    }
#endif

    qmlRegisterType<Calculator>("MyMath", 1, 0, "Calculator");

    QQmlApplicationEngine engine;
    engine.addImportPath(QStringLiteral("."));
    engine.addImportPath(QStringLiteral("qrc:/"));
    QFile file(QStringLiteral("./src/") + fileName);
    if (file.exists()) {
        engine.load(QStringLiteral("./src/") + fileName);
    } else {
        engine.load(QUrl(QStringLiteral("qrc:/src/") + fileName));
    }
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
