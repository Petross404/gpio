////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef GPIO_CHIP_HPP
#define GPIO_CHIP_HPP

////////////////////////////////////////////////////////////////////////////////
#include <gpio++/pin.hpp>
#include <gpio++/types.hpp>

#include <asio/io_service.hpp>
#include <cstddef>
#include <memory>
#include <string>

////////////////////////////////////////////////////////////////////////////////
namespace gpio
{

////////////////////////////////////////////////////////////////////////////////
struct chip
{
    virtual ~chip() { }

    ////////////////////
    virtual const std::string& type() const noexcept = 0;
    virtual const std::string& id() const noexcept = 0;

    virtual const std::string& name() const noexcept = 0;

    ////////////////////
    virtual std::size_t pin_count() const noexcept = 0;

    virtual gpio::pin* pin(gpio::pos) = 0;
    virtual const gpio::pin* pin(gpio::pos) const = 0;
};

////////////////////////////////////////////////////////////////////////////////
using unique_chip = std::unique_ptr<chip>;
extern unique_chip get_chip(asio::io_service&, std::string param = "");

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
