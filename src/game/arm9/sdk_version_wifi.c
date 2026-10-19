/*
 * file:     sdk_version_wifi.c
 * unit:     yes
 * address:  0x020050C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    The .version string of the WiFi library: one NUL padded string (44 bytes) in the library's own .version section of the original. The SDK linker script collects every .version section after crt0's data (0x02005050..0x02005124); here the link places the object by its header symbol.
 *
 * symbols:
 *   SDK_VERSION_WIFI  0x020050C4  data
 */

const char SDK_VERSION_WIFI[44] = "[SDK+NINTENDO:WiFi3.3.30052.201006221129]";
