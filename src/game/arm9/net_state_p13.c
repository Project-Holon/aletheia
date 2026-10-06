/*
 * file:     net_state_p13.c
 * unit:     yes
 * function: func_020371D8, func_02037200, func_02037224, func_02037234, func_02037258, func_02037288, func_02037478
 * address:  0x020371D8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469C8  0x021469C8  data
 *   func_02036D64  0x02036D64  arm
 *   d_020A7A20   0x020A7A20  data  a1
 *   func_0203D788  0x0203D788  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   lbl_021469D0   0x021469D0  data
 *   str_020A7A24   0x020A7A24  data
 *   func_02030734  0x02030734  arm
 *   func_02036AF4  0x02036AF4  arm
 *   g_021469D0     0x021469D0  data
 *   str_020A7A20   0x020A7A20  data
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203640C  0x0203640C  arm
 *   func_02036B4C  0x02036B4C  arm
 */
#include "../../matched/include/Obj05733.h"
#include "../../matched/include/Obj08828.h"

struct Rec;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Notifier_020371D8 {
    u16   unk00;      /* 0x00 */
    u16   unk02 : 14; /* 0x02, bits 0-13 */
    u16   mode  : 2;  /* 0x02, bits 14-15 */
    void *handler;    /* 0x04 */
};

struct Notifier_1 {
    u32   unk00;
    void *handler;
};

typedef unsigned char  u8;

struct Net_02037288 {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    u8  pad1C[0x1ac - 0x1c];
    u32 f1AC;
    u8  pad1B0[0x1e0 - 0x1b0];
    u32 f1E0;
};

typedef signed int     s32;

struct Net_02037478 {
    u32  f00;
    u32 *f04;
    u8  *f08;
    u8  *f0C;
    u8  *f10;
    u8  *f14;
    u8   pad18[0x1b0 - 0x18];
    u32  f1B0;
    u32  f1B4[8];
    u8   pad1D4[0x1e0 - 0x1d4];
    u32  f1E0;
};

extern u32 func_02036D64(u8 *p);
extern void *func_0203D788(void);
extern u32  func_0203D6BC(void);
extern u32  func_0203D680(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02036AF4(u8 *p, u32 n, u32 a, u32 b);
extern void func_02082BCC(u8 *p, u32 v, u32 n);
extern void func_0203640C(struct Rec *p, u32 a, int b);
extern int func_02036B4C(int a0);
void func_020371D8(u32 mode);
u32 func_02037200(void);
void func_02037224(u8 v, int b);
void func_02037234(u8 *p);
u32 func_02037258(void);
int func_02037288(u32 a0, u32 heap, u32 c);
void func_02037478(void);
extern struct Notifier_020371D8 g_021469C8;
extern u8 d_020A7A20;
extern struct Net_02037288 *lbl_021469D0;
extern char str_020A7A24[];
extern struct Net_02037478 *g_021469D0;
extern u8 str_020A7A20[];


/*
 * Setter for the two-bit mode field in the top of the halfword at +0x02 of
 * the global at 0x021469C8.  The `lsl #0x1e` plus the `lsr #16` shifter
 * operand on the `orr` is the bitfield insert, and the `bic` of 0xc000 is
 * the field's own mask.  The `lsl #0x10 / lsr #0x10` pair above it is an
 * explicit `(u16)` cast on the stored value: declaring the parameter `u16`
 * instead drops the pair entirely (the insert already masks), so the cast
 * has to be written out.  See
 * docs/idioms/an-explicit-narrowing-cast-into-a-bitfield-is-not-folded.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020371D8.c \
 *       --func func_020371D8 --addr 0x020371D8 --cc 1.1p1 --arm
 */
void func_020371D8(u32 mode)
{
    g_021469C8.mode = (u16)mode;
}



u32 func_02037200(void)
{
    if (g_021469C8.handler == 0) {
        return 1;
    }
    return func_02036D64(g_021469C8.handler);
}



void func_02037224(u8 v, int b)
{
    d_020A7A20 = v;
}



/*
 * Resets a sixteen-byte record: both halfwords at +8 and +0x0A become 0xFFFF
 * (the "no value" sentinel) and the words at +0 and +4 and the halfword at
 * +0x0C are cleared.  The sentinel cannot be encoded as an ARM immediate, so it
 * comes out of the function's own literal pool; the stores then run in the
 * order the source writes them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037234.c \
 *       --func func_02037234 --addr 0x02037234 --cc 1.1p1 --arm
 */
void func_02037234(u8 *p)
{
    ((struct Obj05733 *)p)->fC = 0;
    ((struct Obj05733 *)p)->f8 = 0xFFFF;
    ((struct Obj05733 *)p)->fA = 0xFFFF;
    ((struct Obj05733 *)p)->f4 = 0;
    ((struct Obj05733 *)p)->f0 = 0;
}



/*
 * The current capacity, or the measured one: when the state object's byte at
 * +0x64 is set and its halfword at +0x6C is non-zero, that halfword is the
 * answer; otherwise the two measurement calls are multiplied.
 *
 * The conjunction is the reason both loads after the first comparison are
 * conditional (`ldrhne`, `cmpne`) and the early return is a bare `popne`:
 * written as one `&&` in a single `if`, mwcc keeps the whole guard inside the
 * flags.  The product is a plain `mul`, so the function returns a 32-bit
 * value, not a narrowed one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037258.c \
 *       --func func_02037258 --addr 0x02037258 --cc 1.1p1 --arm
 */
u32 func_02037258(void)
{
    u8 *p;

    p = func_0203D788();
    if (p[0x64] != 0 && ((struct Obj08828 *)p)->f6C != 0)
        return ((struct Obj08828 *)p)->f6C;
    return func_0203D6BC() * func_0203D680();
}



/*
 * Closes the 4-byte residue docs/notes/pkt_02037288_wave25.c.txt records
 * (the `mov r3, r4` / `lsl r1, r1, #1` pair at +0x00B0).  The lever is the
 * ALLOCATION RESULT TYPE, not the size spelling: the seven pointer fields
 * are declared `void *` so each func_02030734 result is stored without an
 * integer conversion.  With them declared `u32` the file does not even
 * compile; with a cast at each site the argument scheduling shifts and the
 * 0xE8 call's size is finished before r3 is written.  The size arguments
 * themselves must stay as in-place expressions re-reading ->f1E0, never
 * bound to a local.
 *
 * The note's other two findings are confirmed and kept: the prototype
 * returns int (the tail `mov r0,#1` is a `return 1`), and the +0x1E0 store
 * is two separate `+ 0x40` adds in the two arms, not one factored add.
 */
int func_02037288(u32 a0, u32 heap, u32 c)
{
    u32 n;
    u32 m;

    if (lbl_021469D0 == 0) {
        n = func_0203D680();
        m = func_02037258();
        lbl_021469D0 = func_02030734(heap, 0x1f0, 1, str_020A7A24, 0xdd);
        if (c != 0)
            lbl_021469D0->f1E0 = m + 0x40;
        else
            lbl_021469D0->f1E0 = a0 + 0x40;

        lbl_021469D0->f14 = func_02030734(heap, lbl_021469D0->f1E0 * 3, 1,
                                          str_020A7A24, 0xe6);
        lbl_021469D0->f18 = func_02030734(heap, lbl_021469D0->f1E0 * 2, 1,
                                          str_020A7A24, 0xe8);
        lbl_021469D0->f10 = func_02030734(heap, n * lbl_021469D0->f1E0, 1,
                                          str_020A7A24, 0xe9);
        lbl_021469D0->f00 = func_02030734(heap, func_0203D6BC(), 1,
                                          str_020A7A24, 0xec);
        lbl_021469D0->f04 = func_02030734(heap, func_0203D6BC() * 15, 1,
                                          str_020A7A24, 0xed);
        lbl_021469D0->f08 = func_02030734(heap, m, 1, str_020A7A24, 0xee);
        lbl_021469D0->f0C = func_02030734(heap, m * 2, 1, str_020A7A24, 0xef);
        func_02036AF4((u8 *)lbl_021469D0 + 0xcc, 0x64,
                      (u32)((u8 *)lbl_021469D0 + 0x1c), heap);
        func_02036AF4((u8 *)lbl_021469D0 + 0xf4, 0xb4,
                      (u32)((u8 *)lbl_021469D0 + 0x3c), heap);
        lbl_021469D0->f1AC = 1;
        func_02037478();
    }
    *(u16 *)((u8 *)lbl_021469D0 + 0x100 + 0xe4) = 0;
    *((u8 *)lbl_021469D0 + 0x1e7) = 0;
    return 1;
}



/*
 * Second half of net_system init: wipe and re-seed every buffer
 * func_02037288 allocated (docs/families/net_system.h).  Closed from the
 * 520-byte / 135-out source of docs/notes/pkt_02037288_wave25.c.txt with two
 * changes:
 *   1. func_0203640C is a THREE-argument call at every site.  The first
 *      loop's "leftover" r2 is the slot stride f1E0 passed as the header's
 *      length (same finding as func_02037680); with it the file is 12 out.
 *   2. the loop index is declared FIRST, before the three counts.  With
 *      the counts first, n1 and i swap r7/r8 (the last 12 bytes).
 * The three product pairs stay spelled differently per site (n2 + n2 vs
 * n2 << 1, etc.) so the compiler rematerialises instead of CSEing them.
 */
void func_02037478(void)
{
    s32 i;
    s32 n1;
    s32 n2;
    s32 n3;

    n1 = func_0203D680();
    n2 = func_02037258();
    n3 = func_0203D6BC();

    func_02082BCC(g_021469D0->f10, 0, g_021469D0->f1E0 * n1);
    for (i = 0; i < n1; i++) {
        func_0203640C((struct Rec *)((u8 *)g_021469D0 + 0x4c + i * 16),
              (u32)(g_021469D0->f10 + i * g_021469D0->f1E0), g_021469D0->f1E0);
        ((u8 *)g_021469D0)[0x1d7 + i] = 0;
    }

    func_02082BCC(g_021469D0->f0C, 0, n2 + n2);
    func_0203640C((struct Rec *)((u8 *)g_021469D0 + 0x3c), (u32)g_021469D0->f0C, (u32)n2 << 1);
    for (i = 0; i < n2; i++)
        g_021469D0->f08[i] = 0;

    func_02082BCC((u8 *)g_021469D0->f04, 0, n3 * 16 - n3);
    func_0203640C((struct Rec *)((u8 *)g_021469D0 + 0x1c), (u32)((u8 *)g_021469D0->f04), ((u32)n3 << 4) - n3);
    *(u8 *)g_021469D0->f00 = 0xff;
    for (i = 1; i < n3; i++)
        ((u8 *)g_021469D0->f00)[i] = 0;

    func_02082BCC(g_021469D0->f14, 0, g_021469D0->f1E0 + g_021469D0->f1E0 * 2);
    func_0203640C((struct Rec *)((u8 *)g_021469D0 + 0x2c), (u32)g_021469D0->f14,
                  g_021469D0->f1E0 * 3);
    for (i = 0; i < 8; i++) {
        func_02037234((u8 *)g_021469D0 + 0x11c + i * 16);
        g_021469D0->f1B4[i] = 0;
    }
    g_021469D0->f1B0 = 0;
    func_02037234((u8 *)g_021469D0 + 0x19c);
    func_02037224(4, 0x13a);
    str_020A7A20[1] = 4;
    func_02036B4C((int)((u8 *)g_021469D0 + 0xcc));
    func_02036B4C((int)((u8 *)g_021469D0 + 0xf4));
    ((u8 *)g_021469D0)[0x1e8] = 0;
    ((u8 *)g_021469D0)[0x1eb] = 1;
    ((u8 *)g_021469D0)[0x1ea] = 0;
    ((u8 *)g_021469D0)[0x1ed] = 0;
}
