/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_Update
 * address:  0x021F3A28
 * packet:   pkt_ov046_021F3A28
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_GIMMICK_ROTATING_ROOM_IsPosInside  0x021F40D8  thumb  ov046
 *   FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden  0x021F3FA8  thumb  ov046
 */

typedef unsigned int u32;
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FLD_EXP_OBJ_UpdateAnimes(u32);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern int FIELD_GIMMICK_ROTATING_ROOM_IsPosInside(int *);
extern void FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden(char *a, u32 b, u32 c);

void FIELD_GIMMICK_ROTATING_ROOM_Update(void *a)
{
    int v[3];
    u32 r7 = FIELDMAP_GetExpObj(a);
    int *r6 = FIELDMAP_GetCommonWork(a, 1);
    int r4 = 1;

    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a))), 10);
    FLD_EXP_OBJ_UpdateAnimes(r7);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((void *)a), (struct VecFx32 *)v);
    if (FIELD_GIMMICK_ROTATING_ROOM_IsPosInside(v) == 0)
        r4 = 0;
    if (r6[9] != r4) {
        FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden((char *)r7, (u32)a, r4);
        r6[9] = r4;
    }
}
