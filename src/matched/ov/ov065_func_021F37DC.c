/*
 * function: GIMMICK65_Update
 * address:  0x021F37DC
 * packet:   pkt_ov065_021F37DC
 * region:   ov065
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void FLD_EXP_OBJ_UpdateAnimes(int a);
extern int FLD_EXP_OBJ_GetAnimeFrame(int a, int b, int c, int d);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);

void GIMMICK65_Update(int a)
{
    int s;
    int *w;

    s = FIELDMAP_GetExpObj((int *)a);
    w = FIELDMAP_GetCommonWork((char *)a, 1);
    if (w[0] != 0) {
        FLD_EXP_OBJ_UpdateAnimes(s);
        if (w[1] == 0) {
            if (FLD_EXP_OBJ_GetAnimeFrame(s, 0, 0, 0) == 0x3C000)
                func_020061E4(0x7F9);
        }
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)s, 0, 0, 0)) != 0) {
            FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 0, 1);
            w[0] = 0;
            *GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))), 0x36) = 0;
        }
    }
}
