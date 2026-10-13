/*
 * function: func_022014B8
 * address:  0x022014B8
 * packet:   pkt_022014B8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DPW_TR_GetUploadResultAsync  0x021C8770  arm  ov114
 *

 * State 9 with the slot cleared and the u16 at +0x32 set.
 */
#include "../include/Obj09244.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void DPW_TR_GetUploadResultAsync(u8 *p);

int func_022014B8(u8 *p)
{
    DPW_TR_GetUploadResultAsync(p);
    ((struct Obj09244 *)p)->f28 = 9;
    ((struct Obj09244 *)p)->fF8C = 0;
    ((struct Obj09244 *)p)->f32 = 1;
    return 2;
}
