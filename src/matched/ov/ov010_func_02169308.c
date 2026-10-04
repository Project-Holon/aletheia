/*
 * function: func_02169308
 * address: 0x02169308
 * packet: pkt_ov010_02169308
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * address arithmetic: unsigned 32-bit index scaling and base addition
 * preserve the original lsls/adds wraparound without an invented index bound.
 * symbols:

 */
#include "../include/Obj04162.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Cb)(u8 *, u32);
void func_02169308(u8 *p) { Cb cb; if (((struct Obj04162 *)p)->fB0) { cb = *(Cb *)(((struct Obj04162 *)p)->f28+((struct Obj04162 *)p)->f18*16u+4u); if(cb) cb(p,((struct Obj04162 *)p)->fD8); } }
