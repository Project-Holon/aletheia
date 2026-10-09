/*
 * file:     unit_0207312C_p01.c
 * unit:     yes
 * function: func_0207312C, func_020731E0
 * address:  0x0207312C
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
 *   g_0214E00C  0x0214E00C  data
 *   g_0214E018  0x0214E018  data
 *   g_0214E024  0x0214E024  data
 *   g_0214E464  0x0214E464  data
 *   func_02060468  0x02060468  arm
 *   func_020604AC  0x020604AC  arm
 *   g_020A5D08  0x020A5D08  data
 *   func_0208A054  0x0208A054  arm
 *   func_02060614  0x02060614  arm
 *   func_02089D6C  0x02089D6C  arm
 *   func_0207368C  0x0207368C  arm
 *   func_02075C08  0x02075C08  arm
 *   func_02075BD4  0x02075BD4  arm
 *   func_020893D0  0x020893D0  arm
 *   func_02075C20  0x02075C20  arm
 *   func_020735EC  0x020735EC  arm
 *   func_02089378  0x02089378  arm
 */
struct DList;
struct LerpObj;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

struct Chan { u8 p00[0x2c]; u8 b2c; u8 p2d[0x3c - 0x2d]; u8 b3c; u8 p3d[0x44 - 0x3d]; };

struct Slot { u8 p00[0x0c]; u8 p0c[0x18 - 0x0c]; u32 f18; u32 f1c; u8 b20; u8 p21[0x24 - 0x21]; };

typedef signed char s8;

typedef signed short s16;

struct Env { s32 f00; s32 f04; s32 f08; s32 f0c; };

struct Voice {
    void *f00;
    struct { u8 p00[0x20]; u8 b20; } *f04;
    u8  p08[0x1c - 8];
    struct Env env;
    u8  b2c;
    u8  b2d;
    u8  p2e[0x2f - 0x2e];
    u8  b2f;
    u8  p30[4];
    u8  p34[0x3c - 0x34];
    u8  b3c;
    s16 h3e;
    u8  b40;
    u8  b41;
    u8  p42[0x44 - 0x42];
};

extern void func_02060468(int p0, int p1);
extern void func_020604AC(void *list, void *node);
extern u32 func_0208A054(void);
extern void *func_02060614(struct DList *list, void *elem);
extern int func_02089D6C(u32 tag);
extern void func_0207368C(struct Voice *v);
extern void func_02075C08(struct LerpObj *obj);
extern s32 func_02075BD4(struct Obj *o);
extern void func_020893D0(u32 player, s32 vol);
extern int func_02075C20(struct LerpObj *obj);
extern void func_020735EC(struct Voice *v);
extern void func_02089378(u32 player);
void func_0207312C(void);
void func_020731E0(void);
extern char g_0214E00C[];
extern char g_0214E018[];
extern struct Chan g_0214E024[];
extern struct Slot g_0214E464[];
extern s16 g_020A5D08[];


/*
 * Pinned ../2.0/sp2 on the documented "kept constants" tell.  The image
 * materialises the allocator's element size TWICE, `mov r1, #0x14`
 * (`14 10 a0 e3`) at 0x02073134 and again at 0x02073140; 1.1p1 -O4,p CSEs the
 * pair into one hoisted `mov r4, #0x14` plus two `mov r1, r4`, which costs a
 * further callee-saved register and turns the original's
 * `push {r4, r5, r6, r7, r8, sb, sl, lr}` (`f0 47 2d e9`) into a ten-register
 * `push {r3, r4, ..., fp, lr}`, 180 bytes with 128 concrete bytes out.  The
 * indexed-subscript spelling of the two loops additionally leaves an `mla`
 * cursor under both front ends; the pointer-cursor form above is what
 * reproduces the original's `add r7, r7, #0x44` / `add sb, sb, #0x24`
 * strength reduction.  Under the pin the same C is 180 bytes, 0 concrete
 * mismatches.
 *
 * Note c->b3c is the loop INDEX, not zero: the `strb r6, [r7, #0x3c]` at
 * 0x02073164 stores the counter before the `add r6, r6, #1` at 0x0207316C,
 * while c->b2c takes the separate hoisted zero in r5.  Writing both as 0
 * leaves exactly one byte out at +0x38.
 *
 * Blocked at MATCH, evidence class: `literal` unavailable for the ABS32 site
 * at +0xAC.  The word 0x0214E024 appears in exactly one pool image-wide, my
 * own pool_020731D8 at 0x020731D8 (the three grep hits in asm/arm9/src are
 * that one address seen through three overlapping listings), so it has no
 * witness outside 0x0207312C..0x020731E0 and cannot be attested.  Every other
 * site resolves: four `label`, three `literal`.
 */
void func_0207312C(void)
{
    s32 i;
    struct Chan *c;
    struct Slot *s;

    func_02060468((int)g_0214E018, 0x14);
    func_02060468((int)g_0214E00C, 0x14);

    for (i = 0, c = g_0214E024; i < 0x10; i++, c++) {
        c->b2c = 0;
        c->b3c = (u8)i;
        func_020604AC(g_0214E00C, c);
    }

    for (i = 0, s = g_0214E464; i < 0x20; i++, s++) {
        func_02060468((int)s, 0xc);
        func_02060468((int)(&s->p0c), 0);
        s->b20 = 0x7f;
        s->f18 = 1;
        s->f1c = 0;
    }
}


/*
 * Byte-correct: 356 bytes, 0 concrete mismatches, under the DEFAULT 1.1p1
 * -O4,p.  No compiler pin taken or needed.
 *
 * PROMOTED TO EXACT, 2026-09-21 (unblock lane), with NO change to the C.
 * It was parked at MATCH because the two PC24 sites at +0x04 (func_0208A054)
 * and +0x13C (func_02089378) had no `label` witness: both targets are defined
 * and labelled in asm/arm9/src/028_02087E60.s, but the only `bl` reaching
 * either one anywhere in the image (arm9 and all of asm/overlays) was inside
 * this function's own 356 bytes -- the `bl` at 0x020731E4 and the one at
 * 0x0207331C respectively -- so `label` refused both for want of an OUTSIDE
 * branch and a split could not help.  There is no second caller to find.
 * Both callees were therefore written and filed directly instead:
 * src/matched/func_02089378.c (32 bytes, shard pkt_02089378) and
 * src/matched/func_0208A054.c (40 bytes, shard pkt_0208A054), each EXACT on
 * its own evidence.  Both sites now resolve `matched x1` and all 13 of this
 * file's relocations are attested.
 *
 * Levers that mattered, in the order they paid (all under 1.1p1):
 *  - The three sound-curve indices are PLAIN s16 subscripts.  Spelling any of
 *    them with an arithmetic round-trip emits a signed-division fixup
 *    (`add r0,r0,r0,lsr #31` / `asr r0,r0,#1`) that the image does not have.
 *  - The guard at 0x02073250 is `(mask & (1 << v->b3c)) == 0`, not `!= 0`:
 *    the image's `bne 0x2073264` at 0x02073254 skips the func_0207368C arm.
 *  - Declaration order is the whole register allocation, and it took three
 *    passes: 57 bytes out with `v` first, 40 with `next` moved below `tbl`,
 *    12 once `tbl` is declared BEFORE `v` (tbl->r5, v->r6, next->r7).
 *    `tbl` and `lo` must also be ASSIGNED after the early-return guard, not
 *    at their declarations, or they hoist above it.
 *  - The volume sum is `e + (c + (b + a))` with the curve read bound to its
 *    own local `e`: the accumulator is the second operand (see
 *    docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *    Binding the SUM to a local instead forces it before the func_02075BD4
 *    call and costs 30+ bytes.
 *  - The last 8 bytes were the ISSUE ORDER of the three curve reads alone:
 *    b41, then b40, then f04->b20.  Any other order permutes sl/sb/r8.
 */
void func_020731E0(void)
{
    u32 mask;
    s16 *tbl;
    s32 lo;
    struct Voice *v;
    struct Voice *next;
    s32 vol;

    mask = func_0208A054();
    v = func_02060614((struct DList *)g_0214E018, 0);
    if (v == 0) {
        return;
    }
    lo = -0x8000;
    tbl = g_020A5D08;

    do {
        next = func_02060614((struct DList *)g_0214E018, v);
        if (v->b2d == 0) {
            if (func_02089D6C(*(u32 *)&v->p30[0]) != 0) {
                v->b2d = 1;
            }
        }
        if (v->b2d != 0 && (mask & (1 << v->b3c)) == 0) {
            func_0207368C(v);
        } else {
            s32 a, b, c;
            func_02075C08((struct LerpObj *)(&v->env));
            a = tbl[v->b41];
            b = tbl[v->b40];
            c = tbl[v->f04->b20];
            {
                s32 e = tbl[func_02075BD4((struct Obj *)(&v->env)) >> 8];
                vol = e + (c + (b + a));
            }
            if (vol < lo) {
                vol = lo;
            } else if (vol > 0x7fff) {
                vol = 0x7fff;
            }
            if (vol != v->h3e) {
                func_020893D0(v->b3c, vol);
                v->h3e = (s16)vol;
            }
            if (v->b2c == 2 && func_02075C20((struct LerpObj *)(&v->env)) != 0) {
                func_020735EC(v);
            }
            if (v->b2f != 0) {
                func_02089378(v->b3c);
                v->b2f = 0;
            }
        }
        v = next;
    } while (next != 0);
}
