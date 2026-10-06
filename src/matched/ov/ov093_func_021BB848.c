/*
 * function: func_021BB848
 * address: 0x021BB848
 * packet: pkt_ov093_021BB848
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9B94 0x021B9B94 thumb ov093
 */
#include "../include/Obj09956.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Q1;
extern u8 func_021B9B94(struct Q1 *p);
void func_021BB848(u8 *p, void *q, u8 v) { ((struct Obj09956 *)p)->f4 = q; p[8] = func_021B9B94(q); p[9] = v; }
