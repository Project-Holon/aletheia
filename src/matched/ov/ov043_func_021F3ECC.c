/*
 * function: func_021F3ECC
 * address:  0x021F3ECC
 * packet:   pkt_ov043_021F3ECC
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf called only from func_021F3D78; the ov044 twin is
 * ov044_func_021F390C.c with every field one word lower.
 */

int func_021F3ECC(int *p)
{
    if (p[3] < 0) {
        if (p[2] >= p[1]) {
            return 1;
        }
    } else {
        if (p[2] <= p[1]) {
            return 1;
        }
    }
    return 0;
}
