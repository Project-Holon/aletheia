/*
 * function: func_021C4280
 * address: 0x021C4280
 * packet: pkt_ov127_021C4280
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B918 0x0204B918 arm
 */
#include "../include/Obj23021.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern u16 func_0204B918(struct Obj *p);
int func_021C4280(char *p) { return func_0204B918(((struct Obj23021 *)p)->f4); }
