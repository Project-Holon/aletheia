/*
 * function: BTL_CLIENT_StepMoveHighlight
 * address:  0x021CED4C
 * packet:   pkt_ov093_021CED4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_StartMoveHighlight  0x021E9CE0  thumb  ov093
 *   BTL_CLIENT_PollTimeLimitAndSetSub  0x021CE0BC  thumb  ov093
 *   BTLV_CORE_LockPartyChoice  0x021E9B14  thumb  ov093
 *   BTLV_CORE_PollPartyMenu  0x021E9B20  thumb  ov093
 *   BTL_CLIENT_SetSubFn  0x021CE150  thumb  ov093
 *   BTL_CLIENT_StepSelectMove  0x021CEA94  thumb  ov093
 *   BTL_CLIENT_StepAutoSelectActions  0x021CE3C8  thumb  ov093
 */
#include "../include/Obj05199.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTLV_CORE_StartMoveHighlight(u8 *p, u8 a, u8 b);
extern int BTL_CLIENT_PollTimeLimitAndSetSub(u8 *p, void *q);
extern void BTLV_CORE_LockPartyChoice(unsigned int *p);
extern int BTLV_CORE_PollPartyMenu(u8 *p);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
extern int BTL_CLIENT_StepSelectMove(u8 *p, u32 *state);
extern int BTL_CLIENT_StepAutoSelectActions(u8 *p, int *state);

u32 BTL_CLIENT_StepMoveHighlight(u8 *p, s32 *st)
{
    u32 r;
    switch (*st) {
    case 0:
        BTLV_CORE_StartMoveHighlight((u8 *)(((struct Obj05199 *)p)->f54), p[0x1b0], p[0x1b1]);
        *st = *st + 1;
        break;
    case 1:
        r = 0;
        if (BTL_CLIENT_PollTimeLimitAndSetSub(p, 0) != 0) {
            BTLV_CORE_LockPartyChoice((unsigned int *)(((struct Obj05199 *)p)->f54));
            *st = 2;
            return r;
        }
        if (BTLV_CORE_PollPartyMenu((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectMove));
        }
        break;
    case 2:
        if (BTLV_CORE_PollPartyMenu((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAutoSelectActions));
        }
        break;
    }
    return 0;
}
