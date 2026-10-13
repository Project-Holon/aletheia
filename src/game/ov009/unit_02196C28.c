/*
 * file:     unit_02196C28.c
 * function: func_02196C28
 * address:  0x02196C28
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Handler for the ping message type: answers it with a pong. Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * symbols:
 *   func_02197BA4 0x02197BA4 arm
 */


#include "unit_02195B20_types.h"

extern int func_02197BA4(GTI2Connection *connection, unsigned char *message, int len);

int func_02196C28(GTI2Connection *connection, unsigned char *message, int len)
{
    return func_02197BA4(connection, message, len);
}
