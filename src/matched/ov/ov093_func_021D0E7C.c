/*
 * function: BTL_CLIENT_StepChooseReplacement
 * address: 0x021D0E7C
 * packet: pkt_ov093_021D0E7C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the state-0 fallbacks and single-mon path set state 4, not 6;
 * duplicating the state-4 assignment inside both fallback arms preserves
 * the late cross-jump of D8/DC stores. Factoring it outside adds 12 bytes.
 * volatile: count at 021D0EB2 is reread at 021D0EB6 and 021D0ECC.
 * symbols:
 *   BTL_CLIENT_CollectOwnReceivedIds 0x021D0C78 thumb ov093
 *   BTL_CLIENT_ListAbleMons 0x021D0980 thumb ov093
 *   BTL_CLIENT_IsDoubleBattleLeadAlive 0x021D102C thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_ACTION_SetChange 0x021D8394 thumb ov093
 *   BTL_MAIN_GetSlotClientAndNth 0x021B8E28 thumb ov093
 *   BTL_CLIENT_BuildSlotChoices 0x021D0B10 thumb ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   BTL_CLIENT_StartTimeLimit 0x021CE068 thumb ov093
 *   BTL_CLIENT_TrySetRotateAction 0x021D1058 thumb ov093
 *   BTL_ACTION_SetChangeDepleted 0x021D83C4 thumb ov093
 *   BTL_CALC_ActionSetNone 0x021D8434 thumb ov093
 *   BTL_CLIENT_PollTimeLimitReady 0x021CE08C thumb ov093
 *   func_021E9B14 0x021E9B14 thumb ov093
 *   func_021E9B20 0x021E9B20 thumb ov093
 *   BTL_CLIENT_SetChangeActionsFromChoice 0x021D0B6C thumb ov093
 *   BTL_CLIENT_SetChangeActionsFirstAble 0x021D0BB0 thumb ov093
 *   BTL_CLIENT_StopTimeLimit 0x021CE0E0 thumb ov093
 *   BTL_MAIN_GetCommPos 0x021B86C0 thumb ov093
 *   func_021EA7FC 0x021EA7FC thumb ov093
 *   func_021EA814 0x021EA814 thumb ov093
 */
#include "../include/Obj00819.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0x1B3]; volatile u8 count; } CountField;
extern u8 BTL_CLIENT_CollectOwnReceivedIds(void *, u8 *);
extern u8 BTL_CLIENT_ListAbleMons(u8 *, u8 *);
extern int BTL_CLIENT_IsDoubleBattleLeadAlive(char *p);
struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void BTL_ACTION_SetChange(void *, u8, u8);
extern void BTL_MAIN_GetSlotClientAndNth(u8 *, u8, u8 *, u8 *);
extern void BTL_CLIENT_BuildSlotChoices(u8 *p, u32 a, u32 b, void *q, void *out);
extern void func_021E9A78(char *p, const u8 *q, int x, int y, u8 *r);
extern void BTL_CLIENT_StartTimeLimit(u8 *);
extern int BTL_CLIENT_TrySetRotateAction(u8 *, void *);
extern void BTL_ACTION_SetChangeDepleted(u32 *p);
extern void BTL_CALC_ActionSetNone(u32 *p);
extern int BTL_CLIENT_PollTimeLimitReady(u8 *);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern void BTL_CLIENT_SetChangeActionsFromChoice(u8 *g, u8 *s);
extern void BTL_CLIENT_SetChangeActionsFirstAble(u8 *p);
extern void BTL_CLIENT_StopTimeLimit(u8 *p);
extern u8 BTL_MAIN_GetCommPos(u8 **p);
extern void func_021EA7FC(char *p);
extern int func_021EA814(u32 *p);
int BTL_CLIENT_StepChooseReplacement(u8 *p, int *state, u8 param)
{
    u8 order[6];
    u8 pair[2];
    u32 n;
    u32 count;
    int mode;
    void *mon;
    switch (*state) {
    case 0:
        ((CountField *)p)->count = BTL_CLIENT_CollectOwnReceivedIds(p, p + 0x1B5);
        if (((CountField *)p)->count != 0) {
            n = BTL_CLIENT_ListAbleMons(p, order);
            if (n != 0) {
                count = ((CountField *)p)->count;
                if (count > n) count = n;
                if (BTL_CLIENT_IsDoubleBattleLeadAlive((char *)p) != 0) {
                    mon = BTL_SLOT_GetPokeParam(((struct Obj00819 *)p)->f118, 0);
                    if (n == 1 && BTL_POKEPARAM_IsFainted(mon) != 0) {
                        BTL_ACTION_SetChange(p + 0x124, 0, order[0]);
                        *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                        ((struct Obj00819 *)p)->fDC = 4;
                        *state = 4;
                        break;
                    }
                }
                BTL_MAIN_GetSlotClientAndNth(*(u8 * *)&((struct Obj00819 *)p)->f0, p[0x1B5], &pair[1], &pair[0]);
                BTL_CLIENT_BuildSlotChoices(p, param, count, p + 0x184, p + 0x190);
                func_021E9A78(((struct Obj00819 *)p)->f54, p + 0x184, pair[0], 0, p + 0x190);
                BTL_CLIENT_StartTimeLimit(p);
                *state = 1;
            } else {
                if (BTL_CLIENT_IsDoubleBattleLeadAlive((char *)p) != 0 && (mode = BTL_CLIENT_TrySetRotateAction(p, p + 0x124)) != 0) {
                    ((struct Obj00819 *)p)->fDC = mode;
                    *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                    *state = 4;
                } else {
                    BTL_ACTION_SetChangeDepleted((u32 *)(p + 0x124));
                    *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                    ((struct Obj00819 *)p)->fDC = 4;
                    *state = 4;
                }
            }
        } else {
            BTL_CALC_ActionSetNone((u32 *)(p + 0x124));
            *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
            ((struct Obj00819 *)p)->fDC = 4;
            *state = 4;
        }
        break;
    case 1:
        if (BTL_CLIENT_PollTimeLimitReady(p) != 0) {
            func_021E9B14(((struct Obj00819 *)p)->f54);
            *state = 2;
        } else if (func_021E9B20(((struct Obj00819 *)p)->f54) != 0) {
            BTL_CLIENT_SetChangeActionsFromChoice(p, p + 0x190);
            *state = 3;
        }
        break;
    case 2:
        if (func_021E9B20(((struct Obj00819 *)p)->f54) != 0) {
            BTL_CLIENT_SetChangeActionsFirstAble(p);
            *state = 3;
        }
        break;
    case 3:
        BTL_CLIENT_StopTimeLimit(p);
        *state = 4;
        break;
    case 4:
        if (BTL_MAIN_GetCommPos(((struct Obj00819 *)p)->f0) != 0) {
            p[0x1A9] = 1;
            func_021EA7FC(((struct Obj00819 *)p)->f54);
            *state = 5;
        } else {
            *state = 6;
        }
        break;
    case 5:
        if (func_021EA814(((struct Obj00819 *)p)->f54) != 0) {
            *state = 6;
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}
