/*
 * function: NNS_SndSetMasterVolume
 * address:  0x02072788
 * packet:   pkt_02072788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * ARM tail call: ldr ip, =target; bx ip (mwcc's same-module tail call,
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The listing labels the
 * two-instruction body func_02072788 between NNS_SndBoot and
 * NNS_SndSetMasterPan; the C is the volume setter of nns_snd_system.c.
 *
 * symbols:
 *   SND_SetMasterVolume  0x0208970C  arm
 */

extern void SND_SetMasterVolume(int volume);

void NNS_SndSetMasterVolume(int volume)
{
    SND_SetMasterVolume(volume);
}
