/*
 * function: SCRCMD_PROC_FLD_CallWorldTradeEvent
 * address:  0x021B4C98
 * packet:   pkt_ov021_021B4C98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   abs_id_4       0x00000004  data
 *   EVENT_WORLDTRADE_Entry  0x021542C0  thumb  ov004
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *a;
    u32 b;
} Pair;

extern u8 abs_id_4[];
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
struct Ctx;
struct Pair;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Desc;
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int EVENT_WORLDTRADE_Entry(int x, struct Pair *p);

int SCRCMD_PROC_FLD_CallWorldTradeEvent(u32 a, u32 b)
{
    Pair p;
    void *r5;
    void *r4;

    r5 = SCRCMD_WORK_GetScriptWork((void *)b);
    r4 = SCRCMD_WORK_GetGameSystem((void *)b);
    p.a = GAMESYSTEM_GetFieldMap((void *)r4);
    p.b = 0;
    SCRIPT_SYS_CallEvent(r5, GAME_EVENT_CreateOverlayEvent(r4, (u32)abs_id_4, (void *)EVENT_WORLDTRADE_Entry, (u32)(&p)));
    return 1;
}
