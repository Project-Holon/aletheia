/*
 * function: func_021B8150
 * address:  0x021B8150
 * packet:   pkt_ov071_021B8150
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020435F4  0x020435F4  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_021B8270  0x021B8270  thumb  ov071
 *   func_021B82F0  0x021B82F0  thumb  ov071
 *   func_021B83C0  0x021B83C0  thumb  ov071
 *   func_021B833C  0x021B833C  thumb  ov071
 *   func_020315D4  0x020315D4  arm
 */

typedef struct {
    char pad[0x40];
    void *f40;
    void *f44;
} W;

typedef struct {
    int f0;
    struct {
        char pad[8];
        void *f8;
    } *f4;
} B;

typedef unsigned int   u32;
struct PrintSys;
struct Rec3;
struct S020315D4;
struct U16Vec;
int func_021B8150(void *a, int unused, B *b, W *w)
{
    extern u32 func_0201C6B4(const struct PrintSys *p);
    extern void func_020435F4(u32 planes);
    extern void func_0201CE48(struct Rec3 *p);
    extern void func_02045808(struct U16Vec *vec);
    extern void func_021B8270(unsigned char *p);
    extern void func_021B82F0(void *p);
    extern void func_021B83C0(void *p);
    extern void func_021B833C(void);
    extern void func_020315D4(struct S020315D4 *p);

    if (func_0201C6B4(b->f4->f8) == 0) {
        return 0;
    }
    func_020435F4(8);
    if (w->f40 != 0) {
        func_0201CE48(w->f40);
    }
    if (w->f44 != 0) {
        func_02045808(w->f44);
    }
    func_021B8270((unsigned char *)w);
    func_021B82F0(w);
    func_021B83C0(w);
    func_021B833C();
    func_020315D4(a);
    return 1;
}
