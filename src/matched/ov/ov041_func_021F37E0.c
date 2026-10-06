/*
 * function: func_021F37E0
 * address:  0x021F37E0
 * packet:   pkt_ov041_021F37E0
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F37E0  0x021F37E0  thumb
 *   func_021F3884  0x021F3884  thumb
 *   func_021F3EE4  0x021F3EE4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef unsigned short u16;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct Big;
struct Desc;
extern void *func_02188C80(void *p);
extern int *func_021897BC(char *p, int idx);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u16 func_021A3050(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void *func_0200B3A4(u32 a, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u8 func_021F3EE4(int x, int y);
extern int func_021F3884(void *a0, int *state);

int func_021F37E0(void *a)
{
    void *s;
    void *t;
    u8 *p;
    int v[3];
    int x;
    int y;
    int d;
    u8 idx;
    int r;

    s = func_0201210C((void *)a);
    func_0200B3A4((u32)func_02012EC4(func_020120F4(func_02188C80(s))), 5);
    p = (u8 *)func_021897BC(s, 1);
    t = func_02188CB4((void *)s);
    func_021A3038(t, (struct VecFx32 *)v);
    x = v[0] / 0x10000;
    y = v[2] / 0x10000;
    d = func_021A3050(t);
    switch (d) {
    case 0:
        y -= 2;
        break;
    case 1:
        y += 2;
        break;
    case 2:
        x -= 2;
        break;
    case 3:
        x += 2;
        break;
    }
    idx = func_021F3EE4(x, y);
    if (idx >= 10) {
        return 0;
    }
    r = (int)func_020122C0(a, 0, func_021F3884, 0);
    p[0] = idx;
    p[1] = d;
    return r;
}
