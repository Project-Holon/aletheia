/*
 * function: BTLV_EFFECT_ResetPokeSprite
 * address:  0x021F7E38
 * packet:   pkt_ov094_021F7E38
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_MCSS_RefreshSpriteFromParty  0x021FFE48  thumb  ov094
 *   BTLV_MCSS_MakeAddWorkFromPoke  0x022003EC  thumb  ov094
 *   BTLV_MCSS_ReloadSpriteResource  0x022001DC  thumb  ov094
 */
typedef struct {
    char pad[0x190];
    void *h190;
} Work;

extern Work *gBtlvEff;

extern void BTLV_MCSS_RefreshSpriteFromParty(void *h, int b, void *a);
extern void BTLV_MCSS_MakeAddWorkFromPoke(void *h, void *a, int *buf, int b);
extern void BTLV_MCSS_ReloadSpriteResource(void *h, int b, int *buf);

void BTLV_EFFECT_ResetPokeSprite(void *a, int b)
{
    int buf[9];

    BTLV_MCSS_RefreshSpriteFromParty(gBtlvEff->h190, b, a);
    BTLV_MCSS_MakeAddWorkFromPoke(gBtlvEff->h190, a, buf, b);
    BTLV_MCSS_ReloadSpriteResource(gBtlvEff->h190, b, buf);
}
