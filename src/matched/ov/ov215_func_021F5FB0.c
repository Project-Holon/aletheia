/*
 * function: func_021F5FB0, func_021F5FCC
 * address: 0x021F5FB0
 * packet: pkt_ov215_021F5FB0
 * region: ov215
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020063B4 0x020063B4 thumb
 */
#include "../include/Obj14707.h"
#include "../include/Obj25743.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020063B4(u8 *a0, u32 *a1, u32 a2);
void func_021F5FB0(void *unused, char *p)
{
    ((struct Obj14707 *)p)->f24 = 0;
    func_020063B4((u8 *)0x3f3, (u32 *)(p + 0x24), 1);
    ((struct Obj14707 *)p)->f18 = 3;
}

int func_021F5FCC(void *unused, char *p)
{
    if (((struct Obj25743 *)p)->f18 == 4) return 1;
    return 0;
}
