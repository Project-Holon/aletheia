/*
 * function: func_0218A1D0
 * address:  0x0218A1D0
 * packet:   pkt_ov009_0218A1D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      randomString (gpiconnect.o)
 *
 * symbols:
 *   func_02094694  0x02094694  arm  
 *   g_021A4618     0x021A4618  data  ov009
 */

extern unsigned int func_02094694();
extern char g_021A4618[];

void func_0218A1D0(char *buffer, int numChars)
{
    int i;

    for (i = 0; i < numChars; i++)
        buffer[i] = g_021A4618[func_02094694() % 0x3E];
    buffer[i] = 0;
}
