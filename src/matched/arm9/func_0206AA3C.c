/*
 * function: NNS_G3dGlbLightVector
 * address:  0x0206AA3C
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148BCC       0x02148BCC  data
 * Packs three 10-bit fields (each taken from a signed value shifted right by
 * three) plus the slot index at bits 30..31 into one word of g_02148BCC.
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbLightVector.c \
 *       --func NNS_G3dGlbLightVector --addr 0x0206AA3C --cc 1.1p1 --arm
 */

#include "../include/G_Glb.h"

typedef unsigned int u32;

extern struct Glb g_02148BCC;

void NNS_G3dGlbLightVector(int idx, int a, int b, int c)
{
    ((u32 *)&g_02148BCC)[idx] = (u32)(((a >> 3) & 0x3FF) | (((b >> 3) & 0x3FF) << 10)
                            | (((c >> 3) & 0x3FF) << 20) | (idx << 30));
}
