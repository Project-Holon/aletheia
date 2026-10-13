/*
 * function: func_021E172C
 * address: 0x021E172C
 * packet: pkt_ov137_021E172C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 42-byte body followed by two bytes of zero alignment padding.
 * volatile: The raw halfword at q+0 is re-read at 021E1732/021E1734.
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj06543.h"
#include "../include/Obj23807.h"
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
void func_021E172C(char *p,unsigned short *q) { unsigned int index;unsigned short value; index=*(volatile unsigned short *)&((struct Obj06543 *)q)->f0;value=*(volatile unsigned short *)&((struct Obj06543 *)q)->f0;*(unsigned short *)(p+index*4+0x7c)=value;*(unsigned short *)(p+index*4+0x7e)=q[1];if(q[1]==GFL_NET_SYSTEM_GetCurrentAid())((struct Obj23807 *)p)->f2C=q[0]; }
