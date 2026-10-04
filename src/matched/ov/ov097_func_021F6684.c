/*
 * unit: yes
 * function: func_021F6684, func_021F669C
 * address: 0x021F6684
 * packet: pkt_ov097_021F6684
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 */
#include "../include/Obj10193.h"
#include "../include/Obj21989.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020221A4(void);
int func_021F6684(u8 *p) { if(func_020221A4()==1) return ((struct Obj21989 *)p)->f118; return 2; }
int func_021F669C(u8 *p) { if(((struct Obj10193 *)p)->f11C==0) return ((struct Obj10193 *)p)->f114; (((struct Obj10193 *)p)->f11C)--; return 3; }
