/*
 * function: sub_020399A8
 * address:  0x020399A8
 * packet:   pkt_020398B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_0203996C  0x0203996C  arm
 *
 * A two-call shutdown/reset forwarder: no arguments, both results discarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020399A8.c  *       --func sub_020399A8 --addr 0x020399A8 --cc 1.1p1 --arm
 */

extern void func_02039338(void);
extern void func_0203996C(void);

void sub_020399A8(void)
{
    func_02039338();
    func_0203996C();
}
