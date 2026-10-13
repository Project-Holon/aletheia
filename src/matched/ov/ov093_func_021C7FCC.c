/*
 * function: BTL_SERVER_FLOW_GetPartyOfPoke
 * address: 0x021C7FCC
 * packet: pkt_ov093_021C7FCC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_SIDE_GetSlotOfClientThunk 0x021B9AF8 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *, int);
char *BTL_SERVER_FLOW_GetPartyOfPoke(u8 *p, int i) { return BTL_SIDE_GetSlotOfClientThunk(*(char * *)&((struct Obj00003 *)p)->f8, BTL_MAIN_PokeIdToClientIdThunk(i)); }
