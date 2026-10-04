/*
 * function: func_021FC570
 * address: 0x021FC570
 * packet: pkt_ov132_021FC570
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0201DD78 0x0201DD78 thumb
 */
#include "../include/Obj10564.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 func_0201134C(struct Cursor *);
extern void func_0201DD78(u8,u8,u8);
int func_021FC570(int unused,char *p) { u32 a,b,c; a=func_0201134C(*(struct Cursor * *)&((struct Obj10564 *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct Obj10564 *)p)->f4); c=func_0201134C(*(struct Cursor * *)&((struct Obj10564 *)p)->f4); func_0201DD78(a,b,c); return 0; }
