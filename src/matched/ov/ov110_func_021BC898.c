/*
 * function: PMSIV_FADE_IsBlendDone
 * address: 0x021BC898
 * packet: pkt_ov110_021BC898
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 */
#include "../include/Obj08002.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
int PMSIV_FADE_IsBlendDone(u8 *p)
{
    if (((struct Obj08002 *)p)->f18 == 0) {
        if (((struct Obj08002 *)p)->f14 == 0) {
            func_02030EAC(((struct Obj08002 *)p)->f1C);
            ((struct Obj08002 *)p)->f18 += 1;
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}
