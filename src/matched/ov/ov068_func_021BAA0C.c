/*
 * function: func_021BAA0C
 * address:  0x021BAA0C
 * packet:   pkt_ov068_021BAA0C
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040804  0x02040804  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204B8A0  0x0204B8A0  arm
 *   func_021BB0AC  0x021BB0AC  thumb  ov068
 *   d_021BB538     0x021BB538  data  a1
 *   d_021BB704     0x021BB704  data  a4
 *   d_021BB820     0x021BB820  data  a4
 */
#include "../include/Obj00103.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f0;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Rect;

extern int  func_02040804(u32 a);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u8 bg);
struct Obj;
extern void func_0204B8A0(struct Obj *p, u16 v);
extern int  func_021BB0AC(u8 *p, int i);
extern const u8 d_021BB538[];
extern u32  d_021BB704[][6];
extern const Rect d_021BB820[];

void func_021BAA0C(u8 *p, int flag)
{
    int base;
    u32 k;
    int i;

    if (((struct Obj00103 *)p)->f4 >= 5)
        flag = 0;
    ((struct Obj00103 *)p)->f54 = flag;
    base = (func_02040804(((struct Obj00103 *)p)->f2) + 0x14) / 0x18;
    func_020413B0(((struct Obj00103 *)p)->f2, 0, 0, 0x20, 0x20, 5);
    i = 0;
    for (k = 0; k < 5; k++)
        func_020413B0(((struct Obj00103 *)p)->f2, i, (base + k) * 3 + 2, 0x20, 3, d_021BB538[k]);
    for (i = 0; i < 11; i++) {
        if (((struct Obj00103 *)p)->f4 == d_021BB704[i][0] && flag) {
            if (func_021BB0AC(p + 0x44, i))
                func_020413B0(((struct Obj00103 *)p)->f0, d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 7);
            else
                func_020413B0(((struct Obj00103 *)p)->f0, d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 0xC);
        } else {
            if (func_021BB0AC(p + 0x44, i))
                func_020413B0(((struct Obj00103 *)p)->f0, d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 0);
            else
                func_020413B0(((struct Obj00103 *)p)->f0, d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 3);
        }
    }
    for (i = 11; i < 16; i++) {
        if (i - 11 == ((struct Obj00103 *)p)->f4 && flag)
            func_020413B0(((struct Obj00103 *)p)->f0, d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 7);
        else
            func_020413B0(((struct Obj00103 *)p)->f0, d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 0);
    }
    if (flag)
        func_020413B0(((struct Obj00103 *)p)->f2, 0, ((struct Obj00103 *)p)->f4 * 3 + 2, 0x20, 3, 7);
    func_02041B6C(((struct Obj00103 *)p)->f2);
    func_02041B6C(((struct Obj00103 *)p)->f0);
    for (i = 0; i < 11; i++) {
        if (((struct Obj00103 *)p)->f4 == d_021BB704[i][0] && flag) {
            if (func_021BB0AC(p + 0x44, i))
                func_0204B8A0(*(void **)(p + i * 4 + 8), 3);
            else
                func_0204B8A0(*(void **)(p + i * 4 + 8), 2);
        } else {
            if (func_021BB0AC(p + 0x44, i))
                func_0204B8A0(*(void **)(p + i * 4 + 8), 0);
            else
                func_0204B8A0(*(void **)(p + i * 4 + 8), 1);
        }
    }
}
