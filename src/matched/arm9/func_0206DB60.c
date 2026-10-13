/*
 * function: NNS_G3dGeReleaseBuffer
 * address:  0x0206DB60
 * packet:   pkt_0206DB40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gNnsG3dGeState       0x0214BAB4  data
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGeReleaseBuffer.c \
 *       --func NNS_G3dGeReleaseBuffer --addr 0x0206DB60 --cc 1.1p1 --arm
 */

#include "../include/G_GeState.h"

extern struct GeState gNnsG3dGeState;
extern void   NNS_G3dGeFlushBuffer(void);

void *NNS_G3dGeReleaseBuffer(void)
{
    void *r;

    NNS_G3dGeFlushBuffer();
    r = (*(char * *)&gNnsG3dGeState);
    (*(char * *)&gNnsG3dGeState) = 0;
    return r;
}
