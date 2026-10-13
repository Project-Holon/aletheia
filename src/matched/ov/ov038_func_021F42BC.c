/*
 * function: GIMMICK38_EventPressPlate
 * address:  0x021F42BC
 * packet:   pkt_ov038_021F42BC
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the work block's two int arrays are struct fields (index*4 then
 *           [#0x20]/[#0x48]); the flag test is `if (n != -1) { if (a[n])
 *           f = 1; } else f = 1;`, whose cross-jumped else arm gives the
 *           `beq SET ... beq SKIP; b SET` shape (an `||` or else-if does not).
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem 0x020124E4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 *   FLD_EXP_OBJ_SetAnimeFrame 0x021BE6CC thumb ov021
 *   FLD_EXP_OBJ_SetModelHidden 0x021BE4B4 thumb ov021
 *   FLD_EXP_OBJ_GetModelStatus 0x021BE480 thumb ov021
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   gGimmick38PlatePrerequisite    0x021F4628 data a1
 *   gGimmick38PlateDoor    0x021F4632 data a1
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u8 pad[0x20];
    int a[10];
    int b[10];
} Work;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern u8 *FIELDMAP_GetCommonWork(void *p, int idx);
extern u32 FIELDMAP_GetGameSystem(u8 *p);
struct Big;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, int j, u16 k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern Vec *FLD_EXP_OBJ_GetModelStatus(char *p, int i, int j);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern const s8 gGimmick38PlatePrerequisite[];
extern const u8 gGimmick38PlateDoor[];

int GIMMICK38_EventPressPlate(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    Work *p;
    int i;
    int f;
    u8 c;
    u8 m;
    s8 n;
    Vec *v;

    sys = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)a0));
    h = FIELDMAP_GetExpObj(sys);
    s = FIELDMAP_GetCommonWork(sys, 1);
    p = (Work *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(sys))), 6);
    switch (*a1) {
    case 0:
        c = s[1] + 8;
        for (i = 0; i < 2; i++) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, c, (u16)i, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, c, i), 0);
        }
        *a1 = *a1 + 1;
        break;
    case 1:
        f = 0;
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)h, 0, (u8)(s[1] + 8), 0))) {
            p->a[s[1]] = 1;
            n = gGimmick38PlatePrerequisite[s[1]];
            if (n != -1) {
                if (p->a[n] != 0) {
                    f = 1;
                }
            } else {
                f = 1;
            }
            if (f) {
                m = gGimmick38PlateDoor[s[1]];
                if (p->b[m] == 0) {
                    s[4] = m;
                    c = m + 0x12;
                    FLD_EXP_OBJ_SetModelHidden((char *)h, 0, (u16)c, 1);
                    FLD_EXP_OBJ_SetModelHidden((char *)h, 0, (u16)0x21, 0);
                    v = FLD_EXP_OBJ_GetModelStatus((char *)h, 0, c);
                    *FLD_EXP_OBJ_GetModelStatus((char *)h, 0, 0x21) = *v;
                    for (i = 0; i < 4; i++) {
                        c = i + 4;
                        FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, 0x21, (u16)c, 1);
                        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, 0x21, c), 0);
                        FLD_EXP_OBJ_SetAnimeFrame((int)((void *)h), 0, 0x21, c, 0);
                    }
                    GFL_USE_PlaySeDefaultVolume(0x6C8);
                    *a1 = *a1 + 1;
                    break;
                }
                return 1;
            }
            return 1;
        }
        break;
    case 2:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)h, 0, 0x21, 4))) {
            for (i = 0; i < 4; i++) {
                FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, 0x21, (u16)((u8)(i + 4)), 0);
            }
            p->b[s[4]] = 1;
            m = s[4];
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, (u16)(m + 0x12), 1);
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, (u16)(m + 0x19), 0);
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, (u16)0x21, 1);
            GFL_USE_PlaySeDefaultVolume(0x6DC);
            return 1;
        }
        break;
    }
    return 0;
}
