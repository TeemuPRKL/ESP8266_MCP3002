/*
* The MIT License (MIT)
* 
* Copyright (c) 2015 Teemu Leskinen (teemuprkl)
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#ifndef MCP3002_DRV_H
#define MCP3002_DRV_H

// Requires ESP8266 SPI Driver by MetalPhreak
// https://github.com/MetalPhreak/ESP8266_SPI_Driver
#include "driver/spi.h"

// Read mode: either channel 0 or 1 or pseudo-differential
#define MCP3002_CHANNEL_0 0
#define MCP3002_CHANNEL_1 1
#define MCP3002_DIFF_0 2
#define MCP3002_DIFF_1 3

// Initialize mcp3002 driver
// spi_no = SPI or HSPI. Defined in driver/spi.h
bool mcp3002_init(uint8 spi_no);

// Read 10-bit value from mcp3002
uint16 mcp3002_read(uint8 mode);

// Shortcuts
#define mcp3002_read_ch0() mcp3002_read(MCP3002_CHANNEL_0)
#define mcp3002_read_ch1() mcp3002_read(MCP3002_CHANNEL_1)
#define mcp3002_read_diff0() mcp3002_read(MCP3002_DIFF_0)
#define mcp3002_read_diff1() mcp3002_read(MCP3002_DIFF_1)

#endif