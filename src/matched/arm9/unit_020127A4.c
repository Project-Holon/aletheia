/*
 * unit:     yes
 * function: GAME_DATA_GetMyPlayerWork, GAME_DATA_GetBattleRecSlot
 * address:  0x020127A4
 * packet:   pkt_020124F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetBattleRecSlot  0x020127AC  thumb
 *
 * Two address-of-member accessors on the same save-data block, neither of
 * which saves lr, so neither carries a label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md) and the pair
 * has to be worked as one unit.
 *
 * Both offsets are out of Thumb immediate range and are built as
 * `movs #n / lsls #2`, which is why 0x114 appears as 0x45 and 0x1d4 as 0x75.
 * The second takes an index into a 16-byte array that starts at +0x1d4.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020127A4.c \
 *       --addr 0x020127A4 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct SaveBlock {
    u8 pad_000[0x114];
    u8 unk_114[0xc0];
    u8 unk_1d4[1][0x10];
};

void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p)
{
    return p->unk_114;
}

void *GAME_DATA_GetBattleRecSlot(struct SaveBlock *p, u32 idx)
{
    return p->unk_1d4[idx];
}
