/*
 * function: NatifyThink
 * address:  0x02198E74
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
 *   func_02198A0C  0xfunc_02198A0C  arm
 */

struct _NAT;
extern int func_02198A0C(int sock, struct _NAT *nat);

int NatifyThink(int sock, void *nat)
{
    return func_02198A0C(sock, nat);
}
