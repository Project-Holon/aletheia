/*
 * function: func_021B3370
 * address:  0x021B3370
 * packet:   pkt_ov021_021B3370
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3350  0x021B3350  thumb  ov021
 *   func_02007FB8  0x02007FB8  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_021B4714  0x021B4714  thumb  ov021
 *   func_021B4804  0x021B4804  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0200823C  0x0200823C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00030.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021B3350(char *w);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern u32 func_02007E3C(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021B4714(u8 *p, u32 sel, u32 c, u32 d);
extern void func_021B4804(char *w, u32 a);
extern u32 func_0200823C(u32 a);

void func_021B3370(char *w)
{
    u32 n;
    u32 k;
    u32 lim;

    n = func_021B3350(w);
    k = func_02007FB8((u8 *)(((struct Obj00030 *)w)->f10), ((struct Obj00030 *)w)->f1FC, ((struct Obj00030 *)w)->f4);
    if (func_02007E3C((u8 *)(((struct Obj00030 *)w)->f10), ((struct Obj00030 *)w)->f1FC, 1, ((struct Obj00030 *)w)->f4) == 0) {
        func_021B4714((u8 *)w, 10, ((struct Obj00030 *)w)->f1FC, 0);
        w[0] = 10;
        w[1] = 4;
        return;
    }
    lim = ((struct Obj00030 *)w)->f200;
    if (n < lim) {
        if (((struct Obj00030 *)w)->f163 == 0) {
            func_021B4714((u8 *)w, 3, ((struct Obj00030 *)w)->f1FC, 0);
        } else {
            func_021B4714((u8 *)w, 0x10, ((struct Obj00030 *)w)->f1FC, 0);
        }
        w[0] = 10;
        w[1] = 4;
    } else if (n >= lim && n < lim * 2) {
        func_021B4804(w, ((struct Obj00030 *)w)->f162);
        w[0] = 10;
        w[1] = 5;
    } else if (((struct Obj00030 *)w)->f162 == 0) {
        func_021B4714((u8 *)w, 4, ((struct Obj00030 *)w)->f1FC, 0);
        w[0] = 10;
        w[1] = 2;
        ((struct Obj00030 *)w)->f204 = n / ((struct Obj00030 *)w)->f200;
        if (((struct Obj00030 *)w)->f204 > 99) {
            ((struct Obj00030 *)w)->f204 = 99;
        }
        if (((struct Obj00030 *)w)->f204 + k > func_0200823C(((struct Obj00030 *)w)->f1FC)) {
            ((struct Obj00030 *)w)->f204 = func_0200823C(((struct Obj00030 *)w)->f1FC) - k;
        }
    } else {
        func_021B4804(w, ((struct Obj00030 *)w)->f162);
        w[0] = 10;
        w[1] = 6;
    }
}
