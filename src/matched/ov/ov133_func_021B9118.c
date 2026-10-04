/*
 * function: func_021B9118
 * address: 0x021B9118
 * packet: pkt_ov133_021B9118
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4B10 0x021F4B10 thumb ov112
 *   func_021F4AFC 0x021F4AFC thumb ov112
 */
#include "../include/Obj03825.h"
#include "../include/Obj05409.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021F4B10(u8 *p, int index, int mode);
extern int func_021F4AFC(u8 *p, int index, int mode);
u16 func_021B9118(u8 *p, u8 *q, int v)
{
    int a = func_021F4B10(((struct Obj03825 *)p)->f1884, ((struct Obj05409 *)q)->f0, v);
    int b = func_021F4AFC(((struct Obj03825 *)p)->f1884, ((struct Obj05409 *)q)->f0, v);
    int n;
    if (a == 1) {
        if (((struct Obj05409 *)q)->f10 == 1) n = 6000;
        else n = 5000;
    } else if (b == 1) {
        if (((struct Obj05409 *)q)->f10 == 1) n = 4000;
        else n = 3000;
    } else {
        if (((struct Obj05409 *)q)->f10 == 1) n = 2000;
        else n = 1000;
    }
    return n + (999 - ((struct Obj05409 *)q)->f0);
}
