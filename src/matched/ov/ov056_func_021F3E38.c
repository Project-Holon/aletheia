/*
 * function: FIELD_FK_BUILD_SOUND_Exit
 * address:  0x021F3E38
 * packet:   pkt_ov056_021F3E38
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_ReleaseSlot  0x02028B50  thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void *FIELDMAP_GetGameSystem(void *p);
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_ReleaseSlot(u8 *p, int a0);

void FIELD_FK_BUILD_SOUND_Exit(void *a0, void *a1)
{
    FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a1))), 0x746);
}
