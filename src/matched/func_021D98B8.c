/*
 * function: func_021D98B8
 * address:  0x021D98B8
 * packet:   pkt_021D98B8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E82BC  0x021E82BC  thumb  ov177
 *
 * Free-and-null on the +0x24 block: hands it to 0x021E82BC (ov177) and
 *  *  clears the field, so a second call is harmless.
 */

typedef unsigned long u32;

extern void func_021E82BC(u32 p);

void func_021D98B8(char *obj)
{
    u32 p = *(u32 *)(obj + 0x24);
    if (p != 0) {
        func_021E82BC(p);
        *(u32 *)(obj + 0x24) = 0;
    }
}

