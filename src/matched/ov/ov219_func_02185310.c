/*
 * function: func_02185310
 * address:  0x02185310
 * packet:   pkt_02185310
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14780.h"

typedef unsigned int   u32;
struct Descriptor;
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void func_02185310(char *p)
{
    char *q = p + 0xc040;
    func_0201F7A8((void *)(((struct Obj14780 *)q)->f0), 0);
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj14780 *)q)->f0));
}
