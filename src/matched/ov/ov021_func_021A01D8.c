/*
 * function: FIELD_FOG_InitFogTable
 * address:  0x021A01D8
 * packet:   pkt_ov021_021A01D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

void FIELD_FOG_InitFogTable(u8 *p)
{
    int i;
    for (i = 0; i < 32; i++) {
        p[0xC + i] = i * 4;
        p[0xC + i] += (i * 4) / 32;
    }
}
