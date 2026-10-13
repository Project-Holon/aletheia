/*
 * function: SCRCMD_SAVEANIME_Start
 * address:  0x021C46A4
 * packet:   pkt_ov021_021C46A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FLDEFF_RIPPLE_CreateZoneStartWarpTask  0x021D2418  thumb  ov021
 *   FLDEFF_RIPPLE_CreateSpecialLocationWarpTask  0x021D2440  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *
 * The shared SCRIPT_SYS_CallEvent call is written out in every arm and
 * cross-jumped by the compiler; a result local merged after the if chain
 * spills z instead of b.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *FLDEFF_RIPPLE_CreateZoneStartWarpTask(void *a, u32 b);
extern void *FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(void *a, u32 b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);

int SCRCMD_SAVEANIME_Start(void *a, void *b)
{
    u32 t;
    void *y;
    void *x;
    void *z;

    x = SCRCMD_WORK_GetGameSystem(b);
    y = GAMESYSTEM_GetFieldMap(x);
    z = SCRCMD_WORK_GetScriptWork(b);
    t = SCRIPT_WORK_ReadWorkValue(a, b);
    if (t == 0)
        SCRIPT_SYS_CallEvent(z, FLDEFF_RIPPLE_CreateZoneStartWarpTask(x, (u32)y));
    else if (t == 1)
        SCRIPT_SYS_CallEvent(z, FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(x, (u32)y, 0));
    else
        SCRIPT_SYS_CallEvent(z, FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(x, (u32)y, 1));
    return 1;
}
