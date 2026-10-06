/*
 * function: func_02188EE4
 * address:  0x02188EE4
 * packet:   pkt_ov021_02188EE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
#include "../include/Obj01344.h"

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

extern void func_02189140(int x, int b, void *c, int d);
struct Light;
struct LightSet;
struct LightSlot;
extern void *func_0204FE94(u16 a0, u16 a1, u32 a2, int heap);
extern u32 func_02050080(u32 *p);
extern void func_0204EDBC(u8 *dst, u8 val);
extern void func_0204EDC4(u8 *dst, int a, int b);
struct Blk3;
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern void func_021891C0(u8 *p);
extern u32 func_021C63AC(u16 heap, int a, int b);
extern u32 func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048AD0(struct Light *l);
extern void func_02048C58(struct LightSlot *slots);

void func_02188EE4(u8 *p)
{
    Vec12 v30;
    Vec12 v24;
    u8 v20;
    u8 *h;
    u16 heap;

    ((struct Obj01344 *)p)->fB0 = (u32)func_0204FE94(0x40, 0x80, (u32)func_02189140, ((struct Obj01344 *)p)->f0);
    h = (u8 *)func_02050080((u32 *)(((struct Obj01344 *)p)->fB0));
    func_0204EDBC(h, 2);
    func_0204EDC4(h, 0, -0xA00);
    ((struct Obj01344 *)p)->fB4 = (u32)func_0204FE94(0x3A, 0x50, (u32)func_02189140, ((struct Obj01344 *)p)->f0);
    ((struct Obj01344 *)p)->fB8 = (u32)func_0204FE94(0x1E, 0x28, (u32)func_02189140, ((struct Obj01344 *)p)->f0);
    h = (u8 *)func_02050080((u32 *)(((struct Obj01344 *)p)->fB8));
    v30 = d_021D36F4;
    func_0204ED70(h, (struct Blk3 *)(&v30));
    v20 = 0;
    func_0204EDB0(h, &v20);
    func_021891C0(p);
    ((struct Obj01344 *)p)->f130 = func_021C63AC(((struct Obj01344 *)p)->f0, 0x40, 0x40);
    heap = ((struct Obj01344 *)p)->f0;
    v24 = d_021D36E8;
    ((struct Obj01344 *)p)->fA4 = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                                       &d_021D35C0, &v24, &d_021D35CC, heap);
    ((struct Obj01344 *)p)->fA8 = (u32)func_02048BC4((const struct LightSet *)d_021D35AC, ((struct Obj01344 *)p)->f0);
    func_02048AD0((struct Light *)(((struct Obj01344 *)p)->fA4));
    func_02048C58((struct LightSlot *)(((struct Obj01344 *)p)->fA8));
}
