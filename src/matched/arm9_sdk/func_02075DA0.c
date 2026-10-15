/*
 * function: CARD_IsEnabled
 * address:  0x02075DA0
 * packet:   pkt_02075DA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sCardEnabled  0x0215019C  data
 */

extern void *sCardEnabled;

void *CARD_IsEnabled(void)
{
    return sCardEnabled;
}
