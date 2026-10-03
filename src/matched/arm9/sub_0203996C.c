/*
 * function: sub_0203996C
 * address:  0x0203996C
 * packet:   pkt_020398B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *
 * Resolves a slot index to one of the nine 0x50-byte entries at +0x70 of
 * func_0203D788()'s record.  0xff is the "own slot" spelling and names entry
 * 8, which is why it is a separate constant add and not a folded index; every
 * other index is bounds-checked against nine and scaled with an `mla`,
 * 0x50 being too awkward for a shift pair.
 *
 * The record's own +0x340 field (see src/matched/sub_02039338.c) is exactly
 * where this table ends: 0x70 + 9 * 0x50.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203996C.c \
 *       --func sub_0203996C --addr 0x0203996C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef signed int    s32;

struct Entry {
    u8 pad_00[0x50];
};

struct Owner {
    u8 pad_00[0x70];
    struct Entry table[9];
};

extern void *func_0203D788(void);

struct Entry *sub_0203996C(s32 idx)
{
    struct Owner *owner = func_0203D788();

    if (owner != 0) {
        if (idx == 0xff) {
            return &owner->table[8];
        }
        if (idx < 9) {
            return &owner->table[idx];
        }
    }
    return 0;
}
