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
 *   KEY_GetTrg  0x020362DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int func_0218483C(void);
extern u32 KEY_GetTrg(void);

int func_0218484C(void)
{
    return func_0218483C() == 0 || (KEY_GetTrg() & 2) != 0;
}

