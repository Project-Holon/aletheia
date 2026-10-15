/*
 * function: PARTICLE_UpdateSystem
 * address:  0x020514F4
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  ABS32 SPL_EMITTER_FreeTexNode at +0x0c (tail-call pool word): 0x02052770 (pkt_0205250C, 312 bytes) open, no witness
 *
 * NOTE ON PACKET: this 16-byte leaf sits at 0x020514F4..0x02051504, in the
 * four-byte gap between packet pkt_02051230 (ends 0x020514F4) and packet
 * pkt_02051504 (starts 0x02051504) - the last instruction word of the
 * 0x02051414 dump plus a pool word.  The listing does label it
 * (`PARTICLE_UpdateSystem` at asm/arm9/src/019_0204D434.s:5680), but its only caller
 * in the whole image is the `bl` at 0x02051594 inside PARTICLE_UpdateAllSystems, which is
 * itself inside pkt_02051504's range, so the `label` class cannot attest it for
 * that caller.  Filing it here as its own entry makes it a `matched` witness
 * for PARTICLE_UpdateAllSystems instead, which is the only reason it is in this shard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_UpdateSystem.c \
 *       --func PARTICLE_UpdateSystem --addr 0x020514F4 --cc 1.1p1 --arm
 *
 * symbols:
 *   SPL_EMITTER_FreeTexNode  0x02052770  arm
 */

typedef unsigned int u32;

extern int SPL_EMITTER_FreeTexNode(u32 a);

int PARTICLE_UpdateSystem(u32 *p)
{
    return SPL_EMITTER_FreeTexNode(*p);
}
