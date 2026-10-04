/*
 * function: func_021F37B4
 * address:  0x021F37B4
 * packet:   pkt_ov054_021F37B4
 * region:   ov054
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021C4D14  0x021C4D14  thumb  ov021
 *   func_021C4DC0  0x021C4DC0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021F3874  0x021F3874  thumb  ov054
 */

typedef unsigned short u16;

typedef struct O {
    u16 h0;
    u16 pad2;
    int f4;
    int f8;
    int fc;
    int w[2];
} O;

typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern int func_02012134(int);
extern int func_0202B57C(int);
typedef unsigned int   u32;
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern int func_021BE480(char *p, unsigned i, int j);
extern void *func_021C4D14(int a, int b, int c, int d, int e);
extern void func_021C4DC0(int, int, int, int);
extern void func_020307B0(void *p);
extern void func_021F3874(O *);

void func_021F37B4(O *o, int q)
{
    int i;
    int t8;
    int s0;
    int a;
    int *p;
    int r;

    a = func_02188C84((u8 *)q);
    t8 = func_02188D2C((int *)q);
    o->h0 = a;
    o->f4 = func_0202B57C(func_02012134((int)func_02188C80((void *)q)));
    p = func_02048F60(0x7f, 1, a);
    i = 0;
    s0 = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 0), 8, p[0] << 12, p[1]);
    func_021C4DC0(s0, 0x7f, 3, 10);
    o->f8 = s0;
    func_020307B0(p);
    p = func_02048F60(0x7f, 2, a);
    r = (int)func_021C4D14(q, func_021BE480((char *)t8, 0, 1), 9, p[0] << 12, p[1]);
    func_021C4DC0(r, 0x7f, 4, 10);
    o->fc = r;
    func_020307B0(p);
    for (i = 0; i < 2; i++)
        o->w[i] = 0;
    func_021F3874(o);
}
