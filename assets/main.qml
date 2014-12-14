/*
 * Copyright (c) 2014 The Dominion of Awesome
 */

import bb.cascades 1.2

TabbedPane {
    Tab { //First tab
        // Localized text with the dynamic translation and locale updates support
        title: qsTr("Tab 1") + Retranslate.onLocaleOrLanguageChanged
        id: tab1
        delegate: Delegate {
            id: tab1Delegate
            source: "TerminalPage.qml"
        }
        // Note that our TabDelegateActivationPolicy *must not* be Default or ActivatedWhileSelected.
        // Otherwise our terminal controller will be destroyed when we switch tabs, and we lose state.
        delegateActivationPolicy: TabDelegateActivationPolicy.ActivateWhenSelected
    }
    Tab {
        title: qsTr("Tab 2") + Retranslate.onLocaleOrLanguageChanged
        id: tab2
        delegate: Delegate {
            id: tab2Delegate
            source: "TerminalPage.qml"
        }
        delegateActivationPolicy: TabDelegateActivationPolicy.ActivateWhenSelected       
    }
}
