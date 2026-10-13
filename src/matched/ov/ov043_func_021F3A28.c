/*
 * function: FIELD_GIMMICK_LIFT_ELEVATOR_CallElevatorEvent
 * address:  0x021F3A28
 * packet:   pkt_ov043_021F3A28
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   FIELD_GIMMICK_LIFT_ELEVATOR_ElevatorEventMain  0x021F3D78  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FIELDMAP_GetExpObj(int *p);
extern void  FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int FIELD_GIMMICK_LIFT_ELEVATOR_ElevatorEventMain(void *a, int *b);

void FIELD_GIMMICK_LIFT_ELEVATOR_CallElevatorEvent(void *a0, int a1)
{
    void *r6;
    int *r4;
    void *x;
    int d;

    r6 = GAMESYSTEM_GetFieldMap(a0);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(r6))), 7);
    r4 = FIELDMAP_GetCommonWork(r6, 1);
    r4[5] = a1;
    if (a1) {
        r4[1] = 0x320000;
        r4[2] = 0x370000;
    } else {
        r4[1] = 0x370000;
        r4[2] = 0x320000;
        x = (void *)FIELDMAP_GetExpObj(r6);
        FLD_EXP_OBJ_SetAnimeEnabled(x, 0, 7, 1, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(x, 0, 7, 0, 0);
    }
    d = r4[2] - r4[1];
    if (d < 0) {
        d = -0x2000;
    } else {
        d = 0x2000;
    }
    r4[3] = d;
    func_020122C0(a0, 0, FIELD_GIMMICK_LIFT_ELEVATOR_ElevatorEventMain, 0);
}
