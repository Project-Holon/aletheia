/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_LeverEventProc
 * address:  0x021F3C8C
 * packet:   pkt_ov046_021F3C8C
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
 *   FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc  0x021F3DE8  thumb  ov046
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
extern int FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc(void *a, int *st);

int FIELD_GIMMICK_ROTATING_ROOM_LeverEventProc(u32 a, int *b)
{
    void *h = GAME_EVENT_GetGameSystem((void *)a);
    void *x = GAMESYSTEM_GetFieldMap(h);
    Q *q;
    int r;

    FIELDMAP_GetExpObj(x);
    r = 1;
    q = (Q *)FIELDMAP_GetCommonWork(x, 1);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(x))), 10);
    switch (*b) {
    case 0:
        if ((q->a8 + q->a4)[1] != 0)
            r = 0;
        q->c = (q->a4 == 0 ? 1 : 2) + q->a0 * 5;
        q->d = 1;
        q->p18 = r;
        q->e = 2;
        q->p1c = 0x6fc;
        q->p20 = 0x6fd;
        GAME_EVENT_CallEvent((void *)a, (struct Evt **)func_020122C0(h, 0, FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc, 0));
        (q->a8 + q->a4)[1] = r;
        (*b)++;
        break;
    case 1:
        return r;
    }
    return 0;
}
