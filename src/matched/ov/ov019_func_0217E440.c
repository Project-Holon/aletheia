/*
 * function: UNION_ONESELF_ColosseumPartyExchangeMain
 * address:  0x0217E440
 * packet:   pkt_ov019_0217E440
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_CheckNetErrorExit  0x0217BB20  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_ONESELF_CreateBattleTeamParty  0x0217B9CC  thumb  ov019
 *   UNION_ONESELF_DeleteParty  0x0217B9F4  thumb  ov019
 *   COLOSSEUM_ClearPositionsReceived  0x0217FE38  thumb  ov019
 *   COLOSSEUM_IsPositionsReceived  0x0217FE24  thumb  ov019
 *   COLOSSEUM_ResetParties  0x02175240  thumb  ov012
 *   COLOSSEUM_ClearConfirmCount  0x02175208  thumb  ov012
 *   COLOSSEUM_AllPartiesReceived  0x02175214  thumb  ov012
 *   COLOSSEUM_SendParty  0x02174D98  thumb  ov012
 *   COLOSSEUM_SendBattlePositions  0x02174DF0  thumb  ov012
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   POKE_REGULATION_AdjustPartyLevels  0x0201A2A8  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 */
#include "../include/Obj09416.h"

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    void *f8;
} Sys;

int UNION_ONESELF_CheckNetErrorExit(char *p);
typedef unsigned int   u32;
struct BigObj;
void UNION_MSG_CloseAllWindows(void *p);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
void *UNION_ONESELF_CreateBattleTeamParty(char *p);
void UNION_ONESELF_DeleteParty(void *h);
void COLOSSEUM_ClearPositionsReceived(u8 *p);
int COLOSSEUM_IsPositionsReceived(u8 *p);
void COLOSSEUM_ResetParties(u8 *p, int v);
void COLOSSEUM_ClearConfirmCount(u8 *p);
int COLOSSEUM_AllPartiesReceived(u8 *p);
u32 COLOSSEUM_SendParty(u32 p);
int COLOSSEUM_SendBattlePositions(u32 v);
void *GAME_DATA_GetMyParty(const struct BigObj *p);
struct Link;
struct Rec534;
void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
void POKE_REGULATION_AdjustPartyLevels(void *a0, void *a1);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
u32 GFL_NET_GetHandleNetID(struct Link *p);
struct Link;
void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
u32 GFL_NET_IsParentAid(void);

int UNION_ONESELF_ColosseumPartyExchangeMain(u8 *w, void *obj, int a2, u8 *state)
{
    u8 *p;
    int idx;
    void *h;

    p = *(u8 * *)&((struct Obj09416 *)w)->f355C;
    idx = GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()));
    if (UNION_ONESELF_CheckNetErrorExit((char *)w) == 1) {
        UNION_MSG_CloseAllWindows(w);
        return 1;
    }
    switch (*state) {
    case 0:
        switch (p[0x16d]) {
        case 0:
        default:
            func_0201AC2C(GAME_DATA_GetMyParty((*(Sys * *)&((struct Obj09416 *)w)->f0)->f8), (struct Rec534 *)(((int *)(p + 0x148))[idx]));
            break;
        case 1:
            h = UNION_ONESELF_CreateBattleTeamParty((char *)w);
            func_0201AC2C(h, (struct Rec534 *)(((int *)(p + 0x148))[idx]));
            UNION_ONESELF_DeleteParty(h);
            break;
        }
        POKE_REGULATION_AdjustPartyLevels((void *)(((struct Obj09416 *)w)->f352C), (void *)(((int *)(p + 0x148))[idx]));
        (*state)++;
        break;
    case 1:
        COLOSSEUM_ResetParties(p, 1);
        COLOSSEUM_ClearPositionsReceived(p);
        COLOSSEUM_ClearConfirmCount(p);
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x14, 0x14);
        (*state)++;
        break;
    case 2:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x14, 0x14) == 1)
            (*state)++;
        break;
    case 3:
        if (COLOSSEUM_SendParty(((int *)(p + 0x148))[idx]) == 1)
            (*state)++;
        break;
    case 4:
        if (COLOSSEUM_AllPartiesReceived(p) == 1)
            (*state)++;
        break;
    case 5:
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x10, 0x14);
        (*state)++;
        break;
    case 6:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x10, 0x14) == 1)
            (*state)++;
        break;
    case 7:
        if (GFL_NET_IsParentAid() == 1) {
            if (COLOSSEUM_SendBattlePositions((u32)(p + 0xcc)) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 8:
        if (COLOSSEUM_IsPositionsReceived(p) == 1) {
            UNION_ONESELF_SetNextPlayCategory((char *)w, 0x30);
            return 1;
        }
        break;
    }
    return 0;
}
