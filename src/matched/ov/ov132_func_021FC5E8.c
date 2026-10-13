/*
 * function: func_021FC5E8
 * address: 0x021FC5E8
 * packet: pkt_ov132_021FC5E8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021F969C 0x021F969C thumb ov132
 */
#include "../include/Obj08172.h"
#include "../include/Obj23267.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 VM_GetU32(struct Cursor *);
extern int func_021F969C(char *p, u32 a, u32 b, u32 d);
int func_021FC5E8(int unused,char *p) { char *o; u32 a,b,c; o=*(char * *)&((struct Obj08172 *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct Obj08172 *)p)->f4); b=VM_GetU32(*(struct Cursor * *)&((struct Obj08172 *)p)->f4); c=VM_GetU32(*(struct Cursor * *)&((struct Obj08172 *)p)->f4); func_021F969C(*(char * *)&((struct Obj23267 *)o)->f34,(u16)a,(u16)b,(u16)c); return 0; }
