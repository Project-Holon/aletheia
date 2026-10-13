/*
 * function: GIMMICK41_EventLaunch
 * address:  0x021F3884
 * packet:   pkt_ov041_021F3884
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Closed 2026-10-05 (wD9r lane 36), after many waves at an "s keeps r7" allocator residue. The residue
 * was source shape, not the allocator:
 *   - case 1: c and len read into locals (c first), and the clamp written as an if/else with BOTH
 *     stores (0x71C and 0x71E) in each arm; tail merging rebuilds the image's single join store and
 *     its empty-arm `b`. This alone moves s to its spill slot [sp,#0x24] and gives frame 0xE8.
 *   - cases 2, 4, 5: `v = FLD_EXP_OBJ_GetAnimeFrame(...)` then `v / 4096` at each compare (the r*2 index is then
 *     computed before the divide, as in the image).
 *   - all aggregate locals (req, pos, base, end, start, path, fin) are block-scoped where they are
 *     used; their slots then follow the order of appearance, and `Vec x = {0, 0, 0}` gives the
 *     `add rN,sp,#K; str [rN]` zeroing form.
 *   - the tail after the switch is `if (w[2] != 0) { ... } return 0;` (one shared epilogue).
 *   - the tail uses its own local m2 (declared between r and sel) for its spill slot.
 * symbols:
 *   GIMMICK41_GetFirstAnimeSlot  0x021F3F18  thumb  ov041
 *   GIMMICK41_FacingToRingIndex  0x021F3F44  thumb  ov041
 *   GIMMICK41_GetCannonDirection  0x021F3FC0  thumb  ov041
 *   GIMMICK41_StartBounce  0x021F3FD8  thumb  ov041
 *   GIMMICK41_ResetBounce  0x021F3FEC  thumb  ov041
 *   GIMMICK41_UpdateBounce  0x021F4000  thumb  ov041
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_PushState  0x0218F818  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   FIELD_CAMERA_StartMove  0x0218F900  thumb  ov021
 *   FIELD_CAMERA_IsMoving  0x0218FE50  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FIELD_CAMERA_PopState  0x0218F878  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_GetEyeRaw  0x0218ECE4  thumb  ov021
 *   FIELD_CAMERA_StartFreeMove  0x0218F930  thumb  ov021
 *   FIELD_CAMERA_GetMoveGoal  0x0218FE70  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_StartMoveToSaved  0x0218F9C4  thumb  ov021
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   ICA_ANIME_CreateWithFullBuffer  0x02011428  thumb
 *   ICA_ANIME_GetFrameNum  0x02011608  thumb
 *   func_020061E4  0x020061E4  thumb
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   ICA_ANIME_GetTranslateAt  0x02011688  thumb
 *   gGimmick41Flights     0x021F4320  data  a4
 *   gGimmick41CameraInfos     0x021F4198  data  a2
 *   gGimmick41CannonCells     0x021F40F0  data  a2
 *   gGimmick41FireSeFrames     0x021F4084  data  a2
 *   gGimmick41FireDoneFrames     0x021F408C  data  a2
 *   gGimmick41LandingFrames     0x021F4094  data  a2
 *   gGimmick41FlightStartFrames     0x021F409C  data  a2
 *   gGimmick41LandSeFramesBeforeEnd     0x021F40B4  data  a2
 */

#include "../include/G__anon_E.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;
typedef struct { int id; int x, y, z; int k; } Ent;
typedef struct { u16 a; u16 b; u8 e; u8 c; u8 d; u8 f; } Anim;
typedef struct { u8 pad[0x24]; u16 a; u16 b; u8 pad2[8]; int c; int d; int e; int f; int g; u8 pad3[4]; } Req;
typedef struct { int a, b, c, d, e, f; } Six;

extern Ent gGimmick41Flights[][4];
extern Anim gGimmick41CameraInfos[];
extern struct _anon_E gGimmick41CannonCells[];
extern u16 gGimmick41FireSeFrames[];
extern u16 gGimmick41FireDoneFrames[];
extern u16 gGimmick41LandingFrames[];
extern u16 gGimmick41FlightStartFrames[];
extern u16 gGimmick41LandSeFramesBeforeEnd[];

struct Big;
struct Ctx;
struct IcaAnime;
struct Obj;
struct Rec12;
struct VecFx32;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELDMAP_GetCamera(void *);
extern void *FIELDMAP_GetGameSystem(void *);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern void GIMMICK41_ResetBounce(u8 *);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern int GIMMICK41_FacingToRingIndex(int);
extern int GIMMICK41_GetCannonDirection(u32, int);
extern u16 GIMMICK41_GetFirstAnimeSlot(int);
extern void *ICA_ANIME_CreateWithFullBuffer(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4);
struct Obj11244;
extern u32 ICA_ANIME_GetFrameNum(struct Obj11244 *p);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void FLD_EXP_OBJ_SetAnimeFrame(void *, int, u16, u16, int);
extern int FLD_EXP_OBJ_GetAnimeFrame(int a, int b, int c, int d);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void FIELD_CAMERA_PushState(u8 *a);
extern void func_020061E4(u32);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
extern void FIELD_CAMERA_StartMove(u8 *a, void *p, int n);
extern int FIELD_CAMERA_IsMoving(u8 *a);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void GIMMICK41_StartBounce(u8 *);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);
extern void FIELD_CAMERA_PopState(u8 *a);
extern u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *p, struct Rec12 *dst, u32 idx);
extern void FIELD_PLAYER_GetPos(u8 *p, struct VecFx32 *out);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_CAMERA_GetEyeRaw(void *, Vec *);
extern void FIELD_CAMERA_StartFreeMove(u8 *p, u8 *a, u8 *b, u32 *c, u16 v);
extern u8 *FIELD_CAMERA_GetMoveGoal(u8 *p);
extern int FIELD_CAMERA_ResumeTargetTrace(u32 a);
extern void FIELD_CAMERA_StartMoveToSaved(u8 *p, u8 *src, u16 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern void GIMMICK41_UpdateBounce(u8 *p, u8 *obj);

int GIMMICK41_EventLaunch(void *a0, int *state)
{
    void *ctx;
    void *s;
    u8 *w;
    void *obj;
    void *cam;
    int v;
    u16 b0;
    u16 n;
    int row;
    int r;
    void *m2;
    int sel;
    u16 len;
    int c;
    u16 i1;
    u16 i3;
    u16 i4;
    u16 i6;
    u16 idx;
    void *m;

    ctx = GAMESYSTEM_GetFieldMap(func_020124E4(a0));
    s = (void *)FIELDMAP_GetExpObj(ctx);
    w = (u8 *)FIELDMAP_GetCommonWork(ctx, 1);
    obj = FIELDMAP_GetCamera(ctx);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(ctx))), 5);
    switch (*state) {
    case 0:
        FIELD_CAMERA_EndDelay(obj);
        GIMMICK41_ResetBounce(w + 0x720);
        (*state)++;
        break;
    case 1:
        if ((int)FIELD_CAMERA_IsDelayEnabled(obj) != 0)
            break;
        row = w[0];
        sel = GIMMICK41_FacingToRingIndex(w[1]);
        v = gGimmick41Flights[w[0]][sel].id;
        if (v == -1)
            return 1;
        *(u32 *)(w + 0x714) = (u32)ICA_ANIME_CreateWithFullBuffer((int)0x8015, (int)0x79, (int)v, (u32)(w + 4), (int)0x708);
        *(u16 *)(w + 0x71A) = ICA_ANIME_GetFrameNum((struct Obj11244 *)(*(u32 *)(w + 0x714)));
        idx = (u16)gGimmick41Flights[row][sel].k;
        c = gGimmick41CameraInfos[idx].c;
        len = gGimmick41CameraInfos[idx].d;
        n = *(u16 *)(w + 0x71A);
        if (c + len >= n) {
            *(u16 *)(w + 0x71C) = n - (len + 1);
            *(u16 *)(w + 0x71E) = len;
        } else {
            *(u16 *)(w + 0x71C) = c;
            *(u16 *)(w + 0x71E) = len;
        }
        w[3] = 0;
        b0 = w[0];
        i1 = GIMMICK41_GetFirstAnimeSlot(GIMMICK41_GetCannonDirection(w[1], b0));
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, (u16)b0, (u16)i1, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, (u16)b0, (u16)(i1 + 1), 1);
        FLD_EXP_OBJ_SetAnimeFrame(s, 0, b0, i1, 0);
        FLD_EXP_OBJ_SetAnimeFrame(s, 0, b0, i1 + 1, 0);
        FIELD_CAMERA_PushState(obj);
        (*state)++;
        break;
    case 2:
        b0 = w[0];
        r = GIMMICK41_GetCannonDirection(w[1], b0);
        v = FLD_EXP_OBJ_GetAnimeFrame((int)s, 0, (u16)b0, (u16)GIMMICK41_GetFirstAnimeSlot(r));
        if (v / 4096 == gGimmick41FireSeFrames[r])
            func_020061E4(0x698);
        if (v / 4096 < gGimmick41FireDoneFrames[r])
            break;
        i3 = GIMMICK41_GetFirstAnimeSlot(r);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(s, 0, (u16)b0, (u16)i3), 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(s, 0, (u16)b0, (u16)(i3 + 1)), 1);
        SCRIPT_SYS_CallScriptEvent(a0, 2, 0, 0, (int)0x8015);
        idx = (u16)gGimmick41Flights[w[0]][GIMMICK41_FacingToRingIndex(w[1])].k;
        {
        Req req;
        req.a = gGimmick41CameraInfos[idx].a;
        req.b = gGimmick41CameraInfos[idx].b;
        req.c = 0;
        req.d = 1;
        req.e = 1;
        req.f = 0;
        req.g = 0;
        FIELD_CAMERA_StartMove(obj, &req, gGimmick41CameraInfos[idx].e);
        }
        (*state)++;
        break;
    case 3:
        if (FIELD_CAMERA_IsMoving(obj) != 0)
            break;
        FIELD_CAMERA_SetMode(obj, (int)2);
        m = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(ctx));
        FLDMMDL_SetStatusBitVanish(m, (int)1);
        FLDMMDL_SetStatusBit(m, (int)0x200);
        FLDMMDL_SetMoveBit(m, (int)0x8000);
        b0 = w[0];
        i4 = GIMMICK41_GetFirstAnimeSlot(GIMMICK41_GetCannonDirection(w[1], b0));
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(s, 0, (u16)b0, (u16)i4), 0);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(s, 0, (u16)b0, (u16)(i4 + 1)), 0);
        func_020061E4(0x699);
        (*state)++;
        break;
    case 4:
        b0 = w[0];
        r = GIMMICK41_GetCannonDirection(w[1], b0);
        v = FLD_EXP_OBJ_GetAnimeFrame((int)s, 0, (u16)b0, (u16)GIMMICK41_GetFirstAnimeSlot(r));
        if (v / 4096 < gGimmick41FlightStartFrames[r])
            break;
        func_020061E4(0x6A0);
        w[2] = 1;
        *(u16 *)(w + 0x718) = 0;
        (*state)++;
        break;
    case 5:
        b0 = w[0];
        r = GIMMICK41_GetCannonDirection(w[1], b0);
        v = FLD_EXP_OBJ_GetAnimeFrame((int)s, 0, (u16)b0, (u16)GIMMICK41_GetFirstAnimeSlot(r));
        if (v / 4096 == gGimmick41LandingFrames[r]) {
            func_020061E4(0x696);
            if (w[3] == 0) {
                GIMMICK41_StartBounce(w);
                FIELD_CAMERA_SetMode(obj, (int)1);
            }
            FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(ctx)), (int)0);
        }
        if (w[2] != 0)
            break;
        cam = FIELDMAP_GetFieldPlayer(ctx);
        {
            Vec pos = {0, 0, 0};
            Ent *e = &gGimmick41Flights[w[0]][GIMMICK41_FacingToRingIndex(w[1])];
            pos.x = (e->x << 16) + 0x8000;
            pos.y = e->y << 16;
            pos.z = (e->z << 16) + 0x8000;
            FIELD_PLAYER_SetPos(cam, &pos);
        }
        (*state)++;
        break;
    case 6:
        FLDMMDL_ClearStatusBit(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(ctx)), (int)0x200);
        ICA_ANIME_Delete((struct IcaAnime *)(*(u32 *)(w + 0x714)));
        b0 = w[0];
        i6 = GIMMICK41_GetFirstAnimeSlot(GIMMICK41_GetCannonDirection(w[1], b0));
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, (u16)b0, (u16)i6, 0);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, (u16)b0, (u16)(i6 + 1), 0);
        FIELD_CAMERA_RestartDelay(obj);
        FIELD_CAMERA_PopState(obj);
        return 1;
    }
    if (w[2] != 0) {
        {
            Vec base = {0, 0, 0};
            b0 = w[0];
            if (ICA_ANIME_GetTranslateAt((struct IcaAnime *)(*(u32 *)(w + 0x714)), (struct Rec12 *)(&base), *(u16 *)(w + 0x718)) != 0) {
                base.x += (gGimmick41CannonCells[b0].a << 16) + 0x8000;
                base.y += gGimmick41CannonCells[b0].pad << 16;
                base.z += (gGimmick41CannonCells[b0].b << 16) + 0x8000;
                FIELD_PLAYER_SetPos(FIELDMAP_GetFieldPlayer(ctx), &base);
            }
        }
        if (*(int *)(w + 0x724) != 0 && *(u16 *)(w + 0x718) < *(u16 *)(w + 0x71C)) {
            Vec end;
            Vec start;
            Six path;
            FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(ctx), (struct VecFx32 *)(&end));
            if (*(int *)(w + 0x728) == 0) {
                FIELD_CAMERA_StopTargetTrace(obj);
                FIELD_CAMERA_GetEyeRaw(obj, &start);
                path.f = 1;
                path.e = 0;
                path.a = 0;
                path.b = 0;
                path.c = 0;
                path.d = 0;
                FIELD_CAMERA_StartFreeMove(obj, (u8 *)(&start), (u8 *)(&end), (u32 *)(&path), *(u16 *)(w + 0x71C) - *(u16 *)(w + 0x718));
                *(int *)(w + 0x728) = 1;
            } else {
                *(Vec *)(FIELD_CAMERA_GetMoveGoal(obj) + 0xC) = end;
            }
        }
        if (*(u16 *)(w + 0x718) == *(u16 *)(w + 0x71C)) {
            if (*(int *)(w + 0x720) != 0)
                *(int *)(w + 0x720) = 0;
            FIELD_CAMERA_ResumeTargetTrace((u32)obj);
            FIELD_CAMERA_SetMode(obj, (int)0);
            {
            Six fin;
            fin.a = 1;
            fin.b = 1;
            fin.c = 1;
            fin.d = 1;
            fin.e = 1;
            fin.f = 0;
            FIELD_CAMERA_StartMoveToSaved(obj, (u8 *)(&fin), *(u16 *)(w + 0x71E));
            }
            w[3] = 1;
        }
        row = w[0];
        idx = (u16)gGimmick41Flights[row][GIMMICK41_FacingToRingIndex(w[1])].k;
        m2 = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(ctx));
        if (*(u16 *)(w + 0x718) == *(u16 *)(w + 0x71A) - 1 - gGimmick41LandSeFramesBeforeEnd[idx] && idx != 11) {
            FLDMMDL_ClearMoveBit(m2, (int)0x8000);
            func_020061E4(0x697);
        }
        if (idx == 11) {
            if (*(u16 *)(w + 0x718) == 0x46)
                func_020061E4(0x6A1);
            if (*(u16 *)(w + 0x718) + 8 >= *(u16 *)(w + 0x71A)) {
                if ((int)FLDMMDL_CheckMoveBit(m2, (int)0x8000) != 0)
                    FLDMMDL_ClearMoveBit(m2, (int)0x8000);
            }
        }
        *(u16 *)(w + 0x718) += 1;
        if (*(u16 *)(w + 0x718) >= *(u16 *)(w + 0x71A))
            w[2] = 0;
        GIMMICK41_UpdateBounce(w + 0x720, obj);
    }
    return 0;
}
