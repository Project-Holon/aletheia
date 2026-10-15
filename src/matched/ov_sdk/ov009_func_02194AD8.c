/*
 * function: gti2VerifyChallenge
 * address:  0x02194AD8
 * packet:   pkt_ov009_02194AD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2VerifyChallenge (gt2auth.o)
 *
 * The two comparisons are written as `? 1 : 0` conditional expressions (w6_nm);
 * as plain comparisons the last two eor operands come out swapped.
 *
 * symbols:

 */

int gti2VerifyChallenge(unsigned char *buffer)
{
    int oddmode;
    int i;

    oddmode = 0;
    for (i = 1; i < 32; i++) {
        oddmode = (buffer[i - 1] & 1) ^ (i & 1) ^ oddmode ^ (buffer[0] & 1) ^ ((buffer[0] < 79) ? 1 : 0) ^ ((buffer[i - 1] < buffer[0]) ? 1 : 0);
        if ((oddmode && !(buffer[i] & 1)) || (!oddmode && (buffer[i] & 1) == 1))
            return 0;
    }
    return 1;
}
