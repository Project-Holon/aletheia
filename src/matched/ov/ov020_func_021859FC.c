/*
 * function: EVENT_MAPCHANGE_ReloadMmdl
 * address: 0x021859FC
 * packet: pkt_ov020_021859FC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList 0x02186470 thumb ov020
 *   ZONEDATA_IsZoneInTableDFC0 0x02013DD0 thumb
 *   EVENT_MAPCHANGE_AddWfbcMmdl 0x02185928 thumb ov020
 *   GAME_DATA_GetMoveModelSys 0x02012B38 thumb
 *   FIELD_STATUS_GetMapMode 0x0201444C thumb
 *   GAME_DATA_GetSecondUnionInfo 0x020127C4 thumb
 *   FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus 0x021864DC thumb ov020
 */
#include "../include/Obj19456.h"
typedef unsigned short u16;
extern void FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList(int a0);
extern int ZONEDATA_IsZoneInTableDFC0(int id);
extern void EVENT_MAPCHANGE_AddWfbcMmdl(void *a, const short *p);
typedef unsigned int   u32;
struct BigObj;
struct Sub02014444Obj;
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern u32 FIELD_STATUS_GetMapMode(struct Sub02014444Obj *o);
extern unsigned char *GAME_DATA_GetSecondUnionInfo(void *p);
typedef unsigned char  u8;
extern void FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus(u8 *p);
void EVENT_MAPCHANGE_ReloadMmdl(void *p, const short *s)
{
    FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList((int)p);
    if (ZONEDATA_IsZoneInTableDFC0(*(const u16 *)&((struct Obj19456 *)s)->f4) != 0) {
        EVENT_MAPCHANGE_AddWfbcMmdl((void *)p, s);
        if (FIELD_STATUS_GetMapMode(GAME_DATA_GetMoveModelSys(p)) == 0) {
            FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus(GAME_DATA_GetSecondUnionInfo(p));
        }
    }
}
