/*
 * function: BTL_CLIENT_BuildSlotChoices
 * address: 0x021D0B10
 * packet: pkt_ov093_021D0B10
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D0B3C 0x021D0B3C thumb ov093
 *   func_021D0B4C 0x021D0B4C thumb ov093
 *   func_021D0B5C 0x021D0B5C thumb ov093
 */
#include "../include/Obj13364.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D0B3C(void *, u32, u32, u32);
extern void func_021D0B4C(void *, u32);
extern void func_021D0B5C(void *, void *);
void BTL_CLIENT_BuildSlotChoices(u8 *p, u32 a, u32 b, void *q, void *out)
{
    func_021D0B3C(q, ((struct Obj13364 *)p)->f118, b, a);
    func_021D0B4C(q, p[0x11c]);
    func_021D0B5C(out, q);
}
