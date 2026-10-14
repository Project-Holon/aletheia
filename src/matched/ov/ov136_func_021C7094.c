/*
 * function: MB_SEQ_StartPartyListForReturn
 * address:  0x021C7094
 * packet:   pkt_ov136_021C7094
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_CreatePartyListArgs 0x021C7430 thumb
 */
#include "../include/Obj08206.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern void MB_SEQ_CreatePartyListArgs(u8 *, int, u16, u16);
int MB_SEQ_StartPartyListForReturn(u8 *p)
{
    if (((struct Obj08206 *)p)->f24 == 0) {
        ((struct Obj08206 *)p)->f28 = 0x15;
        return 0;
    }
    MB_SEQ_CreatePartyListArgs(p, 0xB, ((struct Obj08206 *)p)->f22, ((struct Bf7 *)(p + 0x21))->v);
    ((struct Obj08206 *)p)->f14 = 3;
    return 6;
}
