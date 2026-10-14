/*
 * function: BTLV_EFFECT_SetStageFieldTint
 * address:  0x021F8298
 * packet:   pkt_ov094_021F8298
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094  a4
 *   BTLV_STAGE_InitLayerEntry  0x021F69E8  thumb  ov094
 *   BTLV_FIELD_InitEntry  0x021F6DEC  thumb  ov094
 *   PALANM_RequestFade  0x0202173C  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern char *gBtlvEff;
extern void BTLV_STAGE_InitLayerEntry(u32 obj, u8 b, u8 c, int d, u16 e);
extern void BTLV_FIELD_InitEntry(u32 obj, u8 b, u8 c, int d, u16 e);
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

void BTLV_EFFECT_SetStageFieldTint(u32 a, u8 b, u8 c, u8 d, u16 e)
{
    if (a == 0 || a == 2 || a == 4)
        BTLV_STAGE_InitLayerEntry(*(u32 *)(gBtlvEff + 0x194), b, c, d, e);
    if (a == 1 || a == 2 || a == 4)
        BTLV_FIELD_InitEntry(*(u32 *)(gBtlvEff + 0x198), b, c, d, e);
    if (a - 3 <= 1)
        PALANM_RequestFade(*(void **)(gBtlvEff + 0x18C), 1, 0xFF00, (s8)d, b, c, e, *(void **)gBtlvEff);
}
