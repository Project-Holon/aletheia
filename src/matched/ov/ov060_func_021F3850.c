/*
 * function: FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels
 * address:  0x021F3850
 * packet:   pkt_021F3850
 * region:   ov060
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DEMO3D_ENGINE_Delete  0x021BE4B4  thumb  ov203
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void DEMO3D_ENGINE_Delete(char *ctx, int b, int c, u32 d);

void FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels(char *p)
{
    int i;

    for (i = 0; i < 0x14; i++) {
        DEMO3D_ENGINE_Delete(p, 0, (u16)i, 1);
    }
}
