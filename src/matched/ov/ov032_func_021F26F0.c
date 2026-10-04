/*
 * function: func_021F26F0
 * address: 0x021F26F0
 * packet: pkt_ov032_021F26F0
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: func_021F067C forwards r0 to func_021F0E24, which reads p.
 * symbols:
 *   func_021F05E8 0x021F05E8 thumb ov032
 *   func_021F067C 0x021F067C thumb ov032
 */
#include "../include/Obj00007.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F05E8(u8 *, int, u32);
extern void func_021F067C(u8 *);
int func_021F26F0(u8 *p)
{
    if (((struct Obj00007 *)p)->fA8 != 0)
        return 2;
    func_021F05E8(p, 4, 0);
    func_021F067C(p);
    return 0;
}
