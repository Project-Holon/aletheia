/*
 * function: func_021EE520
 * address:  0x021EE520
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021EEFA4  0x021EEFA4  thumb  ov170
 *
 * Hand the two tag bytes of the p+0x2c+0x70 object to the 0x54/0x10
 * emitter.
 *
 * Blocked site: +000A, the THM_CALL to the ARM9 SDK func_0202616C.  Every
 * other byte matches (including the 5-argument call it feeds), but that
 * address has no independent witness in the branch index, so the field
 * stays wildcarded and the entry caps at MATCH.  Same class as
 * func_021DE898 and func_021DCDF0.
 */

extern unsigned char *func_0202616C(int);
extern void func_021EEFA4(int, int, int, int, int);
void func_021EE520(char *p)
{
    unsigned char *q = func_0202616C(*(int *)(*(int *)(p + 0x2c) + 0x70));
    func_021EEFA4(*(int *)(p + 0x2c), 0x54, 0x10, q[0], q[1]);
}
