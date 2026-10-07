/*
 * function: func_02205B24
 * address: 0x02205B24
 * packet: pkt_ov195_02205B24
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02208D1C 0x02208D1C data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 */

#include "../include/G_02208D1C.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern struct G_02208D1C d_02208D1C;
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *,int,int);
void func_02205B24(void *p) {u32 i;for(i=0;i<6;i++){u32 id=*(u32 *)(((char *)&d_02208D1C)+i*44);if(id<=3)func_020403F4((u8)id);}func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}
