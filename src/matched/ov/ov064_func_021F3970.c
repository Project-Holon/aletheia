/*
 * function: func_021F3970
 * address:  0x021F3970
 * packet:   pkt_ov064_021F3970
 * region:   ov064
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
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3AF8  0x021F3AF8  thumb  ov064
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef struct {
    u8 pad[0x18];
    V3 v18;
    V3 v24;
    int f30;
    u16 h34;
    u16 h36;
} W;

extern int func_0201210C(int a);
extern int *func_021897BC(char *p, int idx);
extern int func_02188D2C(int a);
extern void func_020061E4(int a);
extern int func_021BE480(int a, unsigned b, int c);
extern void func_021BE4B4(int a, int b, int c, int d);
extern u8 *func_021BE674(int a, int b, int c, u16 d);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(int a, int b, int c, u16 d, int e);
extern void func_021BE6CC(int a, int b, int c, u16 d, int e);
extern int func_020122C0(int a, int b, void *cb, int c);
extern int func_021F3AF8(void *task);

void func_021F3970(int a, const V3 *p0, const V3 *p1, int f30, int n)
{
    int i;
    int sys;
    int s;
    W *w;

    sys = func_0201210C(a);
    w = (W *)func_021897BC((char *)sys, 1);
    s = func_02188D2C(sys);
    func_020061E4(0x566);
    *(V3 *)func_021BE480(s, 0, 1) = *p0;
    func_021BE4B4(s, 0, 1, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674(s, 0, 1, i), 1);
        func_021BE700(s, 0, 1, i, 0);
        func_021BE6CC(s, 0, 1, i, 0);
    }
    w->v18 = *p0;
    w->v24 = *p1;
    w->h34 = n;
    w->h36 = 0;
    w->f30 = f30;
    func_020122C0(a, 0, (void *)func_021F3AF8, 0);
}
