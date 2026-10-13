/*
 * file:     gt2main_2.c
 * unit:     yes
 * function: gt2Listen, gt2Accept, gt2Reject
 * address:  0x02195B20
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gti2SetConnectAttemptCallback  0x02198020  arm
 */
#include "gt2main_2_types.h"

extern void gti2SetConnectAttemptCallback(GTI2Socket *socket, void *connectAttemptCallback);
extern int func_0219569C(GTI2Connection *connection, GT2ConnectionCallbacks *callbacks);
extern void func_021956F8(void);
void gt2Listen(GTI2Socket *socket, void *connectAttemptCallback);
int gt2Accept(GTI2Connection *connection, GT2ConnectionCallbacks *callbacks);
void gt2Reject(void);


/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * Unblocked by matching the 8-byte ARM leaf at 0x02198020 in ov009 (its
 * listing emits it as a .word run, unlabelled); the ABS32 site now resolves
 * via `matched`.  Packet renamed from pkt_02155168 so this promotion does
 * not rewrite that packet's shard.
 */
void gt2Listen(GTI2Socket *socket, void *connectAttemptCallback)
{
    gti2SetConnectAttemptCallback(socket, connectAttemptCallback);
}


/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
int gt2Accept(GTI2Connection *connection, GT2ConnectionCallbacks *callbacks)
{
    return func_0219569C(connection, callbacks);
}


void gt2Reject(void)
{
    func_021956F8();
}
