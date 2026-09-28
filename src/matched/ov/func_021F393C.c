/*
 * function: func_021F393C
 * address:  0x021F393C
 * packet:   pkt_021F393C
 * region:   ov054
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call wrapper: func_021C4E08(*(void **)(a + 4*b + 8), 0).  The pool
 * word names the thumb function at 0x021C4E08; that address is labelled in
 * both ov021 and ov093, so the symbols line carries the ov093 hint to
 * disambiguate.  Resolved as label (3 outside branches).
 *
 * symbols:
 *   func_021C4E08  0x021C4E08  thumb  ov093
 */

extern int func_021C4E08(void *, int);

int func_021F393C(char *a, int b)
{
    return func_021C4E08(*(void **)(a + 4 * b + 8), 0);
}
