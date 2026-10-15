/*
 * function: MYSTERY_UTIL_ClearWindowList
 * address: 0x021DA2A8
 * packet: pkt_ov121_021DA2A8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UTIL_ClearWindow 0x021D9A58 thumb ov121
 */
#include "../include/Obj22880.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTERY_UTIL_ClearWindow(u8 *);
void MYSTERY_UTIL_ClearWindowList(u8 *p) { u32 i; for(i=0;i<((struct Obj22880 *)p)->f4;i++) MYSTERY_UTIL_ClearWindow(*(u8 **)(p+16+i*4)); }
