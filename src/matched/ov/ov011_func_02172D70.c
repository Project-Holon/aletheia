/*
 * function: INTRUDE_COMM_MainStep
 * address:  0x02172D70
 * packet:   pkt_ov011_02172D70
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline  0x02161F74  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   INTRUDE_COMM_RefreshBeacon  0x021735FC  thumb  ov011
 *   INTRUDE_COMM_AgeFoundList  0x02173658  thumb  ov011
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GAME_DATA_SetOwnNetId  0x02012B64  thumb
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   INTRUDE_COMM_SetIntrudeId  0x02175710  thumb  ov011
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   INTRUDE_COMM_HasUnlockFlags  0x02158590  thumb  ov010
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *   EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid  0x02161F54  thumb  ov010
 *   INTRUDE_COMM_RefreshSelfRecord  0x02174E3C  thumb  ov011
 *   INTRUDE_COMM_ApplyPlayerBeacon  0x02174EAC  thumb  ov011
 *   INTRUDE_COMM_SendStatusRecord  0x02173828  thumb  ov011
 *   GF_STANDARD_GetSecondsOfDay  0x0203F4FC  arm
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAMESYSTEM_IsFieldMapExist  0x02012114  thumb
 *   INTRUDE_COMM_UpdateRunning  0x02174978  thumb  ov011
 *   INTRUDE_COMM_IsResultConfirmed  0x02175EB8  thumb  ov011
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb  ov011
 *   INTRUDE_COMM_SendTimeoutWarning  0x021739E0  thumb  ov011
 *   INTRUDE_COMM_GetLeaveFlag  0x02175ED8  thumb  ov011
 *   INTRUDE_COMM_HasConnectedPeers  0x02175628  thumb  ov011
 *
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =MI_CpuCopy8; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Param {
    void *field00;
    void *field04;
} Param;

typedef struct Work {
    u32   field000;
    void *field004;         /* 0x004 */
    u8    pad008[0x8a - 0x8];
    u8    pad08a : 6;       /* 0x08A */
    u8    mode : 2;
    u8    kind : 6;         /* 0x08B */
    u8    flag08b : 1;
    u8    pad08c[0x8fa - 0x8c];
    u8    field8fa;         /* 0x8FA */
    u8    field8fb;         /* 0x8FB */
    u8    pad8fc;
    u8    step;             /* 0x8FD */
    u8    pad8fe[0x90a - 0x8fe];
    u16   idle;             /* 0x90A */
    u8    pad90c[2];
    s16   timer;            /* 0x90E */
    u8    pad910[0x93f - 0x910];
    u8    bit0 : 1;         /* 0x93F */
    u8    quit : 1;
    u8    bit2 : 1;
    u8    bit3 : 1;
    u8    bit4 : 1;
    u8    bit5 : 1;
    u8    lock : 1;
    u32   stamp : 31;       /* 0x940 */
    u32   warned : 1;
} Work;

struct BigObj;
extern u32 GAME_COMM_GetGameData(void *obj);
extern u8 *GAME_DATA_GetSecondUnionInfo(void *p);
extern void EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline(int a0, int a1, int a2);
struct Comm;
struct Rec44;
struct Sub;
struct Sub24;
extern u32 func_0200FB24(void);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern u32   func_02035390(void);
extern int func_020353B0(void);
extern void  INTRUDE_COMM_RefreshBeacon(void *sv, void *p);
extern void INTRUDE_COMM_AgeFoundList(u8 *o);
extern int   GFL_NET_SYSTEM_GetConnectNum(void);
extern void GFL_NET_SetLoginOption(u8 a0);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void  GAME_DATA_SetOwnNetId(void *sv, u32 a);
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void  MYSTATUS_Copy(void *a, void *b);
extern void INTRUDE_COMM_SetIntrudeId(u8 *o, u32 v);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern int   INTRUDE_COMM_HasUnlockFlags(void *sv);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);
extern int EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid(int a0);
extern void INTRUDE_COMM_RefreshSelfRecord(u8 *p);
extern void INTRUDE_COMM_ApplyPlayerBeacon(u8 *p, int idx, u8 *q);
extern int INTRUDE_COMM_SendStatusRecord(char *p);
extern u32 GF_STANDARD_GetSecondsOfDay(void);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
struct Ctx;
extern u32   GAMESYSTEM_IsFieldMapExist(const struct Ctx *p);
extern void INTRUDE_COMM_UpdateRunning(u8 *s);
extern int   INTRUDE_COMM_IsResultConfirmed(void *p);
extern u32 GFL_NET_IsParentAid(void);
extern int INTRUDE_COMM_IsSessionActive(u8 *p);
extern int   INTRUDE_COMM_SendTimeoutWarning(void);
extern int INTRUDE_COMM_GetLeaveFlag(struct Sub *s);
extern int   INTRUDE_COMM_HasConnectedPeers(void);

void INTRUDE_COMM_MainStep(int *state, Param *p, Work *w)
{
    void *sv;
    void *mon;
    s32 base;
    s32 now;

    sv = (void *)GAME_COMM_GetGameData(p->field04);
    if (w != 0 && w->step >= 7) {
        EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline((int)((u8 *)w + 0x35c), (int)GAME_DATA_GetSecondUnionInfo(sv), w->field8fb);
    }
    if (func_0200FB24() != 0 || w->quit == 1) {
        if (w->lock) {
            return;
        }
        w->step = 11;
        w->quit = 1;
        GAME_COMM_RequestExitNoCallback(w->field004);
        return;
    }
    if (func_02035390() == 1 && func_020353B0() == 1 && w->lock == 0) {
        GAME_COMM_RequestExitNoCallback(w->field004);
        return;
    }
    if (w->step == 7 && w->field8fa == 1) {
        GAME_COMM_RequestExitNoCallback(w->field004);
        return;
    }
    INTRUDE_COMM_RefreshBeacon(sv, (u8 *)w + 0xc);
    INTRUDE_COMM_AgeFoundList((u8 *)w);
    switch (*state) {
    case 0:
        if (GFL_NET_SYSTEM_GetConnectNum() > 1 && w->step < 5) {
            w->step = 5;
            GFL_NET_SetLoginOption(1);
        }
        if (w->step == 5) {
            if (GFL_NET_HANDLE_CheckNegotiation() == 1) {
                GAME_DATA_SetOwnNetId(sv, GFL_NET_SYSTEM_GetCurrentAid());
                mon = GAME_DATA_GetMyStatusPlayer(sv, GFL_NET_SYSTEM_GetCurrentAid());
                MYSTATUS_Copy(GAME_DATA_GetMyStatus(sv), mon);
                INTRUDE_COMM_SetIntrudeId((u8 *)w, GFL_NET_SYSTEM_GetCurrentAid());
                w->kind = 0x15;
                w->mode = GAME_DATA_GetSeason(sv);
                if (INTRUDE_COMM_HasUnlockFlags(sv) == 0) {
                    w->flag08b = 1;
                }
                GFL_NET_SetLoginOption(1);
                (*state)++;
            }
        } else if (w->step == 4) {
            w->timer++;
            if (w->timer > 600) {
                w->timer = 0;
                GAME_COMM_RequestExitNoCallback(w->field004);
                return;
            }
        }
        break;
    case 1:
        if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)((u32)GFL_NET_HANDLE_GetCurrentHandle())) == 1) {
            w->step = 6;
            (*state)++;
        }
        break;
    case 2:
        EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid((int)((u8 *)w + 0x35c));
        INTRUDE_COMM_RefreshSelfRecord((u8 *)w);
        INTRUDE_COMM_ApplyPlayerBeacon((u8 *)w, GFL_NET_SYSTEM_GetCurrentAid(), (u8 *)w + 0x160);
        (*state)++;
        break;
    case 3:
        if (INTRUDE_COMM_SendStatusRecord((char *)w) == 1) {
            w->step = 7;
            w->stamp = GF_STANDARD_GetSecondsOfDay();
            (*state)++;
        }
        break;
    case 4:
        if (GAME_DATA_GetIntrudeCount(sv) == 0 && w->mode != GAME_DATA_GetSeason(sv)
            && GAMESYSTEM_IsFieldMapExist(p->field00) == 1) {
            GAME_COMM_RequestExitNoCallback(w->field004);
            return;
        }
        INTRUDE_COMM_UpdateRunning((u8 *)w);
        if (INTRUDE_COMM_IsResultConfirmed((u8 *)w + 0x1ac) == 1) {
            GAME_COMM_RequestExitNoCallback(w->field004);
            return;
        }
        if (GFL_NET_IsParentAid() == 1 && INTRUDE_COMM_IsSessionActive((u8 *)w + 0x1ac) == 0) {
            base = w->stamp;
            now = GF_STANDARD_GetSecondsOfDay();
            if (now < base) {
                now += 86399;
            }
            now -= base;
            if (now >= 180) {
                GAME_COMM_RequestExitNoCallback(w->field004);
                return;
            }
            if (now > 170 && w->warned == 0 && INTRUDE_COMM_SendTimeoutWarning() == 1) {
                w->warned = 1;
            }
        } else if (w->lock == 0 && GFL_NET_IsParentAid() == 1
                   && INTRUDE_COMM_GetLeaveFlag((struct Sub *)((u8 *)w + 0x1ac)) == 1) {
            GAME_COMM_RequestExitNoCallback(w->field004);
        } else {
            w->warned = 0;
        }
        if (INTRUDE_COMM_HasConnectedPeers() == 0) {
            w->idle++;
            if (w->idle > 180) {
                GAME_COMM_RequestExitNoCallback(w->field004);
                return;
            }
        } else {
            w->idle = 0;
        }
        break;
    }
}
