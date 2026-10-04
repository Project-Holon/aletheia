/*
 * function: func_021D5D24
 * address: 0x021D5D24
 * packet: pkt_ov123_021D5D24
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C5CFC 0x021C5CFC arm ov114
 */
#include "../include/Obj06461.h"
extern int func_021C5CFC(void *fileinfo, char *buf, unsigned int size);
int func_021D5D24(char *p){int ok=1;((struct Obj06461 *)p)->fB0=0;((struct Obj06461 *)p)->fCC=1;((struct Obj06461 *)p)->fD0=0;if(!func_021C5CFC(p,((struct Obj06461 *)p)->fB8,((struct Obj06461 *)p)->fBC+0x40))ok=0;return ok;}
