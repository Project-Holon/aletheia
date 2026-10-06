/*
 * function: func_021F3ED0
 * address: 0x021F3ED0
 * packet: pkt_ov112_021F3ED0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_0204ED24 0x0204ED24 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 */
#include "../include/Obj13824.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020403F4(u32);
extern void func_0204ED24(void *);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
void func_021F3ED0(u8 *p) { func_020403F4(3); func_020403F4(1); func_020403F4(2); func_0204ED24(((struct Obj13824 *)p)->f1C); func_02048AC4(((struct Obj13824 *)p)->f18); func_02046788(); func_020403F4(0); }
