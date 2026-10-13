/*
 * function: SCRCMD_StartSubProcOv057
 * address:  0x021CFA58
 * packet:   pkt_ov021_021CFA58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02: abs_id_39 is overlay id 57 (pool ABS32 0x39, the id argument
 * of FIELD_SUBPROC_Start); d_021F3900 resolves as ov057 data once the symbols line
 * carries the ov057 region hint (this function loads ov057).
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   abs_id_39      0x00000039  data
 *   d_021F3900     0x021F3900  data  ov057  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetMapFunc(u8 *p);
extern int *FIELD_SUBPROC_Start(int a, int *d, const int *c);
extern char abs_id_39[];
extern char d_021F3900[];

int SCRCMD_StartSubProcOv057(void *a, void *b)
{
    SCRCMD_WORK_GetScriptWork(b);
    FIELD_SUBPROC_Start((int)abs_id_39, (int *)FIELDMAP_GetMapFunc((u8 *)((u32)GAMESYSTEM_GetFieldMap((void *)SCRCMD_WORK_GetGameSystem(b)))), (const int *)d_021F3900);
    return 0;
}
