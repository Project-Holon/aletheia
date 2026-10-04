/*
 * function: func_021F0340
 * address: 0x021F0340
 * packet: pkt_ov035_021F0340
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027858 0x02027858 thumb
 */
#include "../include/Obj09809.h"
struct TaskMenu;
extern void func_02027858(struct TaskMenu *m);
void func_021F0340(char *p)
{
    if (((struct Obj09809 *)p)->f44 != 0) {
        func_02027858(((struct Obj09809 *)p)->f44);
        ((struct Obj09809 *)p)->f44 = 0;
    }
}
