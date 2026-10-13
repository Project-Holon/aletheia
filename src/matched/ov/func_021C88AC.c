/*
 * function: PLEASURE_BOAT_ScrCmdAddTime
 * address:  0x021C88AC
 * packet:   pkt_021C88AC
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
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   VM_GetU16  0x02011330  thumb
 *   PLEASURE_BOAT_AdvanceTime  0x021C86E8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18340.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Big;
struct Ctx;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u8 *GAME_DATA_GetEventState(struct Big *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern u32 PLEASURE_BOAT_AdvanceTime(u32, u32, u32);

int PLEASURE_BOAT_ScrCmdAddTime(u32 a, u32 b, u32 c, u32 d)
{
SCRCMD_WORK_GetScriptWork((void *)b);
PLEASURE_BOAT_AdvanceTime(((struct Obj18340 *)((u8 *)(GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b))))))))->f0, VM_GetU16((struct Stream *)a), VM_GetU16((struct Stream *)a));
return 0;
}

