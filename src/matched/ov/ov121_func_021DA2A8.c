/*
 * function: func_021DA2A8
 * address: 0x021DA2A8
 * packet: pkt_ov121_021DA2A8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9A58 0x021D9A58 thumb ov121
 */
#include "../include/Obj22880.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D9A58(u8 *);
void func_021DA2A8(u8 *p) { u32 i; for(i=0;i<((struct Obj22880 *)p)->f4;i++) func_021D9A58(*(u8 **)(p+16+i*4)); }
