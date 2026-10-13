/*
 * function: sciInterfaceSetConnectionId
 * address:  0x021DF948
 * packet:   pkt_021DF948
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
 * Clears the byte at +0x84 when the second argument is zero and returns
 *  *  right away; otherwise forwards the address of that same byte to 0x02094798
 *  *  (arm9).  Written as an early-return `if` so MWCC predicates the store, the
 *  *  register clear and the epilogue with moveq/strbeq/popeq.
 */

extern char *func_02094798(char *dst, const char *src);

void sciInterfaceSetConnectionId(char *obj, int v)
{
    if (v == 0) {
        obj[0x84] = 0;
        return;
    }
    func_02094798(obj + 0x84, (const char *)v);
}

