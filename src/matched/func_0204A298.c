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

typedef unsigned short u16;
typedef unsigned int   u32;

extern int         func_020490A8(int a0, int a1, int a2, int a3);
extern int         func_02030734(int a0, int a1, int a2, const char *file, int line);
extern void        func_02048F4C(int a0, int a1, int a2);
extern int         func_020834C0(int a0, int a1);
extern void        func_020307B0(int a0);
extern const char  sArcUtil3730[];

int func_0204A298(int a0, int a1, int a2, int a3, u32 *out)
{
    int r;
    int t;

    *out = func_020490A8(a0, a1, a2, a3);
    if (a2 != 0) {
        r = func_02030734((u16)((a3 & 0x7fff) | 0x8000), *out, 0, sArcUtil3730, 1642);
    } else {
        r = func_02030734(a3, *out, 0, sArcUtil3730, 1646);
    }
    func_02048F4C(r, a0, a1);
    if (a2 != 0) {
        *out = *(u32 *)r >> 8;
        t = func_02030734(a3, *out, 0, sArcUtil3730, 1656);
        func_020834C0(r, t);
        func_020307B0(r);
        r = t;
    }
    return r;
}
