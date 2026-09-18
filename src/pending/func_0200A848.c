/*
 * function: func_0200A848
 * address:  0x0200A848
 * packet:   pkt_0200A848
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02161EEC (no func_ label in any overlay that holds the address,
 *           so attest_overlay_label refuses at part 1 even though ov020
 *           branches to it at 0x02186378) and 02161F00 (labelled func_02161F00
 *           in ov010, but no branch anywhere in the image targets it from
 *           outside this range).  All 28 bytes are right; 1 of 3 sites
 *           resolved (02161D98, func_ label in ov010 plus the branch at
 *           0x0212674).
 * symbols:
 *   func_02161D98    0x02161D98  thumb  ov010
 *   func_02161EEC    0x02161EEC  thumb
 *   func_02161F00    0x02161F00  thumb  ov010
 */

typedef unsigned int u32;

extern void func_02161D98(void *p);
extern void func_02161EEC(void *p);
extern void func_02161F00(void *p);

void func_0200A848(void **a0)
{
    func_02161D98(a0);
    func_02161EEC(&a0[0x7a]);
    func_02161F00(&a0[0x7f]);
}
