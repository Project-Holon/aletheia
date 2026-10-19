/*
 * function: UNION_ONESELF_ColosseumExitMain
 * address:  0x0217E904
 * packet:   pkt_ov019_0217E904
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   UNION_ONESELF_SetFieldBusy  0x0217BAF0  thumb  ov019
 *   COLOSSEUM_CheckAllFinished  0x0217FEB8  thumb  ov019
 *   UNION_CHARA_ClearTable  0x0217AE20  thumb  ov019
 *   COLOSSEUM_SendFinish  0x02174F34  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   UNION_COMM_RequestShutdown  0x02172D38  thumb  ov012
 *   UNION_COMM_RequestStart  0x02172D50  thumb  ov012
 *   UNION_COMM_ClearBeaconPcs  0x02173408  thumb  ov012
 *   UNION_COMM_InitConnectInfo  0x02173524  thumb  ov012
 *   UNION_SCENE_RequestScene  0x0217422C  thumb  ov012
 *   UNION_SCENE_IsScenePending  0x02174268  thumb  ov012
 *   COLOSSEUM_Delete  0x0217505C  thumb  ov012
 *   func_0200FB24  0x0200FB24  thumb
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 */
#include "../include/Obj00033.h"

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
} Bits;

typedef unsigned short u16;
typedef unsigned int   u32;
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
void UNION_MSG_CloseAllWindows(void *p);
void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
int COLOSSEUM_CheckAllFinished(u8 *p);
void UNION_CHARA_ClearTable(u8 *w);
int COLOSSEUM_SendFinish(void);
int UNION_COMM_IsResetting(u8 *w);
void UNION_COMM_RequestShutdown(u8 *w);
void UNION_COMM_RequestStart(u8 *w);
void UNION_COMM_ClearBeaconPcs(u8 *w);
void UNION_COMM_InitConnectInfo(u8 *w, u8 *q);
void UNION_SCENE_RequestScene(u8 *p, int a, int b);
int UNION_SCENE_IsScenePending(u8 *w);
void COLOSSEUM_Delete(int *p, int x);
u32 func_0200FB24(void);
struct Ctx;
void GAMESYSTEM_SetFieldMapState(struct Ctx *p, u32 v);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
void GFL_NET_SetLoginOption(u8 a0);
u32 GFL_NET_IsParentAid(void);
int GFL_NET_SYSTEM_GetConnectNum(void);
u16 GFL_NET_SYSTEM_GetCurrentAid(void);
u32 GFL_NET_IsConnectMember(u32 index);

int UNION_ONESELF_ColosseumExitMain(u8 *w, u8 *obj, u8 *a2, u8 *state)
{
    u8 *p;
    int m;
    int i;

    p = *(u8 * *)&((struct Obj00033 *)w)->f355C;
    if (*state < 7 && func_0200FB24() != 0 && UNION_MSG_CheckTalkPrintEnd(w) == 1) {
        UNION_ONESELF_SetFieldBusy((char *)w, (int)a2, (int)1);
        *state = 7;
    }
    switch (*state) {
    case 0:
        UNION_ONESELF_SetFieldBusy((char *)w, (int)a2, (int)1);
        if (p[0xde] == 2) {
            if (UNION_MSG_CheckTalkPrintEnd(w) == 1)
                *state = 6;
        } else {
            UNION_MSG_SetupPrintTalkMsg(w, a2, 0x14c);
            (*state)++;
        }
        break;
    case 1:
        if (COLOSSEUM_SendFinish() == 1)
            (*state)++;
        break;
    case 2:
        if (COLOSSEUM_CheckAllFinished(p) == 1)
            (*state)++;
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(w) == 1)
            (*state)++;
        break;
    case 4:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x13, 0x14);
        (*state)++;
        break;
    case 5:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x13, 0x14) == 1) {
            GFL_NET_SetLoginOption(0);
            (*state)++;
        }
        break;
    case 6:
        if (GFL_NET_IsParentAid() == 1) {
            m = p[0x16e];
            if (GFL_NET_SYSTEM_GetConnectNum() <= 1) {
                (*state)++;
                break;
            }
            for (i = 0; i < 5; i++) {
                if (i != GFL_NET_SYSTEM_GetCurrentAid() && ((1 << i) & m)) {
                    if ((int)GFL_NET_IsConnectMember((u8)i) == 1)
                        break;
                }
            }
            if (i == 5)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 7:
        if (((Bits *)(p + 0xc8))->b1 == 1 && UNION_COMM_IsResetting(w) == 1)
            return 0;
        if (func_0200FB24() != 0) {
            UNION_MSG_CloseAllWindows(w);
            GAMESYSTEM_SetFieldMapState((struct Ctx *)((*(Sys * *)&((struct Obj00033 *)w)->f0)->fc), 1);
            return 0;
        }
        UNION_COMM_RequestShutdown(w);
        (*state)++;
        break;
    case 8:
        if (UNION_COMM_IsResetting(w) == 0)
            (*state)++;
        break;
    case 9:
        p[0xc9] = 1;
        UNION_COMM_ClearBeaconPcs(w);
        UNION_CHARA_ClearTable(w);
        UNION_COMM_InitConnectInfo(w, obj + 0x14);
        UNION_SCENE_RequestScene(w, 0x19, 0);
        (*state)++;
        break;
    case 10:
        if (UNION_SCENE_IsScenePending(w) == 0) {
            if (*(u8 **)(w + 0x355C) != 0) {
                COLOSSEUM_Delete((int *)(*(u8 **)(w + 0x355C)), (*(Sys * *)&((struct Obj00033 *)w)->f0)->fc);
                *(u8 **)(w + 0x355C) = 0;
            }
            UNION_COMM_RequestStart(w);
            (*state)++;
        }
        break;
    case 11:
        if (UNION_COMM_IsResetting(w) == 0)
            return 1;
        break;
    }
    return 0;
}
