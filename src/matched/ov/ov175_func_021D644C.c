/*
 * function: func_021D644C
 * address:  0x021D644C
 * packet:   pkt_021D644C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E7710   0x021E7710  thumb
 *   func_021E8AA0   0x021E8AA0  thumb
 *   func_021E8A80   0x021E8A80  thumb
 *   func_021E8A90   0x021E8A90  thumb
 *   func_021E64C8   0x021E64C8  thumb
 *   func_021E8AA8   0x021E8AA8  thumb
 *
 * Release path for the ov175 object's 0x1c pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
#include "../include/Obj14327.h"

typedef unsigned long u32;

extern void func_021E7710(u32 p);

void func_021D644C(char *obj)
{
    u32 p = ((struct Obj14327 *)obj)->f1C;

    if (p != 0) {
        func_021E7710(p);
        ((struct Obj14327 *)obj)->f1C = 0;
    }
}

