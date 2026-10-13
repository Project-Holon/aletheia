/*
 * function: PARTICLE_CreateSystemDefault
 * address:  0x02050C04
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_CreateSystemDefault.c \
 *       --func PARTICLE_CreateSystemDefault --addr 0x02050C04 --cc 1.1p1 --arm
 *
 * symbols:
 *   PARTICLE_CreateSystem  0x02050C30  arm
 */

typedef unsigned int   u32;
extern void *PARTICLE_CreateSystem(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);

int PARTICLE_CreateSystemDefault(int a, int b, int c, int d)
{
    return (int)PARTICLE_CreateSystem(a, b, c, 5, 6, 63, d);
}
