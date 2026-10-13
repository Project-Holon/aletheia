/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_StartButtonEvent
 * address:  0x021F3A88
 * packet:   pkt_ov046_021F3A88
 * region:   ov046
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
 *   func_020122C0  0x020122C0  thumb
 *   FIELD_GIMMICK_ROTATING_ROOM_ButtonEventProc  0x021F3BFC  thumb  ov046
 */

typedef unsigned int u32;
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
extern int *FIELDMAP_GetCommonWork(char *, int);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int FIELD_GIMMICK_ROTATING_ROOM_ButtonEventProc(u32 a, int *b);

void FIELD_GIMMICK_ROTATING_ROOM_StartButtonEvent(void *a, int b, int c)
{
    void *x = GAMESYSTEM_GetFieldMap(a);
    int p;
    int *q;

    p = (int)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(x))), 10);
    q = FIELDMAP_GetCommonWork(x, 1);
    q[0] = b;
    q[1] = c;
    q[2] = p + b * 12;
    func_020122C0(a, 0, FIELD_GIMMICK_ROTATING_ROOM_ButtonEventProc, 0);
}
