/*
 * file:     time_icon_p03.c
 * unit:     yes
 * function: func_0202EC24, func_0202EC44, func_0202EC7C, func_0202ECB0, func_0202ED00, func_0202ED60, func_0202ED90, func_0202EDE4, func_0202EE0C, func_0202EE30, func_0202EE8C
 * address:  0x0202EC24
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
 *   func_0200856C   0x0200856C  thumb
 *   func_02008530   0x02008530  thumb
 *   func_0200974C   0x0200974C  thumb
 *   func_02009750   0x02009750  thumb
 *   func_020095E8   0x020095E8  thumb
 *   func_0202EC24   0x0202EC24  thumb
 *   _u32_div_f      0x0209C2B0  arm
 *   g_020A7814     0x020A7814  data
 *   unk_0202F099   0x0202F099  data
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_0202EECC  0x0202EECC  thumb
 *   unk_0202F0A5   0x0202F0A5  data  a1
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 */
#include "../../matched/include/Obj06927.h"
#include "../../matched/include/Obj08812.h"

struct Sub0200852CObj;
struct Sub02009470Obj;
struct Slot;
struct Ent0202EC24;
struct S02030FB4;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Ent0202EC24 {
    u8 pad[0x26];
    u8 unk26_0 : 4;
    u8 unk26_4 : 1;
    u8 unk26_5 : 3;
    u8 unk27;
};

typedef int           s32;

struct Slot_0202EC44 {
    u8  pad[0x26];
    u8      : 4;
    u8 flag : 1;
    u8      : 3;
    u8  pad2;
};

struct Slot_0202EC7C {
    u8  pad[0x26];
    u8      : 4;
    u8 flag : 1;
    u8      : 3;
    u8  pad2;
};

struct Slot_0202ECB0 {
    u8  pad[0x26];
    u8      : 4;
    u8 flag : 1;
    u8      : 3;
    u8  pad2;
};

/* 0x28-byte slot; the u32 member is load-bearing (4-byte alignment turns
 * the record copy into five ldm/stm pairs). */
struct Slot_0202ED00 {
    u32 w00;
    u8  pad04[0x22];
    u8      : 4;
    u8 flag : 1;
    u8      : 3;
    u8  pad27;
};

struct Body {
    u32 w[10];
};

struct Slot {
    u8  pad[0x26];
    u8      : 3;
    u8 mark : 1;
    u8 flag : 1;
    u8      : 3;
    u8  pad2;
};

typedef unsigned short u16;

extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32  func_0200974C(u32 a);
extern u32 func_02009750(struct Sub02009470Obj *obj, u32 n);
extern void func_020095E8(struct Sub02009470Obj *obj);
extern void func_0202ED90(u8 *a, struct Slot *b, u32 c);
extern u32 func_0202EC24(const struct Ent0202EC24 *p);
extern u32 _u32_div_f(u32 a, u32 b);
u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_0202ED60(u32 a, void *b, u32 c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32   func_02030DA8(void *owner, u8 *tag, void *p, u32 a3);
extern void  func_0202EECC(u8 *p, void *a1, u8 a2, u8 a3, u16 a4);
extern void *func_020311B8(u32 a, u8 *tag, u32 size, u32 flags);
extern void *func_02031290(struct S02030FB4 *p);
u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
extern char g_020A7814[];
extern u8   unk_0202F099[];
extern u8   unk_0202F0A5[];




/*
 * A whole translation unit, matched as one byte range.
 *
 * Counts the leading run of occupied slots in a 20-entry array of
 * 0x28-byte records and returns the index of the first free one, or 20.
 * No prologue at all, because it calls nothing and needs no callee-saved
 * register, so `disasm.py` gives it no label.
 *
 * The occupancy test is `lsls #0x1B` / `lsrs #0x1F` on a byte at offset
 * 0x26, which is a one-bit unsigned bitfield at bit 4 and cannot be
 * written as a mask: `& 0x10` folds to `movs`/`ands` and a shift pair
 * with unequal amounts is a narrowing cast, not a field
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md,
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The record stride arrives as `movs r1, #0x28` / `muls` rather than a
 * scaled index because 0x28 is not a power of two.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202EC24.c
 *       --addr 0x0202EC24 --thumb
 */
u32 sub_0202EC24(const struct Ent0202EC24 *p)
{
    u32 i;

    for (i = 0; i < 20; i++) {
        if (p[i].unk26_4 == 0) {
            break;
        }
    }
    return i;
}


/*
 * Counts the occupied slots whose key matches, capped at five.  Same 0x28-byte
 * record as func_0202EC7C, matched next door.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EC44.c \
 *       --func func_0202EC44 --addr 0x0202EC44 --cc 1.1p1 --thumb
 */
u32 func_0202EC44(struct Slot_0202EC44 *a0, u32 a1)
{
    u32 i;
    u32 n = 0;

    for (i = 0; i < 0x14; i++) {
        u32 v;
        if (!a0[i].flag)
            break;
        v = func_0200856C((const struct Sub0200852CObj *)(&a0[i]));
        if (v == a1)
            n++;
    }

    if (n > 5)
        n = 5;
    return n;
}


s32 func_0202EC7C(struct Slot_0202EC7C *a0, u32 a1)
{
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 v;
        if (!a0[i].flag) break;
        v = func_0200856C((const struct Sub0200852CObj *)(&a0[i]));
        if (v == a1) return i;
    }
    return 0x14;
}


/*
 * Finds the first occupied slot whose two keys both match the reference
 * record's, or 0x14 when there is none.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ECB0.c \
 *       --func func_0202ECB0 --addr 0x0202ECB0 --cc 1.1p1 --thumb
 */
s32 func_0202ECB0(struct Slot_0202ECB0 *a0, void *b)
{
    u32 v0 = func_02008530(b);
    u32 v1 = func_0200856C(b);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 w, x;
        if (!a0[i].flag)
            break;
        w = func_02008530((const struct Sub0200852CObj *)(&a0[i]));
        if (w == v0) {
            x = func_0200856C((const struct Sub0200852CObj *)(&a0[i]));
            if (x == v1)
                return i;
        }
    }
    return 0x14;
}


/*
 * note:     EXACT* only for the two bytes of alignment padding at
 *           0x0202ED5E.  Closed in wave 16 (the residue since wave 12 was
 *           the ldm/stm base order of the record copy): the copy goes
 *           through a named destination and a source derived from it
 *           (`dst = &t[n]; src = dst + 1; *dst = *src;`), and the flag test
 *           must NOT share the `t + n` subexpression with them, or the
 *           front end rematerialises t + n*0x28 and computes the source
 *           first.  `(t + 1)[n]` shares only the n*0x28 product, which is
 *           what the image keeps in r7.  See docs/notes/pkt_0202ED00.c.txt.
 */
void func_0202ED00(struct Slot_0202ED00 *t, u32 n)
{
    struct Slot_0202ED00 *dst;
    struct Slot_0202ED00 *src;

    if (n >= 0x14)
        return;

    if (n < 0x13) {
        while (1) {
            dst = &t[n];
            src = dst + 1;
            *dst = *src;
            if (!(t + 1)[n].flag) {
                n++;
                break;
            }
            n++;
            if (n >= 0x13)
                break;
        }
    }

    while (n < 0x14) {
        t[n].flag = 0;
        n++;
    }
}



/*
 * The three-call pair at the end is the useful part: the key is read out of
 * `b` once into a named local and handed to func_02009750; that call's
 * answer decides whether func_020095E8 runs.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ED60.c \
 *       --func func_0202ED60 --addr 0x0202ED60 --cc 1.1p1 --thumb
 */
void func_0202ED60(u32 a, void *b, u32 c)
{
    u32 t = func_0200974C(a);
    u32 v;

    func_0202ED90((u8 *)t, b, c);

    v = func_0200856C(b);
    if (func_02009750((struct Sub02009470Obj *)a, v) != 0)
        func_020095E8((struct Sub02009470Obj *)a);
}



/*
 * Stores the record at `b` into slot index func_0202EC24(a), after setting
 * the bit-3 mark from `c` and the bit-4 occupied flag.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ED90.c \
 *       --func func_0202ED90 --addr 0x0202ED90 --cc 1.1p1 --thumb
 */
void func_0202ED90(u8 *a, struct Slot *b, u32 c)
{
    u32 i = func_0202EC24((const struct Ent0202EC24 *)a);

    if (i >= 0x14)
        return;

    if (c != 0)
        b->mark = 1;
    else
        b->mark = 0;

    b->flag = 1;

    *(struct Body *)(a + i * 0x28) = *(struct Body *)b;
}


/*
 * Maps v into the band [a2+w/2, a3-w/2] of a0, 0 below it and a0 above it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EDE4.c \
 *       --func func_0202EDE4 --addr 0x0202EDE4 --cc 1.1p1 --thumb
 */
u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 h  = a4 >> 1;
    u32 lo = a2 + h;
    u32 hi = a3 - h;
    u32 n;

    if (a1 <= lo)
        return 0;
    if (a1 >= hi)
        return a0;

    n = a1 - lo;
    return (n * (a0 << 8) / (hi - lo)) >> 8;
}


/*
 * A scaled-span helper: the span (d - c - e) is raised eight bits, scaled by
 * the rate b, divided by the total a and shifted back down; the quotient
 * joins c and half of e.
 *
 * The divide is the UNSIGNED runtime entry at 0x0209C2B0 (which
 * layout/runtime_arm9.txt names `_div_by_zero_check`, but the code there is
 * the unsigned divide entry itself; `signed / signed` emits 0x0209C0A4
 * instead).  Declared here under the front end's own name, `_u32_div_f`.
 *
 * Two spellings are load-bearing, both found by tools/permuter.py
 * (mutations `temp` then `commute(+)`, hill, budget 800):
 *   - the quotient must be bound to its own local.  Written inline, the
 *     quotient stays live in r0 and the re-read of `e` is scheduled into r1
 *     BEFORE the shift, which is the four-instruction residue the earlier
 *     note recorded (docs/notes/pkt_0202EE0C.c.txt).
 *   - the sum must associate as `(c + tmp) + (e >> 1)`.  With
 *     `(tmp + c) + (e >> 1)` the two `adds` land on the other operand order.
 * Together they put the quotient's high half in r2 and re-read `e` into r0,
 * which is exactly the original's tail.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EE0C.c \
 *       --func func_0202EE0C --addr 0x0202EE0C --cc 1.1p1 --thumb
 */
u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 t = ((d - c) - e) << 8;
    u32 tmp = _u32_div_f(t * b, a) >> 8;

    return (c + tmp) + (e >> 1);
}



/*
 * Allocates and fills the 0x1c-byte time_icon record.  The heap id is the
 * fifth (stack) argument and is re-read from its slot for the second use
 * (it is also what func_0202EECC's u16 tail parameter receives), so it is
 * spelled `volatile u16`.  When the optional owner a0 is non-null the
 * record is registered with func_02030DA8 against the tag 0x0202F099 and
 * that call's result lands at +0; otherwise +0 is zeroed.
 *
 * Sibling of func_0202EE8C (docs/notes/pkt_0202EE0C.c.txt), which builds
 * the same record through the func_020311B8 allocator instead.
 */
u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap)
{
    u8 *p;

    p = (u8 *)func_02030734(heap, 0x1c, 0, g_020A7814, 0x49);
    func_0202EECC(p, a1, a2, a3, heap);
    if (owner != 0) {
        ((struct Obj06927 *)p)->f0 = func_02030DA8(owner, unk_0202F099, p, 0);
    } else {
        ((struct Obj06927 *)p)->f0 = 0;
    }
    ((struct Obj06927 *)p)->f4 = 0;
    ((struct Obj06927 *)p)->f18 = 1;
    return p;
}



/*
 *           0x0202F0A5 as a `pool` row whose only referrer sites image-wide are the
 *           pool word at 0x0202EEC8 (listed twice, once per unit listing), which lies
 *           INSIDE this function's own 0x0202EE8C..0x0202EECC extent.  A lone
 *           reference never contributes its own start, so sole-ref/data refuses it
 *           exactly as `literal` and `label` do.  No other src/matched or src/pending
 *           file declares the address either, so `matched` has nothing to offer.
 *           Contrast 0x0202F099 (line 179), the sibling tag func_0202EE30 uses: that
 *           one also has a referrer at 0x0202F034, outside any one function, plus a
 *           data-symbol declaration from two EXACT files, which is why the sibling
 *           resolves and this one cannot.  Unblocks the moment any function outside
 *           this extent references the tag, or a matched file declares it.
 *
 * Sibling of func_0202EE30 (src/matched, EXACT): the same 0x1c-byte IconRec, built
 * through the func_020311B8 node allocator instead of func_02030734.  The node is
 * stashed at +4 and +0 is zeroed, the mirror image of func_0202EE30, which registers
 * an owner into +0 and zeroes +4.  Struct layout: docs/families/time_icon.h.
 *
 * Every concrete byte of the 64-byte extent is right; the sole wildcard is the tag
 * above.  NOTE: docs/notes/pkt_0202EE0C.c.txt recorded this same C as DIFF with a
 * five-instruction scheduling residue (the saved-argument loads scheduled before the
 * copy of the call result).  That residue is GONE as of 2026-09-21: the identical
 * source now compiles to 64 bytes with 0 concrete mismatches.  The note's residue
 * table is stale; its prediction that the tag would cap the file at MATCH is not.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_0202EE8C.c \
 *       --func func_0202EE8C --addr 0x0202EE8C --cc 1.1p1 --thumb
 */
u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e)
{
    void *v;
    u8 *r;

    v = func_020311B8(a, unk_0202F0A5, 0x1c, 0);
    r = func_02031290(v);
    func_0202EECC(r, b, c, d, e);
    ((struct Obj08812 *)r)->f4 = (u32)v;
    ((struct Obj08812 *)r)->f0 = 0;
    ((struct Obj08812 *)r)->f18 = 1;
    return r;
}
