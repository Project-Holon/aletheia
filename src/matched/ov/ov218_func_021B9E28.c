/*
 * function: func_021B9E28
 * address: 0x021B9E28
 * packet: pkt_ov218_021B9E28
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_021B796C 0x021B796C thumb ov067
 */
#include "../include/Obj14772.h"
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
struct U16Vec;struct S; extern void func_02045808(struct U16Vec *);extern void func_021B796C(struct S *);
void func_021B9E28(char *p){int i;for(i=0;i<130;i++)func_02045808(*(struct U16Vec **)(((struct Obj14772 *)p)->f28+i*4+0x2c));func_021B796C(*(struct S * *)&((struct Obj14772 *)p)->f2C);}
