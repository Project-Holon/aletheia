/*
 * function: FIELD_EVENT_CHECK_CheckGridEvents
 * address:  0x02189BD0
 * packet:   pkt_ov021_02189BD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Root of the field input tree: builds the FieldInput record on the stack
 * and runs the talk / step / menu / surf / script checks in order,
 * returning the first non-zero result.  The u16 local at sp+0x28 is the
 * out slot of FIELD_GetPlayerAreaZoneId; its address doubles as the base for the
 * in.f0 / in.f10 loads, which is why `add r1, sp, #0x28` sits above the
 * beq after the INTRUDE_FindOfferSlotAt test.
 *
 * symbols:
 *   FIELD_EVENT_CHECK_InitInput  0x0218A4E0  thumb
 *   FIELD_EVENT_CHECK_StartPendingScript  0x0218A738  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   PLEASURE_BOAT_Update  0x021C868C  thumb
 *   EVENT_TRAINER_EYE_Check  0x021AE0CC  thumb
 *   FIELD_EVENT_CHECK_AddStepRecord  0x0218A728  thumb
 *   FIELD_EVENT_CHECK_CheckPosEventAtPlayer  0x0218A76C  thumb
 *   FIELD_EVENT_CHECK_CheckGridConnect  0x0218ACD0  thumb
 *   FIELD_EVENT_CHECK_CheckTileMoveTask  0x0218AD28  thumb
 *   FIELD_EVENT_CHECK_CheckStepEvents  0x0218A9B0  thumb
 *   FIELD_EVENT_CHECK_CheckPosEventFacing  0x0218A7F0  thumb
 *   FIELD_EVENT_CHECK_CheckPosEventHeldDir  0x0218A824  thumb
 *   FIELD_EVENT_CHECK_CheckIntrudeEdge  0x0218A878  thumb
 *   FIELD_EVENT_CHECK_CheckWildEncount  0x0218B208  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   FIELD_PLAYER_TryPushBoulder  0x021A2F20  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   INTRUDE_FIELD_IsCommAllowed  0x0217BFD8  thumb  ov018
 *   INTRUDE_SUBDISP_CreateDisconnectEvent  0x0217CA84  thumb  ov018
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   INTRUDE_FIELD_IsStartRequested  0x0217C070  thumb  ov018
 *   INTRUDE_FIELD_CreateNoticeEvent  0x0217B810  thumb  ov018
 *   INTRUDE_COMM_ConsumeAreaNoticeSeen  0x0217689C  thumb  ov011
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 *   FIELD_INTRUDE_EVENT_StartSymbolEntry  0x0216B3A8  thumb  ov010
 *   INTRUDE_COMM_GetActiveRequestTarget  0x021754B4  thumb  ov011
 *   FIELD_PLAYER_ResetMoveWork  0x021A2F6C  thumb
 *   EVENT_COMM_COMMON_CreateTalkedStartEvent  0x0217FC6C  thumb  ov018
 *   INTRUDE_FIELD_TryStartOfferEvent  0x0217BDE0  thumb  ov018
 *   INTRUDE_FIELD_FindRemotePlayerAhead  0x0217AFC4  thumb  ov018
 *   EVENT_COMM_COMMON_CreateTalkStartEvent  0x0217FB5C  thumb  ov018
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FIELD_EVENT_CHECK_SearchGridFrontMmdl  0x0218B4B0  thumb
 *   FLDMMDL_GetEventId  0x0216D5B8  thumb  ov010
 *   SCRIPT_SYS_IsZoneScriptId  0x02158D90  thumb  ov010
 *   FIELD_RAIL_LOADER_CreateScriptEvent  0x0219F01C  thumb
 *   EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk  0x02162A54  thumb  ov010
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   FIELD_EVENT_CHECK_GetFrontTileMessage  0x0218B56C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   INTRUDE_FindOfferSlotAt  0x021CFAC0  thumb
 *   INTRUDE_StartOfferEvent  0x021CFC14  thumb
 *   FIELD_GetPlayerAreaZoneId  0x021CD440  thumb
 *   ZONEDATA_IsZoneInTableDFB8  0x02013FFC  thumb
 *   EVENTDATA_SYSTEM_GetAutoPosEventScriptId  0x02162940  thumb  ov010
 *   FIELD_EVENT_CHECK_CheckLedgeJump  0x0218B408  thumb
 *   FIELD_EVENT_CHECK_CheckGridConnectFront  0x0218AED4  thumb
 *   FIELD_EVENT_CHECK_CheckFrontTileEvents  0x0218AF90  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb
 *   EVENT_SHORTCUT_MENU_HasShortcuts  0x0215FF34  thumb  ov010
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb
 *   EVENT_SHORTCUT_MENU_Create  0x0215FF54  thumb  ov010
 *   GAMESYSTEM_GetFieldMapState  0x0201212C  thumb
 *   EVENT_COMM_ERROR_Create  0x021C06CC  thumb
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb
 *   SCRCMD_NETWORK_CreateBattleRecordLinkEvent  0x0215FC40  thumb  ov010
 *   FIELD_SUBSCREEN_CheckModeRequest  0x021A0EB0  thumb
 *   FIELD_EVENT_CHECK_CreateGPowerExpireEvent  0x0218ACA8  thumb
 *   INTRUDE_FIELD_CreateTileEvent  0x0217B410  thumb  ov018
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

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

struct Obj00020;
extern void FIELD_EVENT_CHECK_InitInput(struct FieldInput *p, void *sys, struct Obj00020 *pos);
typedef signed int     s32;
struct Big;
struct Ctx738;
struct Ctx9B0;
struct FieldCtx;
extern int FIELD_EVENT_CHECK_StartPendingScript(struct Ctx738 *c);
extern u32 *GAME_DATA_GetEventState(void *p);
struct BigObj;
struct Ctx;
struct Desc;
struct VecFx32;
extern int PLEASURE_BOAT_Update(int a, char *b);
extern int EVENT_TRAINER_EYE_Check(int a);
extern int FIELD_EVENT_CHECK_AddStepRecord(void *a);
extern int FIELD_EVENT_CHECK_CheckPosEventAtPlayer(void *p);
extern int FIELD_EVENT_CHECK_CheckGridConnect(u8 *p, void *a, void *arg);
extern void *FIELD_EVENT_CHECK_CheckTileMoveTask(struct FieldCtx *p, struct Obj00020 *pos);
extern int FIELD_EVENT_CHECK_CheckStepEvents(struct Ctx9B0 *p, u8 *pos);
extern int FIELD_EVENT_CHECK_CheckPosEventFacing(struct FieldCtx *p);
extern int FIELD_EVENT_CHECK_CheckPosEventHeldDir(struct FieldCtx *p);
extern void *FIELD_EVENT_CHECK_CheckIntrudeEdge(u8 *p, void *a, void *b);
extern int FIELD_EVENT_CHECK_CheckWildEncount(struct FieldCtx *p, void *unused, u8 *pos);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern int FIELD_PLAYER_TryPushBoulder(u32 *p, int a, int b, int c);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int INTRUDE_FIELD_IsCommAllowed(const struct Ctx *a, int b);
extern int INTRUDE_SUBDISP_CreateDisconnectEvent(void *sys, int v);
extern u32 GAME_COMM_GetKind(void *obj);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern int INTRUDE_FIELD_IsStartRequested(u8 *p);
extern void *INTRUDE_FIELD_CreateNoticeEvent(void *a, u8 *pos);
extern int INTRUDE_COMM_ConsumeAreaNoticeSeen(u8 *ctx, int arg);
extern int GAME_DATA_GetSymbolMapFlag(unsigned char *base);
struct Desc;
extern struct Desc *FIELD_INTRUDE_EVENT_StartSymbolEntry(int a0, int a1, int a2);
extern int INTRUDE_COMM_GetActiveRequestTarget(u8 *p, int *out);
extern void FIELD_PLAYER_ResetMoveWork(u32 *p);
extern void *EVENT_COMM_COMMON_CreateTalkedStartEvent(void *p, int a, int b, int c, int d, u16 e);
extern int INTRUDE_FIELD_TryStartOfferEvent(int a, u8 *b, int c);
extern int INTRUDE_FIELD_FindRemotePlayerAhead(int *a, u8 *b, int *out);
extern void *EVENT_COMM_COMMON_CreateTalkStartEvent(void *owner, int b, int unused, int d, int e, u16 f);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern void FIELD_PLAYER_GetPos(u8 *p, struct VecFx32 *out);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern int FIELD_EVENT_CHECK_SearchGridFrontMmdl(struct FieldCtx *p, u8 *pos);
extern u32 FLDMMDL_GetEventId(void *p);
extern int SCRIPT_SYS_IsZoneScriptId(u16 v);
extern int FIELD_RAIL_LOADER_CreateScriptEvent(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
extern u32 EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk(void *p, void *q, int *pos, u32 d);
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern u16 FIELD_EVENT_CHECK_GetFrontTileMessage(struct FieldCtx *p, u8 *pos);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *INTRUDE_GetFromSave(void *sys);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern int INTRUDE_FindOfferSlotAt(u8 *base, int a, int b, int c, int d);
extern void *INTRUDE_StartOfferEvent(void *a, void *unused, void *c);
extern int FIELD_GetPlayerAreaZoneId(void *a, u16 *out);
extern u32 ZONEDATA_IsZoneInTableDFB8(u32 id);
extern u16 EVENTDATA_SYSTEM_GetAutoPosEventScriptId(void *p, void *q, int key);
extern int FIELD_EVENT_CHECK_CheckLedgeJump(char *p, void *a, void *x);
extern int FIELD_EVENT_CHECK_CheckGridConnectFront(char *p, int unused, void *a);
extern int FIELD_EVENT_CHECK_CheckFrontTileEvents(struct FieldInput *p, void *sys, u8 *pos);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern int EVENT_SHORTCUT_MENU_HasShortcuts(void *sys);
extern int FIELD_SUBSCREEN_IsIdle(u32 a);
extern struct Desc *EVENT_SHORTCUT_MENU_Create(int a0, int a1, u16 a2);
extern u8 GAMESYSTEM_GetFieldMapState(const struct Ctx *p);
extern int EVENT_COMM_ERROR_Create(void *sys, u8 *pos);
extern u32 FIELD_SUBSCREEN_GetMode(u8 *p);
extern struct Desc *SCRCMD_NETWORK_CreateBattleRecordLinkEvent(int a0, int a1, u16 a2);
extern int FIELD_SUBSCREEN_CheckModeRequest(u32 *p, u32 a);
extern struct Desc *FIELD_EVENT_CHECK_CreateGPowerExpireEvent(void *a);
extern int INTRUDE_FIELD_CreateTileEvent(int a0, int a1, int a2);

int FIELD_EVENT_CHECK_CheckGridEvents(void *sys, struct Obj00020 *pos, int *outA, int *outB)
{
    struct FieldInput in;
    int xyz[3];
    u32 out;
    u16 id;
    int r;
    u32 flags;
    void *ev;
    void *obj;
    void *model;

    *outA = 0;
    *outB = 0;
    FIELD_EVENT_CHECK_InitInput(&in, sys, pos);
    r = FIELD_EVENT_CHECK_StartPendingScript((struct Ctx738 *)(&in));
    if (r != 0) {
        *outA = 1;
        return r;
    }
    r = PLEASURE_BOAT_Update((int)sys, (char *)(*GAME_DATA_GetEventState(in.f8)));
    if (r != 0)
        return r;
    r = EVENT_TRAINER_EYE_Check((int)pos);
    if (r != 0) {
        *outA = 1;
        return r;
    }
    if (in.b2)
        FIELD_EVENT_CHECK_AddStepRecord(in.f8);
    if (in.b2) {
        r = FIELD_EVENT_CHECK_CheckPosEventAtPlayer(&in);
        if (r != 0) {
            *outA = 1;
            return r;
        }
        r = FIELD_EVENT_CHECK_CheckGridConnect((u8 *)(&in), pos, (void *)in.f34);
        if (r != 0)
            return r;
        r = (int)FIELD_EVENT_CHECK_CheckTileMoveTask((struct FieldCtx *)(&in), (struct Obj00020 *)pos);
        if (r != 0)
            return r;
    }
    r = FIELD_EVENT_CHECK_CheckStepEvents((struct Ctx9B0 *)(&in), (u8 *)pos);
    if (r != 0)
        return r;
    if (in.b3) {
        r = FIELD_EVENT_CHECK_CheckPosEventFacing((struct FieldCtx *)(&in));
        if (r != 0)
            return r;
    }
    r = FIELD_EVENT_CHECK_CheckPosEventHeldDir((struct FieldCtx *)(&in));
    if (r != 0)
        return r;
    r = (int)FIELD_EVENT_CHECK_CheckIntrudeEdge((u8 *)(&in), sys, pos);
    if (r != 0)
        return r;
    r = FIELD_EVENT_CHECK_CheckWildEncount((struct FieldCtx *)(&in), sys, (u8 *)pos);
    if (r != 0)
        return r;

    flags = 0;
    if ((int)ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(in.f8), (u32)0x964) == 1)
        flags |= 1;
    r = FIELD_PLAYER_TryPushBoulder((u32 *)in.f18, in.trg, in.cont, flags);
    if (r != 0)
        return r;

    obj = (void *)GAMESYSTEM_GetGameComm(sys);
    ev = (void *)INTRUDE_COMM_GetWorkIfRunning((int)obj);
    model = FIELD_PLAYER_GetMmdl((u8 *)in.f18);
    if (INTRUDE_FIELD_IsCommAllowed((const struct Ctx *)sys, in.f10) == 1)
        return INTRUDE_SUBDISP_CreateDisconnectEvent(sys, 0);
    if ((int)GAME_COMM_GetKind(obj) == 2 && ev != 0) {
        if (GAME_DATA_GetIntrudeCount(in.f8) == 1 && INTRUDE_FIELD_IsStartRequested(ev) == 1)
            return (int)INTRUDE_FIELD_CreateNoticeEvent(sys, (u8 *)pos);
        if (INTRUDE_COMM_ConsumeAreaNoticeSeen(ev, in.f10) == 1)
            return (int)FIELD_INTRUDE_EVENT_StartSymbolEntry((int)sys, 9, (u32)GAME_DATA_GetSymbolMapFlag(in.f8));
        if (in.b10 == 1 && INTRUDE_COMM_GetActiveRequestTarget(ev, (int *)(&out)) == 1) {
            FIELD_PLAYER_ResetMoveWork((u32 *)in.f18);
            return (int)EVENT_COMM_COMMON_CreateTalkedStartEvent(sys, (int)pos, (int)ev, (int)model, out, in.f0);
        }
        if (in.b3) {
            r = INTRUDE_FIELD_TryStartOfferEvent((int)sys, ev, in.f18);
            if (r != 0)
                return r;
        }
        if (in.b0 && INTRUDE_FIELD_FindRemotePlayerAhead(ev, (u8 *)in.f18, (int *)(&out)) == 1) {
            FIELD_PLAYER_ResetMoveWork((u32 *)in.f18);
            return (int)EVENT_COMM_COMMON_CreateTalkStartEvent(sys, (int)pos, (int)ev, (int)model, out, in.f0);
        }
    }

    if (in.b0) {
        u32 dir = FIELD_PLAYER_GetDirDisp((u8 *)in.f18);
        int target;
        u32 msg;
        int x;
        int y;
        int z;
        void *map;

        FIELD_PLAYER_GetPos((u8 *)in.f18, (struct VecFx32 *)xyz);
        FLDMMDL_MOVE_AddDirVector((u32)dir, xyz, 0x10000);
        target = FIELD_EVENT_CHECK_SearchGridFrontMmdl((struct FieldCtx *)(&in), (u8 *)pos);
        if (target != 0) {
            u32 kind = FLDMMDL_GetEventId((void *)target);

            if (SCRIPT_SYS_IsZoneScriptId(kind) == 1) {
                void *m = FIELD_PLAYER_GetMmdl((u8 *)in.f18);

                FIELD_PLAYER_ResetMoveWork((u32 *)in.f18);
                *outA = 1;
                return FIELD_RAIL_LOADER_CreateScriptEvent((u32)sys, (u32)pos, kind, (u32)m, target, in.f0);
            }
        }
        msg = EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk(in.fC, (void *)GAME_DATA_GetEventWork(in.f8), xyz, dir);
        if (msg != 0xFFFF)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)sys, msg, 0, in.f0);
        msg = FIELD_EVENT_CHECK_GetFrontTileMessage((struct FieldCtx *)(&in), (u8 *)pos);
        if (msg != 0xFFFF)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)sys, msg, 0, in.f0);
        x = xyz[0] >> 12;
        y = xyz[1] >> 12;
        z = xyz[2] >> 12;
        map = INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(in.f8));
        msg = (u32)INTRUDE_FindOfferSlotAt(map, (u16)FIELDMAP_GetZoneId((u8 *)pos), (s16)(x / 16), (s16)(y / 16), (s16)(z / 16));
        if (msg != 0xFF)
            return (int)INTRUDE_StartOfferEvent(sys, (void *)in.f0, (void *)msg);
        if (FIELD_GetPlayerAreaZoneId(pos, &id) == 1)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)sys, 0x271B, 0, in.f0);
        if (ZONEDATA_IsZoneInTableDFB8(in.f10)) {
            msg = EVENTDATA_SYSTEM_GetAutoPosEventScriptId(in.fC, (void *)GAME_DATA_GetEventWork(in.f8), (int)xyz);
            if (msg != 0xFFFF)
                return (int)SCRIPT_SYS_CreateScriptEventSimple((int)sys, msg, 0, in.f0);
        }
    }

    if (in.f1C == 3 || in.f1C == 0) {
        r = FIELD_EVENT_CHECK_CheckLedgeJump((char *)(&in), sys, pos);
        if (r != 0)
            return r;
    }
    if (in.b5) {
        r = FIELD_EVENT_CHECK_CheckGridConnectFront((char *)(&in), (int)sys, pos);
        if (r != 0)
            return r;
        r = FIELD_EVENT_CHECK_CheckFrontTileEvents(&in, sys, (u8 *)pos);
        if (r != 0)
            return r;
    }
    if (in.b6 && WIPE_SYS_EndCheck()) {
        void *pl = (void *)FIELDMAP_GetSubscreen((u8 *)pos);

        if (EVENT_SHORTCUT_MENU_HasShortcuts(sys) && FIELD_SUBSCREEN_IsIdle((u32)pl)) {
            r = (int)EVENT_SHORTCUT_MENU_Create((int)sys, (int)pos, in.f0);
            if (r != 0)
                return r;
        }
    }
    if (GAMESYSTEM_GetFieldMapState(sys) == 1 && WIPE_SYS_EndCheck() && in.b10)
        return EVENT_COMM_ERROR_Create(sys, (u8 *)pos);
    if (in.b1 && WIPE_SYS_EndCheck()) {
        if ((int)FIELD_SUBSCREEN_GetMode((void *)FIELDMAP_GetSubscreen((u8 *)pos)) == 6)
            return 0;
        *outB = 1;
        return (int)SCRCMD_NETWORK_CreateBattleRecordLinkEvent((int)sys, (int)pos, in.f0);
    }
    if (WIPE_SYS_EndCheck()) {
        r = FIELD_SUBSCREEN_CheckModeRequest((void *)FIELDMAP_GetSubscreen((u8 *)pos), in.b7);
        if (r != 0)
            return r;
    }
    if (in.b7 && WIPE_SYS_EndCheck()) {
        r = (int)FIELD_EVENT_CHECK_CreateGPowerExpireEvent(sys);
        if (r != 0)
            return r;
    }
    r = INTRUDE_FIELD_CreateTileEvent((int)pos, (int)sys, in.f18);
    if (r == 0)
        return 0;
    return r;
}
