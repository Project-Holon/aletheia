/*
 * function: func_021D6FB4
 * address: 0x021D6FB4
 * packet: pkt_ov120_021D6FB4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: declaring element after i puts the element in r4 and the counter in r5.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj10394.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void func_021D6FB4(u8 *p)
{
    int i;
    u32 element;
    for (i = 0; i < 3; i++) {
        element = (u32)p + (u32)i * 4;
        if (((struct Obj10394 *)element)->f140 != 0) {
            CLACT_DeleteActor(((struct Obj10394 *)element)->f140);
            ((struct Obj10394 *)element)->f140 = 0;
        }
    }
}
