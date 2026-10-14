/*
 * function: IRCi_CheckPacket
 * address:  0x0217A280
 * packet:   pkt_ov015_0217A280
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    2026-10-05 wave P13 lane B9: libirc receive check. The empty delay loop needs the bottom-test form
 *           (i < n) ? 1 : 0, otherwise mwcc deletes it. Callee IRCi_CalcSum is IRCi_CalcSum (u16 return, matched);
 *           IRCi_Restore is void. Plain C, no pragmas.
 *
 * symbols:
 *   IRCi_CalcSum  0x02179EE0  arm  ov015
 *   IRCi_Restore  0x02179F28  arm  ov015
 *   gIrcBuffer     0x0217ABD8  data  ov015
 *   d_0217ABA8     0x0217ABA8  data  ov015
 */

#include "../include/G_ov015_0217ABA8.h"

extern unsigned char gIrcBuffer[];
extern struct G_ov015_0217ABA8 d_0217ABA8;
extern unsigned short IRCi_CalcSum(void *input, unsigned long length);
extern void IRCi_Restore(void);

int IRCi_CheckPacket(unsigned long n)
{
    unsigned char *pk = gIrcBuffer;
    unsigned long i;
    unsigned short sum;
    unsigned short calc;

    if (n == 1)
        return pk[0] == 0xFC;
    if (n < 4)
        return 0;
    sum = pk[2] + (pk[3] << 8);
    pk[2] = 0;
    pk[3] = 0;
    calc = IRCi_CalcSum(pk, n);
    pk[3] = sum >> 8;
    pk[2] = sum;
    if (calc == sum) {
        ((char *)&d_0217ABA8)[0] = 0;
        return 1;
    }
    if (*(int *)(((char *)&d_0217ABA8) + 0x24)) {
        for (i = 0; (i < n) ? 1 : 0; i++)
            ;
        IRCi_Restore();
    }
    return 0;
}
