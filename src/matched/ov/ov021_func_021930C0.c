/*
 * function: func_021930C0
 * address:  0x021930C0
 * packet:   pkt_ov021_021930C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(int, int);
extern void func_02045374(int);
extern void func_02045334(struct Descriptor *);
extern void func_020409B4(u32 index);
extern void func_0201F73C(int, int, int, int);

int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f)
{
    int r;
    int k;

    r = func_020450F0(a & 0xff, b & 0xff, c & 0xff, d & 0xff, e & 0xff, f & 0xff, 1);
    func_02043B5C((int)func_02045770((struct Descriptor *)r), 0xff);
    func_02045374(r);
    func_02045334((struct Descriptor *)r);
    func_020409B4((u8)a);
    k = 0xd;
    if (f != 0xe) {
        k = 0xa;
    }
    func_0201F73C(r, 0, 1, k & 0xff);
    return r;
}
