/*
 * function: func_021BB580
 * address: 0x021BB580
 * packet: pkt_ov070_021BB580
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj13160.h"
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
void func_021BB580(char *p, int v) { if (v == 1) func_0204B878(((struct Obj13160 *)p)->f720, 1); else func_0204B878(((struct Obj13160 *)p)->f720, 15); }
