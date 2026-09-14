/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201AE14
 * packet:   pkt_0201AE14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201AE14, sub_0201AE1C, sub_0201AF6C, sub_0201AF80
 *
 * poke_personal.c, the middle of it: the record destructor, the 44 field
 * getter over the 0x3C byte personal record, the "is this a placeholder
 * ability id" predicate and the form-table loader.  It abuts
 * src/matched/unit_0201ADD0.c on the left, whose sub_0201ADE4 carries the
 * "poke_personal.c" file string, and src/matched/unit_0201AFD4.c on the
 * right, which reads the same 0x3C byte record out of the same archive
 * handle at 0x0214652C.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Three content constants live in this file and every one of them is a
 * number the game's data, not its structure, decides:
 *
 *   0x29C (668)  sub_0201AF80's archive member id, the form table.  It is the
 *                index of one member inside the handle at 0x0214652C, so it
 *                moves if the archive is repacked; IRAO is expected to share
 *                the packing but this is the first thing to re-read.
 *   999          sub_0201AF80's "no entry" sentinel in that form table.  It is
 *                a species-space sentinel, not a count, and it is what the
 *                entry count is measured against.
 *   0, 0xFE,0xFF sub_0201AF6C's three accepted ids.  The callers (0x02017D00,
 *                0x0201860E, 0x020186AE, 0x020186FE, 0x02018718) all feed it a
 *                value read out of the personal record, so these are content
 *                ids in the same space as the record's own fields.
 *
 * The 44 case ids of sub_0201AE1C are an interface rather than content: they
 * are the field selector the whole region uses, and src/matched/sub_02018A7C.c
 * reads the same record through ids of its own.  The field offsets are
 * structure and will not move; the ids will not either unless a field is
 * added, which is exactly the kind of thing a version diff does, so the map
 * below is the thing to check against IRAO rather than any single number.
 *
 * ---------------------------------------------------------------------------
 * THE FIELD MAP, from the jump table
 * ---------------------------------------------------------------------------
 * The table at 0x0201AE2E is 44 signed halfwords and every one of them names a
 * real body, so the source has case labels 0 through 43 with no gaps
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  The bodies
 * are emitted in the source's order, which here is also the numeric order,
 * even though the offsets they read are not monotonic: id 9 reads +0x22 and id
 * 36 reads +0x09, both out of sequence.
 *
 *    0.. 5  +0x00..+0x05  the six base stats
 *    6, 7   +0x06, +0x07  the two types
 *    8      +0x08
 *    9      +0x22
 *   10..15  +0x0A bits 0..11, six 2 bit fields: the six effort yields
 *   16      +0x0A bit 12, one bit
 *   17..19  +0x0C, +0x0E, +0x10  three held item ids
 *   20..29  +0x12..+0x1B  ten bytes
 *   30, 31  +0x1C, +0x1E  the form table base and its companion; +0x1C is the
 *                         same field src/matched/unit_0201AFD4.c reads
 *   32      +0x20         the form count, also read by unit_0201AFD4.c
 *   33      +0x21 bits 0..5
 *   34, 35  +0x21 bit 6, bit 7
 *   36      +0x09
 *   37, 38  +0x24, +0x26
 *   39..43  +0x28..+0x38  five words
 *
 * Two shapes in there are readings of the declaration rather than of the code.
 * The 2 bit and 1 bit extractions at +0x0A are `lsls`/`lsrs` pairs whose width
 * is neither 8, 16 nor 32, so they are bitfields and nothing else
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); the
 * container has to be `u16` for the load to be a `ldrh`, and `u8` at +0x21 for
 * it to be a `ldrb`.  And the two bytes at +0x20 and +0x21 each cost an
 * `adds r0, #0x20` first, which is only the byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md); the halfword at +0x22
 * needs none, because `ldrh` reaches 62.
 *
 * ---------------------------------------------------------------------------
 * THE THREE SMALLER FUNCTIONS
 * ---------------------------------------------------------------------------
 * sub_0201AE14 is four bytes of code and one pool word: a tail call with no
 * argument set-up at all
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * sub_0201AF6C is a disjunction and not a conjunction.  The `beq` from the
 * first test lands on the `movs r0, #1` that the second test's `bhi` falls
 * through to, and the `movs r0, #0` is out of line behind it; written
 * `if (v != 0 && v - 0xFE > 1) return 0;` every byte is still right and the
 * two exit blocks come out in the opposite order
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md,
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201AF80 narrows the byte length the archive hands back to a halfword
 * count with a single `lsls #0xf` / `lsrs #0x10` pair.  The amounts are
 * unequal, so it is a cast folded with a shift and not a bitfield: 32 - 16 is
 * the width and 15 - 16 is the shift, i.e. `(u16)(len >> 1)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * Writing `(u16)(len / 2)` costs a second pair.  The counter's zero is a copy
 * of the accumulator's (`adds r2, r5, #0`), which is what says the
 * accumulator is assigned first
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0204A39C  0x0204A39C  arm
 *   g_0214652C     0x0214652C  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AE14.c \
 *       --addr 0x0201AE14 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Personal {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08;
    u8  unk09;
    u16 ev0 : 2;
    u16 ev1 : 2;
    u16 ev2 : 2;
    u16 ev3 : 2;
    u16 ev4 : 2;
    u16 ev5 : 2;
    u16 unk0A_12 : 1;
    u16 unk0A_13 : 3;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u8  unk12;
    u8  unk13;
    u8  unk14;
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    u8  unk1B;
    u16 unk1C;
    u16 unk1E;
    u8  unk20;
    u8  unk21_0 : 6;
    u8  unk21_6 : 1;
    u8  unk21_7 : 1;
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
};

extern void func_020307B0(void *p);

void sub_0201AE14(void *p)
{
    func_020307B0(p);
}

u32 sub_0201AE1C(const struct Personal *p, u32 field)
{
    switch (field) {
    case 0:  return p->unk00;
    case 1:  return p->unk01;
    case 2:  return p->unk02;
    case 3:  return p->unk03;
    case 4:  return p->unk04;
    case 5:  return p->unk05;
    case 6:  return p->unk06;
    case 7:  return p->unk07;
    case 8:  return p->unk08;
    case 9:  return p->unk22;
    case 10: return p->ev0;
    case 11: return p->ev1;
    case 12: return p->ev2;
    case 13: return p->ev3;
    case 14: return p->ev4;
    case 15: return p->ev5;
    case 16: return p->unk0A_12;
    case 17: return p->unk0C;
    case 18: return p->unk0E;
    case 19: return p->unk10;
    case 20: return p->unk12;
    case 21: return p->unk13;
    case 22: return p->unk14;
    case 23: return p->unk15;
    case 24: return p->unk16;
    case 25: return p->unk17;
    case 26: return p->unk18;
    case 27: return p->unk19;
    case 28: return p->unk1A;
    case 29: return p->unk1B;
    case 30: return p->unk1C;
    case 31: return p->unk1E;
    case 32: return p->unk20;
    case 33: return p->unk21_0;
    case 34: return p->unk21_6;
    case 35: return p->unk21_7;
    case 36: return p->unk09;
    case 37: return p->unk24;
    case 38: return p->unk26;
    case 39: return p->unk28;
    case 40: return p->unk2C;
    case 41: return p->unk30;
    case 42: return p->unk34;
    case 43: return p->unk38;
    }
    return 0;
}

u32 sub_0201AF6C(u32 v)
{
    if (v == 0 || v - 0xFE <= 1) {
        return 1;
    }
    return 0;
}

extern void *func_0204A39C(void *handle, u32 id, u32 x, u32 heap, u32 *sizeOut);
extern void *g_0214652C;

u16 *sub_0201AF80(u32 heap, u16 *countOut)
{
    u32 len;
    u16 *tab;
    u16 count;
    u16 n;
    u16 i;

    count = 0;
    tab = func_0204A39C(g_0214652C, 0x29C, 0, heap, &len);
    n = (u16)(len >> 1);
    if (countOut != 0) {
        for (i = 0; i < n; i++) {
            if (tab[i] != 999) {
                count++;
            }
        }
        *countOut = count;
    }
    return tab;
}
