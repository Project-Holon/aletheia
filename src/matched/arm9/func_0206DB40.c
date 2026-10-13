/*
 * function: NNS_G3dGeSetBuffer
 * address:  0x0206DB40
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
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGeSetBuffer.c \
 *       --func NNS_G3dGeSetBuffer --addr 0x0206DB40 --cc 1.1p1 --arm
 */

#include "../include/G_GeState.h"

typedef unsigned int u32;

extern struct GeState gNnsG3dGeState;

void NNS_G3dGeSetBuffer(u32 *p)
{
    if ((*(char * *)&gNnsG3dGeState) == 0) {
        *p = 0;
        (*(char * *)&gNnsG3dGeState) = (char *)p;
    }
}
