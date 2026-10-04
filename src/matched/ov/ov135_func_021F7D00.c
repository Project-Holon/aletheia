/*
 * function: func_021F7D00
 * address: 0x021F7D00
 * packet: pkt_ov135_021F7D00
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021F81C8 0x021F81C8 thumb ov135
 */
#include "../include/Obj02856.h"
typedef unsigned char u8;
extern int func_021F99F0(void *p);
extern void func_0201F7A8(void *p, unsigned kind);
typedef unsigned int   u32;
extern void func_021F81C8(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
int func_021F7D00(u8 *p)
{
    unsigned result = func_021F99F0(((struct Obj02856 *)p)->fDE4);
    switch (result) {
    case (unsigned)-2:
        func_0201F7A8(((struct Obj02856 *)p)->fD40, 0);
        ((struct Obj02856 *)p)->f28 = 0;
        break;
    case 0: case 1: case 2:
        ((struct Obj02856 *)p)->fB52 = result + 1;
        ((struct Obj02856 *)p)->f28 = 10;
        func_021F81C8(((struct Obj02856 *)p)->fB6C, ((struct Obj02856 *)p)->fB70, (int)(((struct Obj02856 *)p)->fB68), p + 0xD90, ((struct Obj02856 *)p)->fB50, ((struct Obj02856 *)p)->fB52, -1, p + 0xFA0);
        break;
    }
    return 2;
}
