/*
 * function: func_021F3880
 * address:  0x021F3880
 * packet:   pkt_ov048_021F3880
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE4C4  0x021BE4C4  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F4698  0x021F4698  thumb  ov048
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    u16 f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
} Obj;

typedef struct Cfg {
    u16 a;
    u8 b;
    u8 c;
    u8 d;
    int w;
} Cfg;

struct Ctx;
extern void *func_02188C80(void *p);
extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void *func_021BE4C4(int a, int b, int c);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_021F4698(unsigned char *p);

Obj *func_021F3880(int a)
{
    u16 r5;
    int r7;
    Obj *o;
    int v;
    Cfg c;

    r5 = func_02188C84((u8 *)a);
    r7 = func_02188D2C((int *)a);
    o = func_02189764((unsigned char *)a, 0, r5, 0x68);
    func_02082BCC(o, 0, 0x68);
    o->f00 = r5;
    o->f04 = a;
    v = (int)func_02188C80((void *)a);
    o->f0C = v;
    o->f08 = (int)func_020120F4((const struct Ctx *)v);
    o->f10 = 0;
    c.a = r5;
    c.b = 7;
    c.c = 8;
    c.d = 3;
    c.w = (int)func_021BE4C4(r7, 1, 0);
    o->f14 = (int)func_021F4698((unsigned char *)(&c));
    return o;
}
