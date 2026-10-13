/*
 * function: SCRCMD_MSGWIN_CmdSetAutoMode
 * address:  0x021B15C8
 * packet:   pkt_ov021_021B15C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_MSGBG_SetAutoMode  0x021904DC  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Stream;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u16 VM_GetU16(struct Stream *s);
extern void FIELD_MSGBG_SetAutoMode(u8 *p, u8 v);
extern void SCRIPT_WORK_SetCheckFlag(int n);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

int SCRCMD_MSGWIN_CmdSetAutoMode(u32 a, u32 b)
{
    u32 *p = (u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b));

    if (VM_GetU16((struct Stream *)a)) {
        FIELD_MSGBG_SetAutoMode((u8 *)(*p), 1);
        SCRIPT_WORK_SetCheckFlag(9);
    } else {
        FIELD_MSGBG_SetAutoMode((u8 *)(*p), 0);
        SCRIPT_WORK_ResetCheckFlag(9);
    }
    return 0;
}
