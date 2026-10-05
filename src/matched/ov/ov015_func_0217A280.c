/*
 * function: func_0217A280
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
 *           (i < n) ? 1 : 0, otherwise mwcc deletes it. Callee func_02179EE0 is IRCi_CalcSum (u16 return, matched);
 *           func_02179F28 is void. Plain C, no pragmas.
 *
 * symbols:
 *   func_02179EE0  0x02179EE0  arm  ov015
 *   func_02179F28  0x02179F28  arm  ov015
 *   g_0217ABD8     0x0217ABD8  data  ov015
 *   d_0217ABA8     0x0217ABA8  data  ov015
 */

extern unsigned char g_0217ABD8[];
extern char d_0217ABA8[];
extern unsigned short func_02179EE0(void *input, unsigned long length);
extern void func_02179F28(void);

int func_0217A280(unsigned long n)
{
    unsigned char *pk = g_0217ABD8;
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
    calc = func_02179EE0(pk, n);
    pk[3] = sum >> 8;
    pk[2] = sum;
    if (calc == sum) {
        d_0217ABA8[0] = 0;
        return 1;
    }
    if (*(int *)(d_0217ABA8 + 0x24)) {
        for (i = 0; (i < n) ? 1 : 0; i++)
            ;
        func_02179F28();
    }
    return 0;
}
