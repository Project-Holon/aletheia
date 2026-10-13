/*
 * function: SCRIPT_SYS_GetZoneId
 * address:  0x021588D0
 * packet:   pkt_021588D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec44;
extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);

int SCRIPT_SYS_GetZoneId(int a0)
{
    u8 *p;

    p = GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)a0);
loc_021588D6:
    a0 = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)p);
loc_021588DA:
    return a0;}
