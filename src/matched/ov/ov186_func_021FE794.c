/*
 * function: func_021FE794
 * address: 0x021FE794
 * packet: pkt_ov186_021FE794
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FED08 0x021FED08 thumb ov186
 */
#include "../include/Obj05506.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021FED08(u32);
void func_021FE794(char *p,u32 index,u32 a,u32 b,u32 c) { ((struct Obj05506 *)p)->f4=a; ((struct Obj05506 *)p)->f18=c; ((struct Obj05506 *)p)->f8=b; ((struct Obj05506 *)p)->f1C=func_021FED08(index); ((struct Obj05506 *)p)->f0=0; ((struct Obj05506 *)p)->fC=0; }
