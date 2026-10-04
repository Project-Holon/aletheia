/*
 * function: func_021FBFDC
 * address: 0x021FBFDC
 * packet: pkt_ov132_021FBFDC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DC0 0x021F9DC0 thumb ov132
 *   func_021F9DC4 0x021F9DC4 thumb ov132
 *   func_021F9F58 0x021F9F58 thumb ov132
 *   func_021F9DCC 0x021F9DCC thumb ov132
 */
#include "../include/Obj10558.h"
#include "../include/Obj14119.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 func_0201134C(struct Cursor *);
extern void *func_021F9DC0(void *);
extern void *func_021F9DC4(void *,u8);
extern void func_021F9F58(u8 *,u8 *);
extern void func_021F9DCC(void *p, void *v, u32 i);
int func_021FBFDC(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct Obj14119 *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct Obj14119 *)p)->f4); ctx=func_021F9DC0(((struct Obj10558 *)o)->f34); func_021F9F58(ctx,func_021F9DC4(((struct Obj10558 *)o)->f34,a)); func_021F9DCC(((struct Obj10558 *)o)->f34,0,(u8)a); return 0; }
