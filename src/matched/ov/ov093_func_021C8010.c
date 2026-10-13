/*
 * function: BTL_SERVER_FLOW_GetPokeViewPos
 * address: 0x021C8010
 * packet: pkt_ov093_021C8010
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *, void *, unsigned int);
int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v) { return BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, v); }
