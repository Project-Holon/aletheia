/*
 * function: func_021841F8
 * address:  0x021841F8
 * packet:   pkt_ov023_021841F8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_02082B0C  0x02082B0C  arm
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021844D8  0x021844D8  thumb  ov023
 *   func_02186860  0x02186860  thumb  ov023
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_02039338(int a);
extern void func_02082B0C(void *src, void *dst, u32 n);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct Bmp;
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02045334(struct Descriptor *d);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_021844D8(u8 *d, int x, int y);
extern void func_02186860(u8 *d, int x, int y);

void func_021841F8(int a, int b, u8 *c, u8 *d, int e)
{
    int n;
    int off;
    u32 t;

    if (func_02039338(a) != 0) {
        off = c[0x3ec] * 0x3e8;
        if (off > 0x3840) {
            func_02082B0C(c, d + 0x4290 + off, 0x190);
        } else {
            func_02082B0C(c, d + 0x4290 + off, 0x3e8);
        }
        func_02082B0C(d + 0x4290,
                      func_020437D4(func_02045770((struct Descriptor *)*(u32 *)(d + 0x118))),
                      0x3840);
        t = *(u32 *)(d + 0x118);
        func_02045334((struct Descriptor *)t);
        func_02045374((struct Cfg *)t);
        func_020409B4(func_02045730((struct Descriptor *)t));
    } else {
        n = *(int *)(d + 0x428c);
        if (n * 1000 < 0x3840) {
            *(int *)(d + 0x428c) += 1;
            func_021844D8(d, *(int *)(d + 0x428c), e);
        } else {
            func_02186860(d, 0x2904, 0);
        }
    }
}
