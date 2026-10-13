/*
 * function: GIMMICK46_RotateEventProc
 * address:  0x021F3D40
 * packet:   pkt_ov046_021F3D40
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GIMMICK46_PlayAnimEventProc  0x021F3DE8  thumb  ov046
 *   GIMMICK46_CalcUnitPose  0x021F3BC8  thumb  ov046
 *   GIMMICK46_GetRotateAnim  0x021F3BE8  thumb  ov046
 *   GIMMICK46_ApplyPoseLines  0x021F4078  thumb  ov046
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Q {
    int a0;
    int a4;
    int *a8;
    u8 c;
    u8 d;
    u8 e;
    u8 pad;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
} Q;

struct Big;
struct Ctx;
struct Desc;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *);
struct Evt;
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int GIMMICK46_PlayAnimEventProc(void *a, int *st);
extern int GIMMICK46_CalcUnitPose(int *);
extern int GIMMICK46_GetRotateAnim(int *, int);
extern void GIMMICK46_ApplyPoseLines(u32, int, int);

int GIMMICK46_RotateEventProc(u32 a, int *b)
{
    void *h = GAME_EVENT_GetGameSystem((void *)a);
    void *x = GAMESYSTEM_GetFieldMap(h);
    Q *q;
    int t;
    int y;

    FIELDMAP_GetExpObj(x);
    q = (Q *)FIELDMAP_GetCommonWork(x, 1);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(x))), 10);
    switch (*b) {
    case 0:
        t = GIMMICK46_CalcUnitPose(q->a8);
        y = GIMMICK46_GetRotateAnim(q->a8, t);
        q->c = q->a0 * 5;
        q->d = 1;
        q->p18 = y;
        q->e = 8;
        q->p1c = 0x6d4;
        q->p20 = 0x6d9;
        GAME_EVENT_CallEvent((void *)a, (struct Evt **)func_020122C0(h, 0, GIMMICK46_PlayAnimEventProc, 0));
        q->a8[0] = t;
        (*b)++;
        break;
    case 1:
        GIMMICK46_ApplyPoseLines((u32)x, q->a0, *q->a8);
        return 1;
    }
    return 0;
}
