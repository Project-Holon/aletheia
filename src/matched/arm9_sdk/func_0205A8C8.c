/*
 * function: IsValidApnum
 * address:  0x0205A8C8
 * packet:   pkt_0205A8C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IsValidApnum (libdwcac.TWL.HYB.a(wds.o))
 *
 * symbols:
 *   (none)
 */

int IsValidApnum(unsigned char *apnum)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (apnum[i] < 0x20 || apnum[i] > 0x7e) {
            return 0;
        }
    }
    return 1;
}
