/*
 * function: MICTEST_CheckTouchOrKey
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
 *   MICTEST_TouchHit  0x0218483C  thumb  ov168
 *   KEY_GetTrg  0x020362DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int MICTEST_TouchHit(void);
extern u32 KEY_GetTrg(void);

int MICTEST_CheckTouchOrKey(void)
{
    return MICTEST_TouchHit() == 0 || (KEY_GetTrg() & 2) != 0;
}

