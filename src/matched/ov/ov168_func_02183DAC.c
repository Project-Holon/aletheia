/*
 * function: MICTEST_StepRecord
 * address:  0x02183DAC
 * packet:   pkt_02183DAC
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MICTEST_GetOwner   0x02183D3C  thumb
 *   MICTEST_SetStep   0x02183D34  thumb
 *   MICTEST_StepWaitAnim   0x02183E18  thumb
 *   MICTEST_ArmMic   0x02184470  thumb
 *   MICTEST_DisarmMic   0x0218448C  thumb
 *   MICTEST_CheckTouchOrKey   0x0218484C  thumb
 *   SND_MIC_IsLimitReached   0x02006D94  thumb
 *   GFL_USE_PlaySeDefaultVolume   0x020061E4  thumb
 *
 * Four-state step: x+0xF8 through 0x2184470 on 0, gate two polls on 1,
 *   x+0xF8 through 0x218448C on 2, install 0x2183E18 on 3.
 */


extern unsigned int MICTEST_GetOwner(unsigned int *p);
extern void MICTEST_SetStep(unsigned int *p, unsigned int v);
typedef unsigned int   u32;
extern void MICTEST_StepWaitAnim(int a, int *state);
extern void MICTEST_ArmMic(int *p);
extern void MICTEST_DisarmMic(int *p);
extern int MICTEST_CheckTouchOrKey(void);
extern u32 SND_MIC_IsLimitReached(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void MICTEST_StepRecord(int a, int *state)
{
    int x = MICTEST_GetOwner((unsigned int *)a);
    switch (*state) {
    case 0:
        MICTEST_ArmMic((int *)(x + 0xF8));
        *state = 1;
        break;
    case 1:
        if (MICTEST_CheckTouchOrKey() && SND_MIC_IsLimitReached()) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            *state = 2;
        }
        break;
    case 2:
        MICTEST_DisarmMic((int *)(x + 0xF8));
        *state = 3;
        break;
    case 3:
        MICTEST_SetStep((unsigned int *)a, (unsigned int)MICTEST_StepWaitAnim);
        break;
    }
}
