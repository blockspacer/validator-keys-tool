//------------------------------------------------------------------------------
/*
    This file is part of jbcoind: https://github.com/jbcoin/jbcoind
    Copyright (c) 2012, 2013 Jbcoin Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef JBCOIN_BASICS_CHECKLIBRARYVERSIONSIMPL_H_INCLUDED
#define JBCOIN_BASICS_CHECKLIBRARYVERSIONSIMPL_H_INCLUDED

#include <jbcoin/basics/CheckLibraryVersions.h>

namespace jbcoin {
namespace version {

/** Both Boost and OpenSSL have integral version numbers. */
using VersionNumber = unsigned long long;

std::string
boostVersion(VersionNumber boostVersion);

std::string
openSSLVersion(VersionNumber openSSLVersion);

void checkVersion(
    std::string name,
    std::string required,
    std::string actual);

void checkBoost(std::string version);
void checkOpenSSL(std::string version);

}  // namespace version
}  // namespace jbcoin

#endif
