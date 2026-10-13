/*
 * function: PARTICLE_UpdateAllSystems
 * address:  0x02051574
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  PC24 PARTICLE_UpdateSystem at +0x20: 0x020514F4 is itself capped (see src/pending/PARTICLE_UpdateSystem.c)
 *
 * symbols:
 *   g_pParticleMan   0x02146A88  data
 *   PARTICLE_UpdateSystem  0x020514F4  arm
 *
 * Same walk as PARTICLE_DrawAllSystems, but each live slot goes to PARTICLE_UpdateSystem -
 * the pair is a start/stop pass over the same 16-entry table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_UpdateAllSystems.c \
 *       --func PARTICLE_UpdateAllSystems --addr 0x02051574 --cc 1.1p1 --arm
 */

#include "../include/G_02146A88.h"

typedef unsigned int u32;

extern struct G_02146A88 *g_pParticleMan;
extern int PARTICLE_UpdateSystem(u32 *p);

int PARTICLE_UpdateAllSystems(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (((u32 *)g_pParticleMan)[i] != 0) {
            PARTICLE_UpdateSystem((u32 *)((u32 *)g_pParticleMan)[i]);
            n++;
        }
    }
    return n;
}
