/*
 * function: EVENT_MAPCHANGE_ChangeFieldEvent
 * address:  0x021841C0
 * packet:   pkt_ov020_021841C0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two spellings are load-bearing.  The u8 range check on GAME_COMM_GetKind's
 * result is `adds r0, #0xff; lsls/lsrs #0x18; cmp #1; bhi`: written
 * `(u8)(v - 1) <= 1` it compiles to `subs r0, r0, #1` (one byte out), and as
 * `switch (v) { case 1: case 2: }` it grows by 4 bytes with two compares;
 * only `(u8)(v + 0xff) <= 1` gives the add.  The dead `str r2, [sp, #0xc]`
 * after `adds r2, #0x14` is `a += 0x14;` on the spilled local before the
 * FORMCHANGE_RevertShayminAtNight call.  func_021882A0/02188318/021883CC are ov230's decrypted
 * code (ov230d token); each gets the range EVENT_MAPCHANGE_StartMarker to one of this
 * overlay's end markers.  Leaves filed for this function: ov010 0x02164454,
 * 0x0216445C, 0x02164464 and ov020 0x0218608C.
 *
 * symbols:
 *   ov230_id       0x000000E6  data
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_SwapSeasonDispFlag  0x0201447C  thumb
 *   FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent  0x02014554  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   ZONEDATA_IsNoGameEventZone  0x02013D34  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   EVENT_MAPCHANGE_StartMarker  0x02183B60  thumb  ov020
 *   EVENT_MAPCHANGE_AllocWorkBufferA  0x0218604C  thumb  ov020
 *   EVENT_MAPCHANGE_AllocWorkBufferB  0x0218606C  thumb  ov020
 *   EVENT_MAPCHANGE_EndMarker  0x0218608C  thumb  ov020
 *   func_021882A0  0x021882A0  arm  ov230d
 *   func_02188318  0x02188318  arm  ov230d
 *   func_021883CC  0x021883CC  arm  ov230d
 *   EVENT_MAPCHANGE_DeleteAllMmdlOfSystem  0x02185B70  thumb  ov020
 *   COMM_PLAYER_SUPPORT_SetSeason  0x0202E8CC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   FORMCHANGE_UpdateSeasonForms  0x0216AAE4  thumb  ov010
 *   FORMCHANGE_RevertShayminAtNight  0x0216A358  thumb  ov010
 *   EVENT_MAPCHANGE_UpdateFieldStateForZone  0x02185A68  thumb  ov020
 *   EVENT_MAPCHANGE_ApplyLocation  0x021857C0  thumb  ov020
 *   GAME_BEACON_SetZone  0x0202735C  thumb
 *   FIELD_MAP_CHANGE_ResetGimmickStateCase1  0x02164454  thumb  ov010
 *   FIELD_MAP_CHANGE_ResetGimmickStateCase3  0x0216445C  thumb  ov010
 *   FIELD_MAP_CHANGE_ResetGimmickStateCase2  0x02164464  thumb  ov010
 *   INTRUDE_COMM_ClearHoldMode  0x0215874C  thumb  ov010
 *   FIELD_STATUS_CreateFieldOpenNoNotifyEvent  0x020145FC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitSettledTask  0x02029C64  thumb
 */
#include "../include/Obj01649.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 ov230_id[];
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef signed int     s32;
struct Big;
struct BigObj;
struct Comm;
struct Evt;
struct Sub02008AECSession;
struct Sub02014444Obj;
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern u8 FIELD_STATUS_SwapSeasonDispFlag(struct Sub02014444Obj *o, u8 v);
extern int FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(int a, int b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int func_02034AC4(int id);
extern void func_02034A5C(int handle);
extern u32 ZONEDATA_IsNoGameEventZone(u32 id);
extern u32 GAME_COMM_GetKind(void *obj);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern int EVENT_MAPCHANGE_StartMarker(int f);
extern void *EVENT_MAPCHANGE_AllocWorkBufferA(void);
extern void *EVENT_MAPCHANGE_AllocWorkBufferB(void);
extern void EVENT_MAPCHANGE_EndMarker(void);
extern u32 func_021882A0(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188318(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_021883CC(void (*a)(void), void (*b)(void), u32 c);
extern void EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(void *p);
extern u8 COMM_PLAYER_SUPPORT_SetSeason(s32 a, s32 b);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void FORMCHANGE_UpdateSeasonForms(void *sys, void *party, int season);
extern int FORMCHANGE_RevertShayminAtNight(int a, int b, u32 *p, int c);
extern void EVENT_MAPCHANGE_UpdateFieldStateForZone(void *a, int b);
extern void EVENT_MAPCHANGE_ApplyLocation(void *a, int b);
extern void GAME_BEACON_SetZone(u32 a0, u32 a1);
extern int FIELD_MAP_CHANGE_ResetGimmickStateCase1(int a, int b);
extern int FIELD_MAP_CHANGE_ResetGimmickStateCase3(int a, int b);
extern int FIELD_MAP_CHANGE_ResetGimmickStateCase2(int a, int b);
extern void INTRUDE_COMM_ClearHoldMode(void *p);
extern int FIELD_STATUS_CreateFieldOpenNoNotifyEvent(int a);
extern void *FIELD_SOUND_SYSTEM_StartWaitSettledTask(void *a);

int EVENT_MAPCHANGE_ChangeFieldEvent(int ctx, int *state, u8 **pp)
{
    u8 *p;
    int x;
    int y;
    int z;
    int w;
    void *c;
    int b;
    int a;

    p = *pp;
    z = ((struct Obj01649 *)p)->f8;
    x = ((struct Obj01649 *)p)->f0;
    y = ((struct Obj01649 *)p)->f4;
    w = GAMESYSTEM_GetGameComm((const struct Ctx *)x);

    switch (*state) {
    case 0:
        FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys((const struct BigObj *)y), 2);
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(x, z));
        (*state)++;
        break;
    case 1:
        func_02034AC4((int)ov230_id);
        if (ZONEDATA_IsNoGameEventZone(((struct Obj01649 *)p)->f14) == 1 && (u8)(GAME_COMM_GetKind((void *)w) + 0xff) <= 1) {
            GAME_COMM_RequestExitNoCallback((struct Comm *)w);
            *state = 2;
        } else {
            *state = 3;
        }
        break;
    case 2:
        if (GAME_COMM_GetKind((void *)w) == 0) {
            *state = 3;
        }
        break;
    case 3:
        func_021882A0((void (*)(void))EVENT_MAPCHANGE_StartMarker, (void (*)(void))EVENT_MAPCHANGE_AllocWorkBufferA, 0);
        EVENT_MAPCHANGE_DeleteAllMmdlOfSystem((void *)x);
        if (((struct Obj01649 *)p)->f40 != 0 && ((struct Obj01649 *)p)->f44 != 0) {
            COMM_PLAYER_SUPPORT_SetSeason(y, ((struct Obj01649 *)p)->f4A);
            a = (int)func_02008B14(GAME_DATA_GetSaveControl((struct Big *)y));
            b = GAME_DATA_GetSeason((const struct BigObj *)y);
            c = GAME_DATA_GetMyParty((void *)y);
            FORMCHANGE_UpdateSeasonForms((void *)y, c, b);
            a += 0x14;
            FORMCHANGE_RevertShayminAtNight(y, (int)c, (u32 *)a, b);
        }
        func_02188318((void (*)(void))EVENT_MAPCHANGE_StartMarker, (void (*)(void))EVENT_MAPCHANGE_AllocWorkBufferB, 0);
        EVENT_MAPCHANGE_UpdateFieldStateForZone((void *)x, ((struct Obj01649 *)p)->f14);
        EVENT_MAPCHANGE_ApplyLocation((void *)x, (int)(p + 0x10));
        if (((struct Obj01649 *)p)->f30 != 4) {
            GAME_BEACON_SetZone(((struct Obj01649 *)p)->f14, y);
        }
        func_021883CC((void (*)(void))EVENT_MAPCHANGE_StartMarker, EVENT_MAPCHANGE_EndMarker, 0);
        switch (((struct Obj01649 *)p)->f30) {
        case 1:
            FIELD_MAP_CHANGE_ResetGimmickStateCase1(y, ((struct Obj01649 *)p)->f14);
            break;
        case 2:
            FIELD_MAP_CHANGE_ResetGimmickStateCase2(y, ((struct Obj01649 *)p)->f14);
            break;
        case 3:
            FIELD_MAP_CHANGE_ResetGimmickStateCase3(y, ((struct Obj01649 *)p)->f14);
            break;
        }
        func_02034A5C((int)ov230_id);
        INTRUDE_COMM_ClearHoldMode((void *)w);
        (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)FIELD_STATUS_CreateFieldOpenNoNotifyEvent(x));
        (*state)++;
        break;
    case 5:
        GAME_EVENT_CallEvent((struct Evt *)ctx, FIELD_SOUND_SYSTEM_StartWaitSettledTask((void *)x));
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}
