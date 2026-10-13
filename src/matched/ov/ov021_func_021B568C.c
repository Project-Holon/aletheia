/*
 * function: SCRCMD_PROC_FLD_SetFieldRegionTable
 * address:  0x021B568C
 * packet:   pkt_ov021_021B568C
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
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   ov56_id        0x00000038  data  a1
 *   g_021F4344     0x021F4344  data  ov056  a4
 *   g_021F4374     0x021F4374  data  ov056  a4
 *   g_021F438C     0x021F438C  data  ov056  a4
 *   g_021F435C     0x021F435C  data  ov056  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetMapFunc(u8 *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int *FIELD_SUBPROC_Start(int a, int *d, const int *c);
extern u8 ov56_id[];
extern u32 g_021F4344[];
extern u32 g_021F4374[];
extern u32 g_021F438C[];
extern u32 g_021F435C[];

int SCRCMD_PROC_FLD_SetFieldRegionTable(int a0, int a1)
{
    int r4 = FIELDMAP_GetMapFunc(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)a1)));

    switch (SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1)) {
    case 0:
        break;
    case 1:
        FIELD_SUBPROC_Start((int)ov56_id, (int *)r4, (const int *)g_021F4344);
        break;
    case 2:
        FIELD_SUBPROC_Start((int)ov56_id, (int *)r4, (const int *)g_021F4374);
        break;
    case 3:
        FIELD_SUBPROC_Start((int)ov56_id, (int *)r4, (const int *)g_021F438C);
        break;
    case 4:
        FIELD_SUBPROC_Start((int)ov56_id, (int *)r4, (const int *)g_021F435C);
        break;
    }
    return 0;
}
