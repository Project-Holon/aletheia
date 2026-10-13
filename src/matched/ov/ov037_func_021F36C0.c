/*
 * function: GIMMICK_INIT_SetCartLanesFlags
 * address:  0x021F36C0
 * packet:   pkt_ov037_021F36C0
 * region:   ov037
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Cross-overlay collision: the same address is also resident in ov039.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 */
#include "../include/Obj13080.h"

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);

void GIMMICK_INIT_SetCartLanesFlags(unsigned int a0, int a1, int a2)
{
    char *p = (char *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)a0)), 2);

    if (a1)
        ((struct Obj13080 *)p)->f14 = 1;
    if (a2)
        ((struct Obj13080 *)p)->f16 = 1;
}
