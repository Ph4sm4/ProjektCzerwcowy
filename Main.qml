import QtQuick 2.9
import QtQuick.Window 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        width: parent.width
        height: parent.height / 2
        color: "#123123"
    }
}
