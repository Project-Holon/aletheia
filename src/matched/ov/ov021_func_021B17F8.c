/*
 * function: func_021B17F8
 * address:  0x021B17F8
 * packet:   pkt_ov021_021B17F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   SCRCMD_FLDMMDL_GetPlayerMmdl  0x021B1E74  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern int SCRCMD_FLDMMDL_GetPlayerMmdl(u32 a);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 FLDMMDL_GetDirDisp(void *p);

int func_021B17F8(u32 a, u32 b)
{
    u32 x = SCRCMD_FLDMMDL_GetPlayerMmdl(b);
    u16 *o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);

    *o = FLDMMDL_GetDirDisp((void *)x);
    return 0;
}
