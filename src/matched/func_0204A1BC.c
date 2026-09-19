/*
 * unit:     no
 * function: func_0204A1BC
 * address:  0x0204A1BC
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
 * arc_util.c's "open a member and read it" entry.  The three __LINE__
 * constants 1599, 1603 and 1611 are the only three the pool carries, and
 * each is the fifth argument of a func_02030734 call whose fourth
 * argument is the file-name word at 0x020A7F30 ("arc_util.c").
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int         func_020490A8(int a0, int a1, int a2, int a3);
extern int         func_02030734(int a0, int a1, int a2, const char *file, int line);
extern void        func_02048F4C(int a0, int a1, int a2);
extern int         func_020834C0(int a0, int a1);
extern void        func_020307B0(int a0);
extern const char  sArcUtil3730[];

int func_0204A1BC(int a0, int a1, int a2, int a3)
{
    int t;
    int r;
    int t2;

    if (a2 != 0) {
        t = func_020490A8(a0, a1, a2, a3);
        r = func_02030734((u16)((a3 & 0x7fff) | 0x8000), t, 0, sArcUtil3730, 1599);
    } else {
        t = func_020490A8(a0, a1, a2, a3);
        r = func_02030734(a3, t, 0, sArcUtil3730, 1603);
    }
    func_02048F4C(r, a0, a1);
    if (a2 != 0) {
        t2 = func_02030734(a3, *(u32 *)r >> 8, 0, sArcUtil3730, 1611);
        func_020834C0(r, t2);
        func_020307B0(r);
        r = t2;
    }
    return r;
}
