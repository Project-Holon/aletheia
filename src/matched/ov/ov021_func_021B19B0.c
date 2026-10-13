/*
 * function: SCRCMD_FLDMMDL_GetMmdlEventFlag
 * address:  0x021B19B0
 * packet:   pkt_ov021_021B19B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_GetEventFlag  0x0216D5B0  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern u16 FLDMMDL_GetEventFlag(u8 *p);

int SCRCMD_FLDMMDL_GetMmdlEventFlag(u32 a, u32 b)
{
    u32 x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    u16 *p = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    u32 o = (u32)FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo((void *)b), x);

    if (o != 0) {
        *p = FLDMMDL_GetEventFlag((u8 *)o);
    }
    return 0;
}
