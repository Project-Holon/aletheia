/*
 * function: func_021B6608
 * address:  0x021B6608
 * packet:   pkt_ov067_021B6608
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02027624  0x02027624  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02027628  0x02027628  thumb
 *   func_02049740  0x02049740  arm
 *   func_0202762C  0x0202762C  thumb
 *   func_021B6738  0x021B6738  thumb  ov067
 *   func_02027614  0x02027614  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_02027618  0x02027618  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
} S;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32 func_020275E4(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_02027624(void);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02027628(void);
extern u32 func_02049740(void *h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern u32 func_0202762C(void);
extern void func_021B6738(void *a0, u32 a1, u32 a2, u16 a3,
                          u8 k0, u8 k1, u8 k2, u8 k3, u8 k4, u8 k5, u8 k6, u8 k7,
                          u8 k8, u32 k9, u32 k10);
extern u32 func_02027614(void);
extern u32 func_0204AC18(void *arc, u32 id, u32 a, u32 b, u32 c, u32 d, u32 heap);
extern u32 func_02027618(void);
extern u32 func_0204A6C8(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern u32 func_0204AF28(void *arc, u32 a, u32 b, u32 heap);
extern void func_02049238(void *h);

void func_021B6608(S *p, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6, u32 a7, u32 heap)
{
    void *h;
    u32 t;

    func_02082BCC(p, 0, 0x14);
    p->fC = a1;
    h = func_020490F4(func_020275E4(), heap);
    if (a7 == 0) {
        func_02049B68(h, func_02027624(), a3, a5 << 5, 0x20, heap);
        p->f10 = func_02049740(h, func_02027628(), p->fC, 0x800, 0, heap);
        func_021B6738(h, func_0202762C(), p->fC, p->f10,
                      0, 0x15, 0x20, 0x18, 0, 0x15, 0x20, 3, a5, 0, heap);
    }
    p->f0 = func_0204AC18(h, func_02027614(), a2, (u16)(a6 << 5), 0, 3, heap);
    p->f4 = func_0204A6C8(h, func_02027618(), 0, a2, heap);
    t = func_0202761C(a4);
    p->f8 = func_0204AF28(h, t, func_02027620(a4), heap);
    func_02049238(h);
}
