/*
 * function: func_021671FC
 * address:  0x021671FC
 * packet:   pkt_ov010_021671FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_021672D0  0x021672D0  thumb  ov010
 *   func_021672E4  0x021672E4  thumb  ov010
 *   func_021672F8  0x021672F8  thumb  ov010
 *   func_0216730C  0x0216730C  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F31C  0x0201F31C  thumb
 *   func_02190758  0x02190758  thumb  ov021
 *   func_021907C0  0x021907C0  thumb  ov021
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045808  0x02045808  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct O {
    u16 id;
    u16 pad2[3];
    int f8;
    int pad0c[2];
    int f14;
    int f18;
    int f1c;
};

extern void *func_020457B0(u32 size, u32 heap);
extern int func_021672D0(struct O *o);
extern int func_021672E4(struct O *o);
extern int func_021672F8(struct O *o);
extern int func_0216730C(int a);
extern int func_02012944(int a);
extern void func_0201F02C(int a, int b, int c);
extern void func_0201EFA4(int a, int b, int c, int d, int e, int f);
extern void func_02045CAC(int a, int b, void *c);
extern void func_0201F250(int a, void *b, void *c);
extern void func_0201F31C(int a);
extern void func_02190758(int a, int b, int c, void *d);
extern int func_021907C0(int a);
extern void func_02045730();
extern void func_020409B4();
extern void func_02045808(void *a);

void func_021671FC(struct O *o)
{
    void *r4;
    void *r6;
    int r7;
    int s8;
    int sc;
    r4 = func_020457B0(0x100, o->id);
    r6 = func_020457B0(0x100, o->id);
    r7 = func_021672D0(o);
    s8 = func_021672E4(o);
    sc = func_021672F8(o);
    r7 = func_0216730C(r7);
    func_0201F02C(o->f1c, 0, func_02012944(o->f8));
    func_0201EFA4(o->f1c, 1, s8, 5, 1, 1);
    func_0201EFA4(o->f1c, 2, sc, 5, 1, 1);
    func_02045CAC(o->f18, r7, r4);
    func_0201F250(o->f1c, r6, r4);
    func_0201F31C(o->f1c);
    func_02190758(o->f14, 8, 0, r6);
    func_021907C0(o->f14);
    func_02045730();
    func_020409B4();
    func_02045808(r4);
    func_02045808(r6);
}
