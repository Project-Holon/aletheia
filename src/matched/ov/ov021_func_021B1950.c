/*
 * function: SCRCMD_FLDMMDL_InitMmdlGridPosition
 * address:  0x021B1950
 * packet:   pkt_ov021_021B1950
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetMmdlSys  0x0215A5EC  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_InitGridPosition  0x0216E084  thumb  ov010
 */

typedef signed short s16;

unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
typedef unsigned int   u32;
void *SCRCMD_WORK_GetMmdlSys(void *p);
void *FLDMMDL_SysSearchObjId(void *map, u32 id);
void FLDMMDL_InitGridPosition(int a, int b, int c, int d, int e);

int SCRCMD_FLDMMDL_InitMmdlGridPosition(int a, int b)
{
    int r0;
    int r2;
    s16 r1;
    s16 r7;
    s16 r6;
    int r4;

    r2 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r1 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r7 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r6 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r4 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r0 = (int)FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetMmdlSys((void *)b), r2);
    if (r0) {
        FLDMMDL_InitGridPosition(r0, r1, r7, r6, r4);
    }
    return 0;
}
