/*
 * function: GIMMICK43_LiftEventMain
 * address:  0x021F3AC0
 * packet:   pkt_ov043_021F3AC0
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callees 0x021F3EEC and 0x021F3FBC (ov043) and 0x0218CEE0 and 0x021C06C0
 * (ov021) are unlabelled leaves, filed under their own shards.
 * Levers from the first draft (311 bytes): bind FIELD_G3D_MAPPER_GetHeightEx's result to
 * c before the 06C0 call (inline, w[0] is loaded first and spilled, which
 * adds a frame slot); bind BE674's result to e and set f = 0 after it; write
 * `w[17 + n++] = cur`; and pass `vec2.y` rather than re-reading w[1].
 *
 * symbols:
 *   sGimmick43LiftHeights     0x021F4490  data  a4
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   GIMMICK43_IsInLiftZone  0x021F3EEC  thumb  ov043
 *   GIMMICK43_StartCameraShake  0x021F41B8  thumb  ov043
 *   GIMMICK43_UpdateCameraShake  0x021F4210  thumb  ov043
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GIMMICK43_IsLiftArrived  0x021F3ECC  thumb  ov043
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   GIMMICK43_GetLiftAnimeIndex  0x021F3FBC  thumb  ov043
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetHeightEx  0x0218CEE0  thumb  ov021
 *   HEIGHT_EX_SetAreaHeight  0x021C06C0  thumb  ov021
 *   GIMMICK43_ShowLiftAnime  0x021F3F38  thumb  ov043
 *   FIELDMAP_GetFog  0x02188C64  thumb  ov021
 *   FIELD_FOG_FADE_IsFade  0x021A0244  thumb  ov021
 *   GIMMICK43_UpdateBigLift  0x021F3FE8  thumb  ov043
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    int v[2];
    int pad[4];
} E;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

extern E sGimmick43LiftHeights[];

struct Ctx;
struct Obj;
struct Rec;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Big;
struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELDMAP_GetCamera(void *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *v);
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern Vec *FLDMMDL_GetPosPtr(u32 o);
extern void FLDMMDL_SetGridNowY(void *p, int v);
extern void FLDMMDL_SetPos(u32 o, Vec *v);
extern int GIMMICK43_IsInLiftZone(u8 i, int x, int y);
extern void GIMMICK43_StartCameraShake(int a0, int a1, int a2, int a3, u8 *s);
extern int GIMMICK43_UpdateCameraShake(u8 *s);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GIMMICK43_IsLiftArrived(int *p);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern int GIMMICK43_GetLiftAnimeIndex(int *a, int i);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern void *FIELD_G3D_MAPPER_GetHeightEx(void *p);
extern void HEIGHT_EX_SetAreaHeight(u8 i, int v, int *p);
extern void GIMMICK43_ShowLiftAnime(int *a, void *b, int c);
extern u32 FIELDMAP_GetFog(u8 *p);
extern int FIELD_FOG_FADE_IsFade(u8 *p);
extern void GIMMICK43_UpdateBigLift(void *a);

int GIMMICK43_LiftEventMain(void *a, int *b)
{
    Vec pos;
    Vec vec;
    Vec vec2;
    int it;
    u32 cur;
    void *t;
    void *s;
    void *r;
    int *w;
    u32 h;
    int *q;
    void *m;
    int n;
    int i;
    int x;
    int y;
    u32 o;
    int k;
    int f;
    void *e;
    int c;

    t = GAME_EVENT_GetGameSystem(a);
    s = GAMESYSTEM_GetFieldMap(t);
    r = (void *)FIELDMAP_GetExpObj(s);
    w = FIELDMAP_GetCommonWork(s, 1);
    h = (u32)FIELDMAP_GetCamera(s);
    q = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(s))), 7);
    switch (*b) {
    case 0:
        n = 0;
        it = 0;
        m = FIELDMAP_GetMmdlSys((void *)s);
        for (i = 0; i < 5; i++) {
            w[17 + i] = 0;
        }
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((void *)s), (struct VecFx32 *)&pos);
        while (FLDMMDL_SysSearchUseMmdl(m, (struct Rec **)(&cur), (u32 *)(&it)) == 1) {
            x = FLDMMDL_GetGridNowX((void *)cur);
            y = FLDMMDL_GetGridNowZ((void *)cur);
            if (GIMMICK43_IsInLiftZone(w[0], x, y)) {
                FLDMMDL_GetPos((const struct Actor *)cur, (struct VecFx32 *)&vec);
                if (pos.y - 0x10000 < vec.y && vec.y < pos.y + 0x10000 && n < 5) {
                    w[17 + n++] = cur;
                }
            }
        }
        GIMMICK43_StartCameraShake((u8)w[0], w[3], 1, (u32)h, (u8 *)(w + 8));
        (*b)++;
        break;
    case 1:
        if (GIMMICK43_UpdateCameraShake((u8 *)(w + 8))) {
            (*b)++;
        }
        break;
    case 2:
        FIELD_CAMERA_EndDelay((u8 *)h);
        (*b)++;
        break;
    case 3:
        if (FIELD_CAMERA_IsDelayEnabled((u8 *)h) != 0) {
            break;
        }
        GFL_USE_PlaySeDefaultVolume((int)0x6ca);
        (*b)++;
    case 4:
        if (w[6] == 0) {
            w[1] += w[3];
        }
        if (GIMMICK43_IsLiftArrived(w)) {
            w[1] = w[2];
            GIMMICK43_StartCameraShake((u8)w[0], w[3], 0, (u32)h, (u8 *)(w + 8));
            GFL_USE_PlaySeDefaultVolume((int)0x6cb);
            (*b)++;
        }
        ((int *)FLD_EXP_OBJ_GetModelStatus(r, (int)0, (u16)w[0]))[1] = w[1];
        for (i = 0; i < 5; i++) {
            o = w[17 + i];
            if (o != 0) {
                vec2 = *FLDMMDL_GetPosPtr(o);
                vec2.y = w[1];
                FLDMMDL_SetGridNowY((void *)o, (s16)((vec2.y >> 4) / 4096));
                FLDMMDL_SetPos(o, &vec2);
            }
        }
        break;
    case 5:
        if (GIMMICK43_UpdateCameraShake((u8 *)(w + 8))) {
            (*b)++;
        }
        break;
    case 6:
        FIELD_CAMERA_RestartDelay((unsigned char *)h);
        k = w[0];
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(r, 0, (u16)k, (u16)GIMMICK43_GetLiftAnimeIndex(q, k)), 0);
        (*b)++;
        break;
    case 7:
        k = w[0];
        e = FLD_EXP_OBJ_GetAnime(r, 0, (u16)k, (u16)GIMMICK43_GetLiftAnimeIndex(q, k));
        f = 0;
        if (FLD_EXP_OBJ_IsAnimeStopped(e) == 0) {
            break;
        }
        if (q[w[0]]) {
            q[w[0]] = 0;
        } else {
            q[w[0]] = 1;
            f = 1;
        }
        c = (int)FIELD_G3D_MAPPER_GetHeightEx((void *)FIELDMAP_GetG3dMapper(s));
        HEIGHT_EX_SetAreaHeight(w[0] + 8, sGimmick43LiftHeights[w[0]].v[f], (int *)c);
        GIMMICK43_ShowLiftAnime(q, r, w[0]);
        if (w[0] != 5) {
            return 1;
        }
        (*b)++;
        break;
    case 8:
        if (FIELD_FOG_FADE_IsFade((u8 *)FIELDMAP_GetFog(s)) == 0) {
            return 1;
        }
        break;
    }
    GIMMICK43_UpdateBigLift(t);
    return 0;
}
