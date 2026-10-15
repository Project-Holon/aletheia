/*
 * function: STA_ACTING_DeleteAnimHandle
 * address:  0x021F9D08
 * packet:   pkt_021F9D08
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9F58  0x021F9F58  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14087.h"

typedef unsigned char  u8;
extern void func_021F9F58(u8 *unused, u8 *p);

void STA_ACTING_DeleteAnimHandle(char *p)
{
    func_021F9F58(((struct Obj14087 *)p)->f6C, ((struct Obj14087 *)p)->fBC);
}
