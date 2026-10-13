/*
 * file:     dwc_auth_interface_6.c
 * function: DWCi_Auth_ShutdownAuthentication
 * address:  0x02178EF4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * symbols:
 *   func_02178144 0x02178144 arm
 */

extern void func_02178144(void);

void DWCi_Auth_ShutdownAuthentication(void)
{
    func_02178144();
}
