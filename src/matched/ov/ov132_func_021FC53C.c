/*
 * function: func_021FC53C
 * address: 0x021FC53C
 * packet: pkt_ov132_021FC53C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021F93D8 0x021F93D8 thumb ov132
 */
#include "../include/Obj10563.h"
#include "../include/Obj23260.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 VM_GetU32(struct Cursor *);
extern void func_021F93D8(u8 *,u16,u32);
int func_021FC53C(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct Obj10563 *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct Obj10563 *)p)->f4); b=VM_GetU32(*(struct Cursor * *)&((struct Obj10563 *)p)->f4); func_021F93D8(*(u8 * *)&((struct Obj23260 *)o)->f34,a,b); return 0; }
