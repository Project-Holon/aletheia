/*
 * function: func_021978DC
 * address:  0x021978DC
 * packet:   pkt_ov021_021978DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_020433E0  0x020433E0  arm
 *   d_021DDB14     0x021DDB14  data   ov021  a4
 *   d_021D4090     0x021D4090  data   ov021  a4
 *   func_0203FC28  0x0203FC28  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   d_020A1448     0x020A1448  data   a4
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_021978D4  0x021978D4  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   func_0219603C  0x0219603C  thumb  ov021
 *   func_02196538  0x02196538  thumb  ov021
 *   d_021DDBC4     0x021DDBC4  data   ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02027F60  0x02027F60  thumb
 *   func_02196FFC  0x02196FFC  thumb  ov021
 *   func_0219749C  0x0219749C  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_021966F0  0x021966F0  thumb  ov021
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_0203D34C  0x0203D34C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00150.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[4]; } Q16;

extern void func_0203064C(u32, u32, u32);
extern u8 *func_0203159C(u32, u32, u32);
extern void func_02082BCC(void *, u32, u32);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16 heapId);
extern void func_0201DD60(void);
struct DispConfig;
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern u8 d_021DDB14[];
extern const Q16 d_021D4090;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern u8 d_020A1448[];
struct Bank;
struct Cfg;
struct R;
struct Tcbl;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_021978D4(void);
extern u32 func_020056A0(void (*)(void), void *, u32);
extern void func_0219603C(void *a0);
extern void func_02196538(u8 *);
extern u8 d_021DDBC4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32, u32, u32, u32);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_02196FFC(u8 *);
extern void func_0219749C(u8 *, u32, u32, u32, u32);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021966F0(u8 *p);
extern void func_02196034(u8 *, void (*)(void), u32);
struct Ctx;
extern u32 func_02155A90(u8 *);
extern void *func_020120F4(const struct Ctx *);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0203D34C(u32, u32);

int func_021978DC(u32 a, u32 b, u32 c)
{
    u8 *w;

    func_0203064C(1, 0x1f, 0x18000);
    w = func_0203159C(a, 0x308, 0x1f);
    func_02082BCC(w, 0, 0x308);
    ((struct Obj00150 *)w)->f10 = 0x1f;
    func_0203F8F4(((struct Obj00150 *)w)->f10);
    func_02045088(((struct Obj00150 *)w)->f10);
    func_0201DD60();
    func_020433E0((const struct DispVram *)d_021DDB14);
    {
        Q16 q = d_021D4090;
        func_0203FC28((struct DispConfig *)(&q));
    }
    func_02043534(0);
    func_020435F4(0);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)d_021DDB14, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f26C = (u32)func_0204B100(0x28, 0, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f268 = func_020056A0(func_021978D4, w, 0);
    func_0219603C(w);
    func_02196538(w);
    ((struct Obj00150 *)w)->f2EC = (unsigned int)func_02030734(((struct Obj00150 *)w)->f10, 0x200, 0, (const char *)d_021DDBC4, 0x829);
    ((struct Obj00150 *)w)->f2F0 = (unsigned int)func_02030734(((struct Obj00150 *)w)->f10, 0x200, 0, (const char *)d_021DDBC4, 0x82A);
    ((struct Obj00150 *)w)->f2B8 = (u32)func_0203101C(((struct Obj00150 *)w)->f10, ((struct Obj00150 *)w)->f10, 2, 0);
    ((struct Obj00150 *)w)->f2A8 = func_02028590(0xf, 0, 1, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f2BC = func_0201C440((void *)(((struct Obj00150 *)w)->f10));
    ((struct Obj00150 *)w)->f2DC = (u32)func_02027F60(5, 9, *(u32 *)&((struct Obj00150 *)w)->f2C, ((struct Obj00150 *)w)->f2BC, ((struct Obj00150 *)w)->f10);
    func_02196FFC(w);
    func_0219749C(w, 0x39, 0x9a, 0, 10);
    func_0219749C(w, 0xc8, 0x26, 1, 11);
    func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj00150 *)w)->f10);
    func_02196034(w, (void (*)(void))func_021966F0, 0x83B);
    ((struct Obj00150 *)w)->f2E4 = c;
    ((struct Obj00150 *)w)->f30 = (u32)func_020120F4((const struct Ctx *)func_02155A90((u8 *)((struct Obj00150 *)w)->f2E4));
    func_0207D63C(0x04001050, 4, 1, 0xf, 4);
    func_0203D34C(0, ((struct Obj00150 *)w)->f10);
    func_02043534(0x13);
    func_020435F4(0x17);
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}
