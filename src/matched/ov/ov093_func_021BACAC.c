/*
 * unit: yes
 * function: BTL_SERVER_StepSelectCommands, BTL_SERVER_GetRecordInitArg
 * address: 0x021BACAC
 * packet: pkt_ov093_021BACAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Contains the lead callback and its trailing return-one stub.
 * The fifth pool word is BTL_SERVER_StepRequestPokeReplace, the distinct case-1 callback;
 * reusing BTL_SERVER_StepRequestPokeChange there shortens the pool and cross-jumps the calls.
 * symbols:
 *   BTL_SERVER_FLOW_RunBagModeSetup 0x021BC390 thumb ov093
 *   BTL_SERVER_SendCommandData 0x021BB724 thumb ov093
 *   BTL_SERVER_AreRepliesReady 0x021BB798 thumb ov093
 *   BTL_SERVER_SendCommand 0x021BB718 thumb ov093
 *   BTL_SERVER_ClearReplies 0x021BB7D0 thumb ov093
 *   func_021BA5D8 0x021BA5D8 thumb ov093
 *   BTL_SERVER_SetHandler 0x021BABEC thumb ov093
 *   BTL_SERVER_StepSendRecording 0x021BB208 thumb ov093
 *   func_021BA618 0x021BA618 thumb ov093
 *   BTL_SERVER_StepSelectEnding 0x021BB280 thumb ov093
 *   BTL_SERVER_CollectReplies 0x021BB6A8 thumb ov093
 *   BTL_SERVER_SendActionPacket 0x021BB628 thumb ov093
 *   BTL_SERVER_FLOW_ResetInitState 0x021BBC34 thumb ov093
 *   BTL_SERVER_FLOW_StartTurn 0x021BBC44 thumb ov093
 *   BTL_MAIN_GetCommPos 0x021B86C0 thumb ov093
 *   BTL_SERVER_NoOp 0x021BB56C thumb ov093
 *   BTL_SERVER_GotoSelectCommands 0x021BABF4 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_SERVER_StepShiftPrompt 0x021BAE60 thumb ov093
 *   BTL_SERVER_StepRequestPokeChange 0x021BAEF8 thumb ov093
 *   BTL_SERVER_StepRequestPokeReplace 0x021BB0E0 thumb ov093
 *   BTL_SERVER_FLOW_GetChosenSlot 0x021BC55C thumb ov093
 *   func_021B9120 0x021B9120 thumb ov093
 *   func_021C84D8 0x021C84D8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 */
#include "../include/Obj01372.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_SERVER_FLOW_RunBagModeSetup(u8 *);
extern void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c);
extern int BTL_SERVER_AreRepliesReady(u8 *);
extern void BTL_SERVER_SendCommand(int a, int b);
extern void BTL_SERVER_ClearReplies(const u8 *p);
extern int func_021BA5D8(char *);
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern int BTL_SERVER_StepSendRecording(u8 *p, int *s);
extern int func_021BA618(char *p);
extern int BTL_SERVER_StepSelectEnding(u8 *p);
extern void BTL_SERVER_CollectReplies(u8 *);
extern int BTL_SERVER_SendActionPacket(u8 *, int, int);
extern void BTL_SERVER_FLOW_ResetInitState(u8 *);
extern int BTL_SERVER_FLOW_StartTurn(u8 *p, int a);
extern u8 BTL_MAIN_GetCommPos(u8 **p);
extern void BTL_SERVER_NoOp(void *);
extern void BTL_SERVER_GotoSelectCommands(void *);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern u32 BTL_MAIN_GetRule(void **p);
extern int BTL_SERVER_StepShiftPrompt(u8 *, int *);
extern int BTL_SERVER_StepRequestPokeChange(u8 *, int *);
extern int BTL_SERVER_StepRequestPokeReplace(u8 *p, int *s);
extern u8 BTL_SERVER_FLOW_GetChosenSlot(u8 *);
extern void func_021B9120(u8 *p, u8 n);
extern int func_021C84D8(u8 *p);
extern void func_021B916C(u8 *p, u32 x);
int BTL_SERVER_GetRecordInitArg(u8 *);

int BTL_SERVER_StepSelectCommands(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        if (BTL_SERVER_FLOW_RunBagModeSetup(*(u8 * *)&((struct Obj01372 *)p)->f44)) {
            int *q = *(int * *)&((struct Obj01372 *)p)->fCB0;
            BTL_SERVER_SendCommandData(p, 8, (int)(q + 2), *q);
            (*s)++;
        } else
            *s += 2;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            (*s)++;
        }
        break;
    case 2:
        BTL_SERVER_SendCommand((int)p, 3);
        (*s)++;
        break;
    case 3:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            if (func_021BA5D8(*(char * *)&((struct Obj01372 *)p)->fC)) {
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSendRecording);
                break;
            }
            if (func_021BA618((char *)(*(u8 * *)&((struct Obj01372 *)p)->fC))) {
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSelectEnding);
                break;
            }
            BTL_SERVER_CollectReplies(p);
            if (BTL_SERVER_SendActionPacket(p, 1, BTL_SERVER_GetRecordInitArg(p)))
                (*s)++;
            else
                *s += 2;
        }
        break;
    case 4:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            (*s)++;
        }
        break;
    case 5:
        BTL_SERVER_FLOW_ResetInitState(*(u8 * *)&((struct Obj01372 *)p)->f44);
        BTL_SERVER_ClearReplies(p);
        (*s)++;
    case 6:
        ((struct Obj01372 *)p)->f48 = BTL_SERVER_FLOW_StartTurn(*(u8 * *)&((struct Obj01372 *)p)->f44, (int)(p + 0xb4));
        if (BTL_MAIN_GetCommPos(((struct Obj01372 *)p)->fC))
            BTL_SERVER_NoOp(p + 0xb4);
        {
            int *q = *(int * *)&((struct Obj01372 *)p)->fCB0;
            BTL_SERVER_SendCommandData(p, 8, (int)(q + 2), *q);
        }
        (*s)++;
        break;
    case 7:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            switch (((struct Obj01372 *)p)->f48) {
            case 0:
                BTL_SERVER_GotoSelectCommands(p);
                break;
            case 3:
                *s = 6;
                break;
            case 2:
                {
                    void *a = BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj01372 *)p)->fC);
                    u32 b = BTL_MAIN_GetRule(((struct Obj01372 *)p)->fC);
                    if (!a && !b)
                        BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepShiftPrompt);
                    else
                        BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepRequestPokeChange);
                }
                break;
            case 1:
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepRequestPokeReplace);
                break;
            case 6:
                func_021B9120(((struct Obj01372 *)p)->fC, BTL_SERVER_FLOW_GetChosenSlot(*(u8 * *)&((struct Obj01372 *)p)->f44));
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSelectEnding);
                return 0;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj01372 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj01372 *)p)->f44)));
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSelectEnding);
                return 0;
            case 5:
            default:
                return 1;
            }
        }
        break;
    }
    return 0;
}

int BTL_SERVER_GetRecordInitArg(u8 *p)
{
    return 1;
}
