/*
 * function: SHINKA_DEMO_EFFECT_DeleteParticle
 * address:  0x02208994
 * packet:   pkt_02208994
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   func_020307B0 0x020307B0 arm
 */

extern void PARTICLE_ExitManager(void);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void SHINKA_DEMO_EFFECT_DeleteParticle(char *a)
{
    PARTICLE_ExitManager();
    func_020307B0(a);
}
