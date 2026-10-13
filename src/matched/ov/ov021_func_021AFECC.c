/*
 * function: SCRCMD_WarpToFixedZone
 * address:  0x021AFECC
 * packet:   pkt_ov021_021AFECC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   EVENT_MAPCHANGE_CreateFixedZoneEvent  0x021850A8  thumb
 *   GAMESYSTEM_GetEvent  0x02012104  thumb  arm9
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb  arm9
 *   GAME_EVENT_CallEvent  0x02012374  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Ctx;
struct Evt;
extern void *SCRIPT_WORK_GetGameSystem(void *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAMESYSTEM_GetEvent(const struct Ctx *p);
extern u32 EVENT_MAPCHANGE_CreateFixedZoneEvent(u32 a, void *b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int SCRCMD_WarpToFixedZone(u32 a, u32 b)
{
    u32 p = (u32)SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork((void *)b));
    void *q = GAMESYSTEM_GetFieldMap((void *)p);
    u32 r = GAMESYSTEM_GetEvent((const struct Ctx *)p);

    GAME_EVENT_CallEvent((struct Evt *)r, (struct Evt **)EVENT_MAPCHANGE_CreateFixedZoneEvent(p, q));
    return 1;
}
