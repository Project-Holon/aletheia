/*
 * function: gt2Accept
 * address:  0x02195B2C
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
 *   func_0219569C  0xfunc_0219569C  arm
 */

extern int func_0219569C(void *connection, void *callbacks);

int gt2Accept(void *connection, void *callbacks)
{
    return func_0219569C(connection, callbacks);
}
