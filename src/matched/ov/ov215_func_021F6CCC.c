/*
 * function: EGG_DEMO_VIEW_PlayAnim
 * address: 0x021F6CCC
 * packet: pkt_ov215_021F6CCC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_SetAnimeIndex 0x02016028 thumb
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   NNS_G2dRestartMCAnimation 0x02064CBC arm
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   NNS_G2dSetCellAnimationParam 0x02063000 arm
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   EGG_DEMO_VIEW_OnAnimStop 0x021F6D0C thumb ov215
 */
#include "../include/Obj06707.h"
/* Legacy 020173B4 inputs r1-r3 are replaced by its body; full forwarding
 * 02015F2C supplies fixed member, one, original p and callback to 02063000.
 * It reads no caller r1-r3. 02016028 retains live incoming flag in r1. */
extern void MCSS_SetAnimeIndex(void *,unsigned);
extern void *MCSS_GetAnimCtrl(void *);
struct Obj;
extern void NNS_G2dRestartMCAnimation(struct Obj *x);
extern void MCSS_ResetAnmStopFlag(void *);
extern void NNS_G2dSetCellAnimationParam(int p0, int p1, int p2, int p3);
extern int MCSS_TOOL_SetAnimeStopCallback(int a0);
extern int EGG_DEMO_VIEW_OnAnimStop(char *);
void EGG_DEMO_VIEW_PlayAnim(char *p,unsigned flag,int enable)
{
    void *obj;
    MCSS_SetAnimeIndex(((struct Obj06707 *)p)->f34,flag);
    obj=MCSS_GetAnimCtrl(((struct Obj06707 *)p)->f34);
    NNS_G2dRestartMCAnimation(obj);
    MCSS_ResetAnmStopFlag(((struct Obj06707 *)p)->f34);
    if(enable) {
        NNS_G2dSetCellAnimationParam((int)obj,1,(int)p,(int)EGG_DEMO_VIEW_OnAnimStop);
        ((struct Obj06707 *)p)->f38=0;
    } else MCSS_TOOL_SetAnimeStopCallback((int)(((struct Obj06707 *)p)->f34));
}
