/*
 * function: func_021D4698
 * address: 0x021D4698
 * packet: pkt_ov124_021D4698
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj00991.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_020307B0(void *);
extern void func_0204B3B4(struct Obj *);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
void func_021D4698(char *p) {func_020307B0(((struct Obj00991 *)p)->f44);func_0204B3B4(*(struct Obj * *)&((struct Obj00991 *)p)->f5C);func_0204ADA4(((struct Obj00991 *)p)->f50);func_0204A8D4(((struct Obj00991 *)p)->f54);func_0204AFD8(((struct Obj00991 *)p)->f58);}
