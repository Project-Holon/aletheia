/*
 * function: GIMMICK_INIT_SetGimmick42Flags
 * address:  0x021F3724
 * packet:   pkt_ov037_021F3724
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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

void GIMMICK_INIT_SetGimmick42Flags(unsigned int a0, int a1)
{
    unsigned char *p = (unsigned char *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)a0)), 4);
    unsigned char i;

    for (i = 0; i < 3; i++)
        p[i] = 0;
    if (a1 & 1)
        p[0] = 1;
    if ((a1 >> 1) & 1)
        p[1] = 1;
    if ((a1 >> 2) & 1)
        p[2] = 1;
}
