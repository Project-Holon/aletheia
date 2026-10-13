/*
 * function: BTL_SERVER_StepRequestPokeChange
 * address: 0x021BAEF8
 * packet: pkt_ov093_021BAEF8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Case 4 falls through into case 5; the two entry points prevent the
 * field-address setup from moving above the state increment.
 * symbols:
 *   BTL_SERVER_SendCommandData 0x021BB724 thumb ov093
 *   BTL_SERVER_AreRepliesReady 0x021BB798 thumb ov093
 *   BTL_SERVER_CheckShiftPromptNeeded 0x021BB040 thumb ov093
 *   BTL_SERVER_GetShiftPromptMon 0x021BB0A0 thumb ov093
 *   BTL_SERVER_SendCommandDataToClient 0x021BB768 thumb ov093
 *   BTL_SERVER_ClearReplies 0x021BB7D0 thumb ov093
 *   func_021BA618 0x021BA618 thumb ov093
 *   BTL_SERVER_SetHandler 0x021BABEC thumb ov093
 *   BTL_SERVER_StepSelectEnding 0x021BB280 thumb ov093
 *   BTL_SERVER_CollectReplies 0x021BB6A8 thumb ov093
 *   BTL_SERVER_SendActionPacket 0x021BB628 thumb ov093
 *   BTL_SERVER_FLOW_ResetInitStateAfterChange 0x021BBD80 thumb ov093
 *   BTL_SERVER_FLOW_StartAfterPokeChange 0x021BBD8C thumb ov093
 *   func_021C84D8 0x021C84D8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   BTL_SERVER_GotoSelectCommands 0x021BABF4 thumb ov093
 */
#include "../include/Obj01235.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c);
extern int BTL_SERVER_AreRepliesReady(u8 *);
extern int BTL_SERVER_CheckShiftPromptNeeded(u8 *);
extern u32 BTL_SERVER_GetShiftPromptMon(u8 *);
extern void BTL_SERVER_SendCommandDataToClient(u8 *p, int a, u32 i, int b, int c);
extern void BTL_SERVER_ClearReplies(const u8 *p);
extern int func_021BA618(char *p);
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern int BTL_SERVER_StepSelectEnding(u8 *p);
extern void BTL_SERVER_CollectReplies(u8 *);
extern int BTL_SERVER_SendActionPacket(u8 *, int, int);
extern void BTL_SERVER_FLOW_ResetInitStateAfterChange(u8 *);
extern int BTL_SERVER_FLOW_StartAfterPokeChange(u8 *, void *);
extern int func_021C84D8(u8 *p);
extern void func_021B916C(u8 *p, u32 x);
extern void BTL_SERVER_GotoSelectCommands(void *);

int BTL_SERVER_StepRequestPokeChange(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        BTL_SERVER_SendCommandData(p, 5, (int)(p + 0xcb4), p[0xcba]);
        (*s)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(p)) {
            if (BTL_SERVER_CheckShiftPromptNeeded(p)) {
                p[0xec] = BTL_SERVER_GetShiftPromptMon(p);
                BTL_SERVER_SendCommandDataToClient(p, 4, 0, (int)(p + 0xec), 1);
            }
            (*s)++;
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            if (func_021BA618((char *)(*(u8 * *)&((struct Obj01235 *)p)->fC))) {
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSelectEnding);
                break;
            }
            BTL_SERVER_CollectReplies(p);
            if (BTL_SERVER_SendActionPacket(p, 2, 0))
                (*s)++;
            else
                *s += 2;
        }
        break;
    case 3:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            (*s)++;
        }
        break;
    case 4:
        BTL_SERVER_ClearReplies(p);
        BTL_SERVER_FLOW_ResetInitStateAfterChange(*(u8 * *)&((struct Obj01235 *)p)->f44);
        (*s)++;
    case 5:
        ((struct Obj01235 *)p)->f48 = BTL_SERVER_FLOW_StartAfterPokeChange(*(u8 * *)&((struct Obj01235 *)p)->f44, p + 0xb4);
        {
            int *q = *(int * *)&((struct Obj01235 *)p)->fCB0;
            BTL_SERVER_SendCommandData(p, 8, (int)(q + 2), *q);
        }
        (*s)++;
        break;
    case 6:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            switch (((struct Obj01235 *)p)->f48) {
            case 2:
                *s = 0;
                break;
            case 3:
                *s = 5;
                break;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj01235 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj01235 *)p)->f44)));
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSelectEnding);
                break;
            case 5:
                return 1;
            default:
                BTL_SERVER_GotoSelectCommands(p);
                break;
            }
        }
        break;
    }
    return 0;
}
