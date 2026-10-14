/*
 * function: BTL_CLIENT_StepPlayEffectById
 * address: 0x021D34B0
 * packet: pkt_ov093_021D34B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 54 bytes followed by two zero alignment bytes.
 * symbols:
 *   BTL_CLIENT_IsMainStepActive 0x021CD9E0 thumb ov093
 *   BTLV_EFFECT_StartEffect 0x021F7998 thumb ov094
 *   BTLV_EFFECT_IsBusy 0x021F7EB4 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_EFFECT_StartEffect(unsigned int);
extern int BTLV_EFFECT_IsBusy(void);
int BTL_CLIENT_StepPlayEffectById(char *p, int *state, unsigned int *q)
{
    if (*state == 0) {
        if (BTL_CLIENT_IsMainStepActive((u8 *)p) != 0) return 1;
        BTLV_EFFECT_StartEffect(q[0]);
        (*state)++;
    } else {
        if (BTLV_EFFECT_IsBusy() == 0) return 1;
    }
    return 0;
}
