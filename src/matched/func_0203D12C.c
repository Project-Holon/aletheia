/*
 * function: func_0203D12C
 * address:  0x0203D12C
 * packet:   pkt_0203D12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_02037A44  0x02037A44  arm
 *
 * EXACT*, not EXACT: the inferred extent runs on to 0x0203D17C because the
 * four eight-byte ARM long-branch veneers at 0x0203D14C, 0x0203D158,
 * 0x0203D164 and 0x0203D170 save no `lr` and so carry no label.  It is not a
 * byte difference.  They want seeding into layout/function_starts.txt, which
 * is the integrator's file.
 *
 * Guarded forwarding call: the hook at 0x0203CD98 answers whether the
 * connection is up, and only then is the argument handed to 0x02037A44.  The
 * `bl` at the top passes r0 through untouched, so the callee is declared
 * `void` while this one takes the value it later forwards.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D12C.c \
 *       --func func_0203D12C --addr 0x0203D12C --cc 1.1p1 --arm
 */

extern int func_0203CD98(void);
extern void func_02037A44(int a);

void func_0203D12C(int a)
{
    if (func_0203CD98() == 0)
        return;

    func_02037A44(a);
}
