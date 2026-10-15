/*
 * function: SYMBOL_SAVE_FinalizeChecksum
 * address:  0x0200E06C
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_ShuffleEx  0x0203F37C  arm
 */
#include "../include/Obj00318.h"

extern void GF_STANDARD_ShuffleEx(void *p, unsigned int size, unsigned int seed);
void SYMBOL_SAVE_FinalizeChecksum(char *p)
{
    GF_STANDARD_ShuffleEx(p, 0x84c,
        ((struct Obj00318 *)p)->f84C + (((struct Obj00318 *)p)->f84E << 16));
    ((struct Obj00318 *)p)->f84E = 0;
}
