/*
 * function: FIELD_GIMMICK_LIFT_ELEVATOR_CallLiftEvent
 * address:  0x021F398C
 * packet:   pkt_ov043_021F398C
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GIMMICK_LIFT_ELEVATOR_CallLiftEvent  0x021F398C  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   FIELD_GIMMICK_LIFT_ELEVATOR_LiftEventMain  0x021F3AC0  thumb
 *   sGimmick43LiftHeights    0x021F4490  data  a4
 */

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int pad[4];
} E;

extern E sGimmick43LiftHeights[];

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned char  u8;
struct Big;
struct Desc;
extern void *FIELDMAP_GetGameSystem(void *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int FIELD_GIMMICK_LIFT_ELEVATOR_LiftEventMain(void *a, int *b);

int FIELD_GIMMICK_LIFT_ELEVATOR_CallLiftEvent(void *a, int b)
{
    void *s;
    int *q;
    int *p;
    int step;

    s = GAMESYSTEM_GetFieldMap((void *)a);
    q = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(s))), 7);
    p = FIELDMAP_GetCommonWork(s, 1);
    if (b >= 6) {
        return 0;
    }
    p[0] = b;
    if (q[b] != 0) {
        p[1] = sGimmick43LiftHeights[b].b;
        p[2] = sGimmick43LiftHeights[b].a;
    } else {
        p[1] = sGimmick43LiftHeights[b].a;
        p[2] = sGimmick43LiftHeights[b].b;
    }
    if (b == 5) {
        step = 0x8000;
        p[15] = 1;
    } else {
        step = 0x4000;
        p[15] = 0;
    }
    if (p[2] - p[1] < 0) {
        p[3] = -step;
    } else {
        p[3] = step;
    }
    p[16] = 0;
    return (int)func_020122C0(a, 0, FIELD_GIMMICK_LIFT_ELEVATOR_LiftEventMain, 0);
}
