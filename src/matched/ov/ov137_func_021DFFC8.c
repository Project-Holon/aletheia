/*
 * unit: no
 * function: func_021DFFC8
 * address: 0x021DFFC8
 * packet: pkt_ov137_021DFFC8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 */
#include "../include/Obj03842.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void func_0204A8D4(u32),func_0204ADA4(u32),func_0204AFD8(u32);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021DFFC8(u8 *p){func_0204A8D4(((struct Obj03842 *)p)->fD6C);func_0204ADA4(((struct Obj03842 *)p)->fD70);func_0204AFD8(((struct Obj03842 *)p)->fD74);func_0204B1CC(*(struct Bank * *)&((struct Obj03842 *)p)->fD68);func_0204A5AC();}
