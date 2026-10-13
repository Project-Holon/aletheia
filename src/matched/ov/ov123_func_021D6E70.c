/*
 * unit: no
 * function: func_021D6E70
 * address: 0x021D6E70
 * packet: pkt_ov123_021D6E70
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 */
#include "../include/Obj10442.h"
#include "../include/Obj22952.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern int GFL_NET_GetRunState(void);
int func_021D6E70(u8 *p){u8 *q=*(u8 * *)&((struct Obj22952 *)p)->f20;if(((struct Obj10442 *)q)->f1C8==2)return 0;if(((struct Obj10442 *)q)->f50 && ((struct Obj10442 *)q)->fC==4)return 0;if(GFL_NET_GetRunState())return 1;return 0;}
