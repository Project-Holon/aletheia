/*
 * function: IRCi_CalcSum
 * address:  0x02179EE0
 * packet:   pkt_ov015_02179EE0
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IRCi_CalcSum (libirc.a irc.o)
 *
 * symbols:

 */

unsigned short IRCi_CalcSum(void *input, unsigned long length)
{
    unsigned long sum;
    unsigned long i;
    unsigned char t;

    sum = 0x80;
    for (i = 0; i < length; i++) {
        t = *(unsigned char *)input;
        input = (unsigned char *)input + 1;
        if (i & 1)
            sum += t;
        else
            sum += t << 8;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return (unsigned short)sum;
}
