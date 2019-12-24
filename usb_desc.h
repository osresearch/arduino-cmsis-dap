/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2017 PJRC.COM, LLC.
 *
 * Hacked version to enable USB CDC serial and raw HID.
 *
 * Backup the old version of the teensyduino file in
 * `hardware/teensy/avr/cores/teensy3/usb_desc.h`
 * and copy this one in its place.
 *
 * Be sure to select `Raw HID` from the `Tools - USB Type` menu.
 *
 **************************
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _usb_desc_h_
#define _usb_desc_h_

// This header is NOT meant to be included when compiling
// user sketches in Arduino.  The low-level functions
// provided by usb_dev.c are meant to be called only by
// code which provides higher-level interfaces to the user.

#include <stdint.h>
#include <stddef.h>

#define ENDPOINT_UNUSED			0x00
#define ENDPOINT_TRANSMIT_ONLY		0x15
#define ENDPOINT_RECEIVE_ONLY		0x19
#define ENDPOINT_TRANSMIT_AND_RECEIVE	0x1D
#define ENDPOINT_RECEIVE_ISOCHRONOUS	0x18
#define ENDPOINT_TRANSMIT_ISOCHRONOUS	0x14


#if defined(USB_RAWHID)
  #define VENDOR_ID		0x16C0
  #define PRODUCT_ID		0x0486
  #define RAWHID_USAGE_PAGE	0xFFAB  // recommended: 0xFF00 to 0xFFFF
  #define RAWHID_USAGE		0x0200  // recommended: 0x0100 to 0xFFFF
  #define MANUFACTURER_NAME	{'T','e','e','n','s','y','d','u','i','n','o'}
  #define MANUFACTURER_NAME_LEN	11
  #define PRODUCT_NAME		{'T','e','e','n','s','y',' ','-',' ','C','M','S','I','S','-','D','A','P'}
  #define PRODUCT_NAME_LEN	18
  #define EP0_SIZE		64
  #define NUM_ENDPOINTS         7
  #define NUM_USB_BUFFERS	12
  #define NUM_INTERFACE		3	// control, cdc status, cdc data, raw hid

  #define RAWHID_INTERFACE      2	// RawHID
  #define RAWHID_TX_ENDPOINT    6
  #define RAWHID_TX_SIZE        64
  #define RAWHID_TX_INTERVAL    1
  #define RAWHID_RX_ENDPOINT    5
  #define RAWHID_RX_SIZE        64
  #define RAWHID_RX_INTERVAL    1

  #define CDC_STATUS_INTERFACE	0
  #define CDC_DATA_INTERFACE	1
  #define CDC_ACM_ENDPOINT	2
  #define CDC_RX_ENDPOINT       3
  #define CDC_TX_ENDPOINT       4
  #define CDC_ACM_SIZE          16
  #define CDC_RX_SIZE           64
  #define CDC_TX_SIZE           64
  #define ENDPOINT2_CONFIG	ENDPOINT_TRANSMIT_ONLY // 
  #define ENDPOINT3_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT4_CONFIG	ENDPOINT_TRANSMIT_ONLY
  #define ENDPOINT5_CONFIG	ENDPOINT_RECEIVE_ONLY
  #define ENDPOINT6_CONFIG	ENDPOINT_TRANSMIT_ONLY

#else
#error "Please select 'Raw HID' from the 'Tools - USB Type' menu"
#endif

#ifdef USB_DESC_LIST_DEFINE
#if defined(NUM_ENDPOINTS) && NUM_ENDPOINTS > 0
// NUM_ENDPOINTS = number of non-zero endpoints (0 to 15)
extern const uint8_t usb_endpoint_config_table[NUM_ENDPOINTS];

typedef struct {
	uint16_t	wValue;
	uint16_t	wIndex;
	const uint8_t	*addr;
	uint16_t	length;
} usb_descriptor_list_t;

extern const usb_descriptor_list_t usb_descriptor_list[];
#endif // NUM_ENDPOINTS
#endif // USB_DESC_LIST_DEFINE

#endif
