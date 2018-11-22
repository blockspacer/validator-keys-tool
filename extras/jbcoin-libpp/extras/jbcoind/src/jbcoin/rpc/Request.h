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

#ifndef JBCOIN_RPC_REQUEST_H_INCLUDED
#define JBCOIN_RPC_REQUEST_H_INCLUDED

#include <jbcoin/resource/Charge.h>
#include <jbcoin/resource/Fees.h>
#include <jbcoin/json/json_value.h>
#include <beast/utility/Journal.h>

namespace jbcoin {

class Application;

namespace RPC {

struct Request
{
    explicit Request (
        beast::Journal journal_,
        std::string const& method_,
        Json::Value& params_,
        Application& app_)
        : journal (journal_)
        , method (method_)
        , params (params_)
        , fee (Resource::feeReferenceRPC)
        , app (app_)
    {
    }

    // [in] The Journal for logging
    beast::Journal journal;

    // [in] The JSON-RPC method
    std::string method;

    // [in] The Jbcoin-specific "params" object
    Json::Value params;

    // [in, out] The resource cost for the command
    Resource::Charge fee;

    // [out] The JSON-RPC response
    Json::Value result;

    // [in] The Application instance
    Application& app;

private:
    Request& operator= (Request const&);
};

}
}

#endif