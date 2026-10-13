/*
 * function: SCRCMD_POKEMON_FLD_SelectMonMove
 * address:  0x021B636C
 * packet:   pkt_ov021_021B636C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   EVENT_POKE_STATUS_CreateMoveSelectEvent  0x0215A2E4  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * EVENT_POKE_STATUS_CreateMoveSelectEvent's prototype is copied from its matched source
 * (ov010_func_0215A2E4.c: last parameter unsigned short). With that
 * parameter fed from a u16 local (SCRIPT_WORK_ReadWorkValue returning u16), the third
 * stack store lands before the r2/r3 reloads; a u32 local needs a
 * narrowing and schedules it after them.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 SCRIPT_WORK_ReadWorkValue(void *a0, void *a1); /* u16 return on purpose: see note above */
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int EVENT_POKE_STATUS_CreateMoveSelectEvent(int a, int b, int c, int d, int e, int f, unsigned short g);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_POKEMON_FLD_SelectMonMove(void *a, void *b)
{
    u16 *t10;
    u16 *t6;
    u16 tc;
    u16 t4;
    void *p7;
    void *p5;

    t10 = SCRIPT_WORK_ReadWorkPointer(a, b);
    t6 = SCRIPT_WORK_ReadWorkPointer(a, b);
    tc = SCRIPT_WORK_ReadWorkValue(a, b);
    t4 = SCRIPT_WORK_ReadWorkValue(a, b);
    p7 = SCRCMD_WORK_GetScriptWork(b);
    p5 = SCRCMD_WORK_GetGameSystem(b);
    SCRIPT_SYS_CallEvent(p7, (void *)EVENT_POKE_STATUS_CreateMoveSelectEvent((int)p5, (int)GAMESYSTEM_GetFieldMap(p5), tc, (int)t10, (int)t6, t4 == 0, t4));
    return 1;
}
