/*
 * function: func_0203D0FC
 * address:  0x0203D0FC
 * packet:   pkt_0203D0FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  `bl` to 0x0203C010: no witness outside this range (0x0203C010 is itself parked at MATCH in src/pending/func_0203C010.c, whose blocker is the call to 0x020379C8)
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203C010  0x0203C010  arm
 *
 * Two calls and nothing else: reset the sub-state, then re-enter the state
 * whose constructor src/matched/func_0203C010.c reproduces.  This function
 * was parked at MATCH until 0x0203C010 was matched - that call was its only
 * open relocation site, and the callee's single branch site image-wide is
 * this one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D0FC.c \
 *       --func func_0203D0FC --addr 0x0203D0FC --cc 1.1p1 --arm
 */

extern void func_0203D788(void);
extern void func_0203C010(void);

void func_0203D0FC(void)
{
    func_0203D788();
    func_0203C010();
}
