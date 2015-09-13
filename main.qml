import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

//import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: mainwindow

    title: qsTr("smssync")
    width: 300
    height: 200//500
    x: Screen.width - width
    // with awesome DM, Screen.desktopAvailableHeight returns same value as Scree.Height
    // (not including systray size)
    // TMP: setting static y position
    y: 19 //Screen.height - Screen.desktopAvailableHeight
    visible: true
    //visibility: Window.FullScreen

    Connections {
        target: systray
        onSystrayClicked: {
            if (mainwindow.visible) {
                mainwindow.hide();
            } else {
                mainwindow.show();
            }
        }
    }

    Item {
        y: 0
        //width: 500
        //height: 850
        clip: false
        antialiasing: true
        visible: true
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

    Connections {
        target: netmgr
        onIncomingMessage: {
            console.log("incoming msg");

            var _contact = content.contact();
            username.text    = _contact.name();
            phonenumber.text = _contact.phoneNumber()

            message.text     = content.content()

            if (!mainwindow.visible) {
                mainwindow.show();
            }
        }
    }
}
