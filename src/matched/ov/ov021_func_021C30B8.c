/*
 * function: FLD3D_CI_StartMessageSequence
 * address:  0x021C30B8
 * packet:   pkt_ov021_021C30B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Runs FLD3D_CI_StartSequence with kind 0x11 and stores the argument at +0x9C (EXACT*: pad).
 *
 * symbols:
 *   FLD3D_CI_StartSequence  0x021C1CB0  thumb  ov021
 */
#include "../include/Obj01213.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int FLD3D_CI_StartSequence(int a, char *b, int c);

int FLD3D_CI_StartMessageSequence(void *a, u8 *b, u32 c)
{
    int r = FLD3D_CI_StartSequence((int)a, (char *)b, 0x11);

    if (r == 0)
        return 0;
    *(u32 *)&((struct Obj01213 *)b)->f9C = c;
    return r;
}
