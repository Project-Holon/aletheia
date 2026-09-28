/*
 * function: func_021E5838
 * address:  0x021E5838
 * packet:   pkt_021E5838
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C   0x0203064C  arm
 *   func_0203159C   0x0203159C  arm
 *   func_02082BCC   0x02082BCC  arm
 *   func_021E58F0   0x021E58F0  thumb
 *   func_021E5A70   0x021E5A70  thumb
 *
 * Allocate the 0x58-byte subobject and dispatch on track[1].
 */


extern void func_0203064C(int, int, int);
extern int func_0203159C(int, int, int);
extern void func_02082BCC(int, int, int);
extern void func_021E58F0(int, int *, int);
extern void func_021E5A70(int, int *, int);

int func_021E5838(int a, int b, int *p)
{
    int h;
    func_0203064C(1, 0x58, 0x10000);
    h = func_0203159C(a, 4, 0x58);
    func_02082BCC(h, 0, 4);
    p[2] = 0;
    switch (p[1]) {
    case 0:
        func_021E58F0(h, p, 0x58);
        break;
    case 1:
        func_021E5A70(h, p, 0x58);
        break;
    }
    return 1;
}
