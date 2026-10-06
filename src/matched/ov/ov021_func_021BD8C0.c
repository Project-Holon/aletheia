/*
 * function: func_021BD8C0
 * address:  0x021BD8C0
 * packet:   pkt_ov021_021BD8C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD904  0x021BD904  thumb  ov021
 *   func_021BD93C  0x021BD93C  thumb  ov021
 *   func_02029E08  0x02029E08  thumb
 *   func_02029DFC  0x02029DFC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12889.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021BD904(u32 *);
extern int func_021BD93C(u32 *);
extern int func_02029E08(int a0, int a1);
extern void *func_02029DFC(const void *p);

u32 func_021BD8C0(u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 q = ((struct Obj12889 *)p)->f8;

    if (!func_021BD904(ctx))
        return 0;
    if (func_02029E08(q, ((struct Obj12889 *)p)->f20))
        return 0;
    if (func_021BD93C(ctx) == 1 && (u32)func_02029DFC((const void *)q) == 0x3F4)
        return 0;
    return 1;
}
