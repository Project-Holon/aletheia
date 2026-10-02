/*
 * function: func_0218644C
 * address: 0x0218644C
 * packet: pkt_ov023_0218644C
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02186E84 0x02186E84 data a4
 */
extern int d_02186E84[][2];
void func_0218644C(char *p, int mode)
{
    int n;
    n = *(int *)(p + 0x19c);
    if (*(int *)(p + 0x198) != n) {
        if (mode != 2) {
            *(int *)(p + 0x198) = n;
            return;
        }
        if (d_02186E84[n][0] != 0)
            *(int *)(p + 0x198) = n;
    }
}
