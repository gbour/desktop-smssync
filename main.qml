import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

//import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: mainwindow

    title: qsTr("smssync")
    width: 300
    height: 500
    x: Screen.width - width
    // with awesome DM, Screen.desktopAvailableHeight returns same value as Scree.Height
    // (not including systray size)
    // TMP: setting static y position
    y: 19 //Screen.height - Screen.desktopAvailableHeight
    visible: true
    //visibility: Window.FullScreen


    Item {
        y: 0
        width: 500
        height: 850
        clip: false
        antialiasing: true
        visible: true
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.fill: parent

        Image {
            id: image1
            x: 5
            y: 7
            width: 100
            height: 100
            fillMode: Image.PreserveAspectCrop
            source: "resources/jdoe-mini.png"
        }

        Text {
            id: username
            x: 111
            y: 8
            width: 241
            height: 34
            text: qsTr("John Doe")
            font.pointSize: 20
            font.family: "Arial"
            horizontalAlignment: Text.AlignLeft
        }

        Text {
            id: phonenumber
            x: 111
            y: 42
            text: qsTr("+1.44.234.334")
            font.italic: true
            font.pixelSize: 12
        }


        Text {
            id: message
            x: 7
            y: 129
            width: 467
            height: 87
            text: qsTr("Hello Pal, Wassa ?")
            wrapMode: Text.WordWrap
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 12
        }


    }

    Component.onCompleted: {
        console.log(Screen.width, Screen.height, Screen.desktopAvailableWidth, Screen.desktopAvailableHeight)
    }
}
