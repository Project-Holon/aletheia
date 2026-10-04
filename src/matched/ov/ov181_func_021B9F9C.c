/*
 * unit: no
 * function: func_021B9F9C
 * address: 0x021B9F9C
 * packet: pkt_ov181_021B9F9C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BACE4 0x021BACE4 data a4
 */
#include "../include/Obj06588.h"
#include "../include/Obj14410.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern const u8 d_021BACE4[];
void func_021B9F9C(u8 *p){u32 i;*(const void * *)&((struct Obj06588 *)p)->f0=d_021BACE4;((struct Obj06588 *)p)->f74=7;((struct Obj06588 *)p)->f78=0;((struct Obj06588 *)p)->f76=0;((struct Obj06588 *)p)->f7C=0;for(i=0;i<16;i++){u8 *q=p+i*4;((struct Obj14410 *)q)->f34=65535;((struct Obj14410 *)q)->f36=0;}}
