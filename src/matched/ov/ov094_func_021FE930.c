/*
 * function: BTLV_EFFVM_MultiPokeTaskMain
 * address:  0x021FE930
 * packet:   pkt_ov094_021FE930
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the `mask |= 1 << i` tail is written out in both arms (then-arm
 * innermost, and the else arm); the compiler cross-jumps them and leaves the
 * `b` to the next instruction.  A single shared tail (goto/continue) gives no
 * `b` and hoists r7/r4 in the other order.
 *
 * symbols:
 *   BTLV_EFFECT_IsPokeSpriteLoaded  0x021F7F1C  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_IsSpriteBusy  0x021FFCB0  thumb  ov094
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
 *   BTLV_MCSS_SetAnimStopMode  0x021FF304  thumb  ov094
 *   BTLV_MCSS_SetShadowVanish  0x021FF470  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 */
typedef struct {
    int pad0;
    int side;
    int mask;
} Arg;

extern int BTLV_EFFECT_IsPokeSpriteLoaded(int i);
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_MCSS_IsSpriteBusy(char *p, int key);
extern int BTLV_EFFECT_GetBitMask(int x);
extern void BTLV_MCSS_SetAnimStopMode(char *p, int key, int mode);
extern void BTLV_MCSS_SetShadowVanish(char *p, int key, void *v);
extern void BTLV_EFFECT_DeleteTask(void *h);

void BTLV_EFFVM_MultiPokeTaskMain(void *h, Arg *a)
{
    int i = 1;
    int want;

    if (a->side == 0)
        i = 0;
    if (a->side != 0)
        want = 0xaa;
    else
        want = 0x55;
    while (i <= 7) {
        if (BTLV_EFFECT_IsPokeSpriteLoaded(i)) {
            if (BTLV_MCSS_IsSpriteBusy((char *)BTLV_EFFECT_GetMcss(), i) == 0) {
                if ((BTLV_EFFECT_GetBitMask(i) & a->mask) == 0) {
                    BTLV_MCSS_SetAnimStopMode((char *)BTLV_EFFECT_GetMcss(), i, 0);
                    BTLV_MCSS_SetShadowVanish((char *)BTLV_EFFECT_GetMcss(), i, 0);
                    a->mask |= BTLV_EFFECT_GetBitMask(i);
                }
            }
        } else {
            a->mask |= BTLV_EFFECT_GetBitMask(i);
        }
        i += 2;
    }
    if (want == a->mask)
        BTLV_EFFECT_DeleteTask(h);
}
