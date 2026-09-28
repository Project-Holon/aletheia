/*
 * function: func_02156C4C
 * address:  0x02156C4C
 * packet:   pkt_ov010_02156C4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B6100  0x021B6100  thumb ov070
 *   func_021B63BC  0x021B63BC  thumb
 *   func_021B6294  0x021B6294  thumb
 *   func_021FD904  0x021FD904  thumb
 *   func_021FD52C  0x021FD52C  thumb ov132
 */

extern int func_021B6100(int, int);
extern int func_021B63BC(int);
extern void func_021B6294(int);
extern int func_021FD904(void);
extern void func_021FD52C(int);

int func_02156C4C(int a, int *state, int c, int *d)
{
    switch (*state) {
    case 0:
        d[1] = func_021B6100(d[0], 0x2d);
        *state = 1;
        if (*(int *)d[3] != 0) {
            if (func_021FD904() == 1)
                func_021FD52C(*(int *)d[3]);
        }
        break;
    case 1: {
        int r = func_021B63BC(d[1]);
        if (r != 0) {
            d[2] = r;
            *state = 2;
        }
        break;
    }
    case 2:
        func_021B6294(d[1]);
        return 1;
    }
    return 0;
}
