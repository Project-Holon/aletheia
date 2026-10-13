/*
 * function: func_0220163C
 * address:  0x0220163C
 * packet:   pkt_0220163C
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

 * State-setter: hand the object to DPW_TR_UploadFinishAsync, latch state 0xe at +0x28,
 * clear the word at +0xf8c and report 2.
 */
#include "../include/Obj12233.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void DPW_TR_UploadFinishAsync(u8 *p);

int func_0220163C(u8 *p)
{
    DPW_TR_UploadFinishAsync(p);
    ((struct Obj12233 *)p)->f28 = 0xe;
    ((struct Obj12233 *)p)->fF8C = 0;
    return 2;
}
