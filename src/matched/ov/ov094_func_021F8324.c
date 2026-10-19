/*
 * function: BTLV_EFFECT_IsStageFieldBusy
 * address:  0x021F8324
 * packet:   pkt_ov094_021F8324
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094  a4
 *   BTLV_STAGE_IsTintActive  0x021F6A18  thumb  ov094
 *   BTLV_FIELD_IsTintActive  0x021F6E1C  thumb  ov094
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 */
typedef unsigned int u32;

extern char *gBtlvEff;
extern int BTLV_STAGE_IsTintActive(char *p);
extern int BTLV_FIELD_IsTintActive(char *p);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);

int BTLV_EFFECT_IsStageFieldBusy(u32 a)
{
    int x = 0;
    int y = 0;
    int z = 0;

    if (a == 0 || a == 2 || a == 4)
        x = BTLV_STAGE_IsTintActive((char *)(*(u32 *)(gBtlvEff + 0x194)));
    if (a == 1 || a == 2 || a == 4)
        y = BTLV_FIELD_IsTintActive((char *)(*(u32 *)(gBtlvEff + 0x198)));
    if (a - 3 <= 1) {
        z = PALANM_GetFadeRequestBits((const char *)(*(int *)(gBtlvEff + 0x18C))) != 0;
    }
    if (x == 1 || y == 1 || z == 1)
        return 1;
    return 0;
}
