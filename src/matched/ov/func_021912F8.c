/*
 * function: FIELD_MSGBG_WaitTalkWinClose
 * address:  0x021912F8
 * packet:   pkt_021912F8
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
 *   TALKMSGWIN_IsFree  0x02194960  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02082BCC(u32, u32, u32);
extern u32 TALKMSGWIN_IsFree(u32, u32, u32, u32);

int FIELD_MSGBG_WaitTalkWinClose(u32 a, u32 b, u32 c, u32 d)
{
if (TALKMSGWIN_IsFree(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8, *(u8 *)((u8 *)(a) + 1), c, d) != 0) {
    func_02082BCC(a, 0, 52);
    return 1;
}
return 0;
}

