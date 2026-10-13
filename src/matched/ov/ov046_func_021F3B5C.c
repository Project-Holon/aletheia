/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent
 * address:  0x021F3B5C
 * packet:   pkt_ov046_021F3B5C
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The negation is a multiply by 0xffffffff (see the idiom on
 * multiplying by minus one), and the +12 base is a separate local that
 * is formed after the func_020122C0 call.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   FIELD_GIMMICK_ROTATING_ROOM_HopEventProc  0x021F3EFC  thumb  ov046
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
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int FIELD_GIMMICK_ROTATING_ROOM_HopEventProc(u32 a, int *b);

void *FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent(void *a, int b)
{
    void *x = GAMESYSTEM_GetFieldMap(a);
    char *q;
    int *w;
    void *r;
    int v[3];

    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(x))), 10);
    q = (char *)FIELDMAP_GetCommonWork(x, 1);
    r = func_020122C0(a, 0, FIELD_GIMMICK_ROTATING_ROOM_HopEventProc, 0);
    w = (int *)(q + 12);
    ((unsigned char *)w)[3] = 0;
    w[1] = 0x2000;
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((void *)x), (struct VecFx32 *)v);
    w[2] = v[1];
    if (b == 2)
        w[1] = w[1] * 0xffffffff;
    return r;
}
