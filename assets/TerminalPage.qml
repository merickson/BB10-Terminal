import bb.cascades 1.4

Page {
    TerminalControl {
        id: terminalControl
    }
    
    actionBarVisibility: ChromeVisibility.Visible
    actions: [
        ActionItem {
            title: "Tab"
            imageSource: "asset:///tab.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                terminalControl.write("\x09");
            }
        },
        ActionItem {
            title: "Control-C"
            imageSource: "asset:///control-c.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                terminalControl.write("\x03")
            }
        },
        ActionItem {
            title: "Escape"
            imageSource: "asset:///esc.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                terminalControl.write("\x1b");
            }
        },
        ActionItem {
            title: "Control-D"
            imageSource: "asset:///control-d.png"
            onTriggered: {
                terminalControl.write("\x04")
            }
        },
        ActionItem {
            title: "Control-Z"
            imageSource: "asset:///control-z.png"
            onTriggered: {
                terminalControl.write("\x1a")
            }
        }
    ]
}
