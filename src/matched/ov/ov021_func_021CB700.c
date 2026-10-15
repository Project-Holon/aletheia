/*
 * function: BSUBWAY_SCR_WaitTimingSync
 * address:  0x021CB700
 * packet:   pkt_ov021_021CB700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetCurrentEvent  0x02012ED8  thumb
 *   SCRIPT_WORK_GetWorkPtr  0x02158FE0  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   BSUBWAY_COMM_CheckTimingSync  0x02167B34  thumb  ov010
 */
#include "../include/Obj12971.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetGameSystem(void *a);
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetCurrentEvent(struct Big *p);
extern u16 *SCRIPT_WORK_GetWorkPtr(void *a, void *b, unsigned int id);
extern u32 func_0200FB24(void);
extern int BSUBWAY_COMM_CheckTimingSync(int a0);

int BSUBWAY_SCR_WaitTimingSync(u32 unused, u32 a)
{
    void *t;
    u8 *p;
    void *s;
    u16 *q;

    s = SCRCMD_WORK_GetScriptWork((void *)a);
    t = GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(s));
    p = GAME_DATA_GetCurrentEvent(t);
    q = SCRIPT_WORK_GetWorkPtr(s, t, ((struct Obj12971 *)p)->f72A);
    if (func_0200FB24() != 0) {
        *q = 0;
        return 1;
    }
    if (BSUBWAY_COMM_CheckTimingSync(p[0x727]) == 1) {
        *q = 1;
        return 1;
    }
    return 0;
}
