/*
 * function: func_021BA1CC
 * address:  0x021BA1CC
 * packet:   pkt_ov220_021BA1CC
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Destructor pair: tears down the tail field then the head.  This address is
 * also matched as func_021BA1CC in ov217; the ov220 copy is a distinct
 * function and gets its own shard.
 *
 * symbols:
 *   func_021BA300  0x021BA300  thumb  ov220
 *   func_021BA298  0x021BA298  thumb  ov220
 *
 * Addresses are Black-image addresses.
 */

extern void func_021BA300(void *);
extern void func_021BA298(void *);

void func_021BA1CC(char *p)
{
    func_021BA300(p + 4);
    func_021BA298(p);
}
