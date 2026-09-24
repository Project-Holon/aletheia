/*
 * function: func_021EEF74
 * address:  0x021EEF74
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
 * Pull the two tag records through the p+0x70 lookup and hand both
 * pairs to the 0x54/0x10 emitter.
 *
 * Blocked sites: +000A and +0014, the THM_CALLs to the ARM9 SDK func_0202616C.  Every
 * concrete byte matches; that address has no independent witness, so both
 * fields stay wildcarded and the entry caps at MATCH.  Same class as
 * func_021DE898, func_021DCDF0 and func_021EE520.
 */

extern unsigned char *func_0202616C(int, int);
extern void func_021EEFA4(char *, int, int, int, int);
void func_021EEF74(char *q, int a, int b)
{
    unsigned char *x = func_0202616C(*(int *)(q + 0x70), a);
    unsigned char *y = func_0202616C(*(int *)(q + 0x70), b);
    func_021EEFA4(q, x[0], x[1], y[0], y[1]);
}
