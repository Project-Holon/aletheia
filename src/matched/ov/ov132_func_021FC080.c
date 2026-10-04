/*
 * function: func_021FC080
 * address: 0x021FC080
 * packet: pkt_ov132_021FC080
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DC4 0x021F9DC4 thumb ov132
 *   func_021F9FB4 0x021F9FB4 thumb ov132
 */
#include "../include/Obj10559.h"
#include "../include/Obj23259.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 func_0201134C(struct Cursor *);
extern void *func_021F9DC4(void *,u8);
extern void func_021F9FB4(char *,u16);
int func_021FC080(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct Obj10559 *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct Obj10559 *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct Obj10559 *)p)->f4); func_021F9FB4(func_021F9DC4(((struct Obj23259 *)o)->f34,a),b); return 0; }
