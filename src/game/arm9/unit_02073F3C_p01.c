/*
 * file:     unit_02073F3C_p01.c
 * unit:     yes
 * function: func_02073F3C, func_02073FB8
 * address:  0x02073F3C
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214E9FC     0x0214E9FC  data
 *   func_02082A7C  0x02082A7C  arm
 *   func_020862F0  0x020862F0  arm
 *   func_020894B4  0x020894B4  arm
 *   ptr_0214EA50   0x0214EA50  data
 *   func_020788D8  0x020788D8  arm
 *   func_020788AC  0x020788AC  arm
 *   func_020789A4  0x020789A4  arm
 *   func_02074048  0x02074048  arm
 */
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int    s32;

struct G {
    u32 f00;
    u8  pad04[8];
    u32 f0c;
    u32 f10;
    u32 f14;
    u8  pad18[4];
    u32 f1c;
    u8  pad20[4];
    u32 f24;
    u32 f28;
    s32 f2c;
};

struct Pair { u32 a; u32 b; };

struct Ctx {
    u8  pad00[0x30];
    u32 f30;
    u8  f34[0x48];
    struct Pair f7c;
    u8  pad84[4];
    u32 f88;
    u32 f8c;
    u32 f90;
    u32 f94;
};

extern void func_02082A7C(u32 a, u32 b, u32 c);
extern void func_020862F0(u32 a, u32 b);
extern void func_020894B4(u32 a, u32 b, u32 c, u32 d);
extern u32  func_020788D8(struct Pair *p, const char *path);
extern void func_020788AC(void *p);
extern u32  func_020789A4(void *p, struct Pair v);
extern u32  func_02074048(struct Ctx *c, u32 a, u32 b);
void func_02073F3C(void);
extern struct G g_0214E9FC;
extern struct Ctx *ptr_0214EA50;


/*
 * Shutdown of the global sequence object g_0214E9FC: clear +0x1C, unbind both
 * channel handles (+0x0C and +0x10) from the owner at +0x14 through
 * func_02082A7C then func_020862F0, and finally release the channel mask built
 * from +0x2C with func_020894B4.
 *
 * PINNED ../2.0/sp2, the pin six cluster siblings now carry (func_020737C0,
 * func_02073AD0, func_02073B3C, func_02073CA0, func_020746E8, func_02074894).
 * docs/notes/pkt_02073F3C.c.txt recorded this exact body as blocked under
 * dsi/1.1p1, which pools the three separate `mov r0,#0` into one callee-saved
 * register, widens the push from {r4,lr} to {r3,r4,r5,lr}, and then under the
 * extra pressure reloads the global's address through a fresh pool word in the
 * tail: 128 bytes against 124, 94 concrete bytes out
 * (docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md).
 * Under the pin the note's own C is 124 bytes, 0 concrete mismatches, with no
 * further change to the C at all.
 *
 * The mask arm must be written condition-first (`if (f2c >= 0) m = 1u << f2c;
 * else m = 0;`) to give the image's `movge r0,#1` / `lslge r2,r0,r1` /
 * `movlt r2,#0`, the same lever docs/notes/pkt_02073BF0.c.txt records for
 * func_02073EE4; f2c is therefore signed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02073F3C.c \
 *       --func func_02073F3C --addr 0x02073F3C --cc ../2.0/sp2 --arm
 */
void func_02073F3C(void)
{
    struct G *g = &g_0214E9FC;
    u32 m;

    if (g->f00 == 0) return;
    g->f1c = 0;
    func_02082A7C(0, g->f0c, g->f14);
    func_02082A7C(0, g->f10, g->f14);
    func_020862F0(g->f0c, g->f14);
    func_020862F0(g->f10, g->f14);
    if (g->f2c >= 0) m = 1u << g->f2c;
    else m = 0;
    func_020894B4(g->f24, g->f28, m, 0);
}


/*
 * The archive open path.  The second parameter is the archive's path string
 * (the only caller, func_02005B24, loads 0x020A7010 into r1) and it is
 * forwarded untouched to func_020788D8(&c->f7c, path), which moves r1 into r0
 * for its own lookup.  Keeping r1 live across the four zero stores is what
 * parks the zero in ip; the earlier DIFF (docs/notes/pkt_02073F3C.c.txt) had
 * func_020788D8 as one-argument and the path as dead.
 */
u32 func_02073FB8(struct Ctx *c, const char *path, u32 a, u32 b)
{
    c->f90 = 0;
    c->f88 = 0;
    c->f8c = 0;
    c->f94 = 0;
    if (func_020788D8(&c->f7c, path) == 0) return 0;
    func_020788AC(c->f34);
    if (func_020789A4(c->f34, c->f7c) == 0) return 0;
    c->f30 = 1;
    if (func_02074048(c, a, b) == 0) return 0;
    ptr_0214EA50 = c;
    return 1;
}
