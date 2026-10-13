/*
 * function: func_02050B80
 * address:  0x02050B80
 * packet:   pkt_02050A70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Allocate the 0x48-byte singleton on the caller's heap and publish it at
 * 0x02146A88, zero its first sixteen words, then clear the two trailing word
 * fields at +0x40 and +0x44.
 *
 * The heap id is the incoming r0, untouched: the allocator's first argument is
 * the parameter, and its third (the clear flag, 0) is CSE'd off the loop
 * counter's own zero, which is why no `mov r0` appears and r4 is zeroed before
 * the call.
 *
 * The global is a pointer VARIABLE, and both the zero loop and the two field
 * stores re-dereference it: a store through the pointer could overwrite the
 * pointer itself, so only `g[i] = 0` inside the loop and `g->f40`/`g->f44`
 * afterwards reproduce the four separate loads of the global.
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   g_pParticleMan      0x02146A88  data
 *   sParticleFile 0x020A7FC0  data
 */

#include "../include/G_02146A88.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct G_02146A88 *g_pParticleMan;
extern const char sParticleFile[];

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void func_02050B80(u32 heap)
{
    int i = 0;

    g_pParticleMan = func_02030734(heap, 0x48, i, sParticleFile, 190);

    for (i = 0; i < 16; i++) {
        ((u32 *)g_pParticleMan)[i] = 0;
    }

    g_pParticleMan->f40 = 0;
    g_pParticleMan->base = 0;
}
