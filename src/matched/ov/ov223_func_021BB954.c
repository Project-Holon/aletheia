/*
 * function: func_021BB954
 * address:  0x021BB954
 * packet:   pkt_ov223_021BB954
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as func_021BB954 in ov021; the ov223 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_021BB62C  0x021BB62C  thumb  ov223
 *   func_021BB840  0x021BB840  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BB62C(void *);
extern void func_021BB840(void *);

void func_021BB954(char *p)
{
    func_021BB62C(p);
    func_021BB840(p);
}
