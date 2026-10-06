/*
 * function: func_021F150C
 * address:  0x021F150C
 * packet:   pkt_ov032_021F150C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F150C 0x021F150C thumb
 *   func_021F1218 0x021F1218 thumb
 *   func_021F0EA4 0x021F0EA4 thumb
 *   func_021F155C 0x021F155C thumb
 *   func_021F1484 0x021F1484 thumb
 */

typedef unsigned char u8;

extern void func_021F1218(char *p, short x, short y);
extern void func_021F0EA4(char *p, unsigned a);
extern void func_021F155C(char *p, u8 *e, int mode, u8 delay, int *r);
extern void func_021F1484(char *this, int a, u8 *b, u8 *c, void *s);

void func_021F150C(u8 *this, u8 *p, void *s)
{
    int k;

    p[2] = 1;
    func_021F1218((char *)p, -208, 0);
    func_021F0EA4((char *)p, 1);
    k = 0;
    if (this[0x7b] != 0)
        k = 8;
    func_021F155C((char *)this, p, 2, (u8)k, s);
    func_021F1484((char *)this, 1, 0, p, s);
}
