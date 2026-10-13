/*
 * function: GIMMICK_INIT_ResetGimmick46Panels
 * address:  0x021F3800
 * packet:   pkt_ov037_021F3800
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);

void GIMMICK_INIT_ResetGimmick46Panels(unsigned int a0)
{
    int *p = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)a0)), 10);
    int *q;
    int *r;

    p[0] = 3;
    p[1] = 0;
    p[2] = 1;
    q = p + 3;
    q[0] = 1;
    q[1] = 1;
    q[2] = 1;
    r = p + 6;
    r[0] = 2;
    r[1] = 1;
    r[2] = 0;
}
