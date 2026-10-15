/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02009110
 * packet:   pkt_02008FD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: CGEAR_SAVE_GetPanelValue, CGEAR_SAVE_GetPanelFlag
 *
 * Two readers of the 9 by 4 byte table at the front of the 0x2C-byte object
 * whose accessors are in src/matched/unit_020090D8.c.  Each byte of that table
 * is two fields: the low nibble is a count and the top bit is a flag, and these
 * two functions are the only places that say so.
 *
 * Both carry the same pair of range checks, and both write the upper bound
 * first: `cmp #9` then `cmp #0` for the row, `cmp #4` then `cmp #0` for the
 * column, each pair falling through into the next.  That is two compares and
 * two branches per index rather than the single unsigned compare an
 * `(unsigned)i < 9` would give, so the indices are signed `int` and the source
 * spells both halves of the test out.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009110.c \
 *       --addr 0x02009110 --thumb
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
    u8  unk29[3];
};

u32 CGEAR_SAVE_GetPanelValue(const struct Sub020090B0Obj *obj, int row, int col)
{
    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    return obj->unk00[row][col] & 0xF;
}

int CGEAR_SAVE_GetPanelFlag(const struct Sub020090B0Obj *obj, int row, int col)
{
    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    if ((obj->unk00[row][col] & 0x80) != 0) {
        return 1;
    }
    return 0;
}
