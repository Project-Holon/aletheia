/*
 * function: func_021F1BBC
 * address: 0x021F1BBC
 * packet: pkt_ov029_021F1BBC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../include/Obj20395.h"
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void func_021F1BBC(char *p)
{
    int i;
    if (((struct Obj20395 *)p)->f170 != 0) {
        for (i = 0; i < 18; i++) {
            func_0204B3B4((struct Obj *)(*(int *)(p + i * 4 + 0x170)));
            *(int *)(p + i * 4 + 0x170) = 0;
        }
    }
}
