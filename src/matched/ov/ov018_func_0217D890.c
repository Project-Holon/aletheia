/*
 * function: func_0217D890
 * address:  0x0217D890
 * packet:   pkt_ov018_0217D890
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

extern int func_020450F0(int, int, int, int, int, int, int);
extern void func_02045334(int);
extern void func_02045374(int);
extern unsigned char func_02045730(int);
extern void func_020409B4(unsigned int);

typedef struct {
    char pad[0x44];
    int a;
    char b;
    char pad2[3];
    int c;
    char d;
} S;

void func_0217D890(S *p)
{
    int r;
    int r2;
    char z;

    z = 0;
    r = func_020450F0(6, 0, 0, 0x20, 2, 14, 1);
    p->a = r;
    p->b = z;
    func_02045334(r);
    func_02045374(r);
    func_020409B4(func_02045730(r));
    r2 = func_020450F0(6, 1, 0x12, 0x1e, 4, 14, 1);
    p->c = r2;
    p->d = z;
    func_02045334(r2);
    func_02045374(r2);
    func_020409B4(func_02045730(r2));
}
