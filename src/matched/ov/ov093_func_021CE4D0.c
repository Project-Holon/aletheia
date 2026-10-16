/*
 * function: BTL_CLIENT_StepSelectAction
 * address: 0x021CE4D0
 * packet: pkt_ov093_021CE4D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 (wave P26 lane 2): byte-identical to the original except that two call
 * relocations have no witness in the current index: BTLV_CORE_AbortActionMenu and BTLV_CORE_CloseMenu. Both
 * leaves are now filed (src/matched/ov/ov093_func_021E979C.c, ov093_func_021E9954.c, EXACT);
 * the verdict becomes EXACT once the integrator regenerates the index. The original extent is
 * 772 B: 756 B of C plus the 16 B linker veneer at 021CE7C4 (not C, resolved as a veneer witness).
 * Two changes closed the 253 B residue of the older draft: (1) no shared increment label and
 * no goto: each arm writes ++*st; break; so the compiler builds the single shared state store
 * and one epilogue (756 to 748 B, branch layout); (2) the countdown loop reads the index byte
 * through a struct field (struct L at 0x11D and 0x1A6) instead of a count pointer local, so
 * mwcc hoists three separate address computations (count pointer in r5, a copy in r6, a
 * stack copy for the loop test) as in the original.
 * Not tried again from the older note: unsigned-long state pointer, full-word countdown.
 * symbols:
 *   BTL_SIDE_GetClientPokeParam 0x021B990C thumb ov093
 *   BTL_CALC_ActionSetNone 0x021D8434 thumb ov093
 *   BTL_CLIENT_IsActionForced 0x021CF470 thumb ov093
 *   BTL_CLIENT_SetSubFn 0x021CE150 thumb ov093
 *   BTL_CLIENT_FindSupportItem 0x021CE8F0 thumb ov093
 *   BTL_CLIENT_BuildActionPromptMessage 0x021CE0F8 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessageNow 0x021EA65C thumb ov093
 *   BTLV_CORE_WaitMessage 0x021EA710 thumb ov093
 *   BTLV_CORE_StartActionMenu 0x021E9760 thumb ov093
 *   BTL_CLIENT_PollTimeLimitAndSetSub 0x021CE0BC thumb ov093
 *   BTLV_CORE_AbortActionMenu 0x021E979C thumb ov093
 *   BTLV_CORE_PollActionMenu 0x021E97A4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTLV_CORE_CloseMenuToReselect 0x021E9964 thumb ov093
 *   BTL_CLIENT_SetSlotFlag 0x021CF430 thumb ov093
 *   BTL_MAIN_IsRecordEnabledInComm 0x021BA1EC thumb ov093
 *   BTL_MAIN_GetCompetitorKind 0x021B86E4 thumb ov093
 *   BTL_CLIENT_GetSlotFlag 0x021CF43C thumb ov093
 *   BTL_CALC_ActionGetKind 0x021D8454 thumb ov093
 *   func_021CE7C4 0x021CE7C4 thumb ov093
 *   BTL_CLIENT_FlushSlotLinkWord 0x021CF3B8 thumb ov093
 *   BTLV_CORE_IsMenuClosed 0x021E9974 thumb ov093
 *   BTLV_CORE_CloseMenu 0x021E9954 thumb ov093
 *   BTLV_SCU_InitMessage 0x021EAF18 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTLV_SCU_AppendMessageArg 0x021EAF50 thumb ov093
 *   BTL_CLIENT_ShowMessage 0x021CE3B4 thumb ov093
 *   BTL_CLIENT_StepAdvanceSlot 0x021CF220 thumb ov093
 *   BTL_CLIENT_StepShowSupportItemMessage 0x021CE7D4 thumb ov093
 *   BTL_CLIENT_StepAutoSelectActions 0x021CE3C8 thumb ov093
 *   BTL_CLIENT_StepSelectSwitchTarget 0x021CEDC0 thumb ov093
 *   BTL_CLIENT_StepSelectMove 0x021CEA94 thumb ov093
 *   BTL_CLIENT_StepSelectItem 0x021CEEB8 thumb ov093
 *   BTL_CLIENT_StepSelectRun 0x021CF078 thumb ov093
 * proof: full unsigned state dispatch <=8; byte selectors0..255; countdown assigned before reads; byte/state additions wrap at their original widths; fixed veneer is omitted from C.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct H;
struct L;
struct Unk021D62A8;
extern void *BTL_SIDE_GetClientPokeParam(char *p, unsigned int i, unsigned int j);
extern void BTL_CALC_ActionSetNone(u32 *p);
extern u32 BTL_CLIENT_IsActionForced(u8 *, void *, u8 *);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
typedef unsigned short u16;
extern u32 BTL_CLIENT_FindSupportItem(const u8 *p, u16 *out);
extern void BTL_CLIENT_BuildActionPromptMessage(u8 *, u8 *, u8 *);
extern void BTLV_CORE_BuildAndPrintMessageNow(char *p, struct H *h);
extern int BTLV_CORE_WaitMessage(u32 *p);
extern void BTLV_CORE_StartActionMenu(char *, u8 *, int, int);
extern int BTL_CLIENT_PollTimeLimitAndSetSub(u8 *p, void *q);
extern void BTLV_CORE_AbortActionMenu(char *p);
extern int BTLV_CORE_PollActionMenu(char *p);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTLV_CORE_CloseMenuToReselect(u32);
extern void BTL_CLIENT_SetSlotFlag(u8 *, u32, u32);
extern int BTL_MAIN_IsRecordEnabledInComm(char **p);
extern int BTL_MAIN_GetCompetitorKind(unsigned int **p);
extern u8 BTL_CLIENT_GetSlotFlag(u8 *, u32);
extern u32 BTL_CALC_ActionGetKind(u32 *);
extern void func_021CE7C4(u8 *);
extern void BTL_CLIENT_FlushSlotLinkWord(u8 *, u32);
extern int BTLV_CORE_IsMenuClosed(u32);
extern void BTLV_CORE_CloseMenu(void *);
extern void BTLV_SCU_InitMessage(struct L *p, int kind, int id);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTLV_SCU_AppendMessageArg(struct L *p, u32 val);
extern void BTL_CLIENT_ShowMessage(u8 *p, void *q);
extern u32 BTL_CLIENT_StepAdvanceSlot(u8 *p, int *st);
extern u32 BTL_CLIENT_StepShowSupportItemMessage(u8 *p, int *st);
extern int BTL_CLIENT_StepAutoSelectActions(u8 *p, int *state);
extern u32 BTL_CLIENT_StepSelectSwitchTarget(u8 *p, int *st);
extern int BTL_CLIENT_StepSelectMove(u8 *p, u32 *state);
extern u32 BTL_CLIENT_StepSelectItem(u8 *p, int *st);
extern u32 BTL_CLIENT_StepSelectRun(u8 *p, u32 *st);
struct L { u8 pad[0x11D]; u8 idx; u8 pad2[0x1A6-0x11E]; u8 sel; };
#define Q ((struct L *)p)
#define W(o) (*(u32 *)(p+(o)))
#define P(o) (*(void **)(p+(o)))
int BTL_CLIENT_StepSelectAction(u8 *p, u32 *st)
{
    u32 result;
    switch (*st) {
    case 0:
        P(8) = BTL_SIDE_GetClientPokeParam(P(4), p[0x1A6], p[0x11D]);
        P(12) = p + 0x124 + p[0x11D] * 4;
        p[0x1AF] = 0;
        BTL_CALC_ActionSetNone(P(12));
        if (BTL_CLIENT_IsActionForced(p, P(8), P(12))) {
            BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepAdvanceSlot));
            break;
        }
        if (BTL_CLIENT_FindSupportItem(p, (unsigned short *)(p + 0x19E)) == 1) {
            BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepShowSupportItemMessage));
            break;
        }
        ++*st; break;
    case 1:
        if (*(signed char *)(p + 0x11E) != p[0x11D] || p[0x120]) {
            BTL_CLIENT_BuildActionPromptMessage(p, P(8), p + 0x58);
            BTLV_CORE_BuildAndPrintMessageNow(P(0x54), (struct H *)(p + 0x58));
            p[0x120] = 0;
            p[0x11E] = p[0x11D];
            ++*st; break;
        }
        *st += 2U;
        break;
    case 2:
        if (!BTLV_CORE_WaitMessage(P(0x54))) return 0;
        ++*st;
        /* falls through */
    case 3:
        BTLV_CORE_StartActionMenu(P(0x54), P(8), p[0x11D] > p[0x11F], (int)P(12));
        ++*st; break;
    case 4:
        if (BTL_CLIENT_PollTimeLimitAndSetSub(p, (void *)((u32)BTL_CLIENT_StepAutoSelectActions))) {
            BTLV_CORE_AbortActionMenu(P(0x54));
            return 0;
        }
        result = BTLV_CORE_PollActionMenu(P(0x54));
        switch (result) {
        case 3:
            if (BTL_POKEPARAM_HasSick(P(8), 0x21)) {
                BTLV_CORE_CloseMenuToReselect(W(0x54));
                *st = 6;
            } else {
                BTL_CLIENT_SetSlotFlag(p, p[0x11D], 0);
                BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectSwitchTarget));
            }
            break;
        case 1:
            BTL_CLIENT_SetSlotFlag(p, p[0x11D], 0);
            BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectMove));
            break;
        case 2:
            if (BTL_POKEPARAM_HasSick(P(8), 0x21)) *st = 6;
            else if (p[0x1AA] == 1 && !BTL_MAIN_IsRecordEnabledInComm(P(0))) {
                BTLV_CORE_CloseMenuToReselect(W(0x54));
                *st = 5;
            } else BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectItem));
            break;
        case 4:
            if (p[0x11D] == p[0x11F]) {
                if (BTL_POKEPARAM_HasSick(P(8), 0x21) && BTL_MAIN_GetCompetitorKind(P(0)) != 2) *st = 6;
                else {
                    BTL_CLIENT_SetSlotFlag(p, p[0x11D], 0);
                    BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectRun));
                }
                break;
            }
            if (p[0x11D] == 0) break;
            do {
                --Q->idx;
                if (!BTL_CLIENT_IsActionForced(p, BTL_SIDE_GetClientPokeParam(P(4), Q->sel, Q->idx), 0)) {
                    p[0x1AB] += BTL_CLIENT_GetSlotFlag(p, p[0x11D]);
                    if (BTL_CALC_ActionGetKind((u32 *)(p + 0x124 + p[0x11D] * 4)) == 3)
                        func_021CE7C4(p + 0x190);
                    if (BTL_CALC_ActionGetKind((u32 *)(p + 0x124 + p[0x11D] * 4)) == 2)
                        BTL_CLIENT_FlushSlotLinkWord(p, p[0x11D]);
                    BTL_CLIENT_SetSubFn(p, (void *)((u32)BTL_CLIENT_StepSelectAction));
                    return 0;
                }
            } while (Q->idx != 0);
            break;
        }
        break;
    case 5:
        if (BTLV_CORE_IsMenuClosed(W(0x54))) *st = 3;
        break;
    case 6:
        BTLV_CORE_CloseMenu(P(0x54));
        ++*st; break;
    case 7:
        if (!BTLV_CORE_IsMenuClosed(W(0x54))) break;
        BTLV_SCU_InitMessage((struct L *)(p + 0x58), 1, 0xC5);
        BTLV_SCU_AppendMessageArg((struct L *)(p + 0x58), BTL_POKEPARAM_GetPokeId(P(8)));
        BTL_CLIENT_ShowMessage(p, p + 0x58);
        ++*st; break;
    case 8:
        if (BTLV_CORE_WaitMessage(P(0x54))) *st = 1;
        break;
    }
    return 0;
}
