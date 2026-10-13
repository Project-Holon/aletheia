/*
 * function: SODATEYA_ClearEggFlag
 * address:  0x021C33E0
 * packet:   pkt_ov021_021C33E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears event flag 0x4139 (EXACT*: unlabelled follower).
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_GetEventWork  0x0201296C  thumb  arm9
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb  arm9
 */

typedef unsigned short u16;

extern void *FIELDMAP_GetGameSystem(void *p);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_GetEventWorkAddress(u32 a, u32 b);

void SODATEYA_ClearEggFlag(void *a)
{
    *((u16 *)ZONEDATA_GetEventWorkAddress(GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a))), 0x4139)) = 0;
}
