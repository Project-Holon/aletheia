/*
 * function: WEATHER_Draw
 * address:  0x021A1B38
 * packet:   pkt_ov021_021A1B38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_3DBG_DrawBillboard  0x021A15F4  thumb  ov021
 */

typedef unsigned int u32;

void FIELD_3DBG_DrawBillboard(u32 x);

void WEATHER_Draw(u32 *p)
{
    int i;

    if (p != 0) {
        for (i = 0; i < 2; i++)
            FIELD_3DBG_DrawBillboard(p[i]);
    }
}
