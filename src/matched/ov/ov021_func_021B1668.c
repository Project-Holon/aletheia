/*
 * function: SCRCMD_FLDMMDL_GetMmdlByScriptId
 * address:  0x021B1668
 * packet:   pkt_ov021_021B1668
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetMmdlSys  0x0215A5EC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FLDMMDL_SysSearchMoveCode  0x0216DE54  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetMmdlSys(void *p);
extern void *FLDMMDL_SysSearchMoveCode(void *map, u32 kind);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);

u32 SCRCMD_FLDMMDL_GetMmdlByScriptId(u32 a, u32 b)
{
    u32 t;
    u32 r;

    t = (u32)SCRCMD_WORK_GetMmdlSys((void *)a);
    if (b == 0xf2) {
        r = (u32)FLDMMDL_SysSearchMoveCode((void *)t, 0x30);
    } else if (b == 0xf1) {
        SCRCMD_WORK_GetScriptWork((void *)a);
    } else {
        r = (u32)FLDMMDL_SysSearchObjId((void *)t, b);
    }
    return r;
}
