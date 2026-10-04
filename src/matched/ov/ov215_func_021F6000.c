/*
 * function: func_021F6000, func_021F601C
 * address: 0x021F6000
 * packet: pkt_ov215_021F6000
 * region: ov215
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020063B4 0x020063B4 thumb
 */
#include "../include/Obj14708.h"
#include "../include/Obj25744.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020063B4(u8 *a0, u32 *a1, u32 a2);
void func_021F6000(void *unused, char *p)
{
    ((struct Obj14708 *)p)->f24 = 0;
    func_020063B4((u8 *)0x519, (u32 *)(p + 0x24), 1);
    ((struct Obj14708 *)p)->f18 = 5;
}

int func_021F601C(void *unused, char *p)
{
    int state = ((struct Obj25744 *)p)->f18;
    int result = 1;
    if (state != 5 && state != 6) result = 0;
    return result;
}
