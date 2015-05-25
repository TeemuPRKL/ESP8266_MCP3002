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

#include "driver/mcp3002.h"

#define COMMAND_LENGTH 4
#define RESPONSE_LENGTH 12

volatile uint8 mcp3002_spi_no = 0xFF;

bool mcp3002_init(uint8 spi_no)
{
    // Validate that proper SPI module is selected
    if(spi_no > 1) 
    {
        return false;
    }
    mcp3002_spi_no = spi_no;
    spi_init(mcp3002_spi_no);
    return true;
}

uint16 mcp3002_read(uint8 mode)
{
    uint8 cmd = 0;
    switch(mode)
    {  
        case MCP3002_CHANNEL_0:
            cmd = 0b1101;
            break;
        case MCP3002_CHANNEL_1:
            cmd = 0b1111;
            break;
        case MCP3002_DIFF_0:
            cmd = 0b1001;
            break;
        case MCP3002_DIFF_1:
            cmd = 0b1011;
            break;
        default:
            break;
    }
    uint32 retval = spi_transaction(mcp3002_spi_no, 0, 0, 0, 0, COMMAND_LENGTH, cmd, RESPONSE_LENGTH, 0);
    return (retval >> 1) & 0x3FF; // mask to 10-bit value
}