/*
 * function: func_021D99F4
 * address:  0x021D99F4
 * packet:   pkt_021D99F4
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
 * Release path for the ov175 object's 0x30 block pointer: free it
 *     through 0x021E89D0 and clear the field.  Null-safe, so a second call is a
 *     no-op.
 */
#include "../include/Obj00013.h"

typedef unsigned long u32;

extern void func_021E89D0(u32 p);

void func_021D99F4(char *obj)
{
    u32 p = ((struct Obj00013 *)obj)->f30;

    if (p != 0) {
        func_021E89D0(p);
        ((struct Obj00013 *)obj)->f30 = 0;
    }
}

