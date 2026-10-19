/*
 * function: UNION_ONESELF_AppMain
 * address:  0x0217D5B8
 * packet:   pkt_ov019_0217D5B8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_HandleNetError  0x0217BB04  thumb  ov019
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   func_02030734  0x02030734  arm
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   UNION_SCENE_RequestScene  0x0217422C  thumb  ov012
 *   UNION_SCENE_IsScenePending  0x02174268  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_COMM_RequestStart  0x02172D50  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   UNION_COMMAND_SendAppEntry  0x02173D38  thumb  ov012
 *   UNION_MSG_GetDrawStartMsg  0x0217EE10  thumb  ov019
 *   UNION_MSG_GetSpinTradeStartMsg  0x0217EDEC  thumb  ov019
 *   UNION_MSG_GetDrawBusyMsg  0x0217EE1C  thumb  ov019
 *   UNION_MSG_GetSpinTradeBusyMsg  0x0217EDF8  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_COMM_RequestRestart  0x02172D20  thumb  ov012
 *   UNION_COMM_SetSituationParam  0x021734A8  thumb  ov012
 *   d_021807E8     0x021807E8  data  a4
 */
#include "../include/Obj00033.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[7];
    u8 x0 : 3;
    u8 b3 : 1;
} Sub;

typedef struct {
    u8 f00;
    u8 f01;
    u8 pad02[0x14 - 0x02];
    Sub *f14;
    u8 pad18[0x5a - 0x18];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj;

extern int UNION_ONESELF_HandleNetError(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, unsigned int b, unsigned int c);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, unsigned int b, unsigned int c);
typedef unsigned int   u32;
struct BigObj;
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern void UNION_SCENE_RequestScene(u8 *p, int a, int b);
extern int UNION_SCENE_IsScenePending(u8 *a);
extern u32 func_020307B0(void *p);
extern u32 func_0200FB24(void);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern void UNION_COMM_RequestStart(u8 *a);
extern int UNION_COMM_IsResetting(u8 *a);
extern u32 UNION_COMMAND_SendAppEntry(u8 *p);
extern u16 UNION_MSG_GetDrawStartMsg(int i);
extern u16 UNION_MSG_GetSpinTradeStartMsg(int i);
extern u16 UNION_MSG_GetDrawBusyMsg(int i);
extern u16 UNION_MSG_GetSpinTradeBusyMsg(int i);
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
extern void UNION_COMM_RequestRestart(u8 *a);
extern void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);
extern u8 d_021807E8[];

int UNION_ONESELF_AppMain(u8 *a, Obj *b, u8 *c, u8 *d)
{
    int *p;
    if (*d != 4 && *d != 5 && *d != 8 && UNION_ONESELF_HandleNetError((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (b->b1 == 1)
            *d = 6;
        else
            (*d)++;
        break;
    case 1:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 8, 0x14);
        (*d)++;
        break;
    case 2:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 8, 0x14) == 1)
            (*d)++;
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(a) == 1) {
            if (b->f01 == 0xe) {
                p = func_02030734(0x41, 8, 1, (const char *)d_021807E8, 0xB9A);
                p[1] = (*(int **)a)[2];
                *(int * *)&((struct Obj00033 *)a)->f3558 = p;
                UNION_SCENE_RequestScene(a, 3, (int)p);
            } else {
                p = func_02030734(0x41, 0x18, 1, (const char *)d_021807E8, 0xBA2);
                p[1] = (*(int **)a)[2];
                p[2] = (int)GAME_DATA_GetMyParty((void *)(*(int **)a)[2]);
                p[3] = (int)GAME_DATA_GetSaveControl((struct Big *)((*(int **)a)[2]));
                p[4] = (int)GAME_DATA_GetTrainerRecord((int *)((*(int **)a)[2]));
                *(int * *)&((struct Obj00033 *)a)->f3558 = p;
                UNION_SCENE_RequestScene(a, 4, (int)p);
            }
            (*d)++;
        }
        break;
    case 4:
        if (UNION_SCENE_IsScenePending(a) == 0) {
            func_020307B0(*(int * *)&((struct Obj00033 *)a)->f3558);
            *(int * *)&((struct Obj00033 *)a)->f3558 = 0;
            if (func_0200FB24() != 0) {
                UNION_ONESELF_SetNextPlayCategory((char *)a, 1);
                return 1;
            }
            UNION_COMM_RequestStart(a);
            (*d)++;
        }
        break;
    case 5:
        if (UNION_COMM_IsResetting(a) == 0)
            return 1;
        break;
    case 6:
        if (UNION_COMMAND_SendAppEntry(a) == 1)
            (*d)++;
        break;
    case 7:
        switch (a[0x282B]) {
        case 1:
            if (b->f01 == 0xe)
                UNION_MSG_SetupPrintTalkMsg(a, c, UNION_MSG_GetDrawStartMsg(b->f14->b3));
            else
                UNION_MSG_SetupPrintTalkMsg(a, c, UNION_MSG_GetSpinTradeStartMsg(b->f14->b3));
            *d = 3;
            break;
        case 2:
            if (b->f01 == 0xe)
                UNION_MSG_SetupPrintTalkMsg(a, c, UNION_MSG_GetDrawBusyMsg(b->f14->b3));
            else
                UNION_MSG_SetupPrintTalkMsg(a, c, UNION_MSG_GetSpinTradeBusyMsg(b->f14->b3));
            UNION_COMM_RequestRestart(a);
            *d = 8;
            break;
        }
        break;
    case 8:
        if (UNION_MSG_CheckTalkPrintEnd(a) == 1 && UNION_COMM_IsResetting(a) == 0) {
            UNION_COMM_SetSituationParam(a, 3, 0);
            return 1;
        }
        break;
    }
    return 0;
}
