/*
 * function: FIELDMAP_ChangeZoneSound
 * address:  0x02189518
 * packet:   pkt_ov021_02189518
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   ISS_SYS_ChangeZone  0x0202B544  thumb
 *   FIELD_SOUND_SYSTEM_PostZoneBgmChange  0x02029CF0  thumb
 */
#include "../include/Obj12557.h"

typedef unsigned short u16;

typedef unsigned int   u32;
struct Ctx;
struct Rec44;
struct SaveBlock;
struct BigObj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAMESYSTEM_GetIssSystem(u32 *p);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);
extern void ISS_SYS_ChangeZone(u32 a, u16 b);
extern void FIELD_SOUND_SYSTEM_PostZoneBgmChange(void *a, void *b, u16 c);

void FIELDMAP_ChangeZoneSound(char *p, unsigned int idx)
{
    void *a;
    void *b;
    void *c;
    int k;

    a = GAMESYSTEM_GetGameData(((struct Obj12557 *)p)->f4);
    b = (void *)GAMESYSTEM_GetIssSystem(((struct Obj12557 *)p)->f4);
    c = (void *)GAME_DATA_GetBgmInfo(a);
    k = GAME_DATA_GetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(a));
    ISS_SYS_ChangeZone((u32)b, idx);
    if (k != 2)
        FIELD_SOUND_SYSTEM_PostZoneBgmChange(c, a, idx);
}
