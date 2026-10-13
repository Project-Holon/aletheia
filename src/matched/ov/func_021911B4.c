/*
 * function: FIELD_MSGBG_GetInfoSysWinBmpWin
 * address:  0x021911B4
 * packet:   pkt_021911B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter at +0x0.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17934.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_MSGBG_GetInfoSysWinBmpWin(u8 *p)
{
    return ((struct Obj17934 *)p)->f0;
}
