/*
 * function: PARTICLE_DrawAllSystems
 * address:  0x02051534
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  PC24 PARTICLE_DrawSystem at +0x20: 0x02051414 (pkt_02051230, 208 bytes) open, no outside branch
 *
 * symbols:
 *   g_pParticleMan   0x02146A88  data
 *   PARTICLE_DrawSystem  0x02051414  arm
 *
 * For every live slot of g_pParticleMan, calls PARTICLE_DrawSystem with the slot value;
 * returns how many slots were live (not what the callee returned).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_DrawAllSystems.c \
 *       --func PARTICLE_DrawAllSystems --addr 0x02051534 --cc 1.1p1 --arm
 */

#include "../include/G_02146A88.h"

typedef unsigned int u32;

extern struct G_02146A88 *g_pParticleMan;
typedef unsigned char  u8;
extern void PARTICLE_DrawSystem(u8 *a0);

int PARTICLE_DrawAllSystems(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (((u32 *)g_pParticleMan)[i] != 0) {
            PARTICLE_DrawSystem((u8 *)((u32 *)g_pParticleMan)[i]);
            n++;
        }
    }
    return n;
}
