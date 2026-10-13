/*
 * function: FIELD_GIMMICK_CART_LANES_CreateSwitchEvent
 * address:  0x021F3E24
 * packet:   pkt_ov039_021F3E24
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GIMMICK_CART_LANES_CreateSwitchEvent  0x021F3E24  thumb
 *   FIELD_GIMMICK_CART_LANES_SwitchEventMain  0x021F3E70  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
struct Big;
struct Desc;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int FIELD_GIMMICK_CART_LANES_SwitchEventMain(int a0, int *a1);

int FIELD_GIMMICK_CART_LANES_CreateSwitchEvent(void *a, u32 b)
{
    void *s;
    u8 *p;
    int r;

    s = GAMESYSTEM_GetFieldMap((void *)a);
    FIELDMAP_GetExpObj(s);
    p = (u8 *)FIELDMAP_GetCommonWork(s, 1);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(s))), 2);
    if (b >= 4) {
        return 0;
    }
    r = (int)func_020122C0(a, 0, FIELD_GIMMICK_CART_LANES_SwitchEventMain, 0);
    p[5] = b;
    return r;
}
