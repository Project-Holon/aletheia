/*
 * function: SCRCMD_PROC_FLD_CallGtsNegoEvent
 * address:  0x021B4CDC
 * packet:   pkt_ov021_021B4CDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-02: closed by seeding ov001 0x02154694 (Thumb tail-call thunk to
 * EVENT_GTSNEGO_Create, filed as ov001_func_02154694.c). Old note: it sat inside ov001 pool_02154690
 * (ldr r3,[pc]; bx r3; .word EVENT_GTSNEGO_Create+1) so sole-ref/code finds no func_ label;
 * abs_id_01 is the overlay id 1 that GAME_EVENT_CreateOverlayEvent loads (not an OVERLAY_ID_CONSUMER).
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork    0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem    0x0215A5DC  thumb  ov010
 *   SCRIPT_SYS_CallEvent    0x0215897C  thumb  ov010
 *   GAMESYSTEM_GetFieldMap    0x0201210C  thumb
 *   GAME_EVENT_CreateOverlayEvent    0x020124AC  thumb
 *   abs_id_01        0x00000001  data
 *   EVENT_GTSNEGO_Entry  0x02154694  thumb  ov001
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 abs_id_01[];
extern void *EVENT_GTSNEGO_Entry(void *p, int a);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Desc;
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);

int SCRCMD_PROC_FLD_CallGtsNegoEvent(u32 a, u32 b)
{
    void *r5;
    void *r4;

    r5 = SCRCMD_WORK_GetScriptWork((void *)b);
    r4 = SCRCMD_WORK_GetGameSystem((void *)b);
    SCRIPT_SYS_CallEvent(r5, GAME_EVENT_CreateOverlayEvent(r4, (u32)abs_id_01, (u32 (*)(void *, u32))EVENT_GTSNEGO_Entry, (u32)GAMESYSTEM_GetFieldMap((void *)r4)));
    return 1;
}
