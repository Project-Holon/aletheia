/*
 * function: GIMMICK39_UpdateTask
 * address:  0x021F3A34
 * packet:   pkt_ov039_021F3A34
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     spill slots follow reverse declaration order (last declared, lowest
 *           slot): d, v, qr, j2, sr, b, a gives a 8, b 0xc, sr 0x10, j2 0x14, qr 0x18,
 *           v 0x1c, d 0x20. The row pointers qr (q + j) and sr (s + j) and j2 = 2 * j
 *           are named locals so they take their declared places, and `b = v + 1`
 *           keeps v a real variable (with `b = s->cur[j] + 1` a CSE temporary
 *           takes the first slot instead). sStopDocks and sRideAnimeOrigin need the ov039 token.
 *
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   GIMMICK39_GetAnimeFrame 0x021F3DE4 thumb ov039
 *   GIMMICK39_SwapCartAnimes 0x021F47D8 thumb ov039
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   ICA_ANIME_CreateWithFullBuffer 0x02011428 thumb
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FIELD_SOUND_SYSTEM_ClaimSlot 0x02028A7C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   FIELD_SOUND_SYSTEM_TransferSlot 0x02028B18 thumb
 *   GFL_USE_GetSeHandle 0x02006138 thumb
 *   NNS_SndHandleSetSeqPriority 0x02072F34 arm
 *   FLD_EXP_OBJ_GetAnimeFrame 0x021BE6E8 thumb ov021
 *   GIMMICK39_FindStopAtFrame 0x021F4864 thumb ov039
 *   FIELD_SOUND_SYSTEM_ReleaseSlot 0x02028B50 thumb
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   ICA_ANIME_GetTranslateAt 0x02011688 thumb
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FIELD_PLAYER_SetPos 0x021A3044 thumb ov021
 *   GIMMICK39_UpdateCartSound 0x021F4A18 thumb ov039
 *   sRideAnimeIds    0x021F4C38 data a4
 *   sStopDocks    0x021F4C28 data ov039 a1
 *   sRideAnimeOrigin    0x021F4D54 data ov039 a4
 *   sLaneRideOffsets    0x021F4CA0 data a4
 */

#include "../include/G_Vec.h"

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

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
    u8 pad0[0x10];
    u8 flag[8];
} Save;

extern int FIELDMAP_GetExpObj(int *p);
extern Work *FIELDMAP_GetCommonWork(void *p, int idx);
extern u32 FIELDMAP_GetGameSystem(void *p);
struct Big;
struct Ctx;
struct IcaAnime;
struct SoundSys2;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *a);
extern int GIMMICK39_GetAnimeFrame(void *p, u16 delta, u16 i);
extern void GIMMICK39_SwapCartAnimes(void *a, int f, int i);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern u32 ICA_ANIME_CreateWithFullBuffer(u32 heap, u32 a1, u16 a2, void *a3, u32 a4);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *s, u32 id);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GFL_USE_GetSeSlot(u32 a);
extern void FIELD_SOUND_SYSTEM_TransferSlot(struct SoundSys2 *s, u32 id, u32 who);
extern u32 *GFL_USE_GetSeHandle(int i);
struct Obj;
struct Rec;
struct Rec12;
extern void NNS_SndHandleSetSeqPriority(struct Obj *o, u8 v);
extern int FLD_EXP_OBJ_GetAnimeFrame(int p, int i, u8 j, u8 k);
extern int GIMMICK39_FindStopAtFrame(u32 a, u32 b, u8 *out);
extern void FIELD_SOUND_SYSTEM_ReleaseSlot(u8 *p, int a0);
extern void GFL_USE_StopAllSe(void);
extern u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *p, struct Rec12 *dst, u32 idx);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern void GIMMICK39_UpdateCartSound(void *a0, struct Rec *a1);

extern u32 sRideAnimeIds[];
extern s8 sStopDocks[][2];
extern Vec sRideAnimeOrigin;
extern struct Vec sLaneRideOffsets[];

void GIMMICK39_UpdateTask(int a0, void *a1)
{
    u8 i;
    int j;
    int h;
    Work *s;
    u32 t;
    Save *q;
    int w;
    int d;
    u8 v;
    u8 *qr;
    int j2;
    s8 *sr;
    u8 b;
    u8 a;
    void *o;
    int snd;
    u8 k;
    Vec pos;
    u8 buf[4];
    u32 tmp2;

    h = FIELDMAP_GetExpObj(a1);
    s = FIELDMAP_GetCommonWork(a1, 1);
    t = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(a1));
    q = (Save *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave((struct Big *)t), 2);
    w = GAME_DATA_GetBgmInfo((const struct BigObj *)t);
    for (i = 0; i < 4; i++) {
        j = i;
        if (s->req[j] != 0) {
            qr = (u8 *)q + j;
            d = (u8)((qr[0x10] + 1) % 2);
            j2 = j * 2;
            if (GIMMICK39_GetAnimeFrame((void *)h, (u8)j, (u8)(d + (j2 + 1))) == 0) {
                GIMMICK39_SwapCartAnimes((void *)h, d, j);
                tmp2 = qr[0x10];
                s->cur[j] = j2 + tmp2;
                if (s->sel != 0xff && ((u32)s->sel >> 1) == j && s->sel != s->cur[j]) {
                    s->sel = s->cur[j];
                    ICA_ANIME_Delete((struct IcaAnime *)s->anim);
                    s->anim = ICA_ANIME_CreateWithFullBuffer(0x8015, 0x6b, sRideAnimeIds[s->sel], s->f1c, 0x21C0);
                }
                s->req[j] = 0;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        j = i;
        sr = (s8 *)s + j;
        v = s->cur[j];
        b = v + 1;
        a = j;
        o = FLD_EXP_OBJ_GetAnime((char *)h, 0, a, b);
        if (s->timer[j] != 0) {
            if (s->hold != j && --s->timer[j] == 0) {
                FLD_EXP_OBJ_SetAnimePaused(o, 0);
                if (s->sel != 0xff && j == ((u32)s->sel >> 1)) {
                    FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)w, 0x68A);
                    GFL_USE_PlaySeDefaultVolume(0x6DB);
                    snd = GFL_USE_GetSeSlot(0x6DB);
                    FIELD_SOUND_SYSTEM_TransferSlot((struct SoundSys2 *)w, 0x68A, 0x7f);
                    NNS_SndHandleSetSeqPriority((struct Obj *)GFL_USE_GetSeHandle(snd), 0);
                }
                sr[0x21F0] = -1;
            }
        } else if (GIMMICK39_FindStopAtFrame(v, FLD_EXP_OBJ_GetAnimeFrame(h, 0, a, b), buf)) {
            FLD_EXP_OBJ_SetAnimePaused(o, 1);
            if (s->sel != 0xff && j == ((u32)s->sel >> 1)) {
                FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)w, 0x68A);
                GFL_USE_StopAllSe();
            }
            s->timer[j] = 0x5a;
            sr[0x21F0] = sStopDocks[v][buf[0]];
        }
    }
    if (s->active != 0) {
        pos = sRideAnimeOrigin;
        k = s->sel >> 1;
        if (ICA_ANIME_GetTranslateAt((struct IcaAnime *)s->anim, (struct Rec12 *)(&pos), FLD_EXP_OBJ_GetAnimeFrame(h, 0, k, s->sel + 1) / 4096)) {
            pos.x += sLaneRideOffsets[k].x;
            pos.y += sLaneRideOffsets[k].y;
            pos.z += sLaneRideOffsets[k].z;
            FIELD_PLAYER_SetPos(FIELDMAP_GetFieldPlayer((void *)a1), &pos);
        }
    } else {
        GIMMICK39_UpdateCartSound(a1, (struct Rec *)s);
    }
}
