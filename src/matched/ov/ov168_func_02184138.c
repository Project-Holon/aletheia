/*
 * function: func_02184138
 * address: 0x02184138
 * packet: pkt_ov168_02184138
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../include/Obj23820.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;
extern void func_0204B1CC(struct Bank *);
void func_02184138(char *p) { func_0204B1CC(*(struct Bank * *)&((struct Obj23820 *)p)->f1C); }
