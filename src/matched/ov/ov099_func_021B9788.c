/*
 * function: func_021B9788
 * address:  0x021B9788
 * packet:   pkt_ov099_021B9788
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_020362DC  0x020362DC  arm
 *   func_021B9CF8  0x021B9CF8  thumb  ov099
 *   func_021BA1FC  0x021BA1FC  thumb  ov099
 */

typedef unsigned char u8;

extern int func_021C49A4(int a, int b);
extern int func_020362DC(void);
extern int *func_021B9CF8(int a, int *b, int c);
extern int func_021BA1FC(int *a);

int func_021B9788(int a, int *b)
{
    int v;
    int c;
    int *r;

    c = func_021C49A4(b[0], 6);
    if (func_020362DC() & 1) {
        r = func_021B9CF8(a, b, c);
        if (r != 0) {
            if (func_021BA1FC(r) == 1)
                v = func_021C49A4(r[0], 4);
            else
                v = 0;
        } else
            v = 0;
        *(u8 *)((char *)b + 0xa) = v;
    }
    return 1;
}
