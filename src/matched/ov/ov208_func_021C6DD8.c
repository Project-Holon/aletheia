/*
 * function: ov208_func_021C6DD8
 * address:  0x021C6DD8
 * packet:   pkt_ov208_021C6DD8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ov208_func_021C6D6C  0x021C6D6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void ov208_func_021C6D6C(int n, int i, u8 *lo, u8 *mid, u8 *hi);

u16 ov208_func_021C6DD8(u16 n, u8 x)
{
    u8 b[3];
    u16 i;

    for (i = 0; i < n; i++) {
        ov208_func_021C6D6C(n, i, &b[2], &b[1], &b[0]);
        if (i == 0) {
            if (x < b[0])
                break;
        } else {
            if (i == n - 1)
                break;
            if (b[2] <= x && x < b[0])
                break;
        }
    }
    return i;
}
