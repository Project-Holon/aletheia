/*
 * file:     sdk_version_dwc.c
 * unit:     yes
 * address:  0x02005050
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    The .version string of the NitroDWC: one NUL padded string (68 bytes) in the library's own .version section of the original. The SDK linker script collects every .version section after crt0's data (0x02005050..0x02005124); here the link places the object by its header symbol.
 *
 * symbols:
 *   SDK_VERSION_DWC  0x02005050  data
 */

const char SDK_VERSION_DWC[68] = "[SDK+NINTENDO:DWC5.3.30054.20100706.1000_TWLDWC_5_3_PATCH1_SSLGDB4]";
