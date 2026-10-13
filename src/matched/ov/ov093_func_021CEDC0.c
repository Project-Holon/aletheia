/*
 * function: BTL_CLIENT_StepSelectSwitchTarget
 * address: 0x021CEDC0
 * packet: pkt_ov093_021CEDC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CLIENT_GetEscapeBlocker 0x021CF8D4 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTLV_CORE_StartPartyMenu 0x021E9A78 thumb ov093
 *   BTL_CLIENT_PollTimeLimitAndSetSub 0x021CE0BC thumb ov093
 *   BTLV_CORE_LockPartyChoice 0x021E9B14 thumb ov093
 *   BTLV_CORE_PollPartyMenu 0x021E9B20 thumb ov093
 *   func_021CEE98 0x021CEE98 thumb ov093
 *   func_021CEEA8 0x021CEEA8 thumb ov093
 *   BTL_ACTION_SetChange 0x021D8394 thumb ov093
 *   BTL_CLIENT_SetSubFn 0x021CE150 thumb ov093
 *   BTL_CLIENT_StepAdvanceSlot 0x021CF220 thumb ov093
 *   BTL_CLIENT_StepSelectAction 0x021CE4D0 thumb ov093
 *   BTL_CLIENT_StepAutoSelectActions 0x021CE3C8 thumb ov093
 */
#include "../include/Obj03194.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_CLIENT_GetEscapeBlocker(u8 *, void *, u8 *, u16 *);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTLV_CORE_StartPartyMenu(char *, const u8 *, int, int, u8 *);
extern int BTL_CLIENT_PollTimeLimitAndSetSub(u8 *p, void *q);
extern void BTLV_CORE_LockPartyChoice(unsigned int *p);
extern int BTLV_CORE_PollPartyMenu(u8 *p);
extern u32 func_021CEE98(u8 *);
extern u32 func_021CEEA8(u8 *);
extern void BTL_ACTION_SetChange(void *, u8, u32);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
extern u32 BTL_CLIENT_StepAdvanceSlot(u8 *p, int *st);
extern int BTL_CLIENT_StepSelectAction(u8 *p, u32 *st);
extern int BTL_CLIENT_StepAutoSelectActions(u8 *p, int *state);

u32 BTL_CLIENT_StepSelectSwitchTarget(u8 *p, int *st)
{
    u8 a;
    u16 b;
    u32 r, n;
    switch (*st) {
    case 0:
        r = 0;
        if ((u8)BTL_CLIENT_GetEscapeBlocker(p, ((struct Obj03194 *)p)->f8, &a, &b) != 4 ||
            a == BTL_POKEPARAM_GetPokeId(((struct Obj03194 *)p)->f8)) r = 1;
        BTLV_CORE_StartPartyMenu(*(char * *)&((struct Obj03194 *)p)->f54, p + 0x184, p[0x11d], r, p + 0x190);
        ++*st;
        break;
    case 1:
        r = 0;
        if (BTL_CLIENT_PollTimeLimitAndSetSub(p, 0)) {
            BTLV_CORE_LockPartyChoice((unsigned int *)(*(u32 *)&((struct Obj03194 *)p)->f54));
            *st = 2;
            return r;
        }
        if (BTLV_CORE_PollPartyMenu((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) {
            if (func_021CEE98(p + 0x190) == 0) {
                n = func_021CEEA8(p + 0x190);
                if (n < 6) {
                    BTL_ACTION_SetChange(((struct Obj03194 *)p)->fC, p[0x11d], n);
                    BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
                    break;
                }
            }
            BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectAction));
        }
        break;
    case 2:
        if (BTLV_CORE_PollPartyMenu((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAutoSelectActions));
        break;
    }
    return 0;
}
