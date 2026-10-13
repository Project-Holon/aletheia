/*
 * function: SCRCMD_FLDMMDL_GetMmdlParam
 * address:  0x021B19E0
 * packet:   pkt_ov021_021B19E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 */

typedef unsigned short u16;

unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef unsigned int   u32;
void *SCRCMD_WORK_GetOccupyInfo(void *p);
void *FLDMMDL_SysSearchObjId(void *map, u32 id);
int FLDMMDL_GetParam(char *a0, int a1);

int SCRCMD_FLDMMDL_GetMmdlParam(int a, int b)
{
    int r7;
    unsigned int r4;
    u16 *r6;
    int r0;

    r7 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r4 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r6 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    r0 = (int)FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo((void *)b), r7);
    if (r4 <= 2 && r0 != 0) {
        *r6 = FLDMMDL_GetParam((char *)r0, r4);
    }
    return 0;
}
