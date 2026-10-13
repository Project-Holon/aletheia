/*
 * function: SCRCMD_EndMmdlIcaProc
 * address:  0x021D1A54
 * packet:   pkt_ov021_021D1A54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   SCRIPT_WORK_SetReturnParam  0x02159104  thumb  ov010
 *   SCRIPT_WORK_GetReturnParam  0x0215910C  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_MMDL_ICA_EndProc  0x021D1884  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u32 SCRIPT_WORK_GetReturnParam(void *a);
extern void SCRCMD_MMDL_ICA_EndProc(u8 *p);
extern void SCRIPT_WORK_SetReturnParam(u8 *p, u32 v);

int SCRCMD_EndMmdlIcaProc(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);

    SCRCMD_MMDL_ICA_EndProc((u8 *)SCRIPT_WORK_GetReturnParam(x));
    SCRIPT_WORK_SetReturnParam(x, 0);
    return 0;
}
