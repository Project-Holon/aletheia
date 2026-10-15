/*
 * function: taskSound
 * address:  0x021D0034
 * packet:   pkt_ov016_021D0034
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskSound (libdwcutil.TWL.HYB.a sound.o, static)
 *
 * symbols:
 *   NNS_SndBoot  0x02072758  arm
 *
 * Task callback DWCi_SNDlInit (DWCi_SNDlInit) registers: a tail call to
 * NNS_SndBoot.
 */

extern void NNS_SndBoot(void);

void taskSound(void)
{
    NNS_SndBoot();
}
