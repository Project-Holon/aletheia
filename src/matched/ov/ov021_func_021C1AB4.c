/*
 * function: FLD_PARTICLE_IsEffectFinished
 * address:  0x021C1AB4
 * packet:   pkt_ov021_021C1AB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 1 when the effect at +0xC is absent or finished.
 *
 * symbols:
 *   PARTICLE_GetEffectCount  0x02051614  arm  arm9
 */

typedef unsigned int u32;

extern int PARTICLE_GetEffectCount(int **p);

int FLD_PARTICLE_IsEffectFinished(u32 *p)
{
    if (p[3] == 0)
        return 1;
    if (PARTICLE_GetEffectCount((int **)p[3]) == 0)
        return 1;
    return 0;
}
