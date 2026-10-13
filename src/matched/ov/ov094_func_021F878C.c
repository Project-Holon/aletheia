/*
 * function: func_021F878C
 * address:  0x021F878C
 * packet:   pkt_ov094_021F878C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   BTLV_GAUGE_IsLowHpBgmPlaying  0x022088F4  thumb  ov094
 *   BTLV_GAUGE_SetLowHpBgmPlaying  0x02208900  thumb  ov094
 *   BTLV_GAUGE_SetLowHpBgmSuppressed  0x0220893C  thumb  ov094
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern char *d_0220AF20;
extern int BTLV_GAUGE_IsLowHpBgmPlaying(u32 obj);
extern void BTLV_GAUGE_SetLowHpBgmPlaying(u32 obj, u32 v);
extern void BTLV_GAUGE_SetLowHpBgmSuppressed(u32 obj, u32 v);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u16 b);

void func_021F878C(u32 a)
{
    if (BTLV_GAUGE_IsLowHpBgmPlaying(*(u32 *)(d_0220AF20 + 0x1A4))) {
        BTLV_GAUGE_SetLowHpBgmPlaying(*(u32 *)(d_0220AF20 + 0x1A4), 0);
        GFL_USE_PopBgm();
    }
    BTLV_GAUGE_SetLowHpBgmSuppressed(*(u32 *)(d_0220AF20 + 0x1A4), 1);
    GFL_USE_CancelChangeAndPlayBgm(a, 0xFFFF);
}
