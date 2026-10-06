/*
 * function: func_0218516C
 * address: 0x0218516C
 * packet: pkt_ov219_0218516C
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   sub_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 */
#include "../include/Obj08451.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct Obj;
extern void func_0201F7A8(void*,u32);
extern u32 sub_020452E8(struct Descriptor *d);
extern void func_0202020C(struct Obj*,u16*,u16*);
extern u32 func_0201F868(void *p);
void func_0218516C(u8*p){func_0201F7A8(*(void* *)&((struct Obj08451 *)p)->fC018,0);sub_020452E8(*(struct Descriptor* *)&((struct Obj08451 *)p)->fC018);func_0202020C(*(struct Obj* *)&((struct Obj08451 *)p)->fC04C,0,0);func_0201F868(*(void* *)&((struct Obj08451 *)p)->fC050);}
