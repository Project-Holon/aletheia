/*
 * function: MYSTERY_UTIL_IsWindowListDone
 * address: 0x021DA2C8
 * packet: pkt_ov121_021DA2C8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MYSTERY_UTIL_IsMessageDone 0x021D9B34 thumb ov121
 */
#include "../include/Obj22881.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_UTIL_IsMessageDone(u8 *);
int MYSTERY_UTIL_IsWindowListDone(u8 *p) { u32 i; int result=1; for(i=0;i<((struct Obj22881 *)p)->f4;i++) result &= MYSTERY_UTIL_IsMessageDone(*(u8 **)(p+16+i*4)); return result; }
