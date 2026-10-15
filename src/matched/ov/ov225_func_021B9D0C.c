/*
 * function: MANUAL_COMMON_GetEntryOffset
 * address: 0x021B9D0C
 * packet: pkt_ov225_021B9D0C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
#include "../include/Obj26143.h"
unsigned short MANUAL_COMMON_GetEntryOffset(char *p,unsigned i){return *(unsigned short *)(((struct Obj26143 *)p)->fC+i*2+2);}
