/*
 * function: BR_POKESEARCH_Close
 * address: 0x021FFE70
 * packet: pkt_ov186_021FFE70
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_POKESEARCH_DestroySpeciesList 0x022000D0 thumb ov186
 *   BR_POKESEARCH_DestroyGroupWindows 0x021FFFCC thumb ov186
 *   BR_POKESEARCH_DestroyBackButton 0x021FFF1C thumb ov186
 */
#include "../include/Obj14486.h"
typedef unsigned char  u8;
extern void BR_POKESEARCH_DestroySpeciesList(u8 *p);
extern void BR_POKESEARCH_DestroyGroupWindows(u8 *p);
extern void BR_POKESEARCH_DestroyBackButton(char *);
void BR_POKESEARCH_Close(char *p) {((struct Obj14486 *)p)->f6C=0;if(((struct Obj14486 *)p)->f70==1)BR_POKESEARCH_DestroySpeciesList((u8 *)p);else BR_POKESEARCH_DestroyGroupWindows((u8 *)p);BR_POKESEARCH_DestroyBackButton(p);}
