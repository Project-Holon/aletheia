/*
 * unit: yes
 * function: NO_GEAR_Update, NO_GEAR_Hook
 * address: 0x021F00F8
 * packet: pkt_ov030_021F00F8
 * region: ov030
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: empty follower NO_GEAR_Hook then two-byte zero padding.
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   WIH_DWC_PollStatus 0x0201058C thumb
 */
#include "../include/Obj13049.h"
typedef unsigned int u32;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u32 WIH_DWC_PollStatus(void *key);
void NO_GEAR_Update(char *p)
{
    if (*(void (**)(char *))p != 0) {
        (*(void (**)(char *))p)(p);
    }
    WIH_DWC_PollStatus((void *)GAME_DATA_GetWifiList(GAMESYSTEM_GetGameData(((struct Obj13049 *)p)->f18)));
}
void NO_GEAR_Hook(void)
{
}
