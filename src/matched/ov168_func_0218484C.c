/*
 * function: func_0218484C
 * address:  0x0218484C
 * packet:   pkt_ov168_0218484C
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218483C  0x0218483C  thumb  ov168
 *   func_020362DC  0x020362DC  arm
 *
 * Addresses are Black-image addresses.
 */

extern int func_0218483C(void);
extern int func_020362DC(void);

int func_0218484C(void)
{
    return func_0218483C() == 0 || (func_020362DC() & 2) != 0;
}

