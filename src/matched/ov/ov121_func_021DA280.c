/*
 * function: MYSTERY_UTIL_DeleteWindowList
 * address: 0x021DA280
 * packet: pkt_ov121_021DA280
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MYSTERY_UTIL_DeleteWindow 0x021D9A40 thumb ov121
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22879.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTERY_UTIL_DeleteWindow(u8 *);
extern u32 func_020307B0(void *p);
void MYSTERY_UTIL_DeleteWindowList(u8 *p) { u32 i; for(i=0;i<((struct Obj22879 *)p)->f4;i++) MYSTERY_UTIL_DeleteWindow(*(u8 **)(p+16+i*4)); func_020307B0(p); }
