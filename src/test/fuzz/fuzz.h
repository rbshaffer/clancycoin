// Copyright (c) 2009-2019 The Clancycoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CLANCYCOIN_TEST_FUZZ_FUZZ_H
#define CLANCYCOIN_TEST_FUZZ_FUZZ_H

#include <stdint.h>
#include <vector>


void test_one_input(std::vector<uint8_t> buffer);

#endif // CLANCYCOIN_TEST_FUZZ_FUZZ_H
