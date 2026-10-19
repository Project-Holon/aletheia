/*
 * unit:     yes
 * address:  0x0201AF6C
 * packet:   pkt_0201AE14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_PERSONAL_IsFixedGender, POKE_PERSONAL_LoadFormTable
 *
 * The tail of poke_personal.c: the "is this a placeholder ability id"
 * predicate and the form-table loader.  Cut out of
 * src/matched/unit_0201AE14.c together with src/matched/POKE_PERSONAL_GetParam.c so
 * that the 44 field getter at 0x0201AE1C gets a manifest entry of its own
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The C is
 * unchanged; only the file boundary moved.  This file still starts at the
 * address of its own first function, so it loses no entry by the same rule:
 * POKE_PERSONAL_LoadFormTable was already an interior function of unit_0201AE14.c.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Three content constants live here and every one of them is a number the
 * game's data, not its structure, decides:
 *
 *   0x29C (668)  POKE_PERSONAL_LoadFormTable's archive member id, the form table.  It is the
 *                index of one member inside the handle at 0x0214652C, so it
 *                moves if the archive is repacked; IRAO is expected to share
 *                the packing but this is the first thing to re-read.
 *   999          POKE_PERSONAL_LoadFormTable's "no entry" sentinel in that form table.  It is
 *                a species-space sentinel, not a count, and it is what the
 *                entry count is measured against.
 *   0, 0xFE,0xFF POKE_PERSONAL_IsFixedGender's three accepted ids.  The callers (0x02017D00,
 *                0x0201860E, 0x020186AE, 0x020186FE, 0x02018718) all feed it a
 *                value read out of the personal record, so these are content
 *                ids in the same space as the record's own fields.
 *
 * ---------------------------------------------------------------------------
 * THE TWO FUNCTIONS
 * ---------------------------------------------------------------------------
 * POKE_PERSONAL_IsFixedGender is a disjunction and not a conjunction.  The `beq` from the
 * first test lands on the `movs r0, #1` that the second test's `bhi` falls
 * through to, and the `movs r0, #0` is out of line behind it; written
 * `if (v != 0 && v - 0xFE > 1) return 0;` every byte is still right and the
 * two exit blocks come out in the opposite order
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md,
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * POKE_PERSONAL_LoadFormTable narrows the byte length the archive hands back to a halfword
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
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm
 *   _pPersonalArc     0x0214652C  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AF6C.c \
 *       --addr 0x0201AF6C --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u32 POKE_PERSONAL_IsFixedGender(u32 v)
{
    if (v == 0 || v - 0xFE <= 1) {
        return 1;
    }
    return 0;
}

extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void *_pPersonalArc;

u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut)
{
    u32 len;
    u16 *tab;
    u16 count;
    u16 n;
    u16 i;

    count = 0;
    tab = ARC_UTIL_LoadHandleMemberWithSize(_pPersonalArc, 0x29C, 0, heap, &len);
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
