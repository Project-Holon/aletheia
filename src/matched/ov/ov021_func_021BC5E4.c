/*
 * function: func_021BC5E4
 * address:  0x021BC5E4
 * packet:   pkt_ov021_021BC5E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC6D0  0x021BC6D0  thumb  ov021
 *   func_021BC6E8  0x021BC6E8  thumb  ov021
 *   func_021BD01C  0x021BD01C  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 */

extern void func_021BC6D0(int a);
extern void func_021BC6E8(int a);
extern void func_021BD01C(int a);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
typedef unsigned int   u32;
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(int a, int b, int c, int d, int e);

void func_021BC5E4(int *p)
{
    int r4;

    func_021BC6D0((int)p);
    func_021BC6E8((int)p);
    func_021BD01C((int)p);
    r4 = p[9];
    func_02045334((struct Descriptor *)r4);
    func_02045374((struct Cfg *)r4);
    func_020409B4(func_02045730((struct Descriptor *)r4));
    func_0204047C(3, 1);
    func_02040588(3, 0);
    func_0207D63C(0x04000050, 8, 0x11, 0x10, 4);
}
