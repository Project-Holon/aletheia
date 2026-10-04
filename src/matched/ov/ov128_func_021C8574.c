/*
 * function: func_021C8574
 * address: 0x021C8574
 * packet: pkt_ov128_021C8574
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   func_021C873C 0x021C873C thumb ov128
 *   func_021C6E3C 0x021C6E3C thumb ov128
 */
#include "../include/Obj23084.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021C873C(void *,int *,u8 *);
extern void *func_021C6E3C(void *,void **,int,int);
int func_021C8574(u8 *p,int *q,u8 *r,int heap) {if(func_021C873C(p,q,r)==0)return 0;((struct Obj23084 *)p)->f194=func_021C6E3C(p+376,(void **)(p+400),0,heap);return 1;}
