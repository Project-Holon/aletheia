/*
 * function: FIELD_EVENT_CHECK_CheckCommEvents
 * address:  0x0218A0E4
 * packet:   pkt_ov021_0218A0E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   FIELD_EVENT_CHECK_InitInput  0x0218A4E0  thumb  ov021
 *   func_0200FB24  0x0200FB24  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   EVENT_COMM_ERROR_Create  0x021C06CC  thumb  ov021
 *   EVENT_MAPCHANGE_CreateSpecialLocationEvent  0x021850FC  thumb  ov020
 *   UNION_MAIN_GetFieldRequest  0x0217391C  thumb  ov012
 *   UNION_MAIN_IsExitStarted  0x02173928  thumb  ov012
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   FIELD_EVENT_CHECK_CheckPosEventForDir  0x0218A784  thumb  ov021
 *   UNION_ONESELF_TryStartSubEvent  0x0217B80C  thumb  ov019
 *   UNION_ONESELF_GetFieldTalkEvent  0x0217B83C  thumb  ov019
 *   UNION_MAIN_IsIdle  0x0217394C  thumb  ov012
 *   FIELD_EVENT_CHECK_SearchGridFrontMmdl  0x0218B4B0  thumb  ov021
 *   FLDMMDL_GetEventId  0x0216D5B8  thumb  ov010
 *   SCRIPT_SYS_IsZoneScriptId  0x02158D90  thumb  ov010
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   UNION_CHARA_IsUnionObjId  0x0217AF38  thumb  ov019
 *   FIELD_PLAYER_ResetMoveWork  0x021A2F6C  thumb  ov021
 *   func_0219F01C  0x0219F01C  thumb  ov021
 *   GAMESYSTEM_GetFieldMapState  0x0201212C  thumb
 *   SCRCMD_NETWORK_CreateBattleRecordLinkEventForZone  0x0215FCE0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct FieldInput {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    u32 f18;
    u32 f1C;
    u32 f20;
    u16 f24;
    u16 f26;
    u32 trg;
    u32 cont;
    u16 dir;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
};

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 GAME_COMM_GetWork(void *obj);
struct Obj00020;
extern void FIELD_EVENT_CHECK_InitInput(struct FieldInput *p, void *sys, struct Obj00020 *pos);
struct Comm;
struct Ctx;
extern u32 func_0200FB24(void);
extern u32 WIPE_SYS_EndCheck(void);
extern int EVENT_COMM_ERROR_Create(void *sys, u8 *pos);
extern void *EVENT_MAPCHANGE_CreateSpecialLocationEvent(void *p, u8 *pos);
extern int UNION_MAIN_GetFieldRequest(u8 *p);
extern int UNION_MAIN_IsExitStarted(u8 *p);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
struct Ctx784;
struct FieldCtx;
extern int FIELD_EVENT_CHECK_CheckPosEventForDir(struct Ctx784 *c, int a);
extern int UNION_ONESELF_TryStartSubEvent(int a, int b);
extern int UNION_ONESELF_GetFieldTalkEvent(void *sys, void *pos);
extern int UNION_MAIN_IsIdle(const struct Ctx *p);
extern int FIELD_EVENT_CHECK_SearchGridFrontMmdl(struct FieldCtx *p, u8 *pos);
extern u32 FLDMMDL_GetEventId(void *p);
extern int SCRIPT_SYS_IsZoneScriptId(u16 v);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetObjId(void *p);
extern int UNION_CHARA_IsUnionObjId(u16 a);
extern void FIELD_PLAYER_ResetMoveWork(u32 *p);
extern int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
extern u8 GAMESYSTEM_GetFieldMapState(const struct Ctx *p);
extern int SCRCMD_NETWORK_CreateBattleRecordLinkEventForZone(int a, int b, unsigned short c);

int FIELD_EVENT_CHECK_CheckCommEvents(void *sys, struct Obj00020 *pos)
{
    struct FieldInput in;
    void *a;
    void *ev;
    int r;
    int obj;
    u32 k;
    void *m;

    a = (void *)GAMESYSTEM_GetGameComm(sys);
    ev = (void *)GAME_COMM_GetWork(a);
    FIELD_EVENT_CHECK_InitInput(&in, sys, pos);
    if (ev == 0) {
        if (func_0200FB24() != 0) {
            if (WIPE_SYS_EndCheck() != 0)
                return EVENT_COMM_ERROR_Create(sys, (u8 *)pos);
            return 0;
        }
        return (int)EVENT_MAPCHANGE_CreateSpecialLocationEvent(sys, (u8 *)pos);
    }
    if (UNION_MAIN_GetFieldRequest(ev) == 1) {
        if (UNION_MAIN_IsExitStarted(ev) == 0)
            GAME_COMM_RequestExitNoCallback(a);
        return 0;
    }
    if (in.b2 && (r = FIELD_EVENT_CHECK_CheckPosEventForDir((struct Ctx784 *)(&in), 9)) != 0)
        return r;
    if ((r = UNION_ONESELF_TryStartSubEvent((int)sys, (int)pos)) != 0)
        return r;
    if (in.b0 && (r = UNION_ONESELF_GetFieldTalkEvent(sys, pos)) != 0)
        return r;
    if (in.b0 && UNION_MAIN_IsIdle(sys) == 1) {
        obj = FIELD_EVENT_CHECK_SearchGridFrontMmdl((struct FieldCtx *)(&in), (u8 *)pos);
        if (obj != 0) {
            k = FLDMMDL_GetEventId((void *)obj);
            if (SCRIPT_SYS_IsZoneScriptId(k) == 1) {
                m = FIELD_PLAYER_GetMmdl((u8 *)in.f18);
                if (UNION_CHARA_IsUnionObjId(FLDMMDL_GetObjId((void *)obj)) == 0) {
                    FIELD_PLAYER_ResetMoveWork((u32 *)in.f18);
                    return func_0219F01C((u32)sys, (u32)pos, k, (u32)m, obj, in.f0);
                }
            }
        }
    }
    if (GAMESYSTEM_GetFieldMapState(sys) == 1 && WIPE_SYS_EndCheck() != 0)
        return EVENT_COMM_ERROR_Create(sys, (u8 *)pos);
    if (UNION_MAIN_IsIdle(sys) == 0)
        return 0;
    if (in.b1 && WIPE_SYS_EndCheck() != 0)
        return SCRCMD_NETWORK_CreateBattleRecordLinkEventForZone((int)sys, (int)pos, in.f0);
    return 0;
}
