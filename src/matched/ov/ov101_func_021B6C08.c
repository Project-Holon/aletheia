/*
 * function: func_021B6C08
 * address: 0x021B6C08
 * packet: pkt_ov101_021B6C08
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj22114.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S020314B8;
extern void func_0203133C(struct S020314B8 *p);
extern void func_02082BCC(void *,int,u32);
void func_021B6C08(u8 *p) { func_0203133C(((struct Obj22114 *)p)->f0); func_02082BCC(p,0,12); }
