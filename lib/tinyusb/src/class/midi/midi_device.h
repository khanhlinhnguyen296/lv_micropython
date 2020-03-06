/* 
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * This file is part of the TinyUSB stack.
 */

#ifndef _TUSB_MIDI_DEVICE_H_
#define _TUSB_MIDI_DEVICE_H_

#include "common/tusb_common.h"
#include "device/usbd.h"
#include "class/audio/audio.h"

//--------------------------------------------------------------------+
// Class Driver Configuration
//--------------------------------------------------------------------+
#ifndef CFG_TUD_MIDI_EPSIZE
#define CFG_TUD_MIDI_EPSIZE 64
#endif


#ifdef __cplusplus
 extern "C" {
#endif

/** \addtogroup MIDI_Serial Serial
 *  @{
 *  \defgroup   MIDI_Serial_Device Device
 *  @{ */

//--------------------------------------------------------------------+
// APPLICATION API (Multiple Interfaces)
// CFG_TUD_MIDI > 1
//--------------------------------------------------------------------+
bool     tud_midi_n_connected       (uint8_t itf);

uint32_t tud_midi_n_available       (uint8_t itf, uint8_t jack_id);
char     tud_midi_n_read_char       (uint8_t itf, uint8_t jack_id);
uint32_t tud_midi_n_read            (uint8_t itf, uint8_t jack_id, void* buffer, uint32_t bufsize);
void     tud_midi_n_read_flush      (uint8_t itf, uint8_t jack_id);
char     tud_midi_n_peek            (uint8_t itf, uint8_t jack_id, int pos);

uint32_t tud_midi_n_write_char      (uint8_t itf, char ch);
uint32_t tud_midi_n_write           (uint8_t itf, uint8_t jack_id, uint8_t const* buffer, uint32_t bufsize);
bool     tud_midi_n_write_flush     (uint8_t itf);

//--------------------------------------------------------------------+
// APPLICATION API (Interface0)
//--------------------------------------------------------------------+
static inline bool     tud_midi_connected       (void)                                 { return tud_midi_n_connected(0);              }

static inline uint32_t tud_midi_available       (void)                                 { return tud_midi_n_available(0, 0);              }
static inline char     tud_midi_read_char       (void)                                 { return tud_midi_n_read_char(0, 0);              }
static inline uint32_t tud_midi_read            (void* buffer, uint32_t bufsize)       { return tud_midi_n_read(0, 0, buffer, bufsize);  }
static inline void     tud_midi_read_flush      (void)                                 { tud_midi_n_read_flush(0, 0);                    }
static inline char     tud_midi_peek            (int pos)                              { return tud_midi_n_peek(0, 0, pos);              }

static inline uint32_t tud_midi_write_char      (char ch)                              { return tud_midi_n_write_char(0, ch);         }
static inline uint32_t tud_midi_write           (uint8_t jack_id, void const* buffer, uint32_t bufsize) { return tud_midi_n_write(0, jack_id, buffer, bufsize); }
static inline bool     tud_midi_write_flush     (void)                                 { return tud_midi_n_write_flush(0);            }

//--------------------------------------------------------------------+
// APPLICATION CALLBACK API (WEAK is optional)
//--------------------------------------------------------------------+
TU_ATTR_WEAK void tud_midi_rx_cb(uint8_t itf);

//--------------------------------------------------------------------+
// Internal Class Driver API
//--------------------------------------------------------------------+
void midid_init               (void);
bool midid_open               (uint8_t rhport, tusb_desc_interface_t const * p_interface_desc, uint16_t *p_length);
bool midid_control_request (uint8_t rhport, tusb_control_request_t const * p_request);
bool midid_control_request_complete (uint8_t rhport, tusb_control_request_t const * p_request);
bool midid_xfer_cb            (uint8_t rhport, uint8_t edpt_addr, xfer_result_t result, uint32_t xferred_bytes);
void midid_reset              (uint8_t rhport);

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_MIDI_DEVICE_H_ */

/** @} */
/** @} */
