/*
 * function: UNION_ONESELF_ColosseumBattleMain
 * address:  0x0217E5A0
 * packet:   pkt_ov019_0217E5A0
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
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_MAIN_RequestScene  0x0217422C  thumb  ov012
 *   UNION_MAIN_IsScenePending  0x02174268  thumb  ov012
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021807E8     0x021807E8  data  a4
 */
#include "../include/Obj03570.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
} Sys;

typedef struct {
    int f68;
    int f6c;
    u8 f70;
} Ent;

typedef struct {
    int f0;
    void *f4;
    int f8;
    int fc;
    int f10;
    int f14;
    u8 pad18[0x34 - 0x18];
    int f34;
    u8 pad38[0x60 - 0x38];
    u16 f60;
    u8 pad62[0x64 - 0x62];
    int f64;
    Ent ent[3];
    int f8c;
    int f90;
    u8 pad94[0xc0 - 0x94];
    int *fc0;
} Req;

struct Sub0200852CObj;
int UNION_ONESELF_CheckNetErrorExit(char *p);
typedef unsigned int   u32;
void UNION_MSG_CloseAllWindows(void *p);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
void UNION_MAIN_RequestScene(u8 *p, int a, int b);
int UNION_MAIN_IsScenePending(u8 *w);
struct Big;
struct BigObj;
struct Link;
struct Sub02008700Obj;
void *GAME_DATA_GetMyItem(const struct BigObj *p);
void *GAME_DATA_GetSaveControl(struct Big *p);
struct Sub02008700Obj *func_0200873C(void *sys);
const void *func_020084F4(const void *p);
u8 func_02008550(const struct Sub0200852CObj *obj);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
u32 GFL_NET_GetHandleNetID(struct Link *p);
int GFL_NET_GetNegotiationNum(void);
struct Link;
void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, unsigned int b, unsigned int c);
unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, unsigned int b, unsigned int c);
void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
u32 func_020307B0(void *p);
extern int d_021807E8[];

int UNION_ONESELF_ColosseumBattleMain(u8 *w, u8 *obj, u8 *a2, u8 *state)
{
    u8 *p;
    int idx;
    int msg;
    Req *q;
    int i;
    int cnt;
    int k;

    p = *(u8 * *)&((struct Obj03570 *)w)->f355C;
    idx = GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()));
    if (*state < 3 && UNION_ONESELF_CheckNetErrorExit((char *)w) == 1) {
        UNION_MSG_CloseAllWindows(w);
        return 1;
    }
    switch (*state) {
    case 0:
        if (UNION_MSG_CheckTalkPrintEnd(w) != 1)
            break;
        switch (obj[0x2d]) {
        default:
            msg = 0x117;
            break;
        case 6:
        case 7:
        case 22:
        case 23:
            msg = 0x118;
            break;
        case 20:
        case 21:
            msg = 0x11b;
            break;
        case 10:
        case 11:
        case 18:
        case 19:
            msg = 0x119;
            break;
        case 14:
        case 15:
            msg = 0x11a;
            break;
        }
        UNION_MSG_SetupPrintTalkMsg(w, a2, msg);
        (*state)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(w) == 1) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 0x14);
            (*state)++;
        }
        break;
    case 2:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 0x14) == 1) {
            UNION_MSG_CloseAllWindows(w);
            (*state)++;
        }
        break;
    case 3:
        q = func_02030734(0x41, 0xc4, 1, (const char *)d_021807E8, 0x10c4);
        q->f0 = ((int *)(p + 0x148))[idx];
        q->f4 = GAME_DATA_GetMyItem((const struct BigObj *)((*(Sys * *)&((struct Obj03570 *)w)->f0)->f8));
        q->fc = (int)func_0200873C(GAME_DATA_GetSaveControl((struct Big *)((*(Sys * *)&((struct Obj03570 *)w)->f0)->f8)));
        q->f34 = 0x1a;
        q->f14 = ((struct Obj03570 *)w)->f352C;
        q->fc0 = func_02030734(0x41, 0x70, 1, (const char *)d_021807E8, 0x10ce);
        cnt = 0;
        for (i = 0; i < GFL_NET_GetNegotiationNum(); i++) {
            if (i == idx)
                continue;
            if ((p[idx + 0x15c] & 1) == (p[i + 0x15c] & 1))
                k = 0;
            else
                k = ++cnt;
            q->ent[k].f68 = ((int *)(p + 0x148))[i];
            q->ent[k].f6c = (int)func_020084F4(p + 0x18 + i * 0x2c);
            q->ent[k].f70 = func_02008550((const struct Sub0200852CObj *)(p + 0x18 + i * 0x2c));
        }
        switch (obj[0x2d]) {
        case 20:
        case 21:
        case 22:
        case 23:
            q->f64 = 2;
            break;
        default:
            q->f64 = 1;
            break;
        }
        q->f8c = 1;
        q->f90 = 0;
        q->f60 = 0;
        *(Req * *)&((struct Obj03570 *)w)->f3558 = q;
        UNION_MAIN_RequestScene(w, 0x1a, (int)q);
        (*state)++;
        break;
    case 4:
        if (UNION_MAIN_IsScenePending(w) == 1)
            break;
        func_020307B0((*(Req * *)&((struct Obj03570 *)w)->f3558)->fc0);
        func_020307B0(*(Req * *)&((struct Obj03570 *)w)->f3558);
        *(Req * *)&((struct Obj03570 *)w)->f3558 = 0;
        UNION_ONESELF_SetNextPlayCategory((char *)w, 0x2c);
        return 1;
    }
    return 0;
}
