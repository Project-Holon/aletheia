/*
 * function: func_021BD0C4
 * address:  0x021BD0C4
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sets up one whole +0x2c stream: three +0x1c8/+0x1cc/+0x1d0 handles, the
 * 0xf-wide tile window and the 0x440 record, then flags the object busy.
 *
 * symbols:
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201F73C  0x0201F73C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32  func_021BE034(void *p);
extern u32  func_021BE03C(void *p);
extern u32  func_021BE044(void *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 p, int v);
extern u32  func_02045EC0(u32 p, int v);
extern void func_0201C724(u32 a, u32 b, int c, int d, u32 e, u32 f, int g);
extern void func_02045808(u32 p);
extern void func_0201F73C(u32 p, int a, int b, int c);

void func_021BD0C4(void *a0, char *a1, int a2)
{
    u32 x = func_021BE034(a0);
    u32 y = func_021BE03C(a0);
    u32 z = func_021BE044(a0);
    u32 w;

    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(a1 + 0x2c)), 0xf);
    w = func_02045EC0(y, a2);
    func_0201C724(z, (u32)func_02045770((struct Descriptor *)*(u32 *)(a1 + 0x2c)), 0, 0, w, x, 0x440);
    func_02045808(w);
    func_0201F73C(*(u32 *)(a1 + 0x2c), 2, 0x140, 9);
    *(u32 *)(a1 + 0x20) = 1;
}
