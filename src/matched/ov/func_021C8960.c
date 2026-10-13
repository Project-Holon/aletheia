/*
 * function: PLEASURE_BOAT_ScrCmdLock
 * address:  0x021C8960
 * packet:   pkt_021C8960
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   PLEASURE_BOAT_Lock  0x021C8810  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18341.h"

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
extern void *FIELDMAP_GetGameSystem(void *p);
extern u32 PLEASURE_BOAT_Lock(u32);

int PLEASURE_BOAT_ScrCmdLock(u32 a, u32 b, u32 c, u32 d)
{
PLEASURE_BOAT_Lock(((struct Obj18341 *)((u8 *)(GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b))))))))->f0);
return 0;
}

