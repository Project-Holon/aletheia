/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov063_021F36C0
 * region:   ov063
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A2F6C  0x021A2F6C  thumb  ov021
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DC98  0x0216DC98  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F377C  0x021F377C  thumb  ov063
 *   d_021F3D80     0x021F3D80  data  a1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    void *fC;
    int f10;
    int f14;
    int f18;
    u8 pad[0x64];
    int f80;
} W;

extern const char d_021F3D80[];

extern u32 func_02188C84(u32 a);
extern u32 func_02188C5C(u8 *p);
extern void *func_0219E348(void *a);
extern u32 func_02188CD0(u8 *p);
extern void *func_02188C58(void *p);
extern void *func_02188CB4(unsigned char *p);
typedef unsigned short u16;
extern void func_021A2F6C(u32 *p);
extern void func_0216DB4C(int a, int b);
extern void func_0216DC98(int a, int b);
extern void func_0216DAE0(unsigned int *p, unsigned int v);
extern void func_0216DAF8(void *a0);
extern u32 func_02188D30(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02030DA8(u32 owner, void *cb, void *arg, u32 n);
extern void func_021F377C(void);

W *func_021F36C0(int unused, u32 sys, int c, int d)
{
    W *p;

    p = func_02030734(func_02188C84(sys), 0x84, 1, d_021F3D80, 0x80);
    p->f4 = func_02188C5C((u8 *)sys);
    p->f10 = c;
    p->f8 = (int)func_0219E348((void *)c);
    p->f14 = func_02188CD0((u8 *)sys);
    p->f18 = (int)func_02188C58((void *)sys);
    if (d != 0) {
        p->fC = func_02188CB4((void *)sys);
        func_021A2F6C(p->fC);
    } else {
        p->fC = 0;
    }
    func_0216DB4C(p->f10, 1);
    func_0216DC98(p->f10, 1);
    func_0216DAE0((unsigned int *)p->f10, 0);
    func_0216DAF8((void *)p->f10);
    p->f80 = func_02030DA8(func_02188D30((u8 *)sys), (void *)func_021F377C, p, 0);
    return p;
}
