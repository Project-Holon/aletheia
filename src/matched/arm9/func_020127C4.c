/*
 * function: GAME_DATA_GetSecondUnionInfo
 * address:  0x020127C4
 * packet:   pkt_020127B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetUnionInfo  0x020127D0  thumb
 *
 * Promoted from src/pending/GAME_DATA_GetSecondUnionInfo.c (was MATCH, blocker 0x020127D0,
 * declared by the naming convention, i.e. ARM).  Two things had to happen:
 * the pool word is 0x020127D1 so the target is Thumb, and
 * src/matched/GAME_DATA_GetUnionInfo.c has to exist as an EXACT entry for the
 * `matched` class to reach it - both done, and the C never changed.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_GetSecondUnionInfo.c \
 *       --func GAME_DATA_GetSecondUnionInfo --addr 0x020127C4 --cc 1.1p1 --thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *GAME_DATA_GetUnionInfo(u8 *o, u32 idx);

u8 *GAME_DATA_GetSecondUnionInfo(void *p)
{
    return GAME_DATA_GetUnionInfo(p, 1);
}
