/*
 * function: func_0216E7C8
 * address:  0x0216E7C8
 * packet:   pkt_ov010_0216E7C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x10-byte task record (handler func_0216E68C) and fills it
 * from the arguments.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0216E68C  0x0216E68C  thumb  ov010
 *   func_0216EE40  0x0216EE40  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 */

typedef unsigned int u32;

struct Work;
extern int func_0216E68C(void *evt, u32 *state, struct Work *w);
typedef unsigned char  u8;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02008C20Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0216EE40(void *p, int which);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_02188CE8(u8 *p);
extern void func_021AAABC(int s);

int func_0216E7C8(int a0, int a1, int a2, int a3, int a4)
{
    int h;
    u32 *t;

    h = (int)func_020122C0((void *)a0, 0, func_0216E68C, 0x10);
    t = func_020124E8((struct Obj *)h);
    t[0] = a0;
    t[1] = a2;
    t[2] = a3;
    t[3] = a4;
    func_0216EE40((void *)a2, 0);
    func_02008DF0(func_02012F2C(func_020120F4((const struct Ctx *)a0)), 5);
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}
