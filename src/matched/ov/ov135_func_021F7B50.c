/*
 * function: func_021F7B50
 * address: 0x021F7B50
 * packet: pkt_ov135_021F7B50
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F875C 0x021F875C thumb ov135
 */
#include "../include/Obj02855.h"
#include "../include/Obj23386.h"
typedef unsigned char u8;
extern void *func_021F875C(void *p, void *dst, void *win, void *bank, void *names, void *obj, void *ctx);
int func_021F7B50(u8 *p)
{
    ((struct Obj02855 *)p)->fDF4 = func_021F875C(p, p + 0xDE8, ((struct Obj02855 *)p)->fD54, ((struct Obj02855 *)p)->fB6C, ((struct Obj02855 *)p)->fB70, ((struct Obj02855 *)p)->fE00, ((struct Obj23386 *)(*(u8 * *)&((struct Obj02855 *)p)->f0))->f10);
    ((struct Obj02855 *)p)->fBC = 0xFFFF;
    ((struct Obj02855 *)p)->f28 = 6;
    return 2;
}
