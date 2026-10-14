/*
 * function: POKETRADE_2D_DeleteAllOfferIconActors
 * address:  0x021E64B8
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Run the three sub-updates for both halves.
 *
 * symbols:
 *   POKETRADE_2D_DeleteOfferIconActor  0x021E62D4  thumb
 */

extern void POKETRADE_2D_DeleteOfferIconActor(void *p, int i, int j);

void POKETRADE_2D_DeleteAllOfferIconActors(void *p)
{
    int j, i;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            POKETRADE_2D_DeleteOfferIconActor(p, i, j);
}

