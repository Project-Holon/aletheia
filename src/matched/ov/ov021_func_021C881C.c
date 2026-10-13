/*
 * function: PLEASURE_BOAT_ScrCmdCreate
 * address:  0x021C881C
 * packet:   pkt_ov021_021C881C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   PLEASURE_BOAT_Create  0x021C8608  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Big;
extern u8 *GAME_DATA_GetEventState(struct Big *p);
extern char *PLEASURE_BOAT_Create(void);
int PLEASURE_BOAT_ScrCmdCreate(void *task, u32 a)
{
    u32 *p = (u32 *)GAME_DATA_GetEventState(GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)a)))));
    if (*p == 0)
        *p = (u32)PLEASURE_BOAT_Create();
    return 0;
}
