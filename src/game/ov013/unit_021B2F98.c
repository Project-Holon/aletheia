/*
 * file:     unit_021B2F98.c
 * function: DWCi_InitReliableQueue
 * address:  0x021B2F98
 * packet:   pkt_ov013_021B2F98
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVoiceFramePool 0x021B4C24 data
*/

#include "vct_types.h"

/* Forget the frame buffer area of the frame pool. */
void DWCi_InitReliableQueue(void)
{
    gVoiceFramePool.freeHead = 0;
    gVoiceFramePool.base = 0;
}
