/*
 * unit:     no
 * function: func_0204A298
 * address:  0x0204A298
 * packet:   pkt_0204A1BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020490A8  0x020490A8  arm
 *   func_02030734  0x02030734  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_020834C0  0x020834C0  arm
 *   func_020307B0  0x020307B0  arm
 *   sArcUtil3730   0x020A7F30  data
 *
 * The out-parameter twin of func_0204A1BC directly above it: the handle
 * func_020490A8 returns is written through the fifth (stack) argument and
 * the same three arc_util.c line numbers appear, shifted by 43.
 */
#include "../include/Obj16075.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020490A8(u32 a, u32 b);
extern void *      func_02030734(u32 a0, u32 a1, int a2, const char *file, u16 line);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern int         func_020834C0(int a0, int a1);
extern u32 func_020307B0(void *p);
extern const char  sArcUtil3730[];

int func_0204A298(int a0, int a1, int a2, int a3, u32 *out)
{
    int r;
    int t;

    *out = func_020490A8(a0, a1);
    if (a2 != 0) {
        r = (int)func_02030734((u16)((a3 & 0x7fff) | 0x8000), *out, 0, sArcUtil3730, 1642);
    } else {
        r = (int)func_02030734(a3, *out, 0, sArcUtil3730, 1646);
    }
    func_02048F4C((void *)r, a0, a1);
    if (a2 != 0) {
        *out = ((struct Obj16075 *)r)->f0 >> 8;
        t = (int)func_02030734(a3, *out, 0, sArcUtil3730, 1656);
        func_020834C0(r, t);
        func_020307B0((void *)r);
        r = t;
    }
    return r;
}
