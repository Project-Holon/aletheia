/*
 * function: FLDMMDL_RAIL_MOVE_UpdateMove
 * address:  0x0219D6CC
 * packet:   pkt_ov021_0219D6CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckSysStatusBit  0x0216DA20  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove  0x0219D7AC  thumb  ov021
 *   FLDMMDL_RAIL_MOVE_ProcMoveStartFirst  0x0219D7D0  thumb  ov021
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_ACMD_RunCmds  0x02197EB4  thumb  ov021
 *   FLDMMDL_CheckMoveBitMovePause  0x0216DB10  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_CheckMoveStart  0x0219D780  thumb  ov021
 *   FLDMMDL_CallMoveProc  0x0216D708  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_ProcMoveStartSecond  0x0219D7F0  thumb  ov021
 *   FLDMMDL_RAIL_MOVE_ProcMoveEnd  0x0219D824  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern int FLDMMDL_CheckSysStatusBit(void *p, unsigned int v);
extern void FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove(u32);
extern void FLDMMDL_RAIL_MOVE_ProcMoveStartFirst(u32);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern void FLDMMDL_ACMD_RunCmds(u32);
extern int FLDMMDL_CheckMoveBitMovePause(void *a0);
extern int FLDMMDL_RAIL_MOVE_CheckMoveStart(u32 a);
extern void FLDMMDL_CallMoveProc(void *a0);
extern void FLDMMDL_RAIL_MOVE_ProcMoveStartSecond(u32);
extern void FLDMMDL_RAIL_MOVE_ProcMoveEnd(u32);

void FLDMMDL_RAIL_MOVE_UpdateMove(u32 a)
{
    u32 k = 2;
    if (FLDMMDL_CheckSysStatusBit((void *)a, 2) == 0) {
        FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove(a);
        FLDMMDL_RAIL_MOVE_ProcMoveStartFirst(a);
        if (FLDMMDL_CheckMoveBit((void *)a, k << 8) != 0) {
            FLDMMDL_ACMD_RunCmds(a);
        } else if (FLDMMDL_CheckMoveBitMovePause((void *)a) == 0 && FLDMMDL_RAIL_MOVE_CheckMoveStart(a) == 1) {
            FLDMMDL_CallMoveProc((void *)a);
        }
        FLDMMDL_RAIL_MOVE_ProcMoveStartSecond(a);
        FLDMMDL_RAIL_MOVE_ProcMoveEnd(a);
    }
}
