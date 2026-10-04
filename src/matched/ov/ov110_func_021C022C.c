/*
 * unit: yes
 * function: func_021C022C, func_021C0250
 * address: 0x021C022C
 * packet: pkt_ov110_021C022C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202DC98 0x0202DC98 thumb
 */
#include "../include/Obj13806.h"
#include "../include/Obj22406.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj0202DC98;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_0202DC98(struct Obj0202DC98 *o);
int func_021C022C(u8 *p) { if(func_0201C6B4(((struct Obj13806 *)p)->f5C) && func_0202DC98(((struct Obj13806 *)p)->f8C)) return 1; return 0; }
void func_021C0250(int *out,u8 *p,int value) { *out=value; ((struct Obj22406 *)p)->f9C=0; }
