////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef GPIO_HPP
#define GPIO_HPP

////////////////////////////////////////////////////////////////////////////////
#include <gpio++/chip.hpp>
#include <gpio++/pin.hpp>
#include <gpio++/types.hpp>

#include <memory>
#include <string>

////////////////////////////////////////////////////////////////////////////////
namespace gpio
{

////////////////////////////////////////////////////////////////////////////////
using handle = void*;

struct chip_deleter
{
    gpio::handle handle = nullptr;
    void operator()(gpio::chip*);
};
using unique_chip = std::unique_ptr<chip, chip_deleter>;

unique_chip get_chip(asio::io_service&, std::string type);

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
