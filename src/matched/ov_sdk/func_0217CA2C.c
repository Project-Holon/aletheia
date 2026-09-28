/*
 * function: func_0217CA2C
 * address:  0x0217CA2C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls func_0217F120 on the block sixteen bytes into the result.
 *
 * symbols:

 */

extern char *func_0217CA20(void);
extern void func_0217F120(void *p);

void func_0217CA2C(void)
{
    func_0217F120(func_0217CA20() + 0x10);
}

