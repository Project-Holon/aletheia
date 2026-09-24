/*
 * function: func_021DF928
 * address:  0x021DF928
 * packet:   pkt_021DF928
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02094798  0x02094798  arm
 *
 * Clears the byte at +0x5c when the second argument is zero and returns
 *  *  right away; otherwise forwards the address of that same byte to 0x02094798
 *  *  (arm9).  Written as an early-return `if` so MWCC predicates the store, the
 *  *  register clear and the epilogue with moveq/strbeq/popeq.
 */

extern void func_02094798(void *p);

void func_021DF928(char *obj, int v)
{
    if (v == 0) {
        obj[0x5c] = 0;
        return;
    }
    func_02094798(obj + 0x5c);
}

