/*
 * function: func_021BCE30
 * address: 0x021BCE30
 * packet: pkt_ov110_021BCE30
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCE46.
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 */
#include "../include/Obj06390.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
extern u32 func_0204B98C(struct Actor *a);
int func_021BCE30(char *p) { if (func_0204B98C(((struct Obj06390 *)p)->f8C)==0) return 1; return 0; }
