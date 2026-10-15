/*
 * function: Wf2dmapFriend_ListKeyInput
 * address: 0x021C734C
 * packet: pkt_ov128_021C734C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BLINK_PALANM_ResetPhase 0x0202EB04 thumb
 *   WF2DMAP_TOUCH_SetTopHighlight1 0x021CA154 thumb ov128
 *   WF2DMAP_TOUCH_SetTopHighlight 0x021CA184 thumb ov128
 */
#include "../include/Obj00329.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern u32 KEY_GetRepeat(void);
struct CodeIn;
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
extern void WF2DMAP_TOUCH_SetTopHighlight1(u8 *, int);
extern void WF2DMAP_TOUCH_SetTopHighlight(u8 *, int, int);
int Wf2dmapFriend_ListKeyInput(u32 *p, int *q, u8 *ctx)
{
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        WF2DMAP_TOUCH_SetTopHighlight1(ctx, *p);
        func_020355D8(0);
        *q = 0;
        *p = 3;
        return 1;
    }
    if (KEY_GetTrg() & 1024) {
        GFL_USE_PlaySeDefaultVolume(0x556);
        WF2DMAP_TOUCH_SetTopHighlight1(ctx, *p);
        func_020355D8(0);
        *q = 0;
        *p = 4;
        return 1;
    }
    if (*q == 1) {
        if (KEY_GetTrg() & 0xcf3) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_SetTopHighlight(ctx, *p, *p);
            func_020355D8(0);
            *q = 0;
        }
        return 0;
    }
    if (KEY_GetTrg() & 1) {
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BLINK_PALANM_ResetPhase(((struct Obj00329 *)ctx)->f184);
        return 1;
    }
    if (KEY_GetRepeat() & 64) {
        if (*p != 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_SetTopHighlight(ctx, *p - 1, *p);
            --*p;
            return 0;
        }
    } else if (KEY_GetRepeat() & 128) {
        if (*p < 2) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_SetTopHighlight(ctx, *p + 1, *p);
            ++*p;
            return 0;
        }
    }
    return 0;
}
