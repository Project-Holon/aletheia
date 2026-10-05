/*
 * function: func_021F546C
 * address:  0x021F546C
 * packet:   pkt_ov112_021F546C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Slot writer (172 bytes, 0x021F546C..0x021F5518): mode >= 7 sets slot mode-7 (stride 0x38) enabled and copies
 * four Vec records plus two halfwords; mode 4 and 5 copy in->b.x/y into p+0x20C/0x210 and p+0x218/0x21C style
 * word groups and set a flag. Different function from the ov194 one at the same address.
 *
 * 2026-10-05 (wave D5 lane 02): rebuilt from docs/notes/pkt_ov112_021F546C.c.txt. 170 bytes vs 172. The only
 * structural residue is the first block: the original keeps mode-7 in r4 and copies it (`subs r4,r0,#7;
 * movs r0,#0x38; adds r1,r4,#0; muls r1,r0,r1`) while the compiler multiplies in place. Tried: array index
 * &((Slot *)p)[mode-7], int and long and unsigned index, index declared before the if, a copy of mode, Slot *
 * parameter. All give 153 differing bytes (one shifted copy). Everything after the multiply is the same shape.
 *
 * 2026-10-05 (wave D6 lane 01): still DIFF 170/172, 153 bytes, same two residues. (a) the slot
 *   multiply: the original computes idx in r4 and multiplies a copy (`adds r1,r4,#0; muls r1,r0,r1`,
 *   constant as the right operand); ours multiplies into the constant register. (b) modes 4/5 load y
 *   (`ldr r4,[r3,#0x10]`) before x; ours loads x first whatever the source order. Fresh finding: the
 *   slot is a 0x38-byte record {enabled; Vec a,b,c,d; u16 e,f} at p+0x14 (sizeof the draft Slot is
 *   0x4C). Tried, all 170/153 unless noted: `mode -= 7` in place, 56*idx and idx*56, an int local
 *   holding 56, the index in the y local, inline GetSlot(p, idx) (int, and with a separate idx local,
 *   and the -7 inside), inline SetSlot(p, idx, in), a char[56] record array index, per-field
 *   ((Slot *)p)[mode-7] writes; Big{pad[5]; Slot slots[]} with a pointer local gives the copy+mul
 *   shape but adds p+0x14 first (164/128, product reused). Modes 4/5: x/y source order, x read inline,
 *   a {x,y} struct copy (stores) and a {x,y} local (186/101), inline SetT(tgt, i, x, y): no change.
 * 2026-10-05 (wave D7 lane 01): rewritten with a real struct: Big {int pad[5]; Slot slots[9]; Vec t[2];
 *   int flag[2]} with Slot {enabled; Vec a,b,c,d; u16 e,f} (0x38 bytes), per-field writes through
 *   p->slots[mode - 7] (array indexing gives the original `adds rX,idx,#0; muls` copy shape) and
 *   p->t[i] / p->flag[i] for modes 4/5 with y read into a local first. Now 172/172 bytes, 27 differ
 *   (was 170/153). Two residues left: (a) slot index in r1 and product in r4, the original has idx in
 *   r4 and product in r1; (b) modes 4/5 load x (ldr r0,[r3,#0xc]) before y (ldr r4,[r3,#0x10]), the
 *   original loads y first. Tried for (a): named/unnamed index, mode -= 7, unsigned idx, u8/u16/int
 *   mode, a void * third parameter, the index in a shared function-scope local, an inline
 *   SetSlot(p, idx, in); a byte-offset pointer form loses the copy shape. Tried for (b): x/y locals in
 *   both orders and both declaration orders, y-only local, stores y first (keeps store order, worse),
 *   {x,y} 8-byte struct copy, a Vec local assigned per field (adds a frame), inline SetT(p, i, x, y).
 * 2026-10-05 (wave D9r lane 45): adopted the D8 nonconst variant (`Input *in`, y read first): 172/172,
 *   5 bytes differ (was 27). Only residue: the slot multiply colours (original idx r4 and product r1, ours
 *   idx r1 and product r4). Fresh finding: func_021F5450 (matched) is the getter `p + 0x14 + i * 0x38` for
 *   this record and func_021F5204 (matched) gives the real types: p is a 0x22C scene slot {active, enabled,
 *   object, primary, secondary, Track tracks[9] at 0x14, f524..f552}, so the 0x20C..0x228 words are
 *   f524..f552. Tried (all real compiles): the getter as a static inline returning u8 * or &p->tracks[i],
 *   once into a pointer local and once per statement (164 bytes, 128 differ: CSE makes a pointer and the
 *   copy shape is lost); slots in a nested struct; `mode > 6`; idx defined before the if (gives idx r4 and
 *   product r1 as in the original, but the sub moves above the cmp: 6 bytes); one shared local for idx and
 *   y; mode as u8, u16, int (and `(unsigned)mode >= 7`); unsigned idx; function-scope y/idx in both
 *   orders; `register` on idx or p; a switch for modes 4/5 (176 bytes); the slot path after a
 *   `mode < 7` block (162 differ); natural field order a,b,c,d,e,f (174 bytes); an inline CopyVec(d, s)
 *   for the Vec copies. Probe: with the mode 4/5 paths removed the colours are the same, so the residue
 *   is inside the slot block; with only `enabled = 1` there is no copy at all (`muls r0,r1,r0`).
 *   The original behaves as if idx were live across the compare. Not found.
 * 2026-10-05 (wave D9r lane 74): still DIFF 172/172, 5 bytes (slot multiply colours). New tries, all real
 *   compiles, none moves the colours: Slot {int enabled; Input d;} with `p->slots[idx].d.a = in->a`; Vec v[4]
 *   arrays in Input and Slot (same 5 bytes; two 2-iteration copy loops: 178 bytes); `p->slots[idx = mode - 7]`
 *   in the first store; an inline `SlotIndex(mode)` returning mode - 7; `const int idx`; a `first = 7` local
 *   for the bound and the subtraction; a `one = 1` local for the enabled store; `int idx = 0;` at function
 *   scope then `idx = mode - 7` in the block. Per-statement raw `*(T *)((u8 *)p + idx * 0x38 + K)` drops the
 *   copy (`muls r0,r1,r0`, 157 differ); a `Slot *s` from a byte offset or a `Slot *s = p->slots` pointer
 *   folds p+0x14 first (117 to 128 differ); a macro getter likewise (128). Finding: only array indexing
 *   p->slots[idx] gives the `adds; muls` copy, and only an idx defined in the entry block (before the cmp)
 *   gives the image colours (idx r4, product r1). The image has the sub after the branch, so idx is a
 *   block-local value whose colouring order differs from ours for a reason not found in the source.
 * symbols:
 */
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { Vec a,b,c,d; u16 e,f; } Input;
typedef struct { int enabled; Vec a,b,c,d; u16 e,f; } Slot;
typedef struct { int pad[5]; Slot slots[9]; Vec t[2]; int flag[2]; } Big;
void func_021F546C(unsigned mode, Input *in, Big *p)
{
    if (mode >= 7) {
        int idx = mode - 7;
        p->slots[idx].enabled = 1;
        p->slots[idx].a = in->a;
        p->slots[idx].b = in->b;
        p->slots[idx].e = in->e;
        p->slots[idx].f = in->f;
        p->slots[idx].c = in->c;
        p->slots[idx].d = in->d;
        return;
    }
    if (mode == 4) {
        int y = in->b.y;
        p->t[0].x = in->b.x;
        p->t[0].y = y;
        p->t[0].z = 0;
        p->flag[0] = 1;
        return;
    }
    if (mode == 5) {
        int y = in->b.y;
        p->t[1].x = in->b.x;
        p->t[1].y = y;
        p->t[1].z = 0;
        p->flag[1] = 1;
    }
}
