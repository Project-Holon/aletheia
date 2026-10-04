/*
 * function: func_0203CFF0
 * address:  0x0203CFF0
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper: func_0203B0C4(p, 1).  Called by state 10 of
 * func_0203DC70 with ctx + 0x94.  NOTE: layout/symbols_sdk.txt lists this
 * address as DWC_IsSendableReliable (thumb), a false signature match: the
 * bytes are ARM (`ldr ip, [pc, #4]; mov r1, #1; bx ip`) and the caller
 * reaches it with an ARM `bl`.
 *
 * symbols:
 *   func_0203B0C4  0x0203B0C4  arm
 */

extern void func_0203B0C4(int a0, int a1);

void func_0203CFF0(void *p)
{
    func_0203B0C4((int)p, 1);
}
