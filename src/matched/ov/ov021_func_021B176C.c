/*
 * function: SCRCMD_FLDMMDL_GetMmdlGridPos
 * address:  0x021B176C
 * packet:   pkt_ov021_021B176C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 */

typedef signed short s16;

typedef unsigned int   u32;
void *SCRCMD_WORK_GetOccupyInfo(void *p);
unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
void *FLDMMDL_SysSearchObjId(void *map, u32 id);
s16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
int FLDMMDL_GetGridNowX(void *p);
int FLDMMDL_GetGridNowZ(void *p);

int SCRCMD_FLDMMDL_GetMmdlGridPos(int a, int b)
{
    int r6;
    s16 *r7;
    s16 *r4;

    r6 = (int)SCRCMD_WORK_GetOccupyInfo((void *)b);
    r6 = (int)FLDMMDL_SysSearchObjId((void *)r6, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b));
    r7 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    r4 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *r7 = FLDMMDL_GetGridNowX((void *)r6);
    *r4 = FLDMMDL_GetGridNowZ((void *)r6);
    return 0;
}
