/*
 * function: func_021B98C4
 * address:  0x021B98C4
 * packet:   pkt_ov071_021B98C4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02034714  0x02034714  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   d_021BABFC     0x021BABFC  data  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021BABFC[];
struct CharBuf;
struct Descriptor;
struct Rec3;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0201DD78(u32 a, u32 b, u32 c);

void func_021B98C4(char *a)
{
    void *r6;

    r6 = func_02045770(*(void **)(a + 0x280));
    if (*(void **)(a + 0x294) == 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201CE48(*(void **)(a + 0x294));
    *(void **)(a + 0x294) = 0;
    func_02045808(*(void **)(a + 0x290));
    *(void **)(a + 0x290) = 0;
    func_0201F7A8(*(void **)(a + 0x280), 0);
    func_02043B5C(r6, 0xff);
    func_02045334(*(void **)(a + 0x280));
    func_0201DD78(0xf, 2, 0);
}
