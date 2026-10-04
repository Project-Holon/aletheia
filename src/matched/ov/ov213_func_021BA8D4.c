/*
 * function: func_021BA8D4
 * address: 0x021BA8D4
 * packet: pkt_ov213_021BA8D4
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   func_02050DB8 0x02050DB8 arm
 *   func_02050ED4 0x02050ED4 arm
 */
#include "../include/Obj10931.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_02050DB8(u8 *);
extern void func_02050ED4(void);
void func_021BA8D4(char *p) { if(*(u8 * *)&((struct Obj10931 *)p)->f10) func_02050DB8(*(u8 * *)&((struct Obj10931 *)p)->f10); func_02050ED4(); }
