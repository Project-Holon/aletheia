/*
 * function: BTLV_CORE_AbortInput
 * address:  0x021E9928
 * packet:   pkt_ov093_021E9928
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_StartIntroEffect  0x021F8A78  thumb  ov094
 *   func_021E9944  0x021E9944  thumb  ov093
 *   BTLV_CORE_ClearStep  0x021E9730  thumb  ov093
 */
#include "../include/Obj21556.h"
extern void BTLV_EFFECT_StartIntroEffect(void);
extern void func_021E9944(void *p);
struct QU;
extern void BTLV_CORE_ClearStep(struct QU *p);

void BTLV_CORE_AbortInput(char *p)
{
    BTLV_EFFECT_StartIntroEffect();
    func_021E9944(((struct Obj21556 *)p)->f180);
    BTLV_CORE_ClearStep((struct QU *)p);
}
