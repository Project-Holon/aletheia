/*
 * function: func_021D5CF8
 * address: 0x021D5CF8
 * packet: pkt_ov123_021D5CF8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C5C38 0x021C5C38 arm ov114
 */
#include "../include/Obj10439.h"
extern int func_021C5C38(void *filelist, unsigned int offset, unsigned int num);
int func_021D5CF8(char *p){int ok=1;((struct Obj10439 *)p)->fB0=0;((struct Obj10439 *)p)->fCC=1;((struct Obj10439 *)p)->fD0=0;if(!func_021C5C38(p,0,1))ok=0;return ok;}
