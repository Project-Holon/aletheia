/*
 * function: FIELD_GIMMICK_CART_LANES_RideEventMain
 * address:  0x021F41A8
 * packet:   pkt_ov039_021F41A8
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     2026-10-05 final push G2L1: closed. Case 5 stored s->hold before movs r1,#1 only when
 *           FLD_EXP_OBJ_GetAnime takes (char *, int, u8 j, u8 k), as the matched caller ov039 021F404C declares
 *           it (earlier drafts used unsigned int j, int k; with u8 parameters the call site is
 *           the same but the pair order in case 5 follows the original). The FIELD_GIMMICK_CART_LANES_GetAnimeFrame call keeps
 *           (u8)(s->sel + 1) for its u16 parameter.
 * symbols:
 *   GAME_EVENT_GetGameSystem 0x020124E4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 *   FLD_EXP_OBJ_GetModelObject 0x021BE4C4 thumb ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame 0x021BE748 thumb ov021
 *   FIELD_GIMMICK_CART_LANES_SetAnimeFrame 0x021F3E04 thumb ov039
 *   FIELD_GIMMICK_CART_LANES_GetAnimeFrame 0x021F3DE4 thumb ov039
 *   FIELD_GIMMICK_CART_LANES_SampleJointTranslation 0x021F48C0 thumb ov039
 *   ICA_ANIME_CreateWithFullBuffer 0x02011428 thumb
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   GFL_USE_GetSeHandle 0x02006138 thumb
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot 0x02028A7C thumb
 *   FIELD_SOUND_SYSTEM_TransferSlot 0x02028B18 thumb
 *   FIELD_SOUND_SYSTEM_ReleaseSlot 0x02028B50 thumb
 *   NNS_SndHandleSetVolume 0x02072F34 arm
 *   KEY_GetCont 0x0203630C arm
 *   G3D_SYSTEM_GetObjectAnime 0x02047790 arm
 *   G3D_SYSTEM_GetAnimeObj 0x02047674 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   SCRIPT_SYS_CallScriptEvent 0x02158780 thumb ov010
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FIELD_PLAYER_GetMmdl 0x021A3074 thumb ov021
 *   FIELD_PLAYER_SetPos 0x021A3044 thumb ov021
 *   FLDMMDL_SetStatusBitVanish 0x0216DAC8 thumb
 *   FLDMMDL_SetDirDispCheckPause 0x0216D5E0 thumb
 *   sRideAnimeIds    0x021F4C38 data a4
 *   sDockCells    0x021F4C58 data ov039 a4
 *   sRideExitPos    0x021F4CF4 data ov039 a4
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u16 x;
    u16 z;
} Cell;

typedef struct {
    u8 pad0[4];
    u8 sel;
    u8 pad5[2];
    s8 hold;
    int timer[4];
    u32 anim;
    u8 f1c[0x21E4 - 0x1C];
    int active;
    u8 req[4];
    u8 cur[4];
    s8 slot[4];
} Work;

typedef struct {
    u8 pad0[8];
    u8 *mdl;
} Res;

struct Ctx;
struct Obj;
struct Big;
struct BigObj;
struct IcaAnime;
struct SoundSys2;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern Work *FIELDMAP_GetCommonWork(void *p, int idx);
extern u32 FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *a);
extern int GFL_USE_GetSeSlot(u32 a);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, u8 j, u8 k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void *FLD_EXP_OBJ_GetModelObject(void *p, u32 i, int delta);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);
extern void FIELD_GIMMICK_CART_LANES_SetAnimeFrame(void *p, u8 delta, u16 i, int frame);
extern int FIELD_GIMMICK_CART_LANES_GetAnimeFrame(void *p, u16 delta, u16 i);
extern void FIELD_GIMMICK_CART_LANES_SampleJointTranslation(u8 *a, int idx, int x, int *out);
extern void *ICA_ANIME_CreateWithFullBuffer(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GFL_USE_StopSeSlot(int i);
extern u32 *GFL_USE_GetSeHandle(int i);
extern void GFL_USE_StopAllSe(void);
extern void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *s, u32 id);
extern void FIELD_SOUND_SYSTEM_TransferSlot(struct SoundSys2 *s, u32 id, u32 who);
extern void FIELD_SOUND_SYSTEM_ReleaseSlot(u8 *p, int a0);
extern void NNS_SndHandleSetVolume(struct Obj *o, u8 v);
extern unsigned int KEY_GetCont(void);
extern int G3D_SYSTEM_GetObjectAnime(int *p, int i);
extern int G3D_SYSTEM_GetAnimeObj(int p);
extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern int func_0207CBD0(const Vec *a);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern void FLDMMDL_SetStatusBitVanish(void *o, u32 v);
extern void FLDMMDL_SetDirDispCheckPause(void *o, u32 v);

extern u32 sRideAnimeIds[];
extern Cell sDockCells[];
extern Vec sRideExitPos;

int FIELD_GIMMICK_CART_LANES_RideEventMain(void *a0, int *a1)
{
    void *sys;
    int h;
    Work *s;
    u32 w;
    int snd;
    int c;
    void *q;
    u8 j;
    void *o;
    void *p;
    void *m;
    Res *r;
    int f2;
    u8 k;
    int f;
    int n;
    int d;
    u8 vol;
    Vec t;
    Vec a;
    Vec b;
    Vec e;

    sys = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(a0));
    h = FIELDMAP_GetExpObj(sys);
    s = FIELDMAP_GetCommonWork(sys, 1);
    w = GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(sys)));
    snd = GFL_USE_GetSeSlot(0x6DB);
    c = (u8)(s->sel >> 1);
    j = c;
    o = FLD_EXP_OBJ_GetAnime((char *)h, 0, j, 0);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(sys))), 2);
    switch (*a1) {
    case 0:
        s->anim = (u32)ICA_ANIME_CreateWithFullBuffer(0x8015, 0x6b, (u16)sRideAnimeIds[s->sel], (u32)s->f1c, 0x21C0);
        FIELD_GIMMICK_CART_LANES_SetAnimeFrame((void *)h, j, 0, 0);
        FLD_EXP_OBJ_SetAnimePaused(o, 0);
        GFL_USE_PlaySeDefaultVolume(0x687);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (FIELD_GIMMICK_CART_LANES_GetAnimeFrame((void *)h, j, 0) < 0xF000) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(o, 1);
        SCRIPT_SYS_CallScriptEvent(a0, 0xD, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 2:
        FLD_EXP_OBJ_SetAnimePaused(o, 0);
        GFL_USE_PlaySeDefaultVolume(0x687);
        *a1 = *a1 + 1;
        break;
    case 3:
        if (FLD_EXP_OBJ_IsAnimeStopped(o) == 0) {
            break;
        }
        FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(sys)), 1);
        FLD_EXP_OBJ_SetAnimePaused(o, 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, j, s->sel + 1), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        s->hold = -1;
        FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)w, 0x68A);
        GFL_USE_PlaySeDefaultVolume(0x6DB);
        NNS_SndHandleSetVolume((struct Obj *)GFL_USE_GetSeHandle(snd), 0);
        FIELD_SOUND_SYSTEM_TransferSlot((struct SoundSys2 *)w, 0x68A, 0x7f);
        s->active = 1;
        *a1 = *a1 + 1;
        break;
    case 4:
        if (s->slot[c] == -1) {
            break;
        }
        if (KEY_GetCont() & 0x80) {
            *a1 = *a1 + 1;
        }
        break;
    case 5:
        p = FLD_EXP_OBJ_GetAnime((char *)h, 0, j, s->sel + 1);
        s->hold = c;
        FLD_EXP_OBJ_SetAnimePaused(p, 1);
        FIELD_GIMMICK_CART_LANES_SetAnimeFrame((void *)h, j, 0, 0);
        FLD_EXP_OBJ_SetAnimePaused(o, 0);
        GFL_USE_PlaySeDefaultVolume(0x687);
        p = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(sys));
        FLDMMDL_SetDirDispCheckPause(p, 1);
        FLDMMDL_SetStatusBitVanish(p, 0);
        *a1 = *a1 + 1;
        break;
    case 6:
        if (FIELD_GIMMICK_CART_LANES_GetAnimeFrame((void *)h, j, 0) < 0xF000) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(o, 1);
        m = FIELDMAP_GetFieldPlayer(sys);
        t = sRideExitPos;
        k = s->slot[c];
        t.x = (sDockCells[k].x << 16) + 0x8000;
        t.z = ((sDockCells[k].z - 2) << 16) + 0x8000;
        FIELD_PLAYER_SetPos(m, &t);
        s->active = 0;
        *a1 = *a1 + 1;
        break;
    case 7:
        SCRIPT_SYS_CallScriptEvent(a0, 0xE, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 8:
        FLD_EXP_OBJ_SetAnimePaused(o, 0);
        GFL_USE_PlaySeDefaultVolume(0x687);
        *a1 = *a1 + 1;
        break;
    case 9:
        if (FLD_EXP_OBJ_IsAnimeStopped(o) == 0) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(o, 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, j, s->sel + 1), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        ICA_ANIME_Delete((struct IcaAnime *)s->anim);
        s->hold = -1;
        s->sel = 0xff;
        FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)w, 0x68A);
        FIELD_SOUND_SYSTEM_TransferSlot((struct SoundSys2 *)w, 0x68A, 0);
        GFL_USE_StopSeSlot(snd);
        return 1;
    }
    if ((u8)(s->sel + 0xFE) <= 3) {
        f = FIELD_GIMMICK_CART_LANES_GetAnimeFrame((void *)h, j, (u8)(s->sel + 1));
        switch (s->sel) {
        case 2:
            if (f == 0xBF000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)w, 0x68A);
                GFL_USE_StopAllSe();
                GFL_USE_PlaySeDefaultVolume(0x68B);
            } else if (f == 0xEB000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)w, 0x68A);
                GFL_USE_StopAllSe();
            } else if (f == 0xFF000) {
                GFL_USE_PlaySeDefaultVolume(0x68C);
            }
            break;
        case 3:
            if (f == 0x108000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)w, 0x68A);
                GFL_USE_StopAllSe();
                GFL_USE_PlaySeDefaultVolume(0x68B);
            } else if (f == 0x131000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)w, 0x68A);
                GFL_USE_StopAllSe();
            } else if (f == 0x148000) {
                GFL_USE_PlaySeDefaultVolume(0x68C);
            }
            break;
        case 4:
            if (f == 0xB1000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)w, 0x68A);
                GFL_USE_StopAllSe();
                GFL_USE_PlaySeDefaultVolume(0x6D2);
            }
            break;
        case 5:
            if (f == 0xB6000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)w, 0x68A);
                GFL_USE_StopAllSe();
                GFL_USE_PlaySeDefaultVolume(0x6D2);
            }
            break;
        }
    }
    q = FLD_EXP_OBJ_GetModelObject((void *)h, 0, j);
    k = s->sel + 1;
    n = FLD_EXP_OBJ_GetAnimeLastFrame((u32)FLD_EXP_OBJ_GetAnime((char *)h, 0, j, k));
    f = FIELD_GIMMICK_CART_LANES_GetAnimeFrame((void *)h, j, k);
    f2 = f + 0x1000;
    if (f2 >= n) {
        f2 = 0;
    }
    r = (Res *)G3D_SYSTEM_GetAnimeObj(G3D_SYSTEM_GetObjectAnime(q, (u16)k));
    vol = 0;
    FIELD_GIMMICK_CART_LANES_SampleJointTranslation(r->mdl, 0, f, (int *)(&a));
    FIELD_GIMMICK_CART_LANES_SampleJointTranslation(r->mdl, 0, f2, (int *)(&b));
    func_0207CA00(&a, &b, &e);
    d = func_0207CBD0(&e);
    if (d >= 0x20000) {
        vol = 0x7f;
    } else if (d >= 0x18000) {
        vol = 0x5a;
    } else if (d >= 0x10000) {
        vol = 0x3c;
    } else if (d >= 0x8000) {
        vol = 0x1e;
    }
    NNS_SndHandleSetVolume((struct Obj *)GFL_USE_GetSeHandle(snd), vol);
    return 0;
}
