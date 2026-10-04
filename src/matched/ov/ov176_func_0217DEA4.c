/*
 * function: func_0217DEA4
 * address: 0x0217DEA4
 * packet: pkt_ov176_0217DEA4
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E5F24 0x021E5F24 thumb ov177
 *   func_021E62CC 0x021E62CC thumb ov177
 */
#include "../include/Obj00348.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E5F24(char *,int,void *,void *,int,u16);
extern void func_021E62CC(char *,int,void *,void *,int,u16);
void func_0217DEA4(u8 *p,int a) {if(((struct Obj00348 *)p)->f14==0)func_021E5F24(*(char * *)&((struct Obj00348 *)p)->f8,a,((struct Obj00348 *)p)->f0,((struct Obj00348 *)p)->f24,((struct Obj00348 *)p)->f1C,((struct Obj00348 *)p)->f34);else func_021E62CC(*(char * *)&((struct Obj00348 *)p)->f8,a,((struct Obj00348 *)p)->f0,((struct Obj00348 *)p)->f24,((struct Obj00348 *)p)->f1C,((struct Obj00348 *)p)->f34);}
