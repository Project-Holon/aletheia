/*
 * function: func_021F9D08
 * address:  0x021F9D08
 * packet:   pkt_021F9D08
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9F58  0x021F9F58  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void func_021F9F58(u8 *unused, u8 *p);

void func_021F9D08(char *p)
{
    func_021F9F58(*(void **)(p + 0x6c), *(void **)(p + 0xbc));
}
