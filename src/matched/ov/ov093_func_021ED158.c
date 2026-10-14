/*
 * function: BTLV_SCU_ProcWazaEffect
 * address:  0x021ED158
 * packet:   pkt_ov093_021ED158
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_SCU_StartMsgWinFadeOut  0x021ED798  thumb  ov093
 *   BTLV_SCU_UpdateMsgWinFade  0x021ED814  thumb  ov093
 *   BTLV_EFFECT_StartEffectWithRequest  0x021F7B2C  thumb  ov094
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   GFL_USE_StopAllSe  0x02006210  thumb
 */

typedef unsigned char u8;

struct S;
extern void BTLV_SCU_StartMsgWinFadeOut(struct S *s);
extern int BTLV_SCU_UpdateMsgWinFade(struct S *s);
extern void BTLV_EFFECT_StartEffectWithRequest(u8 *);
extern int BTLV_EFFECT_IsBusy(void);
extern void GFL_USE_StopAllSe(void);

int BTLV_SCU_ProcWazaEffect(int *st, u8 *b)
{
    switch (*st) {
    case 0:
        BTLV_SCU_StartMsgWinFadeOut((struct S *)(b + 0x154));
    inc:
        *st = *st + 1;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(b + 0x154)) != 0) {
            BTLV_EFFECT_StartEffectWithRequest(b + 0xf0);
            goto inc;
        }
        break;
    case 2:
        if (BTLV_EFFECT_IsBusy() == 0) {
            GFL_USE_StopAllSe();
            goto inc;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
