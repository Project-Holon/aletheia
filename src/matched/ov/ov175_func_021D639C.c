/*
 * function: func_021D639C
 * address:  0x021D639C
 * packet:   pkt_021D639C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E5D40   0x021E5D40  thumb
 *   func_021E89D0   0x021E89D0  thumb
 *   func_021E8A00   0x021E8A00  thumb
 *   func_021E5EF8   0x021E5EF8  thumb
 *   func_021E5F24   0x021E5F24  thumb
 *
 * Release path for the ov175 object's 0x18 block pointer: free it
 *     through 0x021E5D40 and clear the field.  Null-safe, so a second call is a
 *     no-op.
 */
#include "../include/Obj10680.h"

typedef unsigned long u32;

extern void func_021E5D40(u32 p);

void func_021D639C(char *obj)
{
    u32 p = ((struct Obj10680 *)obj)->f18;

    if (p != 0) {
        func_021E5D40(p);
        ((struct Obj10680 *)obj)->f18 = 0;
    }
}

