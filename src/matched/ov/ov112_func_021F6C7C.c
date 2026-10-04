/*
 * function: func_021F6C7C
 * address: 0x021F6C7C
 * packet: pkt_ov112_021F6C7C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj08024.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204ADA4(u32);extern void func_0204A8D4(u32);extern void func_0204AFD8(u32);extern void func_0204B1CC(void *);extern void func_020307B0(void *);
void func_021F6C7C(char *p) {func_0204ADA4(((struct Obj08024 *)p)->fAC);func_0204A8D4(((struct Obj08024 *)p)->fB0);func_0204AFD8(((struct Obj08024 *)p)->fB4);func_0204B1CC(((struct Obj08024 *)p)->fA8);func_020307B0(p);}
