/*
 * function: func_021D89EC
 * address:  0x021D89EC
 * packet:   pkt_ov119_021D89EC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020173EC 0x020173EC thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_020173EC(void);

int func_021D89EC(const u8 *p)
{
    int n;
    int i;

    n = func_020173EC();
    if (p == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (p[i] != 0) {
            return 1;
        }
    }
    return 0;
}
