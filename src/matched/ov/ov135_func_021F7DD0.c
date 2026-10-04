/*
 * function: func_021F7DD0
 * address: 0x021F7DD0
 * packet: pkt_ov135_021F7DD0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021F7B9C 0x021F7B9C thumb ov135
 *   func_021F882C 0x021F882C thumb ov135
 *   func_021F886C 0x021F886C thumb ov135
 *   func_021F81C8 0x021F81C8 thumb ov135
 */
#include "../include/Obj01942.h"
#include "../include/Obj23389.h"
typedef unsigned char u8;
extern int func_021F99F0(void *p);
extern void func_0201F7A8(void *p, unsigned kind);
extern int func_021F7B9C(u8 *p, int event);
extern void func_021F882C(u8 *dst, int i, int kind);
extern int func_021F886C(int x, int y, int which);
typedef unsigned int   u32;
extern void func_021F81C8(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
int func_021F7DD0(u8 *p)
{
    unsigned result = func_021F99F0(((struct Obj01942 *)p)->fDE4);
    switch (result) {
    case 12: case (unsigned)-2:
        func_0201F7A8(((struct Obj01942 *)p)->fD40, 0);
        if (func_021F7B9C(p + 0xB50, ((struct Obj23389 *)(*(u8 * *)&((struct Obj01942 *)p)->fE00))->f20)) {
            ((struct Obj01942 *)p)->f28 = 0;
        } else {
            ((struct Obj01942 *)p)->f28 = 7;
        }
        break;
    case (unsigned)-1:
        break;
    default:
        func_021F882C(p + 0xB50, result, 0);
        ((struct Obj01942 *)p)->f28 = 13;
        result = func_021F886C(((struct Obj01942 *)p)->fB53, ((struct Obj01942 *)p)->fB54, 0);
        func_021F81C8(((struct Obj01942 *)p)->fB6C, ((struct Obj01942 *)p)->fB70, (int)(((struct Obj01942 *)p)->fB68), p + 0xD90, ((struct Obj01942 *)p)->fB50, ((struct Obj01942 *)p)->fB52, result, p + 0xFA0);
        break;
    }
    return 2;
}
