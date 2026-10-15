/*
 * function: CTVT_COMM_AdvanceWriteCursor
 * address:  0x021B8BFC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Increment the byte at +0x1ac and wrap it at 0x40.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void CTVT_COMM_AdvanceWriteCursor(int unused, u8 *p)
{
    p[0x1ac] += 1;
    if (p[0x1ac] >= 0x40) {
        p[0x1ac] -= 0x40;
    }
}
