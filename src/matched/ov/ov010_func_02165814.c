/*
 * function: GAME_BEACON_SEARCH_SetInfoThanks
 * address: 0x02165814
 * packet: pkt_ov010_02165814
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MISC_GetBlock 0x0200C0F0 thumb
 *   MISC_GetThanksMessage 0x0200C20C thumb
 *   WORDSET_CopyString 0x0201F41C thumb
 *   GAME_BEACON_ResetDetails 0x0202744C thumb
 */
#include "../include/Obj00121.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Blk34;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MISC_GetBlock(void *);
extern u16 *MISC_GetThanksMessage(struct Blk34 *p);
extern void WORDSET_CopyString(const u16 *,u16 *,u32);
extern void GAME_BEACON_ResetDetails(void *);
void GAME_BEACON_SEARCH_SetInfoThanks(u8 *p,void *a,u16 b) { WORDSET_CopyString(MISC_GetThanksMessage(MISC_GetBlock(GAME_DATA_GetSaveControl(a))),(u16 *)(p+0x34),9); ((struct Obj00121 *)p)->f30=0x18; ((struct Obj00121 *)p)->f46=b; GAME_BEACON_ResetDetails(p); }
