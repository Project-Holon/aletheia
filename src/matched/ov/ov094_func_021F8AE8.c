/*
 * unit:     yes
 * function: BTLV_EFFECT_SetPokeEffectValue, BTLV_EFFECT_GetPokeEffectValue, BTLV_EFFECT_SuspendVmWait, BTLV_EFFECT_ResumeVmWait
 * address:  0x021F8AE8
 * packet:   pkt_ov094_021F8AE8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_EFFVM_StopLiveSounds  0x021F9A7C  thumb  ov094
 *   BTLV_EFFVM_ClearLastEffect  0x021F9AA4  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x188];
    void *h;            /* 0x188 */
    char pad2[0x8C];
    u32 tbl[1];         /* 0x218 */
} Work;

extern Work *gBtlvEff;

extern int BTLV_EFFVM_StopLiveSounds(void *h);
extern int BTLV_EFFVM_ClearLastEffect(void *h);

void BTLV_EFFECT_SetPokeEffectValue(int i, u32 v)
{
    gBtlvEff->tbl[i] = v;
}

int BTLV_EFFECT_GetPokeEffectValue(int i)
{
    return gBtlvEff->tbl[i];
}

int BTLV_EFFECT_SuspendVmWait(void)
{
    return BTLV_EFFVM_StopLiveSounds(gBtlvEff->h);
}

int BTLV_EFFECT_ResumeVmWait(void)
{
    return BTLV_EFFVM_ClearLastEffect(gBtlvEff->h);
}
