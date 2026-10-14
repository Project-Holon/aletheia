/*
 * function: POKETRADE_3D_ExitParticleManager
 * address:  0x021E3034
 * packet:   pkt_ov119_021E3034
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PARTICLE_ExitManager  0x02050ED4  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Teardown: release the +0xb4 pointer and the nine 32-bit slots at
 * +0x24, zeroing each. Target of func_021D6C78's second call (ov119).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void PARTICLE_ExitManager(void);
extern u32 func_020307B0(void *p);

void POKETRADE_3D_ExitParticleManager(u32 *p, int a1)
{
    int i;

    PARTICLE_ExitManager();
    if (p[0x2d] != 0) {
        func_020307B0((void *)p[0x2d]);
        p[0x2d] = 0;
    }
    for (i = 0; i < 9; i++) {
        if (p[9 + i] != 0) {
            func_020307B0((void *)p[9 + i]);
            p[9 + i] = 0;
        }
    }
}
