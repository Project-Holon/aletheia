/*
 * function: func_02194AD8
 * address:  0x02194AD8
 * packet:   pkt_ov009_02194AD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gti2VerifyChallenge (gt2auth.o)
 *
 * DIFF, 2 instructions: the operand order of two eor at +0054/+0058 (compiled\n"eor sb, sb, sl" / "eors lr, r8, sb" against "eor sb, sl, sb" / "eors lr, sb, r8").\nControl flow, register allocation (declare oddmode then i) and the hoisted\nbuffer[0]&1 all match. About 40 xor-term permutations and groupings tried;\nthe shared fail block needs the || form of the two parity tests.
 *
 * symbols:

 */

int func_02194AD8(unsigned char *buffer)
{
    int oddmode;
    int i;

    oddmode = 0;
    for (i = 1; i < 32; i++) {
        oddmode = (buffer[i - 1] < buffer[0]) ^ (((buffer[i - 1] ^ i) & 1) ^ oddmode ^ (buffer[0] & 1) ^ (buffer[0] < 0x4f));
        if ((oddmode && !(buffer[i] & 1)) || (!oddmode && (buffer[i] & 1) == 1))
            return 0;
    }
    return 1;
}
