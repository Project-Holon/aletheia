/*
 * function: UNION_ONESELF_ColosseumSetupMain
 * address:  0x0217DCA8
 * packet:   pkt_ov019_0217DCA8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   func_02034714  0x02034714  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MET_TRAINERS_GetFromSave  0x0200ED48  thumb
 *   MET_TRAINERS_Insert  0x0200ED54  thumb
 *   UNION_ONESELF_HandleNetErrorExit  0x0217BB20  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   COLOSSEUM_CheckAllEntered  0x0217FDC8  thumb  ov019
 *   COLOSSEUM_CheckAllTrainerCardsReceived  0x0217FDF8  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   COLOSSEUM_AddCommandTable  0x02174B40  thumb  ov012
 *   COLOSSEUM_SendPlayerEntry  0x02174BB8  thumb  ov012
 *   COLOSSEUM_SendTrainerCard  0x02174C34  thumb  ov012
 *   UNION_COMM_AddMember  0x0217357C  thumb  ov012
 *   COLOSSEUM_SetStartFlag  0x02175094  thumb  ov012
 *   gUnionEmptyString1     0x021807E4  data  a4
 */
#include "../include/Obj19418.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x20];
    u8 f20[6];
    u8 f26;
    u8 pad27[0x2c - 0x27];
} Ent;

typedef struct {
    u8 pad00[0x18];
    Ent ents[4];
    u8 padc8[0x134 - 0xc8];
    u32 f134[4];
} Work;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Big;
struct Ctx;
struct L0200ED54;
struct Link;
struct Sub0200852CObj;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int GFL_NET_GetNegotiationNum(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, u32 b, u32 c);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, u32 b, u32 c);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MET_TRAINERS_GetFromSave(void *p);
extern void MET_TRAINERS_Insert(struct L0200ED54 *l, u32 val);
extern int UNION_ONESELF_HandleNetErrorExit(char *p);
extern void UNION_MSG_CloseAllWindows(void *ctx);
extern int COLOSSEUM_CheckAllEntered(u8 *p);
extern int COLOSSEUM_CheckAllTrainerCardsReceived(u8 *p);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern void COLOSSEUM_AddCommandTable(u32 p);
extern u32 COLOSSEUM_SendPlayerEntry(u32 a, u32 b);
extern int COLOSSEUM_SendTrainerCard(u32 v);
extern void UNION_COMM_AddMember(u8 *p, void *a, int b, int c);
extern void COLOSSEUM_SetStartFlag(Work *w, int v);
extern u8 gUnionEmptyString1[];

int UNION_ONESELF_ColosseumSetupMain(void *ctx, u8 *obj, int a2, u8 *state)
{
    Work *w = *(Work * *)&((struct Obj19418 *)ctx)->f355C;
    int me;
    int n;
    int i;
    int a;
    int x;

    me = GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()));
    if (w == 0)
        func_02034714((const char *)gUnionEmptyString1, (int)0, (const char *)gUnionEmptyString1);

    if (UNION_ONESELF_HandleNetErrorExit(ctx) == 1) {
        UNION_MSG_CloseAllWindows(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd, 0x14);
        (*state)++;
        break;
    case 1:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd, 0x14) == 1)
            (*state)++;
        break;
    case 2:
        COLOSSEUM_AddCommandTable((u32)ctx);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xe, 0x14);
        (*state)++;
        break;
    case 3:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xe, 0x14) == 1)
            (*state)++;
        break;
    case 4:
        if (COLOSSEUM_SendPlayerEntry((u32)(&w->ents[me]), 0) == 1)
            (*state)++;
        break;
    case 5:
        if (COLOSSEUM_CheckAllEntered((u8 *)w) == 1) {
            n = GFL_NET_GetNegotiationNum();
            for (i = 0; i < n; i++) {
                if (w->ents[i].f26 == 1) {
                    a = func_02008554((const struct Sub0200852CObj *)(&w->ents[i]));
                    UNION_COMM_AddMember(obj + 0x14, w->ents[i].f20, a,
                                  (u8)(int)func_02008550((const struct Sub0200852CObj *)(&w->ents[i])));
                }
            }
            (*state)++;
        }
        break;
    case 6:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x14);
        (*state)++;
        break;
    case 7:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x14) == 1)
            (*state)++;
        break;
    case 8:
        if (COLOSSEUM_SendTrainerCard(w->f134[me]) == 1)
            (*state)++;
        break;
    case 9:
        if (COLOSSEUM_CheckAllTrainerCardsReceived((u8 *)w) == 1)
            (*state)++;
        break;
    case 10:
        x = (int)MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)((*(int **)ctx)[3]))));
        n = GFL_NET_GetNegotiationNum();
        for (i = 0; i < n; i++) {
            if (w->ents[i].f26 == 1 && i != GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())))
                MET_TRAINERS_Insert((struct L0200ED54 *)x, (int)func_02008530((const struct Sub0200852CObj *)(&w->ents[i])));
        }
        COLOSSEUM_SetStartFlag(w, 1);
        UNION_ONESELF_SetNextPlayCategory(ctx, 0x2a);
        return 1;
    }
    return 0;
}
