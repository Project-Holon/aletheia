/*
 * function: BTLV_EFFECT_GetPokeSpriteCameraTarget
 * address:  0x021F8628
 * packet:   pkt_ov094_021F8628
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094  a4
 *   BTLV_MCSS_GetSlotPosition  0x021FF3F4  thumb  ov094
 */
typedef unsigned int u32;

extern char *gBtlvEff;
extern void BTLV_MCSS_GetSlotPosition(void *obj, void *out, int idx);

void BTLV_EFFECT_GetPokeSpriteCameraTarget(u32 a, int *out, int *p)
{
    BTLV_MCSS_GetSlotPosition((void *)(*(u32 *)(gBtlvEff + 0x190)), p, a);
    out[0] = p[0] + 0x4B33;
    out[1] = p[1] + 0x2299;
    out[2] = p[2] + 0x99CD;
    p[1] = p[1] + 0x2000;
}
