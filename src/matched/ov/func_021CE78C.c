/*
 * function: COMM_ENTRY_MENU_IsIdle
 * address:  0x021CE78C
 * packet:   pkt_021CE78C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09217.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);

int COMM_ENTRY_MENU_IsIdle(u32 a)
{
if (*(u32 *)((u8 *)(a) + ((1 << 8))) == 0) {
    if (FIELD_MSGBG_SysWinMain((u32 *)(((struct Obj09217 *)((u8 *)(a)))->f14)) == 1) {
        return 1;
    }
}
return 0;
}

