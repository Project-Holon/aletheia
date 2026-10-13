/*
 * function: FIELD_MSGBG_GetPrintQue
 * address:  0x021904A8
 * packet:   pkt_ov021_021904A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

u32 FIELD_MSGBG_GetPrintQue(u32 *p)
{
    return p[3];
}
