/*
 * function: func_02051380
 * address:  0x02051380
 * packet:   pkt_02051380
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call with two zero arguments. Filed as the witness for ov094 func_021FA12C.
 */

extern void func_02051230(void *, void *, int, int);

void func_02051380(void *p, void *r)
{
    func_02051230(p, r, 0, 0);
}
