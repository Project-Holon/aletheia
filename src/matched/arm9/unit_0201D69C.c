/*
 * unit:     yes
 * address:  0x0201D69C
 * packet:   pkt_0201D69C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0201D69C, func_0201D6B8, func_0201D6C4
 *
 * The first three functions of gf_font.c.  The file identity is in the image:
 * the constructor at 0x0201D7EC passes 0x020A7358 to the debug allocator at
 * 0x02030734 and the bytes there spell "gf_font.c"; 0x0201D9BC and 0x0201DA88
 * name the same string.  This unit stops at 0x0201D6D8 because the two
 * functions after it are an unsolved register allocation, not a missing
 * declaration; see the note at the end of this comment.
 *
 * func_0201D69C sizes a string's storage: two bytes per character plus the
 * terminator, rounded up to a multiple of four.  The rounding is a `while`
 * loop over `n & 3`, not an `& ~3` or a `+ 3 & ~3`: this front end has no
 * immediate `bic`, so either of those would materialise the mask and the
 * function would be four bytes shorter with no loop at all.  The loop really
 * is in the original.
 *
 * func_0201D6C4 is the used-byte count of a wrap-around byte ring.  The
 * fall-through arm of `cmp r1, r2` / `bhs` is the non-wrapped case, so the
 * source wrote `if (head < tail)` first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md); written as the
 * wrapped case first it is ten of the twenty bytes wrong.
 *
 * Left open at 0x0201D6D8: func_0201D6D8 and func_0201D768 reproduce the
 * right size and the right instruction multiset but allocate registers the
 * other way round.  The original keeps the ring's write cursor in a
 * callee-saved register across the MI_CpuCopy8 call and spills the loop
 * counter; every source shape tried so far (three local layouts, six
 * declaration orders, struct against scalars, one against two assignments of
 * the buffer base) gives the opposite choice and 72 differing bytes, with no
 * variation between them.  The buffer base is assigned twice, once as the
 * object pointer and once with 0x18 added, which is the aggregate-member
 * non-folding of
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md, but
 * modelling it as an aggregate member does not move the diff either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D69C.c \
 *       --addr 0x0201D69C --thumb
 *
 * symbols:
 *   STRBUF_GetLength  0x020458F8  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct U16Vec;
extern u16 STRBUF_GetLength(struct U16Vec *vec);

struct Ring {
    u16 head;
    u16 tail;
    u16 size;
};

u32 func_0201D69C(void *s)
{
    u32 n = (STRBUF_GetLength(s) + 1) * 2;

    while ((n & 3) != 0) {
        n++;
    }
    return n;
}

u32 func_0201D6B8(void *s)
{
    return func_0201D69C(s) + 0x20;
}

u32 func_0201D6C4(const struct Ring *p)
{
    if (p->head < p->tail) {
        return p->tail - p->head;
    }
    return p->tail + (p->size - p->head);
}
