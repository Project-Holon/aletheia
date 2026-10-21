/*
 * function: SCRCMD_FLDMMDL_SetMmdlZoneDeleteOff
 * address:  0x021B1A20
 * packet:   pkt_ov021_021B1A20
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
 *   FLDMMDL_SetStatusBitZoneDeleteOff  0x0216DB80  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetMmdlSys(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern void FLDMMDL_SetStatusBitZoneDeleteOff(unsigned int *p, unsigned int v);

int SCRCMD_FLDMMDL_SetMmdlZoneDeleteOff(u32 a, u32 b)
{
    u32 x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    u32 o = (u32)FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetMmdlSys((void *)b), x);

    if (o != 0) {
        FLDMMDL_SetStatusBitZoneDeleteOff((unsigned int *)o, 1);
    }
    return 0;
}
