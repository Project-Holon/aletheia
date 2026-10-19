/*
 * function: UNION_ONESELF_TradeMain
 * address:  0x0217D18C
 * packet:   pkt_ov019_0217D18C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_HandleNetError  0x0217BB04  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MET_TRAINERS_GetFromSave  0x0200ED48  thumb
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   MET_TRAINERS_Insert  0x0200ED54  thumb
 *   func_02030734  0x02030734  arm
 *   POKEPARTY_Create  0x0201A920  thumb
 *   UNION_SCENE_RequestScene  0x0217422C  thumb  ov012
 *   UNION_SCENE_IsScenePending  0x02174268  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   d_021807E8     0x021807E8  data  a4
 */
#include "../include/Obj07385.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f00;
    int f04;
    u16 f08;
    u8 f0a;
    u8 f0b;
    int f0c;
    int f10;
} Rec14;

typedef struct {
    u8 pad00[8];
    int f08;
    u8 pad0c[0x14 - 0x0c];
    int f14;
    int pad18;
    int f1c;
    Rec14 *f20;
} Rec30;

extern int UNION_ONESELF_HandleNetError(char *p);
typedef unsigned int   u32;
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
struct Big;
struct Ctx;
struct L0200ED54;
struct Party;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MET_TRAINERS_GetFromSave(void *p);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MET_TRAINERS_Insert(struct L0200ED54 *l, u32 val);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void UNION_SCENE_RequestScene(u8 *p, int a, int b);
extern int UNION_SCENE_IsScenePending(u8 *a);
extern u32 func_020307B0(void *p);
extern u32 GFL_NET_IsParentAid(void);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern u8 d_021807E8[];

int UNION_ONESELF_TradeMain(u8 *a, int b, u8 *c, u8 *d)
{
    int x, y;
    Rec30 *p;
    Rec14 *q;
    if (*d != 4 && UNION_ONESELF_HandleNetError((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        UNION_MSG_SetupPrintTalkMsg(a, c, 0x26);
        (*d)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(a) == 1) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 6, 0x14);
            (*d)++;
        }
        break;
    case 2:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 6, 0x14) == 1) {
            x = (int)GAMESYSTEM_GetGameData((const struct Ctx *)((*(int **)a)[3]));
            y = (int)MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)x));
            MET_TRAINERS_Insert((struct L0200ED54 *)y, func_02008530((const struct Sub0200852CObj *)GAME_DATA_GetMyStatusPlayer((struct Sub24 *)x, GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())) ^ 1)));
            (*d)++;
        }
        break;
    case 3:
        p = func_02030734(0x41, 0x30, 1, (const char *)d_021807E8, 0xA54);
        p->f14 = (int)GAMESYSTEM_GetGameData((const struct Ctx *)((*(int **)a)[3]));
        p->f1c = (int)POKEPARTY_Create(0x41);
        q = func_02030734(4, 0x14, 0, (const char *)d_021807E8, 0xA5B);
        q->f00 = p->f14;
        q->f04 = p->f1c;
        q->f08 = 0;
        q->f0a = 0;
        q->f0b = 0;
        q->f0c = 1;
        q->f10 = 0;
        p->f20 = q;
        p->f08 = 0;
        *(Rec30 * *)&((struct Obj07385 *)a)->f3558 = p;
        UNION_SCENE_RequestScene(a, 2, (int)p);
        (*d)++;
        break;
    case 4:
        if (UNION_SCENE_IsScenePending(a) == 0) {
            p = *(Rec30 * *)&((struct Obj07385 *)a)->f3558;
            func_020307B0(p->f20);
            func_020307B0((void *)p->f1c);
            func_020307B0(*(Rec30 * *)&((struct Obj07385 *)a)->f3558);
            *(Rec30 * *)&((struct Obj07385 *)a)->f3558 = 0;
            (*d)++;
        }
        break;
    case 5:
        UNION_MSG_SetupPrintTalkMsg(a, c, 0x10);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 7, 0x14);
        (*d)++;
        break;
    case 6:
        if (UNION_MSG_CheckTalkPrintEnd(a) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 7, 0x14) == 1) {
            if (GFL_NET_IsParentAid() == 1)
                UNION_ONESELF_SetNextPlayCategory((char *)a, 7);
            else
                UNION_ONESELF_SetNextPlayCategory((char *)a, 9);
            return 1;
        }
        break;
    }
    return 0;
}
