/*
 * function: func_021F9220
 * address:  0x021F9220
 * packet:   pkt_ov094_021F9220
 * region:   ov094
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 */

void func_021F9220(int *p, int *d, int *lim, int *flag)
{
    int n = *p + *d;
    *p = n;
    if (*d < 0) {
        if (n <= *lim) {
            *p = *lim;
        } else {
            if (flag)
                *flag = 0;
        }
    } else {
        if (n >= *lim) {
            *p = *lim;
        } else {
            if (flag)
                *flag = 0;
        }
    }
}
