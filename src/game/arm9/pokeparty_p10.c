/*
 * file:     pokeparty_p10.c
 * unit:     yes
 * function: func_0201C7A4, func_0201C7D0, func_0201C808, func_0201C8A4, func_0201C8BC, func_0201C974, func_0201CA2C, func_0201CA78
 * address:  0x0201C7A4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045A90  0x02045A90  arm
 *   sub_0201C808   0x0201C808  thumb
 *   func_0201C8BC  0x0201C8BC  thumb
 *   g_0214655C     0x0214655C  data
 *   sub_0201C8A4   0x0201C8A4  thumb
 *   func_0201DE18  0x0201DE18  thumb
 *   func_0201DE00  0x0201DE00  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201C974  0x0201C974  thumb
 *   func_0201CAC8  0x0201CAC8  thumb
 *   func_0201CC34  0x0201CC34  thumb
 *   g_02146558   0x02146558  data
 */
#include "../../matched/include/Obj00698.h"

struct U16Vec;
struct PrintCtx_0201C7A4;
struct Rec2;
struct Bmp;
struct Font;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

struct Scratch {
    u8 unk_00[1];
};

struct PrintCtx_0201C7A4 {
    s16 unk00;
    s16 unk02;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

typedef signed int     s32;

struct Rec2 {
    u32 unk00;
    u32 unk04;
    u16 pad08[3];
    u16 unk0E;
};

struct PrintCtx_0201C8A4 {
    s16   unk00;
    s16   unk02;
    s32   unk04 : 10;
    u32   unk04b : 22;
    u16   unk08;
    u16   unk0A;
    u16   unk0C;
    u16   unk0E;
    void *unk10;
    void *unk14;
    void (*unk18)(void *a, s32 b, s32 c, void *d, u16 e, u8 *f);
};

extern u16 *func_02045A90(struct U16Vec *vec);
extern void sub_0201C808(struct PrintCtx_0201C7A4 *p, void *w, void *x, u32 y, s16 z);
extern void func_0201C8BC(u8 *a0, int a1);
extern void sub_0201C8A4(struct Rec2 *p, u16 v);
extern u8 func_02043994(struct Bmp *b);
extern void func_0201DE00(u8 *r, u8 *g, u8 *b);
extern void sub_0201CA2C(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f);
extern void sub_0201CA78(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f);
extern u32 func_0201DE18(u32 r, u32 g, u32 b);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u16 *func_0201C974(struct PrintCtx_0201C8A4 *c, u16 *p, u32 f);
extern u16 *func_0201CAC8(struct PrintCtx_0201C8A4 *c, u16 *p);
extern u16 *func_0201CC34(u16 *a0, u16 *a1);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_0201DB04(struct Font *p, u16 ch, void *c, void *d);
extern void func_02043AAC(struct Bmp *dst, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u16 a10);
void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern struct Scratch g_0214655C;
extern void *g_02146558;



/*
 * A printsys entry point: builds the shared print request in the static
 * scratch through sub_0201C808 and hands it to func_0201C8BC with the
 * string object.  The leading func_02045A90(s) call's result is unused.
 *
 * Withdrawn 2026-09-24 (wave 20, lane 20G): the ../2.0/sp2 pin is retired.
 * The scratch address is held as an integer, a u32 local assigned
 * (u32)&g_0214655C and cast back at each site, matching func_0201C7D0.c.
 * Spelled this way, dsi/1.1p1 caches the address in a callee-saved
 * register and copies it into r0 at each site, byte-exact under the
 * default compiler.
 */
void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w)
{
    u32 base;

    func_02045A90(s);
    base = (u32)&g_0214655C;
    sub_0201C808((struct PrintCtx_0201C7A4 *)base, w, x, y, z);
    func_0201C8BC((u8 *)((struct Scratch *)base), (int)s);
}



/*
 * A printsys entry point: the func_0201C7A4 body plus a
 * sub_0201C8A4(scratch, v) step between building the shared print request
 * in the static scratch and handing it to func_0201C8BC.  The leading
 * func_02045A90(s) call's result is unused.
 *
 * What closed it (wave 20): the scratch address is held as an integer, a
 * u32 local assigned (u32)&g_0214655C and cast back at each of the three
 * sites.  Spelled `&g_0214655C` at every site, 1.1p1 value-numbers the
 * address once, caches it in r4 and schedules z's outgoing stack store
 * straight after the first call to free that register (37 bytes out).
 * Through the integer local the address is rematerialised from its one pool
 * word at every site, z stays in r4 until its store after r0..r3 as the
 * image does, and the stacked u16 read keeps the 1.1p1 base.  This retires
 * the ../2.0/sp2 near miss (2 out) the notes carried.
 */
void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v)
{
    u32 base;

    func_02045A90(s);
    base = (u32)&g_0214655C;
    sub_0201C808((struct PrintCtx_0201C7A4 *)base, w, x, y, z);
    sub_0201C8A4((struct Rec2 *)base, v);
    func_0201C8BC((u8 *)((struct Scratch *)base), (int)s);
}



/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     156 bytes including five pool words, one function
 *
 * printsys.c's render-context set-up: it records the surface and the string,
 * picks the blitter, packs the pen position into two ten bit fields of the
 * word at +4 and snapshots the current text colour into +0xC and +0xE.
 *
 * The two blitter addresses are the reason this is parked.  0x0201CA2C and
 * 0x0201CA78 are reached only through the two pool words in this function's
 * own literal pool, so `literal` discards both witnesses under the honesty
 * rule and no cut helps.  The `matched` class covers 0x0201CA2C now
 * (src/matched/unit_0201CA2C.c) but not 0x0201CA78, which is parked in
 * src/pending/sub_0201CA78.c for a reason of its own.  This file graduates
 * with that one.
 *
 * Two details worth keeping.  The three edits of the word at +4 are plain
 * integer mask-and-or arithmetic, the same spelling
 * src/matched/unit_0201C8A4.c uses, and the compiler writes the field only
 * twice for three statements because it keeps the value in a register across
 * the last two.  And the pen coordinates are read back out of the halfwords
 * that were just stored, with `ldrsh` and a register offset, which is the only
 * evidence that +0 and +2 are signed
 * (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201C808.c \
 *       --addr 0x0201C808 --thumb
 */
void sub_0201C808(struct PrintCtx_0201C7A4 *p, void *w, void *x, u32 y, s16 z)
{
    u8 t[3];

    p->unk14 = x;
    if (func_02043994(x) == 0x20) {
        p->unk18 = (void *)sub_0201CA2C;
    } else {
        p->unk18 = (void *)sub_0201CA78;
    }
    p->unk10 = w;
    p->unk00 = y;
    p->unk04 = (p->unk04 & 0xFFFFFC00u) | (p->unk00 & 0x3FF);
    p->unk02 = z;
    p->unk04 = (p->unk04 & 0xFFF003FFu) | ((p->unk02 & 0x3FF) << 10);
    p->unk04 = (p->unk04 & 0xFF0FFFFFu) | (1u << 20);
    func_0201DE00(&t[2], &t[1], &t[0]);
    p->unk0C = (u16)(((t[2] & 0x1F) << 10) | ((t[1] & 0x1F) << 5)
                     | (t[0] & 0x1F));
    p->unk0E = p->unk0C;
}



/*
 * Stores a halfword parameter at +0xE, then clears a four-bit field at bits
 * 20-23 of the word at +4 and sets it unconditionally to 1 (the mask/OR
 * pair is plain integer arithmetic, `(x & ~0xF00000) | (1 << 20)`; no
 * bitfield struct is needed since the two shift amounts in the AND/OR would
 * not match docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md's
 * shape anyway).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C8A4.c \
 *       --addr 0x0201C8A4 --thumb
 */
void sub_0201C8A4(struct Rec2 *p, u16 v)
{
    p->unk0E = v;
    p->unk04 = (p->unk04 & ~0xF00000u) | (1u << 20);
}


/*
 * printsys.c: if the 4-bit field at bits 20..23 of PrintCtx+0x04 is 1,
 * split the packed 5/5/5 triple at +0x0E and pass it to func_0201DE18; on a
 * nonzero result fill buf through func_0201DE00, pass the triple to
 * func_0201DD78 and set done; then set the field to 2.  Render glyphs
 * through func_0201C974 until 0xFFFF, and if done, pass buf back to
 * func_0201DD78.
 *
 * Two facts the bytes pin (docs/notes/pkt_0201C8BC.c.txt has the history):
 *
 *  1. `done` is a PLAIN u8, not a volatile int.  The image reloads the
 *     zero from [sp,#4] before each of the three byte stores and forms buf's
 *     address as `add r1, sp, #8`: [sp,#4] is the SPILL slot of a register
 *     candidate, and buf is the first addressable local.  A plain int done
 *     has its zero forwarded into the stores (180 bytes); a volatile done
 *     gets a home next to buf in the local area and the stores go off
 *     `add r0, sp, #4` plus 4/5/6 (17 out).  A u8 (or u16, or signed char)
 *     flag is neither forwarded nor addressable
 *     (docs/idioms/a-narrow-flag-local-is-spilled-not-constant-propagated.md).
 *
 *  2. The rewrite mask is 0xFF0FFFFF (clear bits 20..23, the field the
 *     `<< 8 >> 28` test reads), then or 0x200000 (field = 2).  Earlier
 *     notes and docs/families/printsys.h wrote 0xFFFF0FFF.
 *
 * hi and mid are int (the u8 truncation is in the expression), lo is u8:
 * that is what puts hi in r7, mid in r6 and lo in the [sp] spill slot.
 */
void func_0201C8BC(u8 *a0, int a1)
{
    u16 *p = (u16 *)func_02045A90((struct U16Vec *)a1);
    u8 buf[3];
    u8 done = 0;
    int hi;
    int mid;
    u8 lo;

    buf[0] = done;
    buf[1] = done;
    buf[2] = done;
    if (((int)(((struct Obj00698 *)a0)->f4 << 8)) >> 28 == 1) {
        int v = ((struct Obj00698 *)a0)->fE;

        hi = (u8)((v >> 10) & 0x1F);
        mid = (u8)((v >> 5) & 0x1F);
        lo = (u8)(v & 0x1F);
        if (func_0201DE18(hi, mid, lo) != 0) {
            func_0201DE00(&buf[2], &buf[1], &buf[0]);
            func_0201DD78((int)hi, (int)mid, (int)lo);
            done = 1;
        }
        ((struct Obj00698 *)a0)->f4 = (((struct Obj00698 *)a0)->f4 & 0xFF0FFFFF) | 0x200000;
    }
    while (*p != 0xFFFF) {
        p = (u16 *)func_0201C974((struct PrintCtx_0201C8A4 *)a0, p, (int)1);
    }
    if (done) {
        func_0201DD78((int)buf[2], (int)buf[1], (int)buf[0]);
    }
}


/*
 * printsys.c: the glyph-run interpreter.  Walks the halfword string `p`
 * rendering one glyph per call to the renderer hook at PrintCtx+0x18 and
 * returns the cursor one halfword past the glyph it drew; 0xFFFF (end) and a
 * 0xF000 control block whose code byte is 0xBE with `f == 0` return the
 * cursor unchanged.
 *
 * Three facts the bytes pin, each one worth a whole spelling:
 *
 *  1. PrintCtx+0x04 is a SIGNED 10-BIT BITFIELD, not the `u32` flag word
 *     docs/families/printsys.h had.  The 0xFFFE (line break) arm reads it as
 *     `lsls #0x16 / asrs #0x16`, a 22-bit equal-width pair with a signed right
 *     half, which only `s32 :10` produces
 *     (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  Spelled
 *     `u32` the store is a bare `strh` and the pair is gone.
 *
 *  2. The control-code dispatch is a SWITCH, not an if/else chain.  The
 *     original tests 0xBD, 0xBE, 0xFF with three forward `beq`s and a final
 *     `b default`; an if/else chain of the same three tests emits `bne` skips
 *     instead and costs 86 concrete bytes here.  The switch is sparse (0xBD,
 *     0xBE, 0xFF), so no jump table appears, only the compare chain.
 *
 *  3. The 0xBE arm's guard is spelled `if (f != 0) { ...; break; } return p;`
 *     and NOT `if (f == 0) return p;`.  The original's `cmp r1, #0 / beq` puts
 *     the return out of line as the TAKEN target; the equality form emits
 *     `bne` and mirrors the last seven instructions
 *     (docs/idioms/the-fall-through-arm-is-the-source-order.md).  This was the
 *     last 13 concrete bytes.
 *
 * The block-layout shape also matters: the glyph body is reached by an
 * explicit `goto glyph` to a label AFTER the `while (1)`, which is what places
 * it physically last (at +0x8E) rather than in the middle.  Written as the
 * final `else` arm of the chain the compiler sinks the F000 block instead and
 * the function comes out 180 bytes, four short.
 *
 * The redundant inner `if (v == 0xF000) k = (u8)(p[1] >> 8); else k = 0xFF;`
 * inside the F000 arm is real: the original repeats the same `cmp r0, r7` test
 * (at +0x3C, reusing the flags of the outer one at +0x12) rather than assuming
 * it.  That is an inlined code-fetch helper, and collapsing it to a plain
 * `k = (u8)(p[1] >> 8)` loses the `bne`/`movs #0xff` pair.
 */
u16 *func_0201C974(struct PrintCtx_0201C8A4 *c, u16 *p, u32 f)
{
    u8 pen[4];
    s16 *py = &c->unk02;

    while (1) {
        u16 v = *p;
        if (v != 0xF000) {
            if (v != 0xFFFE) {
                if (v == 0xFFFF) {
                    return p;
                }
                goto glyph;
            }
            c->unk00 = (s16)c->unk04;
            p = p + 1;
            *py = (s16)(*py + 0x10);
            continue;
        }
        {
            u32 k;
            if (v == 0xF000) {
                k = (u8)(p[1] >> 8);
            } else {
                k = 0xFF;
            }
            switch (k) {
            case 0xBD:
                p = func_0201CAC8(c, p);
                break;
            case 0xFF:
                p = func_0201CC34((u16 *)c, p);
                break;
            case 0xBE:
                if (f != 0) {
                    if (v != 0xF000) {
                        continue;
                    }
                    p = (u16 *)((u8 *)(p + 3) + p[2] * 2);
                    break;
                }
                return p;
            default:
                if (v != 0xF000) {
                    continue;
                }
                p = (u16 *)((u8 *)(p + 3) + p[2] * 2);
                break;
            }
        }
    }
  glyph:
    {
        u16 v = *p;
        c->unk18(c->unk14, c->unk00, c->unk02, c->unk10, v, pen);
        c->unk00 = (s16)(c->unk00 + pen[2]);
        return p + 1;
    }
}


/*
 * One of the two printsys.c glyph blitters, both of which forward the caller's
 * pen record to func_0201DB04 and then hand the result to a renderer reached
 * through the module object at 0x02146558.  The pair is cut here rather than
 * matched as one range because func_0201DB04 is reached from exactly two places
 * in the image, 0x0201CA4C and 0x0201CA98, one in each function: matched
 * together neither site has a witness, matched apart each is the other's `label`
 * witness.  That is
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * Its sibling at 0x0201CA78 stays parked (src/pending/sub_0201CA78.c): it calls
 * 0x02043AAC, and 0x0201CABC is the only branch to that address anywhere in the
 * image, so no cut reaches it.
 *
 * f is a four-byte pen record: f[0] is an x bias added to the caller's x, f[1]
 * and f[3] are passed straight through.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CA2C.c \
 *       --addr 0x0201CA2C --thumb
 */
void sub_0201CA2C(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f)
{
    func_0201DB04((struct Font *)d, e, func_020437D4(g_02146558), (void *)f);
    func_020439A0(g_02146558, a, 0, 0, b + f[0], c, f[1], f[3], 0);
}


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     80 bytes including two pool words, one function
 *
 * printsys.c's second glyph blitter, the twin of sub_0201CA2C in
 * src/matched/unit_0201CA2C.c.  The two differ only in which renderer they
 * call and in the two extra stack arguments this one passes, 0xF and 0.
 *
 * Why it is capped: the `blx` at 0x0201CABC is the only branch to 0x02043AAC
 * anywhere in the image, checked over every Thumb BL/BLX pair and every ARM
 * branch in all 242 regions, and no pool word holds the address either.  The
 * `label` class therefore has no witness once the compared range holds that
 * call, and no cut helps, because the range cannot be smaller than this one
 * function.  Cutting it away from sub_0201CA2C is what let that function come
 * out EXACT, since the two are the only callers of func_0201DB04 and each is
 * now the other's witness
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * It closes the day 0x02043AAC is matched (the `matched` class) or acquires a
 * second caller.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201CA78.c \
 *       --addr 0x0201CA78 --thumb
 */
void sub_0201CA78(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f)
{
    func_0201DB04((struct Font *)d, e, func_020437D4(g_02146558), (void *)f);
    func_02043AAC(g_02146558, (u32)a, 0, 0, b + f[0], c, f[1], f[3], 0xF, 0);
}
