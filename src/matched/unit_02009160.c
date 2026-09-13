/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02009160
 * packet:   pkt_02009210
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009160, sub_020091AC, sub_020091FC, sub_02009200,
 *           sub_02009208
 *
 * alias: the rest of the 0x2C-byte object of src/matched/unit_020090D8.c and
 * src/matched/unit_02009110.c.  None of these five carries a label: the first
 * two save registers without lr and the last three have no prologue at all, so
 * the whole 176-byte run arrives in the listing as `.word` data.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The 9 by 4 byte table at the front of the object is three fields per byte:
 * the low nibble is the count unit_02009110.c reads, bit 7 is the flag it
 * tests, and bits 4 to 6 are a three-valued mark that these two functions
 * read and write.  The mark is not a bit index computed from the kind: 1 maps
 * to 0x40, 3 to 0x20 and 2 to 0x10, in that source order, which no arithmetic
 * produces and which both functions spell out as the same three-armed chain.
 *
 * In sub_020091AC each arm of that chain assigns only the mask and the `orrs`
 * is emitted once, with the no-match path branching past it, so the `|=` is
 * inside the arms in the source; see
 * docs/idioms/switch-arms-tail-merge.md.
 *
 * `subs r5, r3, #1; cmp r5, #2; bhi` is the folded range check, and it has to
 * be written as `(u32)(kind - 1) <= 2`: `kind >= 1 && kind <= 3` on the signed
 * parameter is two compares and two branches, two bytes longer, exactly as
 * docs/MATCHING.md records for sub_0200A6BC.  The row and column checks next
 * to it do not fold, because they are written as two comparisons against a
 * signed index in the style of unit_02009110.c.
 *
 * In sub_02009160 the `movs r4, #0` sits *after* the range checks, so the mask
 * is declared without an initialiser and assigned once the guards have passed.
 * Written as `u32 mask = 0;` the compiler hoists it above the first `cmp` and
 * the whole prologue shifts by two bytes.
 *
 * sub_02009200 and sub_02009208 pay an `adds r0, #0x29` before the `strb` and
 * the `ldrb`, because the byte offset 0x29 is past the 31 that the Thumb
 * immediate form reaches; see
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009160.c \
 *       --addr 0x02009160 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub020090B0Obj {
    u8  unk00[9][4];
    u16 unk24;
    u8  unk26;
    u8  unk27;
    u8  unk28;
    u8  unk29;
    u8  unk2A[2];
};

u32 sub_02009160(const struct Sub020090B0Obj *obj, int row, int col, int kind)
{
    u32 mask;

    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    mask = 0;
    if (kind == 1) {
        mask = 0x40;
    } else if (kind == 3) {
        mask = 0x20;
    } else if (kind == 2) {
        mask = 0x10;
    }
    if (obj->unk00[row][col] & mask) {
        return 1;
    }
    return 0;
}

void sub_020091AC(struct Sub020090B0Obj *obj, int row, int col, int kind,
                  int marked, int flagged)
{
    u32 value;

    if (kind >= 5) {
        return;
    }
    if (row >= 9 || row < 0) {
        return;
    }
    if (col >= 4 || col < 0) {
        return;
    }
    value = kind;
    if (marked == 1) {
        if ((u32)(kind - 1) <= 2) {
            value |= 0x80;
        }
    }
    if (flagged) {
        if (kind == 1) {
            value |= 0x40;
        } else if (kind == 3) {
            value |= 0x20;
        } else if (kind == 2) {
            value |= 0x10;
        }
    }
    obj->unk00[row][col] = value;
}

void sub_020091FC(void)
{
}

void sub_02009200(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk29 = value;
}

u8 sub_02009208(const struct Sub020090B0Obj *obj)
{
    return obj->unk29;
}
