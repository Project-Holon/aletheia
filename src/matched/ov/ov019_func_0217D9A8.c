/*
 * function: UNION_ONESELF_ColosseumEntryMain
 * address:  0x0217D9A8
 * packet:   pkt_ov019_0217D9A8
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
 *   func_02034714  0x02034714  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_NotifyUserEvent  0x0203D1E8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   UNION_ONESELF_CheckNetErrorExit  0x0217BB20  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   UNION_MSG_GetCategoryTableValue  0x0217F060  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_ONESELF_SetFieldBusy  0x0217BAF0  thumb  ov019
 *   UNION_ONESELF_EntryMenuAddMember  0x0217DC64  thumb  ov019
 *   UNION_ONESELF_EntryMenuRemoveMember  0x0217DC94  thumb  ov019
 *   UNION_COMMAND_SendColosseumCancel  0x02173CB4  thumb  ov012
 *   UNION_COMM_SetGameKindByStatus  0x021736E0  thumb  ov012
 *   COMM_ENTRY_MENU_Create  0x021CD48C  thumb  ov021
 *   COMM_ENTRY_MENU_Delete  0x021CD5A4  thumb  ov021
 *   COMM_ENTRY_MENU_SetCallbacks  0x021CD60C  thumb  ov021
 *   COMM_ENTRY_MENU_Main  0x021CD688  thumb  ov021
 *   gUnionEmptyString1     0x021807E4  data  a4
 */
#include "../include/Obj07386.h"

typedef unsigned char u8;

typedef struct {
    u8 f00;
    u8 pad01[0x2d - 1];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj;

typedef struct {
    u8 pad00[8];
    int f8;
} Sys;

typedef struct {
    Sys *sys;
} Ctx;

typedef struct {
    u8 pad000[0xde];
    u8 fde;
    u8 pad0df[0x168 - 0xdf];
    int f168;
    u8 pad16c[0x16e - 0x16c];
    u8 f16e;
} Work;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_GetHandleNetID(struct Link *p);
extern void func_02034714(const char *expr, unsigned int line, const char *file);
typedef unsigned int   u32;
extern u32 GFL_NET_IsParentAid(void);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GFL_NET_NotifyUserEvent(u32 unused, void *arg);
struct Link;
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int UNION_ONESELF_CheckNetErrorExit(char *p);
extern void UNION_MSG_CloseAllWindows(void *p);
extern int UNION_MSG_GetCategoryTableValue(int i);
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
extern void UNION_ONESELF_EntryMenuAddMember(u8 *base, int obj, int x);
extern void UNION_ONESELF_EntryMenuRemoveMember(u8 *base, int obj, int x);
extern int UNION_COMMAND_SendColosseumCancel(void);
extern void UNION_COMM_SetGameKindByStatus(unsigned int x);
extern int COMM_ENTRY_MENU_Create(int a, int b, int c, int d, int e, int f, int g, int h);
extern u32 COMM_ENTRY_MENU_Delete(u32 *p);
extern void COMM_ENTRY_MENU_SetCallbacks(int h, void *a, void *b, void *c);
extern u32 COMM_ENTRY_MENU_Main(u8 *p);
extern u8 gUnionEmptyString1[];

int UNION_ONESELF_ColosseumEntryMain(Ctx *ctx, Obj *obj, u8 *a2, u8 *state)
{
    Work *w = *(Work * *)&((struct Obj07386 *)ctx)->f355C;
    int r;

    GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    if (w == 0)
        func_02034714((const char *)gUnionEmptyString1, 0, (const char *)gUnionEmptyString1);

    if (UNION_ONESELF_CheckNetErrorExit((char *)ctx) == 1) {
        if (w->f168 != 0)
            COMM_ENTRY_MENU_Delete((u32 *)w->f168);
        UNION_MSG_CloseAllWindows(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        if (UNION_MSG_GetCategoryTableValue(obj->f2d) == 2) {
            w->fde = 1;
            if (GFL_NET_IsParentAid() == 1) {
                if (UNION_COMMAND_SendColosseumCancel() == 1)
                    *state = 100;
            } else {
                *state = 100;
            }
            break;
        }
        GFL_NET_SetLoginOption(0);
        if (GFL_NET_IsParentAid() == 1) {
            w->f168 = COMM_ENTRY_MENU_Create((int)GAME_DATA_GetMyStatus((void *)ctx->sys->f8), (int)a2,
                                    UNION_MSG_GetCategoryTableValue(obj->f2d),
                                    UNION_MSG_GetCategoryTableValue(obj->f2d), 0x41, 0, 0, 0);
            COMM_ENTRY_MENU_SetCallbacks(w->f168, ctx, UNION_ONESELF_EntryMenuAddMember, UNION_ONESELF_EntryMenuRemoveMember);
        } else if (obj->b1 == 0) {
            w->f168 = COMM_ENTRY_MENU_Create((int)GAME_DATA_GetMyStatus((void *)ctx->sys->f8), (int)a2,
                                    UNION_MSG_GetCategoryTableValue(obj->f2d),
                                    UNION_MSG_GetCategoryTableValue(obj->f2d), 0x41, 2, 0, 0);
        } else {
            w->f168 = COMM_ENTRY_MENU_Create((int)GAME_DATA_GetMyStatus((void *)ctx->sys->f8), (int)a2,
                                    UNION_MSG_GetCategoryTableValue(obj->f2d),
                                    UNION_MSG_GetCategoryTableValue(obj->f2d), 0x41, 3, 0, 0);
        }
        if (obj->b1 == 0) {
            UNION_COMM_SetGameKindByStatus(obj->f00);
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xc, 0x14);
        }
        (*state)++;
        break;
    case 1:
        if (obj->b1 == 0) {
            if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xc, 0x14) == 1) {
                GFL_NET_NotifyUserEvent((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 2:
        (*state)++;
        break;
    case 3:
        r = COMM_ENTRY_MENU_Main((u8 *)w->f168);
        if (r != 0) {
            w->f16e = COMM_ENTRY_MENU_Delete((u32 *)w->f168);
            w->f168 = 0;
            switch (r) {
            case 1:
                *state = 100;
                GFL_NET_SetLoginOption(1);
                break;
            case 2:
                *state = 200;
                break;
            case 3:
                *state = 200;
                break;
            case 4:
                *state = 200;
                break;
            default:
                func_02034714((const char *)gUnionEmptyString1, 0, (const char *)gUnionEmptyString1);
                break;
            }
        }
        break;
    case 4:
        break;
    case 100:
        w->fde = 1;
        UNION_ONESELF_SetNextPlayCategory((char *)ctx, 0x29);
        return 1;
    case 200:
        UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, 0x14c);
        w->fde = 2;
        (*state)++;
        break;
    case 201:
        if (UNION_MSG_CheckTalkPrintEnd((u8 *)ctx) == 1) {
            UNION_ONESELF_SetNextPlayCategory((char *)ctx, 0x32);
            UNION_ONESELF_SetFieldBusy((char *)ctx, (int)a2, 1);
            return 1;
        }
        break;
    case 300:
        w->fde = 2;
        UNION_ONESELF_SetNextPlayCategory((char *)ctx, 0x32);
        UNION_ONESELF_SetFieldBusy((char *)ctx, (int)a2, 1);
        return 1;
    }
    return 0;
}
