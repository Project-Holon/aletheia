/*
 * function: func_021F3FBC
 * address:  0x021F3FBC
 * packet:   pkt_ov043_021F3FBC
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf called only from func_021F3AC0. The result goes through
 * the local r: four direct returns invert the first arm's branch (3 bytes).
 *
 * symbols:
 *   d_021F4328     0x021F4328  data  ov043
 */

extern int d_021F4328[];

int func_021F3FBC(int *a, int i)
{
    int r;

    if (a[i]) {
        if (d_021F4328[i]) {
            r = 0;
        } else {
            r = 1;
        }
    } else {
        if (d_021F4328[i]) {
            r = 1;
        } else {
            r = 0;
        }
    }
    return r;
}
