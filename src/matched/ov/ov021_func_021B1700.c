/*
 * function: SCRCMD_FLDMMDL_GetMmdlMoveCode
 * address:  0x021B1700
 * packet:   pkt_ov021_021B1700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern u16 FLDMMDL_GetMoveCode(void *p);

int SCRCMD_FLDMMDL_GetMmdlMoveCode(u32 a, u32 b)
{
    u32 t = (u32)SCRCMD_WORK_GetOccupyInfo((void *)b);
    u16 *o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);

    *o = 0;
    *o = FLDMMDL_GetMoveCode(FLDMMDL_SysSearchObjId((void *)t, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b)));
    return 0;
}
