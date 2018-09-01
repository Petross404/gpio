////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef GPIO_PIN_HPP
#define GPIO_PIN_HPP

////////////////////////////////////////////////////////////////////////////////
#include <gpio++/types.hpp>

#include <set>
#include <string>

////////////////////////////////////////////////////////////////////////////////
namespace gpio
{

////////////////////////////////////////////////////////////////////////////////
struct chip;

////////////////////////////////////////////////////////////////////////////////
struct pin
{
    virtual ~pin() { }

    ////////////////////
    virtual const gpio::chip* chip() const noexcept = 0;

    virtual gpio::pos pos() const noexcept = 0;
    virtual const std::string& name() const noexcept = 0;

    ////////////////////
    virtual void mode(gpio::mode, gpio::flag, gpio::state) = 0;
    virtual void mode(gpio::mode, gpio::flag) = 0;
    virtual void mode(gpio::mode, gpio::state) = 0;
    virtual void mode(gpio::mode) = 0 ;
    virtual gpio::mode mode() const noexcept = 0;

    virtual bool is_digital() const noexcept = 0;
    virtual bool is_analog() const noexcept = 0;

    virtual bool is_input() const noexcept = 0;
    virtual bool is_output() const noexcept = 0;

    virtual bool is(gpio::flag) const noexcept = 0;

    virtual bool supports(gpio::mode) const noexcept = 0;
    virtual bool supports(gpio::flag) const noexcept = 0;

    ////////////////////
    virtual void detach() = 0;
    virtual bool is_detached() const noexcept = 0;

    // pin is in-use eg by the kernel
    virtual bool is_used() const noexcept = 0;

    ////////////////////
    // digital
    virtual void set(gpio::state = on) = 0;
    virtual void reset() = 0;
    virtual gpio::state state() = 0;

    // pwm
    virtual void period(nsec) = 0;
    virtual nsec period() const noexcept = 0;

    virtual void set(nsec) = 0;
    virtual nsec pulse() const noexcept = 0;

    virtual void set(percent) = 0;
    virtual percent duty_cycle() const noexcept = 0;

    ////////////////////
    // digital callback
    virtual void on_state_changed(state_changed) = 0;
    virtual void on_state_on(state_on) = 0;
    virtual void on_state_off(state_off) = 0;
};

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
