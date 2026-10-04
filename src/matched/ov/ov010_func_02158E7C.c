/*
 * function: func_02158E7C
 * address:  0x02158E7C
 * packet:   pkt_ov010_02158E7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02158DB0  0x02158DB0  thumb  ov010
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0215A514  0x0215A514  thumb  ov010
 *   func_02158E54  0x02158E54  thumb  ov010
 *   func_02159130  0x02159130  thumb  ov010
 *   d_0217289C     0x0217289C  data  ov010  a1
 */

typedef unsigned short u16;

struct O {
    int f0; u16 f4; int f8; u16 fc; int f10, f14, f18[3];
    int f24;
    int f20, f28, f2c, f30, f34;
};

typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02158DB0(int);
extern int func_0201EC74(int, int, int);
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0215A514(int a, int heap);
extern void func_02158E54(void *, int);
extern void func_02159130(void);
extern char d_0217289C[];

int *func_02158E7C(u16 a, int b, int c, u16 d, int e, int f)
{
    int *p = func_02030734(a, 0x14C, 1, d_0217289C, 0xAF);
    p[0] = 0x3643F;
    *(u16 *)(p + 3) = a;
    p[4] = b;
    p[5] = c;
    *(u16 *)(p + 1) = d;
    p[2] = 0;
    p[8] = e;
    p[10] = f;
    p[9] = func_02158DB0(f);
    if (p[9] == 0) {
        p[11] = func_0201EC74(0x1C, 0x40, a);
        p[12] = (int)func_020457B0(0x500, a);
        p[13] = (int)func_020457B0(0x500, a);
    } else {
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
    }
    p[0x52] = (int)func_0215A514((int)p, a);
    func_02158E54(p + 6, b);
    if (p[9] == 0)
        func_02159130();
    return p;
}
