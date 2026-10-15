/*
 * function: ZUKAN_SEARCH_SCREEN_RegisterVBlank
 * address: 0x021BC2F4
 * packet: pkt_ov211_021BC2F4
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_SEARCH_SCREEN_VBlank 0x021BC2D8 thumb ov211
 */
#include "../include/Obj10925.h"
extern void *func_020056A0(unsigned,unsigned,unsigned);extern void ZUKAN_SEARCH_SCREEN_VBlank(void);
void ZUKAN_SEARCH_SCREEN_RegisterVBlank(unsigned char *p){((struct Obj10925 *)p)->f4=func_020056A0((unsigned)ZUKAN_SEARCH_SCREEN_VBlank,(unsigned)p,0);}
