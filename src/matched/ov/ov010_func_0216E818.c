/*
 * function: func_0216E818
 * address:  0x0216E818
 * packet:   pkt_ov010_0216E818
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02013090  0x02013090  thumb
 *   func_021AA5CC  0x021AA5CC  thumb  ov021
 *   func_0216EE20  0x0216EE20  thumb  ov010
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0216F02C  0x0216F02C  thumb  ov010
 *   func_02013144  0x02013144  thumb
 *   func_021CF748  0x021CF748  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_0216EB98  0x0216EB98  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0216EB98();
typedef unsigned char  u8;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02008C20Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02188CE8(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F2C(int *p);
extern void *func_02013090(u32 heap);
extern void func_021AA5CC(struct Ctx *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap);
extern void func_0216EE20(u16 id, int col);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_0216F02C(void **p, void *a, void *b);
extern void func_02013144(char *p, int v);
extern void func_021CF748(u32 a, u32 x, int *out, u16 *out2);
extern void func_021AAABC(int s);

int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int h;
    int *t;
    int v;
    int w;
    int x;

    h = (int)func_020122C0((void *)a0, 0, func_0216EB98, 0x28);
    t = func_020124E8((struct Obj *)h);
    v = func_02188CE8((u8 *)a1);
    w = (int)func_02012F2C(func_020120F4((const struct Ctx *)a0));
    x = (int)func_02013090(4);
    func_021AA5CC((struct Ctx *)v, (void *)x, a2, a3, (void *)a4, a5, 4);
    func_0216EE20(a4, 0);
    func_02008DF0((struct Sub02008C20Obj *)w, 6);
    func_02008DF0((struct Sub02008C20Obj *)w, 0x56);
    func_0216F02C((void **)t, (void *)a0, (void *)x);
    t[5] = 1;
    if (a6 & 1) {
        func_02013144((char *)x, 0x100);
        t[6] = 1;
    }
    func_021CF748(a4, a1, (int *)((int)t + 0x24), (u16 *)(t[2] + 0x18));
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}
