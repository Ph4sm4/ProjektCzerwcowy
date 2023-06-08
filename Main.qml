import QtQuick 2.9
import QtQuick.Window 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rec

        property bool isClicked: false

        width: parent.width
        height: parent.height / 2
        color: this.isClicked ? "orange" : "green"

        MouseArea {
            onPressed: parent.isClicked = true
            onReleased: parent.isClicked = false
            anchors.fill: parent
        }
    }
}
