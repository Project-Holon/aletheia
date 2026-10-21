/*
 * function: SCRCMD_FLDMMDL_PauseMmdlsReleaseActive
 * address:  0x021B1B08
 * packet:   pkt_ov021_021B1B08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetMmdlSys  0x0215A5EC  thumb  ov010
 *   SCRIPT_WORK_GetTargetObj  0x02158F90  thumb  ov010
 *   SCRCMD_FLDMMDL_GetPlayerMmdl  0x021B1E74  thumb  ov021
 *   FLDMMDL_SysSearchMoveCode  0x0216DE54  thumb  ov010
 *   FLDMMDL_MOVE_FindFellow  0x0219BBA4  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_OffMoveBitMovePause  0x0216DB04  thumb  ov010
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_FLDMMDL_CheckMmdlPauseRelease  0x021B1A44  thumb  ov021
 *   gScrcmdFldmmdlPauseFlags     0x021EE71C  data  a1
 */

typedef unsigned char u8;
typedef unsigned int u32;

void *SCRCMD_WORK_GetScriptWork(void *p);
void *SCRCMD_WORK_GetMmdlSys(void *b);
void *SCRIPT_WORK_GetTargetObj(void *a);
int SCRCMD_FLDMMDL_GetPlayerMmdl(u32 a);
void *FLDMMDL_SysSearchMoveCode(void *map, u32 kind);
int FLDMMDL_MOVE_FindFellow(int a);
void FLDMMDL_SysPauseMove(void *map);
int FLDMMDL_CheckEndAcmd(void *a);
char *FLDMMDL_OffMoveBitMovePause(void *a0);
int FLDMMDL_CheckMoveBitMove(void *a);
void VM_SetWait(char *p, int val);
int SCRCMD_FLDMMDL_CheckMmdlPauseRelease(int a, int b);
extern u8 gScrcmdFldmmdlPauseFlags;

int SCRCMD_FLDMMDL_PauseMmdlsReleaseActive(int a, void *b)
{
    void *r4;
    void *r6;
    void *r7;

    r4 = SCRCMD_WORK_GetScriptWork(b);
    r6 = SCRCMD_WORK_GetMmdlSys(b);
    r4 = SCRIPT_WORK_GetTargetObj(r4);
    r7 = (void *)SCRCMD_FLDMMDL_GetPlayerMmdl((u32)b);
    FLDMMDL_SysSearchMoveCode(r6, 0x30);
    b = (void *)FLDMMDL_MOVE_FindFellow((int)r4);
    gScrcmdFldmmdlPauseFlags = 0;
    FLDMMDL_SysPauseMove(r6);
    if (FLDMMDL_CheckEndAcmd(r7) == 0) {
        gScrcmdFldmmdlPauseFlags |= 1;
        FLDMMDL_OffMoveBitMovePause(r7);
    }
    if (r4 != 0) {
        if (FLDMMDL_CheckMoveBitMove(r4) == 1) {
            gScrcmdFldmmdlPauseFlags |= 4;
            FLDMMDL_OffMoveBitMovePause(r4);
        }
    }
    if (b != 0) {
        if (FLDMMDL_CheckMoveBitMove(b) == 1) {
            gScrcmdFldmmdlPauseFlags |= 8;
            FLDMMDL_OffMoveBitMovePause(b);
        }
    }
    VM_SetWait((char *)a, (int)SCRCMD_FLDMMDL_CheckMmdlPauseRelease);
    return 1;
}
