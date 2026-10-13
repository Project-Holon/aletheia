/*
 * function: SCRCMD_ResumeBgmSlots
 * address:  0x021AF1B0
 * packet:   pkt_021AF1B0
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
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_ResumeSlots  0x02028BDC  thumb
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
struct S;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_ResumeSlots(struct S *s, u32 mask);
extern void SCRIPT_WORK_ResetCheckFlag(int n);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);

int SCRCMD_ResumeBgmSlots(u32 a, u32 b, u32 c, u32 d)
{
FIELD_SOUND_SYSTEM_ResumeSlots((struct S *)GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem((void *)b))), 2);
SCRIPT_WORK_ResetCheckFlag(13);
return 0;
}

