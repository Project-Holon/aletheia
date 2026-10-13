/*
 * function: INTRUDE_SUBDISP_IsInfoActive
 * address: 0x0217F1E8
 * packet: pkt_ov018_0217F1E8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding at 0x0217F212.
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetIntrudeCount 0x02012B70 thumb
 */
#include "../include/Obj00092.h"
typedef unsigned char u8;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
int INTRUDE_SUBDISP_IsInfoActive(u8 *p)
{
    if (GAME_DATA_GetIntrudeCount(GAMESYSTEM_GetGameData(((struct Obj00092 *)p)->f0)) == 1) {
        switch (((struct Obj00092 *)p)->fDC) {
        case 2: case 3: case 4: return 1;
        }
    }
    return 0;
}
