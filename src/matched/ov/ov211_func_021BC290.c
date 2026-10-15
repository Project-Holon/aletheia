/*
 * function: ZUKAN_SEARCH_PROC_Update
 * address: 0x021BC290
 * packet: pkt_ov211_021BC290
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BC8D8 0x021BC8D8 data a4
 */
#include "../include/Obj14684.h"
extern unsigned char d_021BC8D8[];
int ZUKAN_SEARCH_PROC_Update(unsigned char *p){((struct Obj14684 *)p)->fC=(*(unsigned (**)(unsigned char *))(d_021BC8D8+*(unsigned *)(p+12)*4))(p);return ((struct Obj14684 *)p)->fC!=6;}
