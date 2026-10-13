/*
 * function: FLDMMDL_MoveTcbProc
 * address:  0x0216D3A8
 * packet:   pkt_ov010_0216D3A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (in a .word run): callback thunk that forwards its
 * second argument to FLDMMDL_ExecMove. Filed as the witness that
 * FLDMMDL_AddMoveTcb's pointer to it needs.
 *
 * symbols:
 *   FLDMMDL_ExecMove  0x0216D38C  thumb  ov010
 */

typedef unsigned int u32;

extern void FLDMMDL_ExecMove(int a0);

void FLDMMDL_MoveTcbProc(u32 a, u32 b)
{
    FLDMMDL_ExecMove(b);
}
