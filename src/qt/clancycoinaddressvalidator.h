// Copyright (c) 2011-2014 The Clancycoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CLANCYCOIN_QT_CLANCYCOINADDRESSVALIDATOR_H
#define CLANCYCOIN_QT_CLANCYCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class ClancycoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ClancycoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Clancycoin address widget validator, checks for a valid clancycoin address.
 */
class ClancycoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ClancycoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // CLANCYCOIN_QT_CLANCYCOINADDRESSVALIDATOR_H
