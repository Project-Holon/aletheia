/*
 * function: func_02188EE4
 * address:  0x02188EE4
 * packet:   pkt_ov021_02188EE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  func_02050080 (0x02050080, arm) is an unlabelled arm9 leaf in the
 *           word run after func_0204FFFC's pool; both call sites here are the
 *           only ones in range and no listing labels it, so neither attests.
 *           Verified C for the leaf (EXACT per ov021_func_021891C0.c's header,
 *           arm9, arm, -O4,p): u32 func_02050080(u32 *p) { return p[1]; }
 *           Every concrete byte matches; filing that leaf in arm9 makes this EXACT.
 *
 * symbols:
 *   func_0204FE94  0x0204FE94  arm
 *   func_02050080  0x02050080  arm
 *   func_0204EDBC  0x0204EDBC  arm
 *   func_0204EDC4  0x0204EDC4  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   func_021891C0  0x021891C0  thumb  ov021
 *   func_021C63AC  0x021C63AC  thumb  ov021
 *   func_02048A24  0x02048A24  arm
 *   func_02048BC4  0x02048BC4  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048C58  0x02048C58  arm
 *   func_02189140  0x02189140  thumb  ov021
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   d_021D36F4     0x021D36F4  data  a4
 *   d_021D36E8     0x021D36E8  data  a4
 *   d_021D35C0     0x021D35C0  data  a4
 *   d_021D35CC     0x021D35CC  data  a4
 *   d_021D35AC     0x021D35AC  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u32 w[3];
} Vec12;

extern const s16 d_020A1EB8[];
extern const Vec12 d_021D36F4;
extern const Vec12 d_021D36E8;
extern Vec12 d_021D35C0;
extern Vec12 d_021D35CC;
extern u8 d_021D35AC[];

extern void func_02189140(void);
extern u32 func_0204FE94(int a, int b, void *f, u16 heap);
extern u8 *func_02050080(u32 a);
extern void func_0204EDBC(u8 *dst, u8 val);
extern void func_0204EDC4(u8 *dst, int a, int b);
extern void func_0204ED70(u8 *dst, Vec12 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern void func_021891C0(u8 *p);
extern u32 func_021C63AC(u16 heap, int a, int b);
extern u32 func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern u32 func_02048BC4(void *p, int heap);
extern void func_02048AD0(u32 a);
extern void func_02048C58(u32 a);

void func_02188EE4(u8 *p)
{
    Vec12 v30;
    Vec12 v24;
    u8 v20;
    u8 *h;
    u16 heap;

    *(u32 *)(p + 0xB0) = func_0204FE94(0x40, 0x80, func_02189140, *(u16 *)p);
    h = func_02050080(*(u32 *)(p + 0xB0));
    func_0204EDBC(h, 2);
    func_0204EDC4(h, 0, -0xA00);
    *(u32 *)(p + 0xB4) = func_0204FE94(0x3A, 0x50, func_02189140, *(u16 *)p);
    *(u32 *)(p + 0xB8) = func_0204FE94(0x1E, 0x28, func_02189140, *(u16 *)p);
    h = func_02050080(*(u32 *)(p + 0xB8));
    v30 = d_021D36F4;
    func_0204ED70(h, &v30);
    v20 = 0;
    func_0204EDB0(h, &v20);
    func_021891C0(p);
    *(u32 *)(p + 0x130) = func_021C63AC(*(u16 *)p, 0x40, 0x40);
    heap = *(u16 *)p;
    v24 = d_021D36E8;
    *(u32 *)(p + 0xA4) = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                                       &d_021D35C0, &v24, &d_021D35CC, heap);
    *(u32 *)(p + 0xA8) = func_02048BC4(d_021D35AC, *(u16 *)p);
    func_02048AD0(*(u32 *)(p + 0xA4));
    func_02048C58(*(u32 *)(p + 0xA8));
}
