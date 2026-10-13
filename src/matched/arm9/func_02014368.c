/*
 * function: ZONEDATA_ResetEventFlagRange
 * address:  0x02014368
 * packet:   pkt_02014314
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 */

typedef unsigned short u16;

extern void ZONEDATA_ResetEventFlag(char *a0, int a1);

void ZONEDATA_ResetEventFlagRange(char *a0, int a1, int a2)
{
    int i;

    for (i = a1; i <= a2; i++)
        ZONEDATA_ResetEventFlag(a0, (u16)i);
}
