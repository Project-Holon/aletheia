/*
 * function: func_021C6390
 * address:  0x021C6390
 * packet:   pkt_021C6390
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_021C6664  0x021C6664  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08125.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021C6664(u8 *p);

void func_021C6390(u8 *p)
{
    func_02030EAC(((struct Obj08125 *)p)->f5A8);
    *(u32 *)&((struct Obj08125 *)p)->f5A8 = 0;
    func_021C6664(p + 4);
}
