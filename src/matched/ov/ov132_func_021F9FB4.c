/*
 * function: STA_ACT_EFFECT_KillEffect
 * address:  0x021F9FB4
 * packet:   pkt_021F9FB4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_KillEffect  0x02051630  arm
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x02051630 now has an
 * EXACT arm9 shard entry (pkt_02051630), so the blx at +0012 resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23225.h"

extern void PARTICLE_KillEffect(void **p, void *q);

void STA_ACT_EFFECT_KillEffect(char *p, int i)
{
    int v = *(int *)(p + i * 16 + 0x4808);

    if (v != 0)
        PARTICLE_KillEffect(((struct Obj23225 *)p)->f4804, (void *)v);
}
