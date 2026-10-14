/*
 * function: GSYNC_MESSAGE_PrintDefault
 * address:  0x021D5AB0
 * packet:   pkt_021D5AB0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PDWACC_MESSAGE_FormatNumber  0x021D97CC  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22941.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void PDWACC_MESSAGE_FormatNumber(int, void *);

void GSYNC_MESSAGE_PrintDefault(u8 *p, int x)
{
    PDWACC_MESSAGE_FormatNumber(x, ((struct Obj22941 *)p)->f2C);
}
