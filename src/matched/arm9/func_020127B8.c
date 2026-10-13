/*
 * function: GAME_DATA_GetLastBattleRecSlot
 * address:  0x020127B8
 * packet:   pkt_020127B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetBattleRecSlot  0x020127AC  thumb
 *
 * Promoted from src/pending/GAME_DATA_GetLastBattleRecSlot.c (was MATCH, blocker 0x020127AC,
 * declared by the naming convention, which defaults to ARM).  The pool word
 * is 0x020127AD, so the target is Thumb; declared `thumb` the `matched`
 * class fires on the EXACT unit entry for 0x020127AC
 * (src/matched/unit_020127A4.c, which names it as a member function) and
 * the site resolves with no change to the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_GetLastBattleRecSlot.c \
 *       --func GAME_DATA_GetLastBattleRecSlot --addr 0x020127B8 --cc 1.1p1 --thumb
 */

typedef unsigned int   u32;
struct SaveBlock;
extern void *GAME_DATA_GetBattleRecSlot(struct SaveBlock *p, u32 idx);

void *GAME_DATA_GetLastBattleRecSlot(void *p)
{
    return GAME_DATA_GetBattleRecSlot(p, 3);
}
