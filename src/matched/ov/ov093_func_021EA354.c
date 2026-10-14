/*
 * function: BTLV_CORE_SetMonShown
 * address:  0x021EA354
 * packet:   pkt_ov093_021EA354
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 * note:     2026-10-03: byte-correct. The three callees are unlabelled Thumb tail-call stubs in
 *           ov094 (ov093 window does not hold them; the ov094 hint is right). Witnesses filed
 *           EXACT: src/matched/ov/ov094_func_021F853C.c, ov094_func_021F7E74.c,
 *           ov094_func_021F7E84.c. Once the integrator creates their shards, the `matched`
 *           class resolves the three sites through the ov094 hint; re-verify and file EXACT.
 *
 * symbols:
 *   BTLV_EFFECT_IsPokeSpriteLoaded  0x021F7F1C  thumb  ov094
 *   BTLV_EFFECT_GetPokeSpriteState  0x021F853C  thumb  ov094
 *   BTLV_EFFECT_StartPokeEffectId285  0x021F7E74  thumb  ov094
 *   BTLV_EFFECT_StartPokeEffectId286  0x021F7E84  thumb  ov094
 */
extern int BTLV_EFFECT_IsPokeSpriteLoaded(int i);
extern int BTLV_EFFECT_GetPokeSpriteState(int i);
typedef unsigned int   u32;
extern void BTLV_EFFECT_StartPokeEffectId285(u32 a);
extern void BTLV_EFFECT_StartPokeEffectId286(u32 a);

void BTLV_CORE_SetMonShown(void *ctx, int a, int b)
{
    if (BTLV_EFFECT_IsPokeSpriteLoaded(a) != 0) {
        if (b != BTLV_EFFECT_GetPokeSpriteState(a)) {
            if (b == 1) {
                BTLV_EFFECT_StartPokeEffectId285(a);
            } else {
                BTLV_EFFECT_StartPokeEffectId286(a);
            }
        }
    }
}
