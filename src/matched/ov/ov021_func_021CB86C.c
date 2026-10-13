/*
 * function: func_021CB86C
 * address:  0x021CB86C
 * packet:   pkt_ov021_021CB86C
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
 *   BSUBWAY_COMM_IsRecvEnd  0x02167D00  thumb  ov010
 */
#include "../include/Obj20240.h"

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
struct Obj;
extern int BSUBWAY_COMM_IsRecvEnd(struct Obj *o, u16 *out);

int func_021CB86C(u32 unused, u32 a)
{
    void *t;
    void *s;
    u8 *p;
    u16 *q;

    s = SCRCMD_WORK_GetScriptWork((void *)a);
    t = GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(s));
    p = GAME_DATA_GetCurrentEvent(t);
    q = SCRIPT_WORK_GetWorkPtr(s, t, ((struct Obj20240 *)p)->f72A);
    if (BSUBWAY_COMM_IsRecvEnd((struct Obj *)p, q) == 1)
        return 1;
    return 0;
}
