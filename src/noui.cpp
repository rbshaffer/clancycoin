// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Clancycoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <noui.h>

#include <ui_interface.h>
#include <util/system.h>

#include <cstdio>
#include <stdint.h>
#include <string>

#include <boost/signals2/connection.hpp>

bool noui_ThreadSafeMessageBox(const std::string& message, const std::string& caption, unsigned int style)
{
    bool fSecure = style & CClientUIInterface::SECURE;
    style &= ~CClientUIInterface::SECURE;
    bool prefix = !(style & CClientUIInterface::MSG_NOPREFIX);
    style &= ~CClientUIInterface::MSG_NOPREFIX;

    std::string strCaption;
    if (prefix) {
        switch (style) {
        case CClientUIInterface::MSG_ERROR:
            strCaption = "Error: ";
            break;
        case CClientUIInterface::MSG_WARNING:
            strCaption = "Warning: ";
            break;
        case CClientUIInterface::MSG_INFORMATION:
            strCaption = "Information: ";
            break;
        default:
            strCaption = caption + ": "; // Use supplied caption (can be empty)
        }
    }

    if (!fSecure) {
        LogPrintf("%s%s\n", strCaption, message);
    }
    tfm::format(std::cerr, "%s%s\n", strCaption.c_str(), message.c_str());
    return false;
}

bool noui_ThreadSafeQuestion(const std::string& /* ignored interactive message */, const std::string& message, const std::string& caption, unsigned int style)
{
    return noui_ThreadSafeMessageBox(message, caption, style);
}

void noui_InitMessage(const std::string& message)
{
    LogPrintf("init message: %s\n", message);
}

void noui_connect()
{
    uiInterface.ThreadSafeMessageBox_connect(noui_ThreadSafeMessageBox);
    uiInterface.ThreadSafeQuestion_connect(noui_ThreadSafeQuestion);
    uiInterface.InitMessage_connect(noui_InitMessage);
}
