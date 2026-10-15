/*
 * function: RESEARCH_GRAPH_GetSaveBits
 * address:  0x021BF9CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RESEARCH_GRAPH_GetAppResource  0x021BF740  thumb  ov217
 *   RESEARCH_GRAPH_GetGroupKey  0x021BF7CC  thumb  ov217
 *   MISC_SAVEDATA_GetHalfword  0x0200E458  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   SYMBOL_SAVE_GetBitBlock  0x0200E394  thumb  arm9
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001C THM_CALL MISC_SAVEDATA_GetHalfword       -> unresolved: 0200E458 (arm, from name) has no witness outside 021BF9CC..021BF9EE
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Big;
extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
extern u16 MISC_SAVEDATA_GetHalfword(const u16 *, int);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern u32 RESEARCH_GRAPH_GetAppResource(u8 *);
extern u32 RESEARCH_GRAPH_GetGroupKey(void *);
u16 RESEARCH_GRAPH_GetSaveBits(u32 a0)
{
    return MISC_SAVEDATA_GetHalfword((const u16 *)SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_GRAPH_GetAppResource((u8 *)a0))), RESEARCH_GRAPH_GetGroupKey((void *)a0));
}

