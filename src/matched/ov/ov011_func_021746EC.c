/*
 * function: func_021746EC
 * address:  0x021746EC
 * packet:   pkt_ov011_021746EC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_021583EC  0x021583EC  thumb ov010
 *   func_021861F4  0x021861F4  thumb ov020
 *   func_02082D44  0x02082D44  arm
 *   func_02012800  0x02012800  thumb
 */

int func_02026478(int a);
int func_020127D0(int a, int b);
int func_021583EC(int a, int b);
typedef unsigned short u16;
void func_021861F4(u16 *p, int x);
void func_02082D44(void *d, void *s, int n);
void func_02012800(int a, void *b);

void func_021746EC(int a, int b, void *c, char *d)
{
    int h;
    int s;

    h = func_02026478(*(int *)(d + 4));
    s = func_020127D0(h, 0);
    func_021861F4(c, func_021583EC(h, a));
    func_02082D44(c, (void *)s, 0x1E8);
    func_02012800(h, c);
    d[0x90C] = 1;
}
