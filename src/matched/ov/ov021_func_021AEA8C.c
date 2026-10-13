/*
 * function: SCRCMD_GetScriptTrainerId
 * address:  0x021AEA8C
 * packet:   pkt_ov021_021AEA8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_GetScriptId  0x02158F8C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0215A460  0x0215A460  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u16 SCRIPT_WORK_GetScriptId(u8 *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 func_0215A460(u32 a);

int SCRCMD_GetScriptTrainerId(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    u32 y;

    SCRIPT_WORK_ResetFieldParam((int)x);
    y = SCRIPT_WORK_GetScriptId(x);
    *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = func_0215A460(y);
    return 0;
}
