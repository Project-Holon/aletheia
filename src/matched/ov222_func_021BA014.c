/*
 * function: func_021BA014
 * address:  0x021BA014
 * packet:   pkt_ov222_021BA014
 * region:   ov222
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched in ov114 and ov172; the ov222 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_021BA148  0x021BA148  thumb  ov222
 *   func_021BA0E0  0x021BA0E0  thumb  ov222
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BA148(void *);
extern void func_021BA0E0(void *);

void func_021BA014(char *p)
{
    func_021BA148(p + 4);
    func_021BA0E0(p);
}
