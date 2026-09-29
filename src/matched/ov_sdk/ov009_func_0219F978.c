/*
 * function: func_0219F978
 * address:  0x0219F978
 * packet:   pkt_ov009_0219F978
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NTSLengthSB (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 */

int func_0219F978(char *buf, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        if (buf[i] == 0)
            return i + 1;
    }
    return -1;
}
