/*
 * function: func_021D5C2C
 * address: 0x021D5C2C
 * packet: pkt_ov123_021D5C2C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021DAC20 0x021DAC20 data ov123 a4
 */
#include "../include/Obj10438.h"
extern char *g_021DAC20;
int func_021D5C2C(char *p){if(((struct Obj10438 *)p)->fD0&&((struct Obj10438 *)p)->fC8)return 1;if(*(int *)(g_021DAC20+0xb0)&&((struct Obj10438 *)p)->fB4)return 1;return 0;}
