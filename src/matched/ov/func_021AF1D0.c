/*
 * function: SCRCMD_ResumeBgmSlotsEvent
 * address:  0x021AF1D0
 * packet:   pkt_021AF1D0
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
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_ResumeSlots  0x02028BDC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18089.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *);
struct S;
extern void FIELD_SOUND_SYSTEM_ResumeSlots(struct S *s, u32 mask);

int SCRCMD_ResumeBgmSlotsEvent(u32 a, u32 b, u32 c, u32 d)
{
FIELD_SOUND_SYSTEM_ResumeSlots((struct S *)GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj18089 *)((u8 *)(a)))->f0))), 2);
return 1;
}

