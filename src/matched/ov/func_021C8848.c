/*
 * function: PLEASURE_BOAT_ScrCmdDelete
 * address:  0x021C8848
 * packet:   pkt_021C8848
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   SYMBOL_MAP_DeleteLinkRecord  0x021666A4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u8 *GAME_DATA_GetEventState(struct Big *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void SYMBOL_MAP_DeleteLinkRecord(int a0);
extern void *FIELDMAP_GetGameSystem(void *p);

int PLEASURE_BOAT_ScrCmdDelete(u32 a, u32 b, u32 c, u32 d)
{
SYMBOL_MAP_DeleteLinkRecord((int)GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b))))));
return 0;
}

