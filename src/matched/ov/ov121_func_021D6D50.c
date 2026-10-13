/*
 * function: func_021D6D50
 * address:  0x021D6D50
 * packet:   pkt_021D6D50
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_LoadArchiveMember  0x0205121C  arm
 *   PARTICLE_SetupSystem  0x02051230  arm
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0205121C now has an
 * EXACT arm9 shard entry (pkt_0205121C), so the call at +000A resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern void PARTICLE_SetupSystem(int, int, int, int);

void func_021D6D50(int *p, int a, int b, int c)
{
    int x = PARTICLE_LoadArchiveMember(a, b, c);
    PARTICLE_SetupSystem(*p, x, 1, 0);
}
