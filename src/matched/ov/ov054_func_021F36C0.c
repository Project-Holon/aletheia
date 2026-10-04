/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov054_021F36C0
 * region:   ov054
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021F37B4  0x021F37B4  thumb  ov054
 *   func_021F38E4  0x021F38E4  thumb  ov054
 *   func_0202B914  0x0202B914  thumb
 *   d_021F39A0     0x021F39A0  data  a4
 */

extern char d_021F39A0[];

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void func_021BE310(unsigned a, void *b, int c);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021F37B4(int *p, unsigned a);
extern void func_021F38E4(int *p, unsigned a);
extern void func_0202B914(struct Obj *o, u32 v);

void func_021F36C0(unsigned a)
{
    unsigned r5;
    int *p;

    r5 = func_02188C84((u8 *)a);
    func_021BE310(func_02188D2C((int *)a), d_021F39A0, 0);
    p = func_02189764((unsigned char *)a, 0, r5, 0x28);
    func_021F37B4(p, a);
    func_021F38E4(p, a);
    func_0202B914((struct Obj *)p[1], 0x7f);
}
