/*
 * function: FLD_PARTICLE_LoadResource
 * address:  0x021C1A98
 * packet:   pkt_ov021_021C1A98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads a resource with the owner's heap id (tail call).
 *
 * symbols:
 *   PARTICLE_LoadArchiveMember  0x0205121C  arm  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);

void *FLD_PARTICLE_LoadResource(u16 *p, int a, int b)
{
    return (void *)PARTICLE_LoadArchiveMember(a, b, p[2]);
}
