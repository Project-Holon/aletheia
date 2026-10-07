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
 *   func_02072758  0x02072758  arm
 *
 * Task callback DWCi_SNDlInit (func_021CFEBC) registers: a tail call to
 * func_02072758.
 */

extern void func_02072758(void);

void taskSound(void)
{
    func_02072758();
}
