////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef GPIO_PIGPIO_CHIP_HPP
#define GPIO_PIGPIO_CHIP_HPP

////////////////////////////////////////////////////////////////////////////////
#include "chip_base.hpp"

#include <asio/io_service.hpp>
#include <string>

////////////////////////////////////////////////////////////////////////////////
namespace gpio
{
namespace pigpio
{

////////////////////////////////////////////////////////////////////////////////
class chip : public chip_base
{
public:
    ////////////////////
    chip(asio::io_service&);
    virtual ~chip() override;
};

////////////////////////////////////////////////////////////////////////////////
}
}

////////////////////////////////////////////////////////////////////////////////
#endif