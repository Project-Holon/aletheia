/*
 * function: ZONEDATA_SetEventFlag
 * address:  0x02014314
 * packet:   pkt_02014314
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_GetEventFlagAddress  0x02014388  thumb
 */

extern unsigned char *ZONEDATA_GetEventFlagAddress(char *a0, unsigned int a1);

void ZONEDATA_SetEventFlag(char *a0, int a1)
{
    unsigned char *p = ZONEDATA_GetEventFlagAddress(a0, a1);

    if (p != 0)
        *p |= 1 << (a1 % 8);
}
