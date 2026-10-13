/*
 * function: BTL_SERVER_FLOW_GetFrontCountForRule
 * address: 0x021C7F04
 * packet: pkt_ov093_021C7F04
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeClientFrontCount 0x021C7EEC thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 BTL_MAIN_GetRule(void **p);
extern int BTL_SERVER_FLOW_GetPokeClientFrontCount(u8 *, int);
int BTL_SERVER_FLOW_GetFrontCountForRule(u8 *p, int i) { if (BTL_MAIN_GetRule(((struct Obj00003 *)p)->f4) != 3) return BTL_SERVER_FLOW_GetPokeClientFrontCount(p, i); return 3; }
