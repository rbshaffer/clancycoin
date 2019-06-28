// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Clancycoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CLANCYCOIN_ATTRIBUTES_H
#define CLANCYCOIN_ATTRIBUTES_H

#if defined(__has_cpp_attribute)
#  if __has_cpp_attribute(nodiscard)
#    define NODISCARD [[nodiscard]]
#  endif
#endif
#ifndef NODISCARD
#  if defined(_MSC_VER) && _MSC_VER >= 1700
#    define NODISCARD _Check_return_
#  else
#    define NODISCARD __attribute__((warn_unused_result))
#  endif
#endif

#endif // CLANCYCOIN_ATTRIBUTES_H
