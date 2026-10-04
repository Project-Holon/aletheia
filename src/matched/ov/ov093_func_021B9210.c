/*
 * function: func_021B9210
 * address: 0x021B9210
 * packet: pkt_ov093_021B9210
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj20979.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 lo:6; u8 flag:1; u8 hi:1; } Flags;
u32 func_021B9210(u8 *p) { u32 n; n=((struct Obj20979 *)p)->f434; if(((Flags *)(p+0x473))->flag) { n*=2; if(n>99999) n=99999; } return n; }
