/*
 * function: func_021B7694
 * address: 0x021B7694
 * packet: pkt_ov173_021B7694
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;struct Bank;
extern void func_0204B3B4(struct Obj *);
extern void func_0204B1CC(struct Bank *);
extern void func_0204A5AC(void);
extern void func_02049238(void *);
void func_021B7694(u8 *p) {u32 i;for(i=0;i<14;i++)func_0204B3B4(*(struct Obj **)(p+i*4+260));func_0204B1CC(*(struct Bank * *)&((struct Obj00362 *)p)->f100);func_0204A5AC();func_02049238(((struct Obj00362 *)p)->f13C);}
