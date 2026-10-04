/*
 * function: func_021EEA08
 * address: 0x021EEA08
 * packet: pkt_ov028_021EEA08
 * region: ov028
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 */

extern int *func_021A21B8(int *);
int func_021EEA08(int *a)
{
    int *p;
    p = func_021A21B8(a);
    p[1] = 0;
    return 1;
}
