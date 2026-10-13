/*
 * function: BTL_CLIENT_StepSelectRun
 * address: 0x021CF078
 * packet: pkt_ov093_021CF078
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetCompetitorKind 0x021B86E4 thumb ov093
 *   BTL_CLIENT_GetEscapeBlockerForSide 0x021CF918 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EAF78 0x021EAF78 thumb ov093
 *   BTL_CLIENT_ShowMessage 0x021CE3B4 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   BTL_CLIENT_BuildActionPromptMessage 0x021CE0F8 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_021EABC4 0x021EABC4 thumb ov093
 *   func_021EAC54 0x021EAC54 thumb ov093
 *   BTL_CLIENT_PollTimeLimitReady 0x021CE08C thumb ov093
 *   BTL_ACTION_SetEscape 0x021D8414 thumb ov093
 *   BTL_CLIENT_SetSubFn 0x021CE150 thumb ov093
 *   BTL_CLIENT_StepSelectAction 0x021CE4D0 thumb ov093
 *   BTL_CLIENT_StepAutoSelectActions 0x021CE3C8 thumb ov093
 *   BTL_CLIENT_StepAdvanceSlot 0x021CF220 thumb ov093
 */
#include "../include/Obj02136.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_MAIN_GetCompetitorKind(unsigned int **p);
extern u32 BTL_CLIENT_GetEscapeBlockerForSide(u8 *, u8 *, u16 *);
struct L;
extern void func_021EAF18(struct L *p, int kind, int id);
struct H;
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *, u8);
extern void BTL_CLIENT_ShowMessage(u8 *p, void *q);
extern int func_021EA710(u32 *p);
extern void BTL_CLIENT_BuildActionPromptMessage(u8 *, u8 *, u8 *);
extern void func_021EA65C(char *p, struct H *h);
extern int func_021EA720(u32 *p);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *, int *);
extern int BTL_CLIENT_PollTimeLimitReady(u8 *);
extern void BTL_ACTION_SetEscape(u32 *p);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
extern int BTL_CLIENT_StepSelectAction(u8 *p, u32 *st);
extern int BTL_CLIENT_StepAutoSelectActions(u8 *p, int *state);
extern u32 BTL_CLIENT_StepAdvanceSlot(u8 *p, int *st);
u32 BTL_CLIENT_StepSelectRun(u8 *p, u32 *st)
{
    u8 id;
    u16 k;
    int result;
    switch (*st) {
    case 0:
        switch (BTL_MAIN_GetCompetitorKind(((struct Obj02136 *)p)->f0)) {
        default:
        case 0:
            if (BTL_CLIENT_GetEscapeBlockerForSide(p, &id, &k) == 4) {
                *st = 5;
                break;
            }
            if (k) {
                func_021EAF18((struct L *)(p + 0x58), 2, 0x365);
                func_021EAF50((struct L *)(p + 0x58), id);
                func_021EAF50((struct L *)(p + 0x58), k);
            } else {
                func_021EAF18((struct L *)(p + 0x58), 1, 0x4a);
            }
            BTL_CLIENT_ShowMessage(p, p + 0x58);
            *st = 1;
            break;
        case 1:
            func_021EAF18((struct L *)(p + 0x58), 1, 0x4c);
            BTL_CLIENT_ShowMessage(p, p + 0x58);
            *st = 1;
            break;
        case 2:
            func_021EAF18((struct L *)(p + 0x58), 1, 0x4d);
            func_021EAF78(p + 0x58, 0xff);
            BTL_CLIENT_ShowMessage(p, p + 0x58);
            *st = 3;
            break;
        }
        break;
    case 1:
        if (func_021EA710(((struct Obj02136 *)p)->f54)) {
            BTL_CLIENT_BuildActionPromptMessage(p, *(u8 * *)&((struct Obj02136 *)p)->f8, p + 0x58);
            func_021EA65C(((struct Obj02136 *)p)->f54, (struct H *)(p + 0x58));
            *st = 2;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj02136 *)p)->f54))
            BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectAction));
        break;
    case 3:
        func_021EA710(((struct Obj02136 *)p)->f54);
        if (func_021EA720(((struct Obj02136 *)p)->f54)) {
            func_021EAF18((struct L *)(p + 0x58), 3, 8);
            func_021EAF18((struct L *)(p + 0x7c), 3, 9);
            func_021EABC4(((struct Obj02136 *)p)->f54, (u32)(p + 0x58), (u32)(p + 0x7c), 1);
            *st = 4;
        }
        break;
    case 4:
        if (func_021EA710(((struct Obj02136 *)p)->f54)) {
            if (func_021EAC54(((struct Obj02136 *)p)->f54, &result)) {
                if (result == 0)
                    *st = 5;
                else
                    BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectAction));
            } else if (BTL_CLIENT_PollTimeLimitReady(p)) {
                BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAutoSelectActions));
            }
        }
        break;
    case 5:
        BTL_ACTION_SetEscape(((struct Obj02136 *)p)->fC);
        p[0x1b2] |= 4;
        BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
        break;
    }
    return 0;
}
