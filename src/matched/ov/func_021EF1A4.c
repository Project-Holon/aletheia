/*
 * function: BOX2_UI_GetBodySlotHit
 * address:  0x021EF1A4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_HitTableTrg  0x021EF048  thumb  ov170
 *
 * Register a table with the loader.
 */

extern int BOX2_UI_HitTableTrg(const char *p, unsigned n);

typedef unsigned int   u32;
u32 BOX2_UI_GetBodySlotHit(void)
{
    return BOX2_UI_HitTableTrg((void *)0x021F1354, 6);
}

