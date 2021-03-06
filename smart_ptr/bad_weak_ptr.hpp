// Copyright (c) 2014 The Trident Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// 

// This file is modified from boost.
//
// Copyright Beman Dawes 2002, 2006
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See library home page at http://www.boost.org/libs/system

#ifndef _TRIDENT_BAD_WEAK_PTR_
#define _TRIDENT_BAD_WEAK_PTR_

#include <exception>

namespace trident {


class bad_weak_ptr: public std::exception
{
public:
    virtual char const * what() const throw()
    {
        return "trident::bad_weak_ptr";
    }
};


} // namespace trident

#endif // _TRIDENT_BAD_WEAK_PTR_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
