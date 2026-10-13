/*
 * function: FLDMMDL_MOVE_UpdateMove
 * address:  0x02163028
 * packet:   pkt_ov010_02163028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckSysStatusBit  0x0216DA20  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeightIfRequested  0x021630F4  thumb  ov010
 *   FLDMMDL_MOVE_UpdateAttrIfRequested  0x0216310C  thumb  ov010
 *   FLDMMDL_MOVE_ProcMoveStartFirst  0x02163130  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_ACMD_RunCmds  0x02197EB4  thumb  ov021
 *   FLDMMDL_CheckMoveBitMovePause  0x0216DB10  thumb  ov010
 *   FLDMMDL_MOVE_IsMoveProcAllowed  0x02163090  thumb  ov010
 *   FLDMMDL_MOVECODE_UpdateEventTypeProc  0x0219B41C  thumb  ov021
 *   FLDMMDL_CallMoveProc  0x0216D708  thumb  ov010
 *   FLDMMDL_MOVE_ProcMoveStartSecond  0x02163154  thumb  ov010
 *   FLDMMDL_MOVE_ProcMoveEnd  0x02163188  thumb  ov010
 */

extern int FLDMMDL_CheckSysStatusBit(void *p, unsigned int v);
extern void FLDMMDL_MOVE_UpdateHeightIfRequested();
extern void FLDMMDL_MOVE_UpdateAttrIfRequested(char *p);
extern void FLDMMDL_MOVE_ProcMoveStartFirst(char *p);
extern unsigned int FLDMMDL_CheckMoveBit(void *p, unsigned int v);
typedef unsigned int   u32;
extern void FLDMMDL_ACMD_RunCmds(u32 a);
extern int FLDMMDL_CheckMoveBitMovePause(void *a0);
extern int FLDMMDL_MOVE_IsMoveProcAllowed();
extern int FLDMMDL_MOVECODE_UpdateEventTypeProc();
extern void FLDMMDL_CallMoveProc(void *a0);
extern void FLDMMDL_MOVE_ProcMoveStartSecond(char *p);
extern void FLDMMDL_MOVE_ProcMoveEnd(char *p);

void FLDMMDL_MOVE_UpdateMove(void *a)
{
    int t = 2;

    if (FLDMMDL_CheckSysStatusBit((void *)a, t) == 0) {
        FLDMMDL_MOVE_UpdateHeightIfRequested(a);
        FLDMMDL_MOVE_UpdateAttrIfRequested((char *)a);
        FLDMMDL_MOVE_ProcMoveStartFirst((char *)a);
        if (FLDMMDL_CheckMoveBit(a, t << 8) != 0) {
            FLDMMDL_ACMD_RunCmds((u32)a);
        } else if (FLDMMDL_CheckMoveBitMovePause((void *)a) == 0) {
            if (FLDMMDL_MOVE_IsMoveProcAllowed(a) == 1) {
                if (FLDMMDL_MOVECODE_UpdateEventTypeProc(a) == 0) {
                    FLDMMDL_CallMoveProc((void *)a);
                }
            }
        }
        FLDMMDL_MOVE_ProcMoveStartSecond((char *)a);
        FLDMMDL_MOVE_ProcMoveEnd((char *)a);
    }
}
