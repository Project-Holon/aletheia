/*
 * function: func_02005DE4
 * address:  0x02005DE4
 * packet:   pkt_02005DE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02005FBC  0x02005FBC  thumb
 *   sub_0200590C   0x0200590C  thumb
 * blocker:  +000E THM_CALL func_02072E8C       -> unresolved: 02072E8C (arm, from name) has no witness outside 02005DE4..02005DF8
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */

typedef unsigned int u32;

extern void func_02005FBC(void *p);
extern u32  sub_0200590C(void);
extern void func_02072E8C(u32 a, void *p);

void func_02005DE4(void *p)
{
    func_02005FBC(p);
    func_02072E8C(sub_0200590C(), p);
}
