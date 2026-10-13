/*
 * function: GFL_NET_STATE_IsFatalError
 * address:  0x0203CB00
 * packet:   pkt_0203CB00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM predicate: the card task object exists and its callback at +8 is GFL_NET_STATE_FatalError.
 * MATCH only because 0x0203CADC (GFL_NET_STATE_FatalError.c, EXACT) is not yet a labelled
 * function start: the pool word has no outside witness until the seed lands.
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_FatalError  0x0203CADC  arm
 */

#include "../include/G_Sys.h"

struct Card0203CB00 {
    unsigned char pad[8];
    void *cb;
};

extern struct Sys *_pNetState;
extern void GFL_NET_STATE_FatalError(void);

int GFL_NET_STATE_IsFatalError(void)
{
    struct Card0203CB00 *c = ((struct Card0203CB00 *)_pNetState);
    if (c != 0 && c->cb == (void *)GFL_NET_STATE_FatalError) {
        return 1;
    }
    return 0;
}
