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

#include <BeastConfig.h>
#include <jbcoin/peerfinder/PeerfinderManager.h>

namespace jbcoin {
namespace PeerFinder {

Endpoint::Endpoint ()
    : hops (0)
{
}

Endpoint::Endpoint (beast::IP::Endpoint const& ep, int hops_)
    : hops (hops_)
    , address (ep)
{
}

bool operator< (Endpoint const& lhs, Endpoint const& rhs)
{
    return lhs.address < rhs.address;
}

}
}