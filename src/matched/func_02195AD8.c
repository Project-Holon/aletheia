/*
 * function: func_02195AD8
 * address:  0x02195AD8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the two helpers on the argument.
 *
 * symbols:
 *   func_02195DE4  0x02195DE4  arm  ov009
 *   func_02197FDC  0x02197FDC  arm  ov009
 */

extern void func_02195DE4(void *p);
extern void func_02197FDC(void *p);

void func_02195AD8(void *p)
{
    func_02195DE4(p);
    func_02197FDC(p);
}

