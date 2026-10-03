/*
 * function: func_021F3CFC
 * address:  0x021F3CFC
 * packet:   pkt_ov059_021F3CFC
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3D9C  0x021F3D9C  thumb  ov059
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    u8 pad[0x24];
    u16 *p24;
} W;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
extern void *func_0201210C(const struct Ctx *p);
extern W *func_021897BC(void *p, int i);
extern void *func_02188D2C(void *p);
extern V *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern u8 *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021BE6CC(void *p, int i, u16 j, u16 k, int flag);
extern int func_021F3D9C(void *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);

void func_021F3CFC(void *a, V *b, u16 c, u16 d)
{
    int i;
    void *t;
    void *s;
    W *w;
    u16 *q;

    t = func_0201210C(a);
    w = func_021897BC(t, 1);
    s = func_02188D2C(t);
    q = w->p24;
    q[0] = c;
    q[1] = d;
    *func_021BE480(s, 0, 2) = *b;
    func_021BE4B4(s, 0, 2, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674(s, 0, 2, i), 0);
        func_021BE700(s, 0, 2, i, 1);
        func_021BE6CC(s, 0, 2, i, 0);
    }
    func_020122C0(a, 0, func_021F3D9C, 0);
}
