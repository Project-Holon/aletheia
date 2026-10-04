/*
 * function: func_021F3D0C
 * address:  0x021F3D0C
 * packet:   pkt_ov055_021F3D0C
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 *   d_021F4620     0x021F4620  data  ov055  a4
 *   d_021F45C8     0x021F45C8  data  ov055  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct V {
    u16 h0;
    u16 h2;
    int pad4[2];
    u16 hc;
    u16 he;
    int pad10[5];
} V;

typedef struct O {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 ha;
    int fc;
    void *f10;
    u16 h14;
    u16 h16;
} O;

extern V d_021F4620;
extern void (* const d_021F45C8[])(O *);

extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern u16 func_0216D598(void *p);
extern void func_0216E618(V *, int, int, int);
extern void func_0216E0AC(void *a0, void *a1);
extern void func_0216DCCC(int, int);

void func_021F3D0C(O *o, int a1, int a2, int idx, u16 p4, u16 p5, u16 p6, u16 p7, void *p8)
{
    V v;

    o->f0 = 1;
    func_0216DAC8((unsigned int *)o->fc, 0);
    v = d_021F4620;
    v.h2 = func_0216D598((void *)o->fc);
    v.hc = p6;
    v.h0 = o->h8;
    func_0216E618(&v, p4, p5, 0);
    func_0216E0AC((void *)o->fc, &v);
    o->f2 = idx;
    o->f3 = p6;
    o->f1 = 0;
    o->h4 = p7;
    o->h14 = 0;
    o->h16 = 0;
    func_0216DCCC(o->fc, 1);
    o->f10 = p8;
    d_021F45C8[idx](o);
}
