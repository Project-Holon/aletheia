/*
 * function: func_02189004
 * address:  0x02189004
 * packet:   pkt_ov021_02189004
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020504D8  0x020504D8  arm
 *   func_021BB36C  0x021BB36C  thumb
 *   func_021AB660  0x021AB660  thumb
 *   func_021A030C  0x021A030C  thumb
 *   func_021A1AF4  0x021A1AF4  thumb
 *   func_021A0140  0x021A0140  thumb
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_021A0458  0x021A0458  thumb
 *   func_0218CB34  0x0218CB34  thumb
 *   func_0203D12C  0x0203D12C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_020504D8(u32 a);
extern void func_021BB36C(u32 a);
extern void func_021AB660(u32 a, void *b);
extern void func_021A030C(u32 a, u32 b);
extern void func_021A1AF4(u32 a, u32 b);
extern void func_021A0140(u32 a);
extern u32 func_0203F4FC(void);
extern void func_021A0458(u32 a, u32 b);
extern u32 func_0218CB34(u32 a);
extern void func_0203D12C(u32 a);

void func_02189004(u8 *a)
{
    u32 t;

    func_020504D8(*(u32 *)(a + 0xB0));
    func_020504D8(*(u32 *)(a + 0xB4));
    func_020504D8(*(u32 *)(a + 0xB8));
    func_021BB36C(*(u32 *)(a + 0x3C));
    func_021AB660(*(u32 *)(a + 0x40), a + 0xF4);
    func_021A030C(*(u32 *)(a + 0x1C), *(u16 *)a);
    func_021A1AF4(*(u32 *)(a + 0x20), 0x92);
    func_021A0140(*(u32 *)(a + 0x18));
    func_021A0458(*(u32 *)(a + 0x14), func_0203F4FC());
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    t = func_0218CB34(*(u32 *)(a + 0x48));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    if (t != 0)
        func_0203D12C(2);
}
