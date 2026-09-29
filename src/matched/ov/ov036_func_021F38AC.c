/*
 * function: func_021F38AC
 * address:  0x021F38AC
 * packet:   pkt_ov036_021F38AC
 * region:   ov036
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC 0x020056EC thumb
 */

extern int func_020056EC(int);

void func_021F38AC(int n, int m, unsigned char *buf, unsigned char *out)
{
    unsigned char i;
    unsigned char j;
    unsigned char k;

    for (i = 0; i < n; i++)
        buf[i] = i;
    for (j = 0; j < m; j++) {
        k = func_020056EC(n);
        out[j] = buf[k];
        buf[k] = buf[n - 1];
        n--;
    }
}
