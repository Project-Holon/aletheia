/*
 * function: FIELD_GIMMICK_BSUBWAY_HaltTrainSway
 * address: 0x021F388C
 * packet: pkt_ov052_021F388C
 * region: ov052
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 */
#include "../include/Obj20565.h"

typedef unsigned short u16;
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);

void FIELD_GIMMICK_BSUBWAY_HaltTrainSway(int a)
{
    unsigned h = (unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a)));
    if (FIELDMAP_GetZoneId((u8 *)a) == 0x4b) {
        char *p = (char *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)h, 0x27);
        if (p != 0) {
            unsigned char *q = *(unsigned char * *)&((struct Obj20565 *)p)->f24;
            if (q != 0)
                *q = 1;
        }
    }
}
