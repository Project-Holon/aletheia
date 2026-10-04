/*
 * function: func_021F055C
 * address:  0x021F055C
 * packet:   pkt_ov032_021F055C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012204  0x02012204  thumb
 *   func_021F253C  0x021F253C  thumb  ov032
 *   func_02035D20  0x02035D20  arm
 *   func_021F0A18  0x021F0A18  thumb  ov032
 *   func_021F08E4  0x021F08E4  thumb  ov032
 *   func_021F1F00  0x021F1F00  thumb  ov032
 *   func_021F096C  0x021F096C  thumb  ov032
 *   func_021F1340  0x021F1340  thumb  ov032
 */
#include "../include/Obj00188.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u32 x, y; } Pair;

struct Ctx;
extern u32 func_02012204(const struct Ctx *p);
extern void func_021F253C(u8 *p, int v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021F0A18(u8 *p, Pair *v);
extern int func_021F08E4(u8 *p, void *pt);
extern void func_021F1F00(u8 *p, u8 i);
extern int func_021F096C(u8 *p, void *pt);
extern void func_021F1340(u8 *p, int a, int b);

int func_021F055C(u8 *p)
{
    Pair v;
    int r;
    int s;

    if (func_02012204((const struct Ctx *)(((struct Obj00188 *)p)->f0)) != 0) {
        func_021F253C(p, 1);
        return 6;
    }
    if (func_02035D20(&v.x, &v.y) == 0)
        return 2;
    if (func_021F0A18(p, &v) == 2)
        return 6;
    r = func_021F08E4(p, &v);
    if (r != -1) {
        p[0x7e] = r;
        func_021F1F00(p, r);
        return 4;
    }
    s = func_021F096C(p, &v);
    if (s != -1) {
        func_021F1340(p, s, 5);
        return 3;
    }
    return 2;
}
