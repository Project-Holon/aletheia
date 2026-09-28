/*
 * function: func_021D9A08
 * address:  0x021D9A08
 * packet:   pkt_021D9A08
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
 * Field query: if the +0x30 pointer is live, hand it to the ov175-adjacent
 *     routine at 0x021E8A00 and return its result, else -1.  func_021D99F4 is
 *     the matching free path for the same field.
 */

typedef unsigned long u32;

extern int func_021E8A00(u32 p);

int func_021D9A08(char *obj)
{
    u32 p = *(u32 *)(obj + 0x30);

    if (p != 0)
        return func_021E8A00(p);
    return -1;
}

