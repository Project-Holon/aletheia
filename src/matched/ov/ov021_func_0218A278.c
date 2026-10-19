/*
 * function: FIELD_EVENT_CHECK_CheckRailEvents
 * address:  0x0218A278
 * packet:   pkt_ov021_0218A278
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EVENT_CHECK_InitInput  0x0218A4E0  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_RAIL_GetFrontLocation  0x0219E634  thumb  ov021
 *   FIELD_EVENT_CHECK_StartPendingScript  0x0218A738  thumb  ov021
 *   FIELD_EVENT_CHECK_AddStepRecord  0x0218A728  thumb  ov021
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   EVENTDATA_SYSTEM_GetRailPosEventScriptId  0x02162958  thumb  ov010
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   FIELD_EVENT_CHECK_CheckRailConnect  0x0218B0CC  thumb  ov021
 *   FIELD_EVENT_CHECK_CheckStepEvents  0x0218A9B0  thumb  ov021
 *   FIELD_EVENT_CHECK_CheckWildEncount  0x0218B208  thumb  ov021
 *   FIELD_EVENT_CHECK_SearchRailFrontMmdl  0x0218B53C  thumb  ov021
 *   FLDMMDL_GetEventId  0x0216D5B8  thumb  ov010
 *   SCRIPT_SYS_IsZoneScriptId  0x02158D90  thumb  ov010
 *   FIELD_PLAYER_ResetMoveWork  0x021A2F6C  thumb  ov021
 *   FIELD_RAIL_LOADER_CreateScriptEvent  0x0219F01C  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden  0x02162A5C  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_EVENT_CHECK_IsRailFrontFree  0x0218B310  thumb  ov021
 *   FIELD_EVENT_CHECK_CheckRailConnectFront  0x0218B13C  thumb  ov021
 *   FIELD_EVENT_CHECK_CheckRailSignBoard  0x0218B24C  thumb  ov021
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   EVENT_SHORTCUT_MENU_HasShortcuts  0x0215FF34  thumb  ov010
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   EVENT_SHORTCUT_MENU_Create  0x0215FF54  thumb  ov010
 *   GAMESYSTEM_GetFieldMapState  0x0201212C  thumb
 *   EVENT_COMM_ERROR_Create  0x021C06CC  thumb  ov021
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb  ov021
 *   EVENT_FIELD_MENU_Create  0x0215FC40  thumb  ov010
 *   FIELD_SUBSCREEN_CheckModeRequest  0x021A0EB0  thumb  ov021
 *   FIELD_EVENT_CHECK_CreateGPowerExpireEvent  0x0218ACA8  thumb  ov021
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

typedef struct Cell { u16 x, y, z, w; } Cell;

struct Obj00020;
extern void FIELD_EVENT_CHECK_InitInput(struct FieldInput *p, void *sys, struct Obj00020 *pos);
struct BigObj;
struct Ctx;
struct Desc;
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int FLDMMDL_RAIL_GetFrontLocation(void *a, u32 b);
struct Ctx738;
struct Ctx9B0;
struct FieldCtx;
extern int FIELD_EVENT_CHECK_StartPendingScript(struct Ctx738 *c);
extern int FIELD_EVENT_CHECK_AddStepRecord(void *a);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern u16 EVENTDATA_SYSTEM_GetRailPosEventScriptId(void *c, void *a, int key);
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern int FIELD_EVENT_CHECK_CheckRailConnect(char *p, void *unused, void *x);
extern int FIELD_EVENT_CHECK_CheckStepEvents(struct Ctx9B0 *p, u8 *pos);
extern int FIELD_EVENT_CHECK_CheckWildEncount(struct FieldCtx *p, void *unused, u8 *pos);
extern int FIELD_EVENT_CHECK_SearchRailFrontMmdl(unsigned char *p, void *b);
extern u32 FLDMMDL_GetEventId(void *p);
extern int SCRIPT_SYS_IsZoneScriptId(u16 v);
extern void FIELD_PLAYER_ResetMoveWork(u32 *p);
extern int FIELD_RAIL_LOADER_CreateScriptEvent(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
extern u16 FLDMMDL_GetDirDisp(void *obj);
extern u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden(void *set, void *flags, const void *where, u16 type);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern int FIELD_EVENT_CHECK_IsRailFrontFree(void *a, unsigned char *s);
extern int FIELD_EVENT_CHECK_CheckRailConnectFront(char *p, void *unused, void *x, int *alt);
extern int FIELD_EVENT_CHECK_CheckRailSignBoard(char *p, void *q, void *x);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern int EVENT_SHORTCUT_MENU_HasShortcuts(void *sys);
extern int FIELD_SUBSCREEN_IsIdle(u32 a);
extern struct Desc *EVENT_SHORTCUT_MENU_Create(int a0, int a1, u16 a2);
extern u8 GAMESYSTEM_GetFieldMapState(const struct Ctx *p);
extern int EVENT_COMM_ERROR_Create(void *sys, u8 *pos);
extern u32 FIELD_SUBSCREEN_GetMode(u8 *p);
extern struct Desc *EVENT_FIELD_MENU_Create(int a0, int a1, u16 a2);
extern int FIELD_SUBSCREEN_CheckModeRequest(u32 *p, u32 a);
extern struct Desc *FIELD_EVENT_CHECK_CreateGPowerExpireEvent(void *a);

int FIELD_EVENT_CHECK_CheckRailEvents(void *sys, struct Obj00020 *pos)
{
    struct FieldInput in;
    Cell here;
    int cur[2];
    Cell copy;
    void *model;
    int r;
    u32 msg;

    FIELD_EVENT_CHECK_InitInput(&in, sys, (struct Obj00020 *)pos);
    model = FIELD_PLAYER_GetMmdl((u8 *)in.f18);
    FLDMMDL_RAIL_GetFrontLocation(model, (u32)(&here));
    r = FIELD_EVENT_CHECK_StartPendingScript((struct Ctx738 *)(&in));
    if (r != 0)
        return r;
    if (in.b2)
        FIELD_EVENT_CHECK_AddStepRecord(in.f8);
    if (in.b2) {
        void *obj = FIELD_PLAYER_GetMmdl((u8 *)in.f18);
        void *flags = (void *)GAME_DATA_GetEventWork(in.f8);

        FLDMMDL_RAIL_GetNextLocation(obj, cur);
        msg = EVENTDATA_SYSTEM_GetRailPosEventScriptId(in.fC, flags, (int)cur);
        if (msg != 0xFFFF)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)sys, msg, 0, in.f0);
        r = FIELD_EVENT_CHECK_CheckRailConnect((char *)(&in), sys, pos);
        if (r != 0)
            return r;
        r = FIELD_EVENT_CHECK_CheckStepEvents((struct Ctx9B0 *)(&in), (u8 *)pos);
        if (r != 0)
            return r;
    }
    r = FIELD_EVENT_CHECK_CheckWildEncount((struct FieldCtx *)(&in), sys, (u8 *)pos);
    if (r != 0)
        return r;
    if (in.b0) {
        int target = FIELD_EVENT_CHECK_SearchRailFrontMmdl((unsigned char *)(&in), pos);
        void *flags;
        u16 d;

        if (target != 0) {
            u32 kind = FLDMMDL_GetEventId((void *)target);

            if (SCRIPT_SYS_IsZoneScriptId(kind) == 1) {
                void *m = FIELD_PLAYER_GetMmdl((u8 *)in.f18);

                FIELD_PLAYER_ResetMoveWork((u32 *)in.f18);
                return FIELD_RAIL_LOADER_CreateScriptEvent((u32)sys, (u32)pos, kind, (u32)m, target, in.f0);
            }
        }
        flags = (void *)GAME_DATA_GetEventWork(in.f8);
        d = FLDMMDL_GetDirDisp(model);
        copy = here;
        msg = EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden(in.fC, flags, &copy, d);
        if (msg != 0xFFFF)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)sys, msg, 0, in.f0);
    }
    if (in.b5 && FIELD_EVENT_CHECK_IsRailFrontFree(FIELDMAP_GetFieldPlayer(pos), (unsigned char *)(&in)) == 0) {
        r = FIELD_EVENT_CHECK_CheckRailConnectFront((char *)(&in), sys, pos, (int *)(&here));
        if (r != 0)
            return r;
    }
    r = FIELD_EVENT_CHECK_CheckRailSignBoard((char *)(&in), sys, pos);
    if (r != 0)
        return r;
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
        if (FIELD_SUBSCREEN_GetMode((void *)FIELDMAP_GetSubscreen((u8 *)pos)) == 6)
            return 0;
        return (int)EVENT_FIELD_MENU_Create((int)sys, (int)pos, in.f0);
    }
    {
        u32 f = (in.b7 && WIPE_SYS_EndCheck()) ? 1 : 0;

        r = FIELD_SUBSCREEN_CheckModeRequest((void *)FIELDMAP_GetSubscreen((u8 *)pos), f);
        if (r != 0)
            return r;
    }
    if (in.b7 && WIPE_SYS_EndCheck()) {
        r = (int)FIELD_EVENT_CHECK_CreateGPowerExpireEvent(sys);
        if (r != 0)
            return r;
    }
    return 0;
}
