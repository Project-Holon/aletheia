/*
 * file:     unit_02179EE0.c
 * unit:     yes
 * function: func_02179EE0, func_02179F28
 * address:  0x02179EE0
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0217ABA8  0x0217ABA8  data  ov015
 */
unsigned short func_02179EE0(void *input, unsigned long length);
void func_02179F28(void);
extern int d_0217ABA8[];

/*
 * sdk:      IRCi_CalcSum (libirc.a irc.o)
 */
unsigned short func_02179EE0(void *input, unsigned long length)
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


void func_02179F28(void)
{
    d_0217ABA8[5] = 1;
    d_0217ABA8[1] = d_0217ABA8[1] + 1;
}
