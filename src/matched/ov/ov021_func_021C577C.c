/*
 * function: func_021C577C
 * address:  0x021C577C
 * packet:   pkt_ov021_021C577C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02020350 0x02020350 thumb
 *   func_02020314 0x02020314 thumb
 *   func_02020324 0x02020324 thumb
 *   func_020202FC 0x020202FC thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021C59F8 0x021C59F8 thumb ov021
 */
#include "../include/Obj04282.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern u32 func_02020350(struct Obj *obj, u32 what);
extern u16 func_02020314(struct Obj *obj);
extern u16 func_02020324(struct Obj *obj, u32 n);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern void func_021C59F8(char *w, int b);

void func_021C577C(void *list)
{
    u16 v[2];
    char *w;
    u16 x;
    u32 y;
    u32 s;
    u32 t;
    u32 d;
    u16 a;

    w = (char *)func_02020350(list, 0x13);
    x = func_02020314(list) >> 3;
    y = func_02020350(list, 9) >> 3;
    if (((struct Obj04282 *)w)->f24 == 0) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020413B0(1, 1, x + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    } else if (((struct Obj04282 *)w)->f24 == 1) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020202FC(list, &v[1], &v[0]);
        s = func_02020350(list, 8);
        t = func_02020350(list, 9);
        d = ((struct Obj04282 *)w)->f1E + ((struct Obj04282 *)w)->f1C - v[1];
        s = s + d * t;
        func_020413B0(1, 1, (s >> 3) + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    }
    if (((struct Obj04282 *)w)->f40 == 1) {
        a = func_02020350(((struct Obj04282 *)w)->f4, 3);
        a = func_02020324(((struct Obj04282 *)w)->f4, a) >> 3;
        func_021C59F8(w, (a + 12) << 3);
    } else {
        func_021C59F8(w, (x + 12) << 3);
    }
}
