/*
 * function: func_021D4E34
 * address: 0x021D4E34
 * packet: pkt_ov123_021D4E34
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj04495.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void func_0202F038(u8 *);
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021D4E34(u8 *p) { if(*(u8 * *)&((struct Obj04495 *)p)->f288) { func_0202F038(*(u8 * *)&((struct Obj04495 *)p)->f288); *(u32 *)&((struct Obj04495 *)p)->f288=0; } func_0201F7A8(((struct Obj04495 *)p)->f224,2); func_020456F8(*(struct Descriptor * *)&((struct Obj04495 *)p)->f224); func_02041B6C(5); }
