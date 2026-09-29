/*
 * function: func_0219C554
 * address:  0x0219C554
 * packet:   pkt_ov021_0219C554
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * Blocker: func_02050080 (0x02050080) is an unlabelled arm9 leaf with no witness
 * outside this range (Ilias's). Verified C, EXACT under --arm --region arm9:
 *     u32 func_02050080(u32 *p) { return p[1]; }
 * symbols:
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   sub_02030734   0x02030734  arm
 *   func_0216D51C  0x0216D51C  thumb  ov010
 *   func_0219CAD8  0x0219CAD8  thumb  ov021
 *   func_0219CBE0  0x0219CBE0  thumb  ov021
 *   func_0219D2CC  0x0219D2CC  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DDD70     0x021DDD70  data  a1
 *   d_021D8058     0x021D8058  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct { u32 a, b, c; } T12;
extern int d_021DDD70;
extern T12 d_021D8058;
extern u32 func_0216D4F8(u32);
extern u8 *sub_02030734(u32, u32, u32, void *, u32);
extern void func_0216D51C(u32, void *);
extern void func_0219CAD8(void *, u32);
extern void func_0219CBE0(void *);
extern void func_0219D2CC(void *);
extern u32 func_02050080(u32);
extern void func_0204ED70(u32, T12 *);
extern void func_0204EDB0(u32, u8 *);

void func_0219C554(u32 a, u32 b, u32 c)
{
    u8 *p = sub_02030734(func_0216D4F8(a), 0x24, 1, &d_021DDD70, 360);
    u32 h;
    T12 t;
    u8 z;
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 4) = b;
    *(u16 *)(p + 2) = c;
    func_0216D51C(a, p);
    func_0219CAD8(p, c);
    func_0219CBE0(p);
    func_0219D2CC(p);
    h = func_02050080(b);
    t = d_021D8058;
    func_0204ED70(h, &t);
    z = 0;
    func_0204EDB0(h, &z);
}
