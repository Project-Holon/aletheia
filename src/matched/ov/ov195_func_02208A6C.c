/*
 * function: func_02208A6C
 * address: 0x02208A6C
 * packet: pkt_ov195_02208A6C
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047E54 0x02047E54 arm
 */
#include "../include/Obj05518.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Rec;
extern void func_02047E54(struct Rec *);
void func_02208A6C(char *p) { func_02047E54(*(struct Rec * *)&((struct Obj05518 *)p)->f14); }
