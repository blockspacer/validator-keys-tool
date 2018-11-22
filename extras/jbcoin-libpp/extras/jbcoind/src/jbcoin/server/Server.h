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

#ifndef JBCOIN_SERVER_SERVER_H_INCLUDED
#define JBCOIN_SERVER_SERVER_H_INCLUDED

#include <jbcoin/server/Port.h>
#include <jbcoin/server/impl/ServerImpl.h>
#include <jbcoin/beast/utility/Journal.h>
#include <jbcoin/beast/utility/PropertyStream.h>
#include <boost/asio/io_service.hpp>

namespace jbcoin {

/** Create the HTTP server using the specified handler. */
template<class Handler>
std::unique_ptr<Server>
make_Server(Handler& handler,
    boost::asio::io_service& io_service, beast::Journal journal)
{
    return std::make_unique<ServerImpl<Handler>>(
        handler, io_service, journal);
}

} // jbcoin

#endif