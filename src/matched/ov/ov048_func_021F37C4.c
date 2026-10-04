/*
 * function: func_021F37C4
 * address: 0x021F37C4
 * packet: pkt_ov048_021F37C4
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F37A4 0x021F37A4 thumb ov048
 *   func_021F47B0 0x021F47B0 thumb ov048
 */
#include "../include/Obj05133.h"
#include "../include/Obj09833.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[15]; } Copy60;
extern u8 *func_021F37A4(u32);
extern int func_021F47B0(void *);
void func_021F37C4(u8 *p) { u8 *q; q=func_021F37A4(((struct Obj05133 *)p)->f4); ((struct Obj09833 *)q)->f0=((struct Obj05133 *)p)->f10; ((struct Obj09833 *)q)->f4=func_021F47B0(((struct Obj05133 *)p)->f14)>>12; ((struct Obj09833 *)q)->f8=((struct Obj05133 *)p)->f64; *(Copy60 *)(q+0xc)=*(Copy60 *)(p+0x28); }
