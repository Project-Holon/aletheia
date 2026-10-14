/*
 * function: BTLV_EFFECT_StopLowHpBgmAndSuppress
 * address:  0x021F883C
 * packet:   pkt_ov094_021F883C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_GAUGE_IsLowHpBgmPlaying  0x022088F4  thumb  ov094
 *   BTLV_GAUGE_SetLowHpBgmSuppressed  0x0220893C  thumb  ov094
 *   BTLV_GAUGE_SetLowHpBgmPlaying  0x02208900  thumb  ov094
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x1A4];
    void *obj;          /* 0x1A4 */
} Work;

extern Work *gBtlvEff;

extern u32 BTLV_GAUGE_IsLowHpBgmPlaying(void *o);
extern void BTLV_GAUGE_SetLowHpBgmSuppressed(void *o, u32 v);
extern void BTLV_GAUGE_SetLowHpBgmPlaying(void *o, u32 v);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u32 b);

void BTLV_EFFECT_StopLowHpBgmAndSuppress(u32 a)
{
    if (BTLV_GAUGE_IsLowHpBgmPlaying(gBtlvEff->obj) == 1)
        GFL_USE_PopBgm();
    BTLV_GAUGE_SetLowHpBgmSuppressed(gBtlvEff->obj, 1);
    BTLV_GAUGE_SetLowHpBgmPlaying(gBtlvEff->obj, 0);
    GFL_USE_CancelChangeAndPlayBgm(a, 0x0000FFFF);
}
