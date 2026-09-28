/*
 * function: func_02179CAC
 * address:  0x02179CAC
 * packet:   pkt_02179CAC
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0217AB80  0x0217AB80  data  ov015
 *   d_0217ABA0  0x0217ABA0  data  ov015
 *   func_02179D3C  0x02179D3C  thumb  ov015
 */

extern unsigned char d_0217AB80[];
extern unsigned char d_0217ABA0[];
extern int func_02179D3C(void);

int func_02179CAC(void)
{
    if (d_0217AB80[0xc] == 0)
        return 0;
    if (d_0217ABA0[5] != 0)
        return 1;
    if (d_0217AB80[0x1d] == 1) {
        if (func_02179D3C() == 0)
            return 1;
    }
    return 0;
}
