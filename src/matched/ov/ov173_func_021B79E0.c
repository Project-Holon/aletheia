/*
 * function: func_021B79E0
 * address: 0x021B79E0
 * packet: pkt_ov173_021B79E0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201BD28 0x0201BD28 thumb
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj24185.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
/* The original forwards the full entry r1 without halfword truncation. */
extern u32 func_0201BD28(u16 id, u32 field);
extern void func_0204B878(struct Obj *,u16);
void func_021B79E0(u8 *p, u16 id) {func_0204B878(*(struct Obj * *)&((struct Obj24185 *)p)->f110,func_0201BD28(id,2));}
