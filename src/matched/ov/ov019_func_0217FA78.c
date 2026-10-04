/*
 * function: func_0217FA78
 * address: 0x0217FA78
 * packet: pkt_ov019_0217FA78
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047910 0x02047910 arm
 *   func_0217FA54 0x0217FA54 thumb ov019
 */
#include "../include/Obj03097.h"

typedef unsigned int u32;
typedef unsigned short u16;
extern int func_02047910(void *p, int idx, int amount);
extern void func_0217FA54(u32 *p);
void func_0217FA78(u32 *p)
{
    func_02047910((void *)p[3], 0, 0x1000);
    (((struct Obj03097 *)p)->f12)++;
    if (((struct Obj03097 *)p)->f12 > 90) func_0217FA54(p);
}
