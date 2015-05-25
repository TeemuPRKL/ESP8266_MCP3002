ESP8266 MCP3002 Driver
========
ESP8266 - Driver for Microchip MCP3002, a 10-bit Analog to Digital Converter (ADC) with SPI interface

Requirements
========
This driver requires ESP8266 SPI Driver by MetalPhreak for SPI communications.

https://github.com/MetalPhreak/ESP8266_SPI_Driver

Usage
========
**Initialize MCP3002 driver**

_note: you must initialize the driver before attempting read operation_

bool mcp3002_init(uint8 spi_no)

Parameters: spi_no = SPI or HSPI - depending on which SPI HW module is in use

Returns: true on success, false on failure (invalid spi_no)

**Read value from MCP3002**
uint16 mcp3002_read(uint8 mode)

Parameters: mode = MCP3002_CHANNEL_0, MCP3002_CHANNEL_1, MCP3002_DIFF_0 or MCP3002_DIFF_1 - depending on which channel or pseudo-differential to read.

Returns: 10-bit value from MCP3002



