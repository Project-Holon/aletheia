/*
 * function: func_021F8DA4
 * address: 0x021F8DA4
 * packet: pkt_ov135_021F8DA4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06513.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_020307B0(void *p);
int func_021F8DA4(u8 *p)
{
    u32 *state = *(u32 * *)&((struct Obj06513 *)p)->f10DC;
    if (((struct Obj06513 *)p)->f12F4 == 0) {
        switch (state[7]) {
        case 0: ((struct Obj06513 *)p)->f28 = 0; break;
        case 1:
            func_021F4EC0(p, 0, 0);
            ((struct Obj06513 *)p)->f28 = 1;
            break;
        }
        func_020307B0(((struct Obj06513 *)p)->f10DC);
    }
    return 2;
}
