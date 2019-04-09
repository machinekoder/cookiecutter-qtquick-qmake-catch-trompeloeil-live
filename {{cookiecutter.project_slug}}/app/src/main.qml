import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.2

ApplicationWindow {
  visible: true
  width: 640
  height: 480
  title: qsTr("{{cookiecutter.project_name}}")

  MainPanel {
    anchors.fill: parent
  }
}
