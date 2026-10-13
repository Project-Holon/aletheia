/*
 * function: SCRCMD_MSGWIN_CleanupAutoMode
 * address:  0x021B1604
 * packet:   pkt_ov021_021B1604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   FIELD_MSGBG_SetAutoMode  0x021904DC  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern int SCRIPT_WORK_CheckFlag(int a0);
extern void FIELD_MSGBG_SetAutoMode(u8 *p, u8 v);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

int SCRCMD_MSGWIN_CleanupAutoMode(u32 *a)
{
    u32 *p = (u32 *)SCRIPT_WORK_ResetFieldParam(a[2]);
    u32 id = 9;

    if (SCRIPT_WORK_CheckFlag(id)) {
        FIELD_MSGBG_SetAutoMode((u8 *)(*p), 0);
        SCRIPT_WORK_ResetCheckFlag(id);
    }
    return 1;
}
