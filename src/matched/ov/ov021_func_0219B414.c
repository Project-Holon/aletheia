/*
 * function: func_0219B414
 * address:  0x0219B414
 * packet:   pkt_ov021_0219B414
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of func_02163010 (ov010) +000A.  An
 * unlabelled Thumb tail-call thunk that disasm.py emitted as a word run
 * (`ldr r3,[pc,#0]; bx r3; .word func_0219B440|1`), so no func_ label exists
 * for the caller to reach through `label`/`sole-ref/code`.  Matching it here
 * gives func_02163010's call site a `matched` witness.  Region hint ov021 is
 * required: ov009 overlaps 0x0219B414 but holds unrelated code there.
 *
 * symbols:
 *   func_0219B440  0x0219B440  thumb  ov021
 */

extern int func_0219B440(char *a);

int func_0219B414(int a)
{
    return func_0219B440((char *)a);
}
