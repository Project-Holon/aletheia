/*
 * function: GIMMICK39_UpdateCartSound
 * address: 0x021F4A18
 * packet: pkt_ov039_021F4A18
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FIELD_PLAYER_GetPos 0x021A3038 thumb ov021
 *   FLD_EXP_OBJ_GetModelObject 0x021BE4C4 thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame 0x021BE748 thumb ov021
 *   GIMMICK39_GetAnimeFrame 0x021F3DE4 thumb ov039
 *   GIMMICK39_SampleJointTranslation 0x021F48C0 thumb ov039
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   FIELD_SOUND_SYSTEM_TransferSlot 0x02028B18 thumb
 *   G3D_SYSTEM_GetObjectAnime 0x02047790 arm
 *   G3D_SYSTEM_GetAnimeObj 0x02047674 arm
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   sLaneRideOffsets 0x021F4CA0 data a4
 *
 * note (2026-10-05, wave D5 lane 13): EXACT. The byte array at +0x21EC is a struct
 * field indexed by k (`p->cnt[k]`), not a pointer q = a1 + k; the CSE temp a1 + k then
 * takes the slot below n, as in the original.
 */

#include "../../../matched/include/G_Vec.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec Vec;

typedef struct Rec {
    u8 pad[0x21EC];
    u8 cnt[4];
} Rec;

extern struct Vec sLaneRideOffsets[];

struct BigObj;
struct Ctx;
struct SoundSys2;
struct VecFx32;
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_GetGameSystem(void *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_GetPos(u8 *p, struct VecFx32 *out);
extern int FLD_EXP_OBJ_GetModelObject(void *p, u32 i, u16 j);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);
extern int GIMMICK39_GetAnimeFrame(void *p, u16 j, u16 k);
extern void GIMMICK39_SampleJointTranslation(u8 *a, int idx, int x, int *out);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_TransferSlot(struct SoundSys2 *s, u32 id, u32 who);
extern int G3D_SYSTEM_GetObjectAnime(int a, u16 n);
extern int G3D_SYSTEM_GetAnimeObj(int p);
extern void func_0207C9D0(const Vec *a, const Vec *b, Vec *out);
extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern int func_0207CBD0(const Vec *v);

void GIMMICK39_UpdateCartSound(void *a0, Rec *a1)
{
    int pos;
    int h;
    int best;
    int bestK;
    int bestN;
    int first;
    void *snd;
    int h2;

    u8 n;
    void *sys;
    int i;
    int vol;

    sys = (void *)FIELDMAP_GetExpObj(a0);
    snd = (void *)GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a0)));
    first = 1;
    for (i = 0; i < 4; i++) {
        int k = (u8)i;
        u8 kk = k;
        Vec v6c;
        Vec v60;
        Vec v54;
        int d;

        h = FLD_EXP_OBJ_GetModelObject(sys, 0, kk);
        
        n = a1->cnt[k] + 1;
        FLD_EXP_OBJ_GetAnime(sys, 0, (u16)kk, (u16)n);
        pos = GIMMICK39_GetAnimeFrame(sys, kk, n);
        GIMMICK39_SampleJointTranslation(*(void **)(G3D_SYSTEM_GetAnimeObj(G3D_SYSTEM_GetObjectAnime(h, n)) + 8), 0, pos, (int *)(&v6c));
        func_0207C9D0(&v6c, &sLaneRideOffsets[k], &v6c);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(a0), (struct VecFx32 *)(&v60));
        func_0207CA00(&v6c, &v60, &v54);
        d = func_0207CBD0(&v54);
        if (best > d || first) {
            best = d;
            bestK = kk;
            bestN = a1->cnt[k] + 1;
            first = 0;
        }
    }
    if (best >= 0x60000) {
        vol = 0;
    } else {
        int lim;
        int cur;
        int nxt;
        u8 *img;
        Vec a48;
        Vec a3c;
        Vec a30;
        int d;

        h2 = FLD_EXP_OBJ_GetModelObject(sys, 0, bestK);
        lim = FLD_EXP_OBJ_GetAnimeLastFrame((u32)FLD_EXP_OBJ_GetAnime(sys, 0, (u16)bestK, (u16)bestN));
        cur = GIMMICK39_GetAnimeFrame(sys, bestK, bestN);
        nxt = cur + 0x1000;
        if (nxt >= lim)
            nxt = 0;
        img = (u8 *)G3D_SYSTEM_GetAnimeObj(G3D_SYSTEM_GetObjectAnime(h2, bestN));
        vol = 0;
        GIMMICK39_SampleJointTranslation(*(void **)(img + 8), 0, cur, (int *)(&a48));
        GIMMICK39_SampleJointTranslation(*(void **)(img + 8), 0, nxt, (int *)(&a3c));
        func_0207CA00(&a48, &a3c, &a30);
        d = func_0207CBD0(&a30);
        if (d >= 0x20000)
            vol = 0x7F;
        else if (d >= 0x18000)
            vol = 0x78;
        else if (d >= 0x10000)
            vol = 0x5A;
        else if (d >= 0x8000)
            vol = 0x3C;
    }
    FIELD_SOUND_SYSTEM_TransferSlot(snd, 0x68A, vol);
}
