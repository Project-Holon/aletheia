/*
 * function: BTL_CLIENT_StepOpenBattleWindow
 * address:  0x021CDDDC
 * packet:   pkt_ov093_021CDDDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers (from the DIFF note): case 0 is the call written in each arm, `!= 4` arm first
 * (a-boolean-argument-is-a-call-in-each-arm.md; a flag value hoists `movs r1,#1`);
 * BTLV_EFFECT_TimerStart takes two arguments as its own file says, the second being the 0xe4
 * halfword still live in r1 from the || test; BTL_CLIENT_GetCounterTarget is declared u32 here because
 * the original narrows its result before the u16 parameter of BTLV_CORE_ShowCounterValue.
 *
 * symbols:
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTLV_CORE_StartOpening  0x021E90A0  thumb  ov093
 *   BTLV_CORE_PollOpening  0x021E90D0  thumb  ov093
 *   BTL_MAIN_GetLimitTimeCommand  0x021BA5C4  thumb  ov093
 *   BTL_MAIN_GetLimitTimeGame  0x021BA5D0  thumb  ov093
 *   BTLV_EFFECT_TimerStart  0x021F84E8  thumb  ov094
 *   BTLV_EFFECT_TimerSetVisible  0x021F8504  thumb  ov094
 *   BTL_CLIENT_StoreMonParam  0x021CDECC  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTL_CLIENT_GetCounterTarget  0x021D3FA8  thumb  ov093
 *   BTLV_CORE_ShowCounterValue  0x021EAEA8  thumb  ov093
 */
#include "../include/Obj01689.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *BTL_MAIN_GetCompetitor(void ***p);
struct Q3;
struct S;
extern void BTLV_CORE_StartOpening(unsigned int *o, unsigned int key);
extern int BTLV_CORE_PollOpening(struct S *s);
extern u16 BTL_MAIN_GetLimitTimeCommand(u8 *p);
extern u16 BTL_MAIN_GetLimitTimeGame(struct Q3 *p);
extern void BTLV_EFFECT_TimerStart(int a, int b);
extern void BTLV_EFFECT_TimerSetVisible(u32 a, u32 b, u32 c);
extern void BTL_CLIENT_StoreMonParam(u8 *p);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern u16 BTL_CLIENT_GetCounterTarget(u8 *p);
extern void BTLV_CORE_ShowCounterValue(u8 *p, int v);

int BTL_CLIENT_StepOpenBattleWindow(u8 *p, int *st)
{
    switch (*st) {
    case 0:
        if ((int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj01689 *)p)->f0) != 4) {
            BTLV_CORE_StartOpening(((struct Obj01689 *)p)->f54, 0);
        } else {
            BTLV_CORE_StartOpening(((struct Obj01689 *)p)->f54, 1);
        }
        *st = *st + 1;
        break;
    case 1:
        if (BTLV_CORE_PollOpening(((struct Obj01689 *)p)->f54) == 0) {
            break;
        }
        ((struct Obj01689 *)p)->fE4 = BTL_MAIN_GetLimitTimeCommand(((struct Obj01689 *)p)->f0);
        ((struct Obj01689 *)p)->fE6 = BTL_MAIN_GetLimitTimeGame(((struct Obj01689 *)p)->f0);
        if (((struct Obj01689 *)p)->fE4 != 0 || ((struct Obj01689 *)p)->fE6 != 0) {
            BTLV_EFFECT_TimerStart(((struct Obj01689 *)p)->fE6, ((struct Obj01689 *)p)->fE4);
            if (((struct Obj01689 *)p)->fE6 != 0) {
                BTLV_EFFECT_TimerSetVisible(0, 1, 1);
            }
        }
        BTL_CLIENT_StoreMonParam(p);
        if (BTL_CLIENT_IsMainStepActive(p) != 0) {
            BTLV_CORE_ShowCounterValue(((struct Obj01689 *)p)->f54, (u16)((u32)BTL_CLIENT_GetCounterTarget(p + 0x18)));
        }
        return 1;
    }
    return 0;
}
