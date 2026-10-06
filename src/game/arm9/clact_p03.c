/*
 * file:     clact_p03.c
 * unit:     yes
 * function: func_0204BE38, func_0204BE84, func_0204BF28, func_0204BF40, func_0204BFC4
 * address:  0x0204BE38
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
 *   func_0204C2C8   0x0204C2C8  arm
 *   func_02065B74  0x02065B74  arm
 *   g_020A1418     0x020A1418  data
 *   g_020A13F4     0x020A13F4  data
 *   g_020A1388     0x020A1388  data
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02063294  0x02063294  arm
 *   g_02146A74     0x02146A74  data
 *   func_0204BF40  0x0204BF40  arm
 */
#include "../../matched/include/Obj16091.h"

struct Box;
struct Pair;
struct Obj;
struct Win;
struct OamEntry;
typedef unsigned char u8;

typedef unsigned int u32;

typedef void (*CullFn)(void);

struct Elem {
    u8 pad_00[0x40];
    CullFn fn;
    u8 pad_44[4];
};

struct Obj {
    u8 pad_00[0x30];
    u32 f30;
    u8 pad_34[0x64];
    struct Elem *f98;
    u32 f9c;
};

typedef signed int     s32;

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

typedef unsigned short u16;

struct OamEntry {
    u16 attr[4];
};

struct Mgr {
    u8  pad_000[0xf0];
    u16 unk_f0;
    u16 unk_f2;
    u32 unk_f4;
};

extern void func_0204C2C8(struct Elem *e, struct Pair *p, s32 u2, s32 u3, struct Box *box);
extern void func_02065B74(struct Obj *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32  func_02063294(struct Win *win, struct OamEntry *entry, u32 mode);
extern void func_0204BF40(struct Win *win, struct OamEntry *src, u32 mode, u32 pal, u32 op);
void func_0204BE84(D *a0, const T *a1);
void func_0204BF28(u8 *p, u32 idx);
void func_0204BFC4(u32 a0, u32 a1);
extern S12  g_020A1418[];
extern u32  g_020A13F4[];
extern u16 g_020A1388[];
extern struct Mgr *g_02146A74;


/*
 * Culling on/off for a 0x48-stride element array (the same f98/f9c pair
 * func_0204BD94 allocates): on != 0 installs func_0204C2C8 as each element's
 * +0x40 callback, on == 0 sets obj->f30 = 1 and clears the callbacks.  Reached
 * only through a pool word at 0x0204B0FC; the pool word 0x0204C2C8 resolves
 * sole-ref/code.
 *
 * Two levers, both needed: the non-zero arm first (`if (on != 0)`), and `i`
 * declared before `fn` (tools/permuter.py found the decl-order swap).
 */
void func_0204BE38(struct Obj *obj, int on)
{
    u32 i;
    CullFn fn;

    if (on != 0) {
        fn = (CullFn)func_0204C2C8;
    } else {
        obj->f30 = 1;
        fn = 0;
    }
    for (i = 0; i < obj->f9c; i++) {
        obj->f98[i].fn = fn;
    }
}


/*
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


/*
 * Blocked at MATCH: all 24 concrete bytes are correct (20 code + the pool
 * word), but the ABS32 at +0x0014 has no witness of any class.  0x020A1388
 * is plain data, so only the `literal` class could attest it, and the pool
 * word inside this function is that address's only occurrence image wide.
 * The escape that unblocked 0x0204C83C in this same region (decompile the
 * target to EXACT and cite it as a `matched` witness) does not exist here:
 * nothing compiles a data table.  Same wall as src/matched/func_0204C8B8.c
 * and docs/notes/clact_c_fan_in_1_blockers.c.txt describe for 0x020A138C.
 *
 * Store the u16 entry `idx` of the table at 0x020A1388 into the caller's
 * word at +0x14, zero-extended.
 */
void func_0204BF28(u8 *p, u32 idx)
{
    ((struct Obj16091 *)p)->f14 = g_020A1388[idx];
}


/*
 * Push one OAM entry through the window at `win`, rewriting its palette field
 * on the way.  The caller's 8-byte entry is copied onto the stack first
 * (MI_CpuCopy8, not a struct assignment: the source is only 2-aligned), then
 * the 4-bit palette in bits 12..15 of the attribute halfword at +4 is either
 * BIASED by `pal` (mode 0) or REPLACED with it (mode 1); any other mode leaves
 * the entry alone.  The rewritten copy, not the caller's, is what reaches
 * func_02063294.
 *
 * The bias arm is written as a store through a pointer to the halfword's word
 * (`add r2, sp, #4` then `ldr`/`str` through r2), which is what makes the
 * image reload the base instead of re-using sp; the replace arm is small
 * enough that 1.1p1 predicates it whole
 * (`ldreq`/`lsleq`/`biceq`/`orreq`/`streq`) and needs no such pointer.
 *
 * Signature pinned from src/matched/func_0204BFC4.c, the one filed caller.
 *
 * BYTE-CORRECT, PARKED, NOT FILED.  132 bytes, 0 concrete mismatches; the sole
 * unresolved site is the PC24 to func_02063294 at +0x78.  Blocking evidence
 * class: `label` -- 0x02063294 has no branch anywhere in the image outside
 * 0x0204BF40..0x0204BFC4, and there is no `matched` entry for it
 * (docs/notes/pkt_02063078.c.txt records it as a DIFF, 228 bytes).  Filing
 * func_02063294 unblocks this file with no change to the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BF40.c \
 *       --func func_0204BF40 --addr 0x0204BF40 --cc 1.1p1 --arm
 */
void func_0204BF40(struct Win *win, struct OamEntry *src, u32 mode, u32 pal,
                   u32 op)
{
    struct OamEntry ent;
    u32 *attr2;

    MI_CpuCopy8(src, &ent, sizeof(ent));

    if (op == 0) {
        attr2 = (u32 *)&ent.attr[2];
        *attr2 = (*attr2 & ~0xf000) |
                 ((((u32)(u16)*attr2 >> 12) + pal) << 28 >> 16);
    } else if (op == 1) {
        *(u32 *)&ent.attr[2] = (*(u32 *)&ent.attr[2] & ~0xf000) |
                               (pal << 28 >> 16);
    }

    func_02063294(win, &ent, mode);
}


/*
 * Forward one command at the manager itself: the manager is the command
 * block, its u16 at +0xf0 is the id and the word at +0xf4 the payload.
 */
void func_0204BFC4(u32 a0, u32 a1)
{
    func_0204BF40((struct Win *)g_02146A74, (struct OamEntry *)a0, a1, g_02146A74->unk_f0, g_02146A74->unk_f4);
}
