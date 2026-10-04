/*
 * function: func_021F0390
 * address:  0x021F0390
 * packet:   pkt_ov029_021F0390
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * `const` on the two key/row tables schedules the second table's pool load
 * above the `[sp]` stack-argument store in the cycle loop (14 bytes out
 * without it). The four-way reset is `s18 = s8 = sc = s14 = 0`: the chain
 * stores right to left.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02158630  0x02158630  thumb  ov010
 *   func_021F09DC  0x021F09DC  thumb  ov029
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F31EC     0x021F31EC  data  ov029  a4
 *   d_021F31F8     0x021F31F8  data  ov029  a4
 */
#include "../include/Obj03631.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
struct BigObj;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *key);
extern int func_02158630(int);
extern int func_021F09DC(u8 *p, int row, int v, int st, int a, int b);
extern const u32 d_021F31EC[];
extern const int d_021F31F8[];

void func_021F0390(u8 *p, int a, int b, int c, int e)
{
    int sv;
    int flags;
    int one;
    int mode;
    int s18;
    int s14;
    int i;
    int sc;
    int s8;
    u32 keys;
    int idx;

    sv = func_02012138((const struct Ctx *)((struct Obj03631 *)p)->f1C);
    flags = 0;
    one = 1;
    s8 = 1;
    s18 = 4;
    s14 = 3;
    sc = 2;
    if (c != 0) {
        s18 = s8 = sc = s14 = 0;
    }
    keys = func_0201058C((void *)func_0201283C(func_020120F4((const struct Ctx *)(((struct Obj03631 *)p)->f1C))));
    mode = func_02158630(sv);
    if (e != 0) {
        if (mode == 3) {
            func_021F09DC(p, 2, 3, s14, a, b);
        } else if (keys & 8) {
            flags |= 4;
            func_021F09DC(p, 2, 2, s14, a, b);
        }
    }
    if (flags == 0) {
        one = 0;
        if (keys & 2) {
            flags |= 2;
        }
        if (keys & 0x3c) {
            flags |= 4;
        }
        if (keys & 0x3c0) {
            flags |= 8;
        }
        if (keys & 0x40) {
            func_021F09DC(p, 1, 3, sc, a, b);
        } else if (keys & 0x100) {
            func_021F09DC(p, 1, 0, sc, a, b);
        } else if (keys & 0x80) {
            func_021F09DC(p, 1, 1, sc, a, b);
        } else if (keys & 0x200) {
            func_021F09DC(p, 1, 0, sc, a, b);
        }
        if (mode != 0) {
            if (mode != 3) {
                func_021F09DC(p, 2, 3, sc, a, b);
            }
        } else {
            for (i = 0; i < 3; i++) {
                p[0x44d] = (p[0x44d] + 1) % 3;
                idx = p[0x44d];
                if ((d_021F31EC[idx] & keys) || (idx == 2 && p[0x450] != 0)) {
                    if (func_021F09DC(p, 2, d_021F31F8[idx], sc, a, b) != 0) {
                        if (p[0x44d] == 2) {
                            p[0x450] = 0;
                        }
                        break;
                    }
                }
            }
            if (i == 3) {
                func_021F09DC(p, 2, 8, s8, a, b);
            }
        }
    }
    if (one == 0) {
        func_021F09DC(p, 0, 6, s8, a, b);
        if (!(flags & 8)) {
            func_021F09DC(p, 1, 7, s8, a, b);
        }
        if (!(flags & 4)) {
            func_021F09DC(p, 2, 8, s8, a, b);
        }
    } else {
        func_021F09DC(p, 0, 5, s18, a, b);
        func_021F09DC(p, 1, 5, s18, a, b);
    }
}
