/*
 * function: func_021A66F8
 * address:  0x021A66F8
 * packet:   pkt_ov021_021A66F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

typedef struct {
    int f0;
    int f4;
} S;

int func_021A66F8(S *a, int m)
{
    if (a->f4 & m) {
        return 1;
    }
    return 0;
}
