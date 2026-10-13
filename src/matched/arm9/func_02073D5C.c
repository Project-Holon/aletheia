/*
 * function: NNSi_SndMainReset
 * address:  0x02073D5C
 * packet:   pkt_02073D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0018 ABS32 gNNSSndSystemFlag             -> unresolved: 0214E9B4 (data, from header) has no witness outside 02073D5C..02073D7C
 *
 * symbols:
 *   gNNSSndSystemFlag       0x0214E9B4  data
 *   gNNSSndSystem       0x0214E9FC  data
 *
 * Clears the two words of the sequence/index pair to zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_SndMainReset.c \
 *       --func NNSi_SndMainReset --addr 0x02073D5C --cc 1.1p1 --arm
 */

#include "../include/G_St.h"

typedef unsigned int u32;

extern u32 gNNSSndSystemFlag;
extern struct St gNNSSndSystem;

void NNSi_SndMainReset(void)
{
    gNNSSndSystemFlag = 0;
    (*(u32 *)&gNNSSndSystem) = 0;
}
