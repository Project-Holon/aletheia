/*
 * function: FIELD_PLAYER_NOGRID_HasConnectionAhead
 * address:  0x021A6C6C
 * packet:   pkt_ov021_021A6C6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   FLDMMDL_RAIL_GetLocationByDir  0x0219E664  thumb  ov021
 *   EVENTDATA_SYSTEM_SearchConnectIdByRailLocation  0x02162598  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01119.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern void *FIELDMAP_GetGameSystem(void *p);
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern int FLDMMDL_RAIL_GetLocationByDir(void *o, u32 k, void *buf);
struct Q;
extern int EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(char *p, struct Q *q);

int FIELD_PLAYER_NOGRID_HasConnectionAhead(u8 *p, u32 k)
{
    u32 buf[2];
    void *o = FIELD_PLAYER_CORE_GetMmdl(*(unsigned char * *)&((struct Obj01119 *)p)->f14);
    u32 r4;

    r4 = GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(*(u8 * *)&((struct Obj01119 *)p)->f18)));
    FLDMMDL_RAIL_GetLocationByDir(o, k, buf);
    return EVENTDATA_SYSTEM_SearchConnectIdByRailLocation((char *)r4, (struct Q *)buf) != 0xFFFF;
}
