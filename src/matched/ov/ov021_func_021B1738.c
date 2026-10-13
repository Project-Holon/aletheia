/*
 * function: SCRCMD_FLDMMDL_ChangeMmdlMoveCode
 * address:  0x021B1738
 * packet:   pkt_ov021_021B1738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_ChangeMoveCode  0x0216E0E8  thumb  ov010
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern int FLDMMDL_ChangeMoveCode(int a0, int a1);

int SCRCMD_FLDMMDL_ChangeMmdlMoveCode(u32 a, u32 b)
{
    u32 t = (u32)SCRCMD_WORK_GetOccupyInfo((void *)b);
    u32 x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    u32 y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    FLDMMDL_ChangeMoveCode((int)FLDMMDL_SysSearchObjId((void *)t, x), y);
    return 0;
}
