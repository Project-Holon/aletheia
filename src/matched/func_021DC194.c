/*
 * function: func_021DC194
 * address:  0x021DC194
 * packet:   pkt_021DC194
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Two-level dereference: the pointer the object holds at +0x1464, then
 *     the word it points at.  Both loads are register-offset, so the listing
 *     pools one plain literal 0x1464.
 */

typedef unsigned long u32;

u32 func_021DC194(char *obj)
{
    return *(u32 *)(*(u32 *)(obj + 0x1464));
}

