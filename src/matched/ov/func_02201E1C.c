/*
 * function: WORLDTRADE_SERVER_StateStartUploadFinishAsync
 * address:  0x02201E1C
 * packet:   pkt_02201E1C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DPW_TR_UploadFinishAsync  0x021C8978  arm  ov114
 *

 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
#include "../include/Obj12243.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void DPW_TR_UploadFinishAsync(u8 *p);

int WORLDTRADE_SERVER_StateStartUploadFinishAsync(u8 *p)
{
    DPW_TR_UploadFinishAsync(p);
    ((struct Obj12243 *)p)->f28 = 0x1b;
    ((struct Obj12243 *)p)->fF8C = 0x0;
    return 0x2;
}
