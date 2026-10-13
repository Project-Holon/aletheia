/*
 * function: GIMMICK39_Setup
 * address: 0x021F36FC
 * packet: pkt_ov039_021F36FC
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov039/unit_021F36C0.c and filed here.
 *
 * symbols:
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELDMAP_AllocCommonWork 0x02189764 thumb ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive 0x021BE760 thumb ov021
 *   FLD_EXP_OBJ_GetModelStatus 0x021BE480 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeLoop 0x021BE6B8 thumb ov021
 *   FIELDMAP_GetTcblSys 0x02188D30 thumb ov021
 *   func_02030DA8 0x02030DA8 arm
 *   sCartSetup 0x021F4C18 data ov039 a4
 *   sModelPos00 0x021F4D60 data ov039 a4
 *   sModelPos01 0x021F4D0C data ov039 a4
 *   sModelPos02 0x021F4D6C data ov039 a4
 *   sModelPos03 0x021F4D18 data ov039 a4
 *   sModelPos04 0x021F4D24 data ov039 a4
 *   sModelPos05 0x021F4D3C data ov039 a4
 *   sModelPos06 0x021F4D00 data ov039 a4
 *   sModelPos07 0x021F4CD0 data ov039 a4
 *   sModelPos08 0x021F4CDC data ov039 a4
 *   sModelPos09 0x021F4D30 data ov039 a4
 *   sModelPos10 0x021F4D48 data ov039 a4
 *   sModelPos11 0x021F4CE8 data ov039 a4
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FIELD_SOUND_SYSTEM_ClaimSlot 0x02028A7C thumb
 *   FIELD_SOUND_SYSTEM_TransferSlot 0x02028B18 thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeFrame 0x021BE6CC thumb ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame 0x021BE748 thumb ov021
 *   GIMMICK39_UpdateTask 0x021F3A34 thumb
 */

#include "../include/G_Vec.h"

struct Big;
struct Ctx;
struct SoundSys2;
struct Rec94;
struct BigObj;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    void *task;
    u8 sel;
    s8 idx;
    u8 mode;
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
    int v[4];
    u8 flag[8];
} Save;

typedef signed int     s32;
extern int FIELDMAP_GetExpObj(int *p);
extern Work *FIELDMAP_GetCommonWork(void *p, int idx);
extern u32 FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *a);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, u8 j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *s, u32 id);
extern void FIELD_SOUND_SYSTEM_TransferSlot(struct SoundSys2 *s, u32 id, u32 who);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, u8 k, int flag);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);
void GIMMICK39_UpdateTask(int a0, void *a1);
extern u16 FIELDMAP_GetHeapId(void *p);
extern void *FIELDMAP_AllocCommonWork(void *p, int id, int a, int b);
extern void FLD_EXP_OBJ_AddUnitFromArchive(int h, const void *res, int c);
extern void *FLD_EXP_OBJ_GetModelStatus(int h, int i, int j);
extern void FLD_EXP_OBJ_SetAnimeLoop(void *p, int i);
extern void *FIELDMAP_GetTcblSys(void *p);
extern void *func_02030DA8(void *mgr, void (*fn)(int, void *), void *work, u32 key);
extern const Vec sCartSetup, sModelPos00, sModelPos01, sModelPos02, sModelPos03, sModelPos04, sModelPos05, sModelPos06, sModelPos07, sModelPos08, sModelPos09, sModelPos10, sModelPos11;

void GIMMICK39_Setup(void *a)
{
    int h;
    Work *w;
    u32 t;
    Save *q;
    int snd;
    u32 i;
    int n;
    int f, g;
    u8 *p;
    u8 x;
    u8 j;
    void *o;

    h = FIELDMAP_GetExpObj(a);
    t = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(a));
    q = (Save *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave((struct Big *)t), 2);
    snd = GAME_DATA_GetBgmInfo((const struct BigObj *)t);
    FIELDMAP_AllocCommonWork(a, 1, FIELDMAP_GetHeapId(a), 0x21F4);
    FLD_EXP_OBJ_AddUnitFromArchive(h, &sCartSetup, 0);
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 0) = sModelPos00;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 1) = sModelPos01;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 2) = sModelPos02;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 3) = sModelPos03;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 4) = sModelPos04;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 5) = sModelPos05;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 6) = sModelPos06;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 7) = sModelPos07;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 8) = sModelPos08;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 9) = sModelPos09;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 10) = sModelPos10;
    *(Vec *)FLD_EXP_OBJ_GetModelStatus(h, 0, 11) = sModelPos11;
    for (i = 0; i < 4; i = (u8)(i + 1)) {
        j = i;
        p = (u8 *)q + i;
        x = p[0x10] ? i * 2 + 2 : i * 2 + 1;
        FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, j, x, 1);
        FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, j, 0, 1);
        o = FLD_EXP_OBJ_GetAnime((char *)h, 0, j, 0);
        FLD_EXP_OBJ_SetAnimePaused(o, 1);
        FLD_EXP_OBJ_SetAnimeLoop(o, 0);
        FLD_EXP_OBJ_SetAnimeFrame(h, 0, j, x, q->v[i]);
        j = i + 4;
        f = p[0x10];
        FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, j, f, 1);
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime((char *)h, 0, j, 0), 0);
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime((char *)h, 0, j, 1), 0);
        FLD_EXP_OBJ_SetAnimeFrame(h, 0, j, f, FLD_EXP_OBJ_GetAnimeLastFrame((u32)FLD_EXP_OBJ_GetAnime((char *)h, 0, j, f)));
        g = p[0x10];
        j = i + 8;
        FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, j, g, 1);
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime((char *)h, 0, j, 0), 0);
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime((char *)h, 0, j, 1), 0);
        FLD_EXP_OBJ_SetAnimeFrame(h, 0, j, g, FLD_EXP_OBJ_GetAnimeLastFrame((u32)FLD_EXP_OBJ_GetAnime((char *)h, 0, j, g)));
    }
    w = FIELDMAP_GetCommonWork(a, 1);
    w->task = func_02030DA8(FIELDMAP_GetTcblSys(a), GIMMICK39_UpdateTask, a, 0);
    for (n = 0; n < 4; n++) {
        w->req[n] = 0;
        w->cur[n] = n * 2 + q->flag[n];
        w->slot[n] = -1;
    }
    w->idx = -1;
    w->hold = -1;
    w->sel = 0xff;
    FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)snd, 0x68A);
    FIELD_SOUND_SYSTEM_TransferSlot((struct SoundSys2 *)snd, 0x68A, 0);
}
