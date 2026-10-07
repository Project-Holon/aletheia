/*
 * function: func_021BA330
 * address:  0x021BA330
 * packet:   pkt_ov213_021BA330
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note:     2026-10-05: the zero is passed in each arm's call of func_0201DD78
 *           (call written per arm), and func_0201C7A4 takes a fifth argument
 *           (stack word); 8 byte gap closed. EXACT* (trailing alignment).
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void func_021BA330(void *p, int a)
{
    int z = 0;
    int q;

    func_02043B5C(func_02045770((struct Descriptor *)(*(int *)((char *)p + 0x1c))), z);
    if (*(int *)((char *)p + 0x14) == 0)
        func_0201DD78(5, 6, z);
    else
        func_0201DD78(3, 4, z);
    func_0201C7A4(func_02045770((struct Descriptor *)(*(int *)((char *)p + 0x1c))), 1, 1, (void *)(*(int *)((char *)p + 0x18)), (void *)a);
    q = *(int *)((char *)p + 0x1c);
    func_02045334((struct Descriptor *)q);
    func_02045374((struct Cfg *)q);
    func_02041B6C(func_02045730((struct Descriptor *)q));
}
