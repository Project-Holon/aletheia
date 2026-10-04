/*
 * function: func_021B8440
 * address:  0x021B8440
 * packet:   pkt_ov071_021B8440
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
 *   func_02040588  0x02040588  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   d_021BABF8     0x021BABF8  data  a1
 */

extern char d_021BABF8[];

typedef struct {
    char pad[0x3c];
    void *f3c;
    void *f40;
    void *f44;
} W;

typedef unsigned int   u32;
struct Descriptor;
struct Rec3;
struct U16Vec;
void func_021B8440(W *w)
{
    extern void *func_02045770(struct Descriptor *p);
    extern void func_02034714(const char *expr, u32 line, const char *file);
    extern void func_0201CE48(struct Rec3 *p);
    extern void func_02045808(struct U16Vec *vec);
    extern void func_02040588(u32 which, u32 enable);
    extern void func_02043B5C(unsigned, unsigned);
    extern void func_02045334(struct Descriptor *d);
    extern void func_0201DD78(u32 r, u32 g, u32 b);
    unsigned r = (unsigned)func_02045770(w->f3c);

    if (w->f40 == 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    func_0201CE48(w->f40);
    w->f40 = 0;
    func_02045808(w->f44);
    w->f44 = 0;
    func_02040588(5, 0);
    func_02043B5C(r, 0xff);
    func_02045334(w->f3c);
    func_0201DD78(0xf, 2, 0);
}
