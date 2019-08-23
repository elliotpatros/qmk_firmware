/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

Modified 2019 Elliot Patros <empatros@gmail.com>

reference: https://docs.qmk.fm/#/config_options

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* disable debugging features */
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // #ifndef NO_DEBUG

/* disable printing features */
#ifndef NO_PRINT
#define NO_PRINT
#endif // #ifndef NO_PRINT

/* debouncing time-limit for switch chatter. set to 0 if not needed */
#ifdef DEBOUNCING_DELAY
#undef DEBOUNCING_DELAY
#endif // def DEBOUNCING_DELAY
#define DEBOUNCING_DELAY 10

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

/* force n-key rollover to be enabled every boot */
// #define FORCE_NKRO

/* disable tap dance and other tapping features */
// #define NO_ACTION_TAPPING

/* disable one-shot modifiers */
// #define NO_ACTION_ONESHOT

/* disable old style macro handling */
// #define NO_ACTION_MACRO

/* disable calling of action_function() from the fn_actions array */
// #define NO_ACTION_FUNCTION

/* PERMISSIVE_HOLD
 * when off: tap-hold keys are both tapped when typed fast (within tapping term)
 *  - (shift/A down), (X down), (X up), (shift/A up) = ax
 * when on: tap-hold keys are held when typed fast, so long as the modifier key
 * is pressed before and released after the rodified key(s)
 *  - (shift/A down), (X down), (X up), (shift/A up) = shift X
 */
// #define PERMISSIVE_HOLD

/* IGNORE_MOD_TAP_INTERRUPT
 * when off: rolling tap-hold keys modifies keys
 *  - (shift/A down), (X down), (shift/A up), (X up) = shift X
 * when on: rolling tap-hold keys taps all keys 
 *  - (shift/A down), (X down), (shift/A up), (X up) = ax
 */
// #define IGNORE_MOD_TAP_INTERRUPT

/* TAPPING_TERM x (ms)
 * how long before a tap becomes a hold, if set above 500, a key tapped during
 * the tapping term will turn it into a hold too
 */
#define TAPPING_TERM 200

/* TAPPING_TOGGLE x (count)
 * If you hold the key down, layer is activated, and then is de-activated when
 * you let go (like MO()). If you repeatedly tap it, the layer will be toggled
 * on or off (like TG()). It needs 5 taps by default, but you can change this by
 * defining TAPPING_TOGGLE to another number.
 */
#define TAPPING_TOGGLE 2

/* RETRO_TAPPING 
 * tap anyway, even after TAPPING_TERM, if there was no other key interruption
 * between press and release
 */
// #define RETRO_TAPPING

/* ONESHOT_TIMEOUT x (ms)
 * how long before oneshot times out
 */
// #define ONESHOT_TIMEOUT 2000

/* TAP_CODE_DELAY x (ms)
 * how long tapped keycodes are held down for
 */
// #define TAP_CODE_DELAY 100
