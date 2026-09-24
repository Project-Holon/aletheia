/*
 * function: func_021D9A1C
 * address:  0x021D9A1C
 * packet:   pkt_021D9A1C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8AA0  0x021E8AA0  thumb  ov177
 *
 * Closes the +0x3c stream handle through 0x021E8AA0 and parks the +0x40
 *     result word at the 0xFFFF sentinel.  Mirrors func_021D6788.
 */

typedef unsigned long u32;

extern void func_021E8AA0(u32 h);

void func_021D9A1C(char *obj)
{
    func_021E8AA0(*(u32 *)(obj + 0x3c));
    *(u32 *)(obj + 0x40) = 0xFFFF;
}

