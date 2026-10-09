/*
 * file:     unit_02073F3C.c
 * unit:     yes
 * function: func_02073F3C, func_02073FB8, func_02074048, func_02074220
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
 *   func_02078B44  0x02078B44  arm
 *   func_02078B70  0x02078B70  arm
 *   func_0207482C  0x0207482C  arm
 *   func_020746C4  0x020746C4  arm
 *   func_020746D0  0x020746D0  arm
 *   func_020746DC  0x020746DC  arm
 *   func_02082A90  0x02082A90  arm
 */
#include "../../matched/include/Obj11683.h"

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

struct Tbl { u32 pad0; u32 pad4; u32 count; };

struct Arc {
    u8  pad00[0x10];
    u32 f10_off;
    u32 f14_size;
    u32 f18_off;
    u32 f1c_size;
    u32 f20_off;
    u32 f24_size;
    u8  pad28[8];
    u32 f30;
    u8  f34_file[0x48];
    struct Pair f7c;
    u8  pad84[4];
    struct Tbl *f88;
    void *f8c;
    void *f90;
    u32 f94;
};

extern void func_02082A7C(u32 a, u32 b, u32 c);
extern void func_020862F0(u32 a, u32 b);
extern void func_020894B4(u32 a, u32 b, u32 c, u32 d);
extern u32  func_020788D8(struct Pair *p, const char *path);
extern void func_020788AC(void *p);
extern u32  func_020789A4(void *p, struct Pair v);
extern int   func_02078B44(void *file, u32 pos, int origin);
extern int   func_02078B70(void *file, void *dst, int len);
extern void *func_0207482C(u32 *heap, u32 size, void (*cb)(void *, u32, struct Arc *),
                           struct Arc *c, u32 e);
extern void  func_020746C4(void *payload, u32 size, struct Arc *c);
extern void  func_020746D0(void *payload, u32 size, struct Arc *c);
extern void  func_020746DC(void *payload, u32 size, struct Arc *c);
extern void func_02082A90(void *dst, void *src, u32 n);
void func_02073F3C(void);
u32 func_02073FB8(struct Arc *c, const char *path, u32 *heap, u32 all);
u32 func_02074048(struct Arc *c, u32 *heap, u32 all);
void func_02074220(struct Arc *h, u8 *base);
extern struct G g_0214E9FC;
extern struct Arc *ptr_0214EA50;



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
u32 func_02073FB8(struct Arc *c, const char *path, u32 *heap, u32 all)
{
    c->f90 = 0;
    c->f88 = 0;
    c->f8c = 0;
    c->f94 = 0;
    if (func_020788D8(&c->f7c, path) == 0) return 0;
    func_020788AC(c->f34_file);
    if (func_020789A4(c->f34_file, c->f7c) == 0) return 0;
    c->f30 = 1;
    if (func_02074048(c, heap, all) == 0) return 0;
    ptr_0214EA50 = c;
    return 1;
}



/*
 * The archive header load: seek to 0 and read the 0x30-byte header over the
 * object itself, then (only with a heap) allocate and read the three tables
 * the header names -- (+0x18 offset, +0x1c size) into +0x90, (+0x20, +0x24)
 * into +0x88, and, when `all` is set and +0x14 is non-zero, (+0x10, +0x14)
 * into +0x8c.  Each allocation goes through func_0207482C with a 12-byte
 * release callback (func_020746C4 / D0 / DC, filed EXACT alongside) that
 * nulls the matching pointer.
 *
 * Two levers: the heap test is a wrapping `if (heap != 0) { ... }` so the
 * null case branches to the shared `return 1` (a separate early return is 8
 * bytes long), and each read's result is a named local, which is what puts
 * it in cmp's left slot (docs/idioms/cmp-operand-order-names-the-temporary.md).
 * The listing extent is 472 bytes including the three-word pool.
 */
u32 func_02074048(struct Arc *c, u32 *heap, u32 all)
{
    int n;

    if (func_02078B44(c->f34_file, 0, 0) == 0) return 0;
    if (func_02078B70(c->f34_file, c, 0x30) != 0x30) return 0;
    if (heap != 0) {
        c->f90 = func_0207482C(heap, c->f1c_size, func_020746C4, c, 0);
        if (c->f90 == 0) return 0;
        if (func_02078B44(c->f34_file, c->f18_off, 0) == 0) return 0;
        n = func_02078B70(c->f34_file, c->f90, c->f1c_size);
        if (n != c->f1c_size) return 0;

        c->f88 = func_0207482C(heap, c->f24_size, func_020746D0, c, 0);
        if (c->f88 == 0) return 0;
        if (func_02078B44(c->f34_file, c->f20_off, 0) == 0) return 0;
        n = func_02078B70(c->f34_file, c->f88, c->f24_size);
        if (n != c->f24_size) return 0;

        if (all != 0 && c->f14_size != 0) {
            c->f8c = func_0207482C(heap, c->f14_size, func_020746DC, c, 0);
            if (c->f8c == 0) return 0;
            if (func_02078B44(c->f34_file, c->f10_off, 0) == 0) return 0;
            n = func_02078B70(c->f34_file, c->f8c, c->f14_size);
            if (n != c->f14_size) return 0;
        }
    }
    return 1;
}



/*
 * Relocates a freshly loaded archive header in place and publishes it: copy
 * the 0x30-byte header to the start of the image buffer, turn the three stored
 * file offsets at +0x10/+0x18/+0x20 into absolute pointers at +0x8C/+0x90/+0x88
 * (a zero offset stays a null pointer), clear +0x94, then walk the 0x10-byte
 * records that begin at f88+0xC and relocate each record's +8 word the same
 * way, and finally clear +0x30 and store the object into ptr_0214EA50.
 *
 * PINNED ../2.0/sp2, the pin six cluster siblings carry (func_020737C0,
 * func_02073AD0, func_02073B3C, func_02073CA0, func_020746E8, func_02073F3C,
 * func_02074894).
 *
 * docs/notes/pkt_02073F3C.c.txt flagged this as the packet's best remaining
 * candidate and had the record and the loop right. Three levers closed it,
 * measured at ../2.0/sp2 from a 184-byte first draft:
 *
 * 1. THE NULL ARMS ARE WRITTEN NULL-FIRST. The image emits `moveq r0,#0`
 *    before `addne r0,r4,r0`, so the source is `if (off == 0) p = 0; else
 *    p = base + off;`. Writing the non-null test first swaps both predicated
 *    instructions at all three sites (this front end never reorders an
 *    if/else -- docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * 2. THE LOOP OFFSET IS DERIVED FROM THE COUNTER, NOT CARRIED. A separate
 *    `off` local incremented by 0x10 costs a second zero: the image
 *    materialises ONE `mov r3,#0` and spends it on both the +0x94 store and
 *    the loop counter, then re-derives the byte offset. Spelling the record
 *    address as `(u8 *)h->f88 + 0xc + i * 0x10` took the residue from 48
 *    concrete bytes to 5.
 *
 * 3. THE STORE IS SHARED BY BOTH ARMS. The last 5 bytes were `moveq r0,r1` /
 *    one `str` in the image against a predicated `streq`/`strne` pair in ours:
 *    binding the relocated value to a local and storing it once after the if
 *    is what merges them
 *    (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md, read the
 *    other way round -- here the value, not the block, is what is shared).
 *
 * Both relocation sites resolve (func_02082A90 by label, ptr_0214EA50 by
 * literal), so nothing further was needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074220.c \
 *       --func func_02074220 --addr 0x02074220 --cc ../2.0/sp2 --arm
 */
void func_02074220(struct Arc *h, u8 *base)
{
    u32 i;

    func_02082A90(base, h, 0x30);

    if (h->f18_off == 0) h->f90 = 0; else h->f90 = (void *)(base + h->f18_off);
    if (h->f20_off == 0) h->f88 = 0; else h->f88 = (struct Tbl *)(base + h->f20_off);
    if (h->f10_off == 0) h->f8c = 0; else h->f8c = (void *)(base + h->f10_off);
    h->f94 = 0;

    for (i = 0; i < h->f88->count; i++) {
        u8 *p = (u8 *)h->f88 + 0xc + i * 0x10;
        u32 v = ((struct Obj11683 *)p)->f0;
        u32 r;
        if (v == 0) r = 0;
        else        r = (u32)(base + v);
        ((struct Obj11683 *)p)->f8 = r;
    }

    h->f30 = 0;
    ptr_0214EA50 = h;
}
