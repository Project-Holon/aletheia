/*
 * function: func_021F2508
 * address: 0x021F2508
 * packet: pkt_ov029_021F2508
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02021D50 0x02021D50 thumb
 */
#include "../include/Obj13047.h"
struct S02021D50;
extern void func_02021D50(struct S02021D50 *p);
void func_021F2508(void *task, char *p)
{
    if (((struct Obj13047 *)p)->f210 != 0)
        func_02021D50(((struct Obj13047 *)p)->f210);
}
