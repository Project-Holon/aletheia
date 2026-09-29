/*
 * function: func_021B70C4
 * address:  0x021B70C4
 * packet:   pkt_ov071_021B70C4
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B6F4  0x0204B6F4  arm
 */

typedef unsigned char u8;

typedef struct { int h; u8 a, b, c; } St;

extern void func_0204B6F4(int, int, int);

void func_021B70C4(St *p)
{
    if (p->a == 1) {
        if (p->b % 5 == 0) {
            func_0204B6F4(p->h, p->c, 1);
            p->c ^= 1;
            if (p->b / 5 == 3)
                p->a = 0;
        }
        p->b++;
    }
}
