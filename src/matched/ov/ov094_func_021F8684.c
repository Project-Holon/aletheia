/*
 * function: BTLV_EFFECT_GetCamera
 * address:  0x021F8684
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 */
extern char *gBtlvEff;

int BTLV_EFFECT_GetCamera(void)
{
    return *(int *)(gBtlvEff + 0x19c);
}
