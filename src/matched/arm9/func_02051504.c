/*
 * function: PARTICLE_CountSystems
 * address:  0x02051504
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_pParticleMan   0x02146A88  data
 *
 * Counts the non-NULL entries of the 16-slot pointer table g_pParticleMan.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_CountSystems.c \
 *       --func PARTICLE_CountSystems --addr 0x02051504 --cc 1.1p1 --arm
 */

#include "../include/G_02146A88.h"

typedef unsigned int u32;

extern struct G_02146A88 *g_pParticleMan;

int PARTICLE_CountSystems(void)
{
    int n = 0;
    int i;

    for (i = 0; i < 16; i++) {
        if (((u32 *)g_pParticleMan)[i] != 0)
            n++;
    }
    return n;
}
