/*
 * function: func_021D97B0
 * address:  0x021D97B0
 * packet:   pkt_021D97B0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13999.h"

typedef unsigned int u32;

struct Descriptor;
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32 bit);

void func_021D97B0(char *p)
{
    func_0201F7A8(((struct Obj13999 *)p)->f4C, 2);
    func_020456F8(((struct Obj13999 *)p)->f4C);
    func_02041B6C(6);
}
