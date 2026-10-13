/*
 * function: SCRCMD_FLDMMDL_CheckMmdlPauseRelease
 * address:  0x021B1A44
 * packet:   pkt_ov021_021B1A44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetTargetObj  0x02158F90  thumb  ov010
 *   SCRCMD_FLDMMDL_GetPlayerMmdl  0x021B1E74  thumb  ov021
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_SysSearchMoveCode  0x0216DE54  thumb  ov010
 *   FLDMMDL_MOVE_FindFellow  0x0219BBA4  thumb  ov021
 *   gScrcmdFldmmdlPauseFlags     0x021EE71C  data  a1
 */

typedef unsigned char u8;

void *SCRCMD_WORK_GetScriptWork(void *p);
void *SCRIPT_WORK_GetTargetObj(void *p);
typedef unsigned int   u32;
int SCRCMD_FLDMMDL_GetPlayerMmdl(u32 a);
void *SCRCMD_WORK_GetOccupyInfo(void *p);
int FLDMMDL_CheckEndAcmd(int a);
void FLDMMDL_OnMoveBitMovePause(void *a0);
int FLDMMDL_CheckMoveBitMove(void *a0);
void *FLDMMDL_SysSearchMoveCode(void *map, u32 kind);
int FLDMMDL_MOVE_FindFellow(int a);
extern u8 gScrcmdFldmmdlPauseFlags;

int SCRCMD_FLDMMDL_CheckMmdlPauseRelease(int a, int b)
{
    int r5;
    int r6;
    int r7;

    r5 = (int)SCRIPT_WORK_GetTargetObj(SCRCMD_WORK_GetScriptWork((void *)b));
    r6 = SCRCMD_FLDMMDL_GetPlayerMmdl(b);
    r7 = (int)SCRCMD_WORK_GetOccupyInfo((void *)b);
    if (gScrcmdFldmmdlPauseFlags & 1) {
        if (FLDMMDL_CheckEndAcmd(r6) == 1) {
            FLDMMDL_OnMoveBitMovePause((void *)r6);
            gScrcmdFldmmdlPauseFlags &= 0xfe;
        }
    }
    if (gScrcmdFldmmdlPauseFlags & 4) {
        if (FLDMMDL_CheckMoveBitMove((void *)r5) == 0) {
            FLDMMDL_OnMoveBitMovePause((void *)r5);
            gScrcmdFldmmdlPauseFlags &= 0xfb;
        }
    }
    if (gScrcmdFldmmdlPauseFlags & 2) {
        r6 = (int)FLDMMDL_SysSearchMoveCode((void *)r7, 0x30);
        if (FLDMMDL_CheckMoveBitMove((void *)r6) == 0) {
            FLDMMDL_OnMoveBitMovePause((void *)r6);
            gScrcmdFldmmdlPauseFlags &= 0xfd;
        }
    }
    if (gScrcmdFldmmdlPauseFlags & 8) {
        r5 = FLDMMDL_MOVE_FindFellow(r5);
        if (r5 == 0) {
            gScrcmdFldmmdlPauseFlags &= 0xf7;
        } else if (FLDMMDL_CheckMoveBitMove((void *)r5) == 0) {
            FLDMMDL_OnMoveBitMovePause((void *)r5);
            gScrcmdFldmmdlPauseFlags &= 0xf7;
        }
    }
    if (gScrcmdFldmmdlPauseFlags == 0) {
        return 1;
    }
    return 0;
}
