/*
 * function: MYSTERY_UTIL_TransferWindowList
 * address: 0x021DA318
 * packet: pkt_ov121_021DA318
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UTIL_TransferWindowChars 0x021D9B9C thumb ov121
 */
#include "../include/Obj22882.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTERY_UTIL_TransferWindowChars(u8 *);
void MYSTERY_UTIL_TransferWindowList(u8 *p) { u32 i; for(i=0;i<((struct Obj22882 *)p)->f4;i++) MYSTERY_UTIL_TransferWindowChars(*(u8 **)(p+16+i*4)); }
