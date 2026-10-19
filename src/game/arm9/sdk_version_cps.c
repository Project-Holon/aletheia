/*
 * file:     sdk_version_cps.c
 * unit:     yes
 * address:  0x020050AC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    The .version string of the CPS network stack: one NUL padded string (24 bytes) in the library's own .version section of the original. The SDK linker script collects every .version section after crt0's data (0x02005050..0x02005124); here the link places the object by its header symbol.
 *
 * symbols:
 *   SDK_VERSION_CPS  0x020050AC  data
 */

const char SDK_VERSION_CPS[24] = "[SDK+UBIQUITOUS:CPS]";
