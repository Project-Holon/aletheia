/*
 * function: FLD_WIPE_3DOBJ_MapChangeEventMain
 * address:  0x021C82C4
 * packet:   pkt_ov021_021C82C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback armed by FLD_WIPE_3DOBJ_CreateMapChangeEvent (0x30-byte context). Case 8 is an
 * if/else with GAME_EVENT_CallEvent written in both arms (its `beq` over `b`);
 * spelled as `if (v == 0) v = ...; GAME_EVENT_CallEvent(a, v);` the call merges
 * with case 3's and every `(*st)++` moves off case 0's copy.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_PushState  0x0218F818  thumb  ov021
 *   FIELD_CAMERA_PushStateConstrained  0x0218F848  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_CAMERA_StartMove  0x0218F900  thumb  ov021
 *   FIELD_CAMERA_IsMoving  0x0218FE50  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLD3D_CI_StartSequence  0x021C1CB0  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FIELD_CAMERA_PopState  0x0218F878  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent  0x021BEA30  thumb  ov021
 *   EVENT_MAPCHANGE_CreateWarpEventToLocation  0x021854CC  thumb  ov020
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_Cancel  0x021BC5BC  thumb  ov021
 *   BG_SYS_GetMainVisiblePlanes  0x02043658  arm
 *   FIELDMAP_SetBgMode  0x02188DA0  thumb  ov021
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   FLD_WIPE_3DOBJ_FadeOutEventMain  0x021C85CC  thumb  ov021
 *   FIELD_PLACE_NAME_ShowForZone  0x021BC578  thumb  ov021
 *   FIELD_CAMERA_StartMoveToSaved  0x0218F9C4  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct Buf24 {
    u32 w[6];
} Buf24;

typedef struct Param {
    u32 pad0[3];
    VecFx32 pos;
    u32 f18;
    u32 f1c;
    u32 f20;
    u16 h24;
    u16 h26;
    u32 f28;
    u16 h2c;
    u16 pad2e;
    Buf24 buf;
} Param;

typedef struct TaskCtx {
    void *w0;
    u32 f04;
    u32 f08;
    u8 f0c[0x28 - 0x0c];
    u32 f28;
    u32 f2c;
} Ctx;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Desc;
struct Evt;
extern void *FIELDMAP_GetCamera(void *p);
extern void *FIELDMAP_GetFld3dCi(u8 *p);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void FIELD_CAMERA_SetAreasEnabled(u8 *p, u32 v);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *p);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern void FIELD_NOGRID_MAPPER_SetActive(u32 a, u32 b);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_CAMERA_PushState(u8 *a);
extern void FIELD_CAMERA_PushStateConstrained(u8 *a);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_GetPos(u8 *a, VecFx32 *out);
extern void FIELD_CAMERA_StartMove(u8 *a, void *p, int n);
extern int FIELD_CAMERA_IsMoving(u8 *a);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void FLDMMDL_SysPauseMove(void *map);
extern int FLD3D_CI_StartSequence(int a, char *b, int c);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
extern void FIELD_CAMERA_PopState(u8 *a);
extern u32 EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent(u32 a, u32 b, u32 c, u32 d);
extern u32 EVENT_MAPCHANGE_CreateWarpEventToLocation(void *p, u32 u, u16 u2, void *src, u16 h);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern int FIELD_PLACE_NAME_Cancel(u8 *a);
extern u32 BG_SYS_GetMainVisiblePlanes(void);
extern void FIELDMAP_SetBgMode(void);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void FIELDMAP_ResetBgAffineShowMsg(u8 *a);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int FLD_WIPE_3DOBJ_FadeOutEventMain(void *task, int *state);
extern void FIELD_PLACE_NAME_ShowForZone(void *p, int v);
extern void FIELD_CAMERA_StartMoveToSaved(u8 *p, u8 *src, u16 v);
extern void FIELD_CAMERA_SetTraceTarget(u32 a, u32 b);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);

int FLD_WIPE_3DOBJ_MapChangeEventMain(u32 a, int *st, Ctx *c)
{
    void *sys;
    u32 h;
    void *y;
    u32 x;
    u32 v;
    void *o;
    void *t;
    Param p1;
    Param p2;
    VecFx32 v1;
    VecFx32 v2;
    Buf24 buf;

    sys = GAMESYSTEM_GetFieldMap(c->w0);
    h = (u32)FIELDMAP_GetCamera(sys);
    y = FIELDMAP_GetFld3dCi(sys);
    x = FIELDMAP_GetNogridMapper(sys);
    switch (*st) {
    case 0:
        FIELD_CAMERA_SetAreasEnabled((u8 *)h, 0);
        c->f04 = FIELD_CAMERA_GetTraceTarget((u8 *)h);
        FIELD_CAMERA_EndDelay((u8 *)h);
        (*st)++;
        break;
    case 1:
        if (c->f04 != 0 && FIELD_CAMERA_IsDelayEnabled((u8 *)h) != 0)
            break;
        FIELD_NOGRID_MAPPER_SetActive(x, 0);
        FIELD_CAMERA_StopTargetTrace((u8 *)h);
        FIELD_CAMERA_PushState((u8 *)h);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(sys), &v1);
        p1.h24 = 0x25d8;
        p1.h26 = 0;
        p1.f28 = 0xed000;
        p1.f18 = 0;
        p1.f1c = 0x4000;
        p1.f20 = 0;
        p1.pos = v1;
        p1.h2c = 0xe38;
        p1.buf.w[0] = 1;
        p1.buf.w[1] = 1;
        p1.buf.w[2] = 0;
        p1.buf.w[3] = 1;
        p1.buf.w[4] = 1;
        p1.buf.w[5] = 1;
        FIELD_CAMERA_StartMove((u8 *)h, &p1, 10);
        (*st)++;
    case 2:
        if (FIELD_CAMERA_IsMoving((u8 *)h) != 0)
            break;
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(sys));
        v = (u32)FLD3D_CI_StartSequence((u32)c->w0, y, (u8)c->f28);
        if (v != 0)
            GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)v);
        (*st)++;
        break;
    case 3:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(sys));
        FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(sys)), 1);
        FIELD_CAMERA_PopState((u8 *)h);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent((u32)c->w0, (u32)sys, 0, 0));
        (*st)++;
        break;
    case 4:
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_MAPCHANGE_CreateWarpEventToLocation(c->w0, (u32)sys, c->f08, c->f0c, 1));
        (*st)++;
        break;
    case 5:
        FIELD_PLACE_NAME_Cancel((u8 *)FIELDMAP_GetPlaceName(sys));
        c->f04 = FIELD_CAMERA_GetTraceTarget((u8 *)h);
        FIELD_CAMERA_EndDelay((u8 *)h);
        (*st)++;
        break;
    case 6:
        if (c->f04 != 0 && FIELD_CAMERA_IsDelayEnabled((u8 *)h) != 0)
            break;
        FIELD_NOGRID_MAPPER_SetActive(x, 0);
        FIELD_CAMERA_StopTargetTrace((u8 *)h);
        FIELD_CAMERA_PushStateConstrained((u8 *)h);
        FIELD_CAMERA_SetAreasEnabled((u8 *)h, 0);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(sys), &v2);
        p2.h24 = 0x25d8;
        p2.h26 = 0;
        p2.f28 = 0xed000;
        p2.f18 = 0;
        p2.f1c = 0x4000;
        p2.f20 = 0;
        p2.pos = v2;
        p2.h2c = 0xe38;
        p2.buf.w[0] = 1;
        p2.buf.w[1] = 1;
        p2.buf.w[2] = 0;
        p2.buf.w[3] = 1;
        p2.buf.w[4] = 1;
        p2.buf.w[5] = 1;
        FIELD_CAMERA_StartMove((u8 *)h, &p2, 1);
        (*st)++;
    case 7:
        if (FIELD_CAMERA_IsMoving((u8 *)h) != 0)
            break;
        FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(sys)), 1);
        t = (void *)BG_SYS_GetMainVisiblePlanes();
        FIELDMAP_SetBgMode();
        BG_SYS_SetMainVisiblePlanes((u32)t);
        FIELDMAP_ResetBgAffineShowMsg(sys);
        (*st)++;
        break;
    case 8:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(sys));
        v = (u32)FLD3D_CI_StartSequence((u32)c->w0, y, (u8)c->f2c);
        if (v != 0) {
            GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)v);
        } else {
            o = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(sys));
            FLDMMDL_SetStatusBitVanish(o, 0);
            FLDMMDL_SetDirDispCheckPause((u32)o, (u32)1);
            GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)func_020122C0(c->w0, (void *)a, FLD_WIPE_3DOBJ_FadeOutEventMain, 0));
        }
        (*st)++;
        break;
    case 9:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(sys));
        FIELD_PLACE_NAME_ShowForZone((void *)FIELDMAP_GetPlaceName(sys), c->f08);
        buf.w[0] = 1;
        buf.w[1] = 1;
        buf.w[2] = 0;
        buf.w[3] = 1;
        buf.w[4] = 1;
        buf.w[5] = 1;
        FIELD_CAMERA_StartMoveToSaved((u8 *)h, (u8 *)(&buf), 10);
        (*st)++;
    case 10:
        if (FIELD_CAMERA_IsMoving((u8 *)h) != 0)
            break;
        if (c->f04 != 0)
            FIELD_CAMERA_SetTraceTarget(h, c->f04);
        FIELD_CAMERA_RestartDelay((unsigned char *)h);
        FIELD_NOGRID_MAPPER_SetActive(x, 1);
        FIELD_CAMERA_PopState((u8 *)h);
        FIELD_CAMERA_SetAreasEnabled((u8 *)h, 1);
        return 1;
    }
    return 0;
}
