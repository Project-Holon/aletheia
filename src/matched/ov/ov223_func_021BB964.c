/*
 * function: func_021BB964
 * address:  0x021BB964
 * packet:   pkt_ov223_021BB964
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as func_021BB964 in ov093; the ov223 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_021BB630  0x021BB630  thumb  ov223
 *   func_021BB844  0x021BB844  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BB630(void *);
extern void func_021BB844(char *p);

void func_021BB964(char *p)
{
    func_021BB630(p);
    func_021BB844(p);
}
