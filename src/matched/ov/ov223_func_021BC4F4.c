/*
 * function: func_021BC4F4
 * address:  0x021BC4F4
 * packet:   pkt_ov223_021BC4F4
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched as func_021BC4F4 in ov208; the ov223 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_021BC64C  0x021BC64C  thumb  ov223
 *   func_021BC5E4  0x021BC5E4  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BC64C(void *);
extern void func_021BC5E4(void *);

void func_021BC4F4(char *p)
{
    func_021BC64C(p + 4);
    func_021BC5E4(p);
}
