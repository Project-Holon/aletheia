/*
 * function: func_021B8FA8
 * address: 0x021B8FA8
 * packet: pkt_ov106_021B8FA8
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203630C 0x0203630C arm
 */
#include "../include/Obj22267.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0203630C(void);
void *func_021B8FA8(u8 *p,int *out) { if(out) *out=((struct Obj22267 *)p)->f28; return (void *)func_0203630C(); }
