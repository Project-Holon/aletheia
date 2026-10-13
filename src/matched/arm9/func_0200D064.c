/*
 * function: ZUKAN_SAVE_IsSeen
 * address:  0x0200D064
 * packet:   pkt_0200D064
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The four-row "distributed" test: after the ZUKAN_SAVE_IsInvalidSpecies range guard,
 * true when species `id` has its bit set in any of the four 0x54-byte rows
 * struct Blk37::unk05C (docs/families/musical_dist_save.h).
 *
 * Closed in wave 13 by writing it through two small inline helpers instead
 * of one open-coded address (docs/notes/pkt_0200D064.c.txt has the long
 * history of the open-coded spellings, best 10 bytes out):
 *   - a row accessor taking a u16 row index, which is where the image's
 *     `lsls/lsrs #16` of the u32 loop counter at every use comes from;
 *   - the species-bit test `TestSpecies(row, id)` that forms `u16 x = id -
 *     1` itself (the same helper closed ZUKAN_SAVE_GetViewGenderAndForm).  Inlined, it keeps
 *     `row + (x >> 3)` in the image's operand order instead of letting the
 *     compiler hoist `p + (x >> 3)` out of the loop, and the plain
 *     `return 1;` inside the loop then gives the preheader `movs r0, #1`.
 *
 * symbols:
 *   ZUKAN_SAVE_IsInvalidSpecies  0x0200C720  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk37 {
    u32 unk00;
    u32 unk04;
    u8  unk008[0x54];
    u8  unk05C[4][0x54];
    u8  unk1AC[4][0x54];
    u8  unk2FC[4][9];
    u8  unk320[0x1B0];
    u32 unk4D0;
};

extern u32 ZUKAN_SAVE_IsInvalidSpecies(u32 v);

static inline u32 TestSpecies(const u8 *row, u32 id)
{
    u16 x = id - 1;
    return row[x >> 3] & (1 << (x & 7));
}

static inline u8 *DistRow(struct Blk37 *p, u16 row)
{
    return p->unk05C[row];
}

u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id)
{
    u32 i;

    if (ZUKAN_SAVE_IsInvalidSpecies(id) != 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (TestSpecies(DistRow(p, i), id)) {
            return 1;
        }
    }
    return 0;
}
