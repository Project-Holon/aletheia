/*
 * function: func_021D5A60
 * address:  0x021D5A60
 * packet:   pkt_021D5A60
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13973.h"

typedef unsigned int u32;

struct Descriptor;
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 bit);

void func_021D5A60(char *p)
{
    func_0201F7A8(((struct Obj13973 *)p)->f48, 2);
    BMP_WIN_ClearScreen(((struct Obj13973 *)p)->f48);
    func_02041B6C(6);
}
