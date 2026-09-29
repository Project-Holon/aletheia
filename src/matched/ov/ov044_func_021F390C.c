/*
 * function: func_021F390C
 * address:  0x021F390C
 * packet:   pkt_ov044_021F390C
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf called only from func_021F37F0.
 */

int func_021F390C(int *p)
{
    if (p[2] < 0) {
        if (p[1] >= p[0]) {
            return 1;
        }
    } else {
        if (p[1] <= p[0]) {
            return 1;
        }
    }
    return 0;
}
