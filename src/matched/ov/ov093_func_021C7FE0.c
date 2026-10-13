/*
 * function: BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed
 * address: 0x021C7FE0
 * packet: pkt_ov093_021C7FE0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes alignment padding follow.
 * ABI: original forwards full-word B8DDC/B9010 results without narrowing;
 * widen B9010 and B8B9C input declarations relative to narrow legacy sources.
 * symbols:
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_MAIN_GetPartnerClient 0x021B9010 thumb ov093
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 *   BTL_SIDE_GetSlotOfClientThunk 0x021B9AF8 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern u8 BTL_MAIN_GetPartnerClient(u8 *p, u8 k);
extern int BTL_MAIN_IsClientUsed(u8 *, unsigned int);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *, int);
char *BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed(u8 *p, int v) { unsigned int k; k=BTL_MAIN_GetPartnerClient(*(u8 * *)&((struct Obj00003 *)p)->f4, BTL_MAIN_PokeIdToClientIdThunk(v)); if(BTL_MAIN_IsClientUsed(*(u8 * *)&((struct Obj00003 *)p)->f4,k)) return BTL_SIDE_GetSlotOfClientThunk(*(char * *)&((struct Obj00003 *)p)->f8,k); return 0; }
