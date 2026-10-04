/*
 * function: func_021AF3D8
 * address:  0x021AF3D8
 * packet:   pkt_ov021_021AF3D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021AF4E8  0x021AF4E8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u32 f4;
    u32 f8;
} Rec;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern unsigned int func_02159B10(void *a, void *b);
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *a, void *b, void *c, unsigned int d);
extern void *func_020124E8(struct Obj *p);
extern void func_0215897C(void *vm, void *task);
extern int func_021AF4E8(u32 a, u32 b, Rec *c);

int func_021AF3D8(u32 a, u32 b)
{
    u32 u, v, h;
    void *p;
    void *x;
    Rec *r;

    p = func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    u = func_02159B10((void *)a, (void *)b);
    v = func_02159B10((void *)a, (void *)b);
    h = (u32)func_020122C0(x, 0, (void *)func_021AF4E8, 12);
    r = func_020124E8((struct Obj *)h);
    r->a = u;
    r->b = v;
    r->f4 = 1;
    r->f8 = b;
    func_0215897C(p, (void *)h);
    return 1;
}
