/*
 * function: MONOLITH_TOOL_GetTitleSpecies
 * address: 0x021B6F2C
 * packet: pkt_ov071_021B6F2C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatusByNetId 0x021583EC thumb ov010
 */
#include "../include/Obj13166.h"
typedef unsigned char u8;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
void *MONOLITH_TOOL_GetTitleSpecies(u8 **p)
{
    u8 *q = *p;
    return (void *)GAME_DATA_GetMyStatusByNetId(GAMESYSTEM_GetGameData(((struct Obj13166 *)q)->f0), q[0x3c]);
}
