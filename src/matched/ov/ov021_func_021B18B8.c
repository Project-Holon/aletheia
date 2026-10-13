/*
 * function: SCRCMD_FLDMMDL_DeleteMmdl
 * address:  0x021B18B8
 * packet:   pkt_ov021_021B18B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern void FLDMMDL_DeleteMmdl(u32);

int SCRCMD_FLDMMDL_DeleteMmdl(u32 a, u32 b)
{
    u32 t = (u32)SCRCMD_WORK_GetOccupyInfo((void *)b);
    u32 o = (u32)FLDMMDL_SysSearchObjId((void *)t, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b));

    if (o != 0) {
        FLDMMDL_DeleteMmdl(o);
    }
    return 0;
}
