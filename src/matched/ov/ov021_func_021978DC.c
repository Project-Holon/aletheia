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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[4]; } Q16;

extern void func_0203064C(u32, u32, u32);
extern u8 *func_0203159C(u32, u32, u32);
extern void func_02082BCC(void *, u32, u32);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0201DD60(void);
extern void func_020433E0(void *);
extern u8 d_021DDB14[];
extern const Q16 d_021D4090;
extern void func_0203FC28(Q16 *);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern u8 d_020A1448[];
extern void func_0204A48C(void *, void *, u32);
extern u32 func_0204B100(u32, u32, u32);
extern void func_021978D4(void);
extern u32 func_020056A0(void (*)(void), void *, u32);
extern void func_0219603C(u8 *);
extern void func_02196538(u8 *);
extern u8 d_021DDBC4[];
extern u32 func_02030734(u32, u32, u32, void *, u32);
extern u32 func_0203101C(u32, u32, u32, u32);
extern u32 func_02028590(u32, u32, u32, u32);
extern u32 func_0201C440(u32);
extern u32 func_02027F60(u32, u32, u32, u32, u32);
extern void func_02196FFC(u8 *);
extern void func_0219749C(u8 *, u32, u32, u32, u32);
extern void func_0202208C(u32, u32, u32, u32, u32, u32, u32);
extern void func_021966F0(void);
extern void func_02196034(u8 *, void (*)(void), u32);
extern void func_02155A90(u32);
extern u32 func_020120F4(void);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0203D34C(u32, u32);

int func_021978DC(u32 a, u32 b, u32 c)
{
    u8 *w;

    func_0203064C(1, 0x1f, 0x18000);
    w = func_0203159C(a, 0x308, 0x1f);
    func_02082BCC(w, 0, 0x308);
    *(u16 *)(w + 0x10) = 0x1f;
    func_0203F8F4(*(u16 *)(w + 0x10));
    func_02045088(*(u16 *)(w + 0x10));
    func_0201DD60();
    func_020433E0(d_021DDB14);
    {
        Q16 q = d_021D4090;
        func_0203FC28(&q);
    }
    func_02043534(0);
    func_020435F4(0);
    func_0204A48C(d_020A1448, d_021DDB14, *(u16 *)(w + 0x10));
    *(u32 *)(w + 0x26C) = func_0204B100(0x28, 0, *(u16 *)(w + 0x10));
    *(u32 *)(w + 0x268) = func_020056A0(func_021978D4, w, 0);
    func_0219603C(w);
    func_02196538(w);
    *(u32 *)(w + 0x2EC) = func_02030734(*(u16 *)(w + 0x10), 0x200, 0, d_021DDBC4, 0x829);
    *(u32 *)(w + 0x2F0) = func_02030734(*(u16 *)(w + 0x10), 0x200, 0, d_021DDBC4, 0x82A);
    *(u32 *)(w + 0x2B8) = func_0203101C(*(u16 *)(w + 0x10), *(u16 *)(w + 0x10), 2, 0);
    *(u32 *)(w + 0x2A8) = func_02028590(0xf, 0, 1, *(u16 *)(w + 0x10));
    *(u32 *)(w + 0x2BC) = func_0201C440(*(u16 *)(w + 0x10));
    *(u32 *)(w + 0x2DC) = func_02027F60(5, 9, *(u32 *)(w + 0x2C), *(u32 *)(w + 0x2BC), *(u16 *)(w + 0x10));
    func_02196FFC(w);
    func_0219749C(w, 0x39, 0x9a, 0, 10);
    func_0219749C(w, 0xc8, 0x26, 1, 11);
    func_0202208C(0, 1, 1, 0, 6, 1, *(u16 *)(w + 0x10));
    func_02196034(w, func_021966F0, 0x83B);
    *(u32 *)(w + 0x2E4) = c;
    func_02155A90(*(u32 *)(w + 0x2E4));
    *(u32 *)(w + 0x30) = func_020120F4();
    func_0207D63C(0x04001050, 4, 1, 0xf, 4);
    func_0203D34C(0, *(u16 *)(w + 0x10));
    func_02043534(0x13);
    func_020435F4(0x17);
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}
