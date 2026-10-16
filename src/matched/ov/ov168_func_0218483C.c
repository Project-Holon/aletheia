/*
 * function: MICTEST_TouchHit
 * address:  0x0218483C
 * packet:   pkt_0218483C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 */

extern int TOUCHPANEL_HitTrg(const void *p);

int MICTEST_TouchHit(void)
{
    return TOUCHPANEL_HitTrg((void *)0x0218486E);
}
