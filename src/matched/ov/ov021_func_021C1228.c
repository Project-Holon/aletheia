/*
 * function: func_021C1228
 * address:  0x021C1228
 * packet:   pkt_ov021_021C1228
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DE3AC     0x021DE3AC  data  ov021  a4
 *   func_021A3068  0x021A3068  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021A36E0  0x021A36E0  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_021C1988  0x021C1988  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern u8 *func_02030734(u32, u32, u32, u8 *, u32);
extern u8 d_021DE3AC;
extern u32 func_021A3068(u32 a);
extern void *func_021A3074(unsigned char *p);
extern u32 func_021A36E0(u32 a);
extern void func_0216D88C(void *a, Vec3 *v);
extern void func_02164208(u32 a, Vec3 *v, u32 c);
extern void func_02163E58(void *a, Vec3 *v, int *out);
extern u32 func_02188D30(u32 a);
extern void func_02030DA8(u32, void (*)(), u8 *, u32);
extern void func_021C1988();

void func_021C1228(u32 a, u16 b, u32 c, u32 d)
{
    u8 *r;
    void *r7;
    Vec3 va;
    Vec3 vb;
    int out;

    r = func_02030734((u16)(0x8000 | (d & 0x7fff)), 0x4c, 1, &d_021DE3AC, 0x2b3);
    *(u16 *)(r + 4) = b;
    *(u32 *)(r + 0x3c) = a;
    *(u32 *)(r + 0x40) = func_021A3068(a);
    r7 = func_021A3074((void *)a);
    func_0216D88C(r7, &va);
    vb = va;
    func_02164208(*(u16 *)(r + 4), &vb, 0x20000);
    func_02163E58(r7, &vb, &out);
    if (out > va.y)
        *(u16 *)r = 1;
    *(u32 *)(r + 0x44) = func_021A36E0(*(u32 *)(r + 0x3c));
    func_02030DA8(func_02188D30(*(u32 *)(r + 0x40)), func_021C1988, r, 0);
}
