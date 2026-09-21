/*
 * function: sub_0203331C
 * address:  0x0203331C
 * packet:   pkt_0203331C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * backup_system.c.  The packed 2-bit-per-slot array SETTER, companion to
 * the getter src/matched/unit_020332FC.c at 0x020332FC (same file, the
 * function immediately before it).  The backing store is a u32 array at
 * offset 0x138 of the object; slot `idx` lives in word `idx >> 4` at bit
 * position `(idx & 0xf) * 2`.
 *
 * Two spellings carry this function and neither is optional:
 *
 * 1. The clear mask is a 64-bit complement, not `~`.  The original's
 *    `mov r3, #3` / `sub r1, r3, #4` / `eor r1, r1, r3, lsl lr` triple is
 *    the low half of a `long long` NOT with the high half dead-code
 *    eliminated -- see docs/idioms/
 *    a-64-bit-complement-is-eors-with-minus-one-not-mvns.md.  Spelling it
 *    `~(3 << sh)` compiles to `mvn r1, r1, lsl r4` and loses four bytes
 *    (60 against 64); the literal `3` must stay inline in the `^ -1` form
 *    so the same `mov r3, #3` feeds both the `sub` that makes -1 and the
 *    shifted operand of the `eor`.  Binding it to a `long long mask = 3;`
 *    local instead costs a second constant materialisation (68 bytes).
 *
 * 2. The word index of the CLEAR half goes through a two-step copy chain
 *    (`tmp1 = idx >> 4; tmp = tmp1;`) while the SET half re-reads
 *    `idx >> 4` and `sh` directly.  Without the copy chain the compiler
 *    colours the shift amount r4 and the word index lr, which is the
 *    exact reverse of the original (10 concrete bytes, a pure r4 <-> lr
 *    swap with every instruction otherwise identical).  The extra copy
 *    splits the word index's live range so the allocator numbers the
 *    shift amount first and it takes lr.  Found by tools/permuter.py
 *    (--mode anneal, `expand(sh) ; temp(tmp=idx >> 4) ; temp(tmp1=idx >> 4)
 *    ; reorder(-1)`), then reduced by hand: dropping either temp returns
 *    the residue to the same 10 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203331C.c \
 *       --func sub_0203331C --addr 0x0203331C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj020332FC {
    char pad[0x138];
    u32 *slots;
};

void sub_0203331C(struct Obj020332FC *p, u32 idx, u32 val)
{
    u32 sh = (idx & 0xf) * 2;
    u32 tmp;
    u32 tmp1;

    tmp1 = idx >> 4;
    tmp = tmp1;
    p->slots[tmp] &= (3 << ((idx & 0xf) * 2)) ^ -1;
    p->slots[idx >> 4] |= val << sh;
}
