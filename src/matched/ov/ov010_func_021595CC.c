/*
 * function: SCRIPT_WORK_CmdCallScript
 * address:  0x021595CC
 * packet:   pkt_ov010_021595CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRCMD_WORK_GetCallMode  0x0215A5D4  thumb  ov010
 *   SCRCMD_WORK_GetCallParam  0x0215A5D8  thumb  ov010
 *   SCRIPT_WORK_GetPlayerZoneId  0x02159B38  thumb  ov010
 *   SCRIPT_SYS_AddScript  0x021589A0  thumb  ov010
 *   SCRCMD_WORK_SetChildScriptIndex  0x0215AA48  thumb  ov010
 *   SCRCMD_WORK_SaveScriptState  0x0215AA24  thumb  ov010
 *   SCRCMD_WORK_RestoreScriptState  0x0215AA34  thumb  ov010
 *   SCRIPT_SYS_RunScriptNow  0x02158A34  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 *   SCRIPT_WORK_WaitChildScript  0x021595A0  thumb  ov010
 */

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern u32 SCRCMD_WORK_GetCallMode(void *p);
extern u32 SCRCMD_WORK_GetCallParam(void *p);
extern int SCRIPT_WORK_GetPlayerZoneId(int);
extern int SCRIPT_SYS_AddScript(int a, int b, int c);
extern void SCRCMD_WORK_SetChildScriptIndex(void *p, int v);
extern void *SCRCMD_WORK_SaveScriptState(int a0);
extern int SCRCMD_WORK_RestoreScriptState(int a0);
extern void SCRIPT_SYS_RunScriptNow(void *, void *, int, int);
extern void VM_SetWait(char *p, int val);
extern int SCRIPT_WORK_WaitChildScript(int a0, int a1);

int SCRIPT_WORK_CmdCallScript(int a, int b)
{
    void *x = SCRCMD_WORK_GetGameSystem((void *)b);
    void *y = SCRCMD_WORK_GetScriptWork((void *)b);
    int z = VM_GetU16((struct Stream *)a);
    if (SCRCMD_WORK_GetCallMode((void *)b) == 0) {
        SCRCMD_WORK_SetChildScriptIndex((void *)b, SCRIPT_SYS_AddScript((int)y, SCRIPT_WORK_GetPlayerZoneId(b), z));
        SCRCMD_WORK_SaveScriptState(b);
        VM_SetWait((char *)a, (int)SCRIPT_WORK_WaitChildScript);
        return 1;
    }
    SCRCMD_WORK_SaveScriptState(b);
    SCRIPT_SYS_RunScriptNow(x, y, z, SCRCMD_WORK_GetCallParam((void *)b));
    SCRCMD_WORK_RestoreScriptState(b);
    return 0;
}
