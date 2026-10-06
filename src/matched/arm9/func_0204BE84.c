/*
 * function: func_0204BE84
 * address:  0x0204BE84
 * packet:   pkt_0204BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02065B74  0x02065B74  arm
 *   func_0204BF28  0x0204BF28  arm
 *   g_020A1418     0x020A1418  data
 *   g_020A13F4     0x020A13F4  data
 *
 * Wave 15 (register-tie lane).  Three facts closed the 104-byte residue of
 * docs/notes/pkt_0204BE84.c.txt:
 *  - func_0204BF28 takes TWO arguments (a0, a1->f8): its body is
 *    `a0->f14 = tbl_020A1388[idx]`, and the image's `ldr r1, [r4, #8]`
 *    inside the store block is that argument, not an early load of the
 *    table index.  The "missing mov r0, r5" of the older note follows.
 *  - `const T *a1` (the source record is read-only); the volatile +0x04
 *    device of the older note is no longer needed.
 *  - the f2 and f6 halfwords bound to s16 locals at the image's load points
 *    (found by permuter anneal, then reduced by hand): that fixes the
 *    f0, f2, f6, f4 load order and the r2/r3 pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BE84.c \
 *       --func func_0204BE84 --addr 0x0204BE84 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;

typedef struct { u32 w0, w1, w2; } S12;

typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u32 f8;
    u32 fC;
} T;

typedef struct {
    int f00;
    int f04;
    int f08;
    int f0c;
    u8  pad_10[0x28 - 0x10];
    int f28;
    int f2c;
    int f30;
    int f34;
} D;

struct Obj;
extern void func_02065B74(struct Obj *p);
extern void func_0204BF28(u8 *p, u32 idx);
extern S12  g_020A1418[];
extern u32  g_020A13F4[];

void func_0204BE84(D *a0, const T *a1)
{
    S12 t;
    s16 y;
    s16 x;

    func_02065B74((struct Obj *)a0);
    x = a1->f2;
    a0->f00 = (int)a1->f0 << 12;
    y = a1->f6;
    a0->f04 = (int)x << 12;
    a0->f08 = (int)a1->f4 << 12;
    a0->f0c = (int)y << 12;
    func_0204BF28((u8 *)a0, a1->f8);
    t = g_020A1418[a1->f8];
    t.w2 = g_020A13F4[a1->fC];
    a0->f28 = (int)t.w0;
    a0->f2c = (int)t.w1;
    a0->f34 = (int)t.w2;
}
