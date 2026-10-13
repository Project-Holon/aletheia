/*
 * function: GIMMICK41_CreateLaunchEvent
 * address:  0x021F37E0
 * packet:   pkt_ov041_021F37E0
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GIMMICK41_CreateLaunchEvent  0x021F37E0  thumb
 *   GIMMICK41_EventLaunch  0x021F3884  thumb
 *   GIMMICK41_FindCannonAt  0x021F3EE4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef unsigned short u16;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Big;
struct Desc;
extern void *FIELDMAP_GetGameSystem(void *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u8 GIMMICK41_FindCannonAt(int x, int y);
extern int GIMMICK41_EventLaunch(void *a0, int *state);

int GIMMICK41_CreateLaunchEvent(void *a)
{
    void *s;
    void *t;
    u8 *p;
    int v[3];
    int x;
    int y;
    int d;
    u8 idx;
    int r;

    s = GAMESYSTEM_GetFieldMap((void *)a);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(s))), 5);
    p = (u8 *)FIELDMAP_GetCommonWork(s, 1);
    t = FIELDMAP_GetFieldPlayer((void *)s);
    FIELD_PLAYER_GetPos(t, (struct VecFx32 *)v);
    x = v[0] / 0x10000;
    y = v[2] / 0x10000;
    d = FIELD_PLAYER_GetDirDisp(t);
    switch (d) {
    case 0:
        y -= 2;
        break;
    case 1:
        y += 2;
        break;
    case 2:
        x -= 2;
        break;
    case 3:
        x += 2;
        break;
    }
    idx = GIMMICK41_FindCannonAt(x, y);
    if (idx >= 10) {
        return 0;
    }
    r = (int)func_020122C0(a, 0, GIMMICK41_EventLaunch, 0);
    p[0] = idx;
    p[1] = d;
    return r;
}
