/*
 * function: func_021FC22C
 * address: 0x021FC22C
 * packet: pkt_ov132_021FC22C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F6EE4 0x021F6EE4 thumb ov112
 *   func_021F9DE8 0x021F9DE8 thumb ov132
 *   func_021F95E8 0x021F95E8 thumb ov132
 */
#include "../include/Obj08169.h"
#include "../include/Obj14120.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 func_0201134C(struct Cursor *);
extern void *func_021F9DD4(void *);
extern void *func_021F9DDC(void *,u8);
extern void func_021F6EE4(void *,u8 *);
extern void func_021F9DE8(void *,void *,u8);
extern void func_021F95E8(char *p);
int func_021FC22C(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct Obj14120 *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct Obj14120 *)p)->f4); ctx=func_021F9DD4(((struct Obj08169 *)o)->f34); func_021F6EE4(ctx,func_021F9DDC(((struct Obj08169 *)o)->f34,a)); func_021F9DE8(((struct Obj08169 *)o)->f34,0,a); func_021F95E8(((struct Obj08169 *)o)->f34); return 0; }
