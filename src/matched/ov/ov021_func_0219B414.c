/*
 * function: FLDMMDL_MOVECODE_InitEventTypeProcThunk
 * address:  0x0219B414
 * packet:   pkt_ov021_0219B414
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of FLDMMDL_MOVE_SetupMove (ov010) +000A.  An
 * unlabelled Thumb tail-call thunk that disasm.py emitted as a word run
 * (`ldr r3,[pc,#0]; bx r3; .word FLDMMDL_MOVECODE_InitByEventType|1`), so no func_ label exists
 * for the caller to reach through `label`/`sole-ref/code`.  Matching it here
 * gives FLDMMDL_MOVE_SetupMove's call site a `matched` witness.  Region hint ov021 is
 * required: ov009 overlaps 0x0219B414 but holds unrelated code there.
 *
 * symbols:
 *   FLDMMDL_MOVECODE_InitByEventType  0x0219B440  thumb  ov021
 */

extern int FLDMMDL_MOVECODE_InitByEventType(char *a);

int FLDMMDL_MOVECODE_InitEventTypeProcThunk(int a)
{
    return FLDMMDL_MOVECODE_InitByEventType((char *)a);
}
