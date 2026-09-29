/*
 * function: func_021AF2AC
 * address:  0x021AF2AC
 * packet:   pkt_ov013_021AF2AC
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021B3C80     0x021B3C80  data  ov013
 *   func_021B2254  0x021B2254  arm  ov013
 */

typedef unsigned char u8;

typedef struct Work {
    u8 pad0[0x19A0];
    int a[2];
    int f19A8;
} Work;

extern Work *d_021B3C80;
extern int func_021B2254(u8 i);

int func_021AF2AC(int n)
{
    int i;

    if (d_021B3C80 == 0 || d_021B3C80->f19A8 != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == n) {
            continue;
        }
        if (d_021B3C80->a[i] != 1) {
            continue;
        }
        if (func_021B2254(i)) {
            return 0;
        }
        d_021B3C80->a[i] = 0;
    }
    return 1;
}
