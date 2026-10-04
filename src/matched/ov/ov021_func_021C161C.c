/*
 * function: func_021C161C
 * address:  0x021C161C
 * packet:   pkt_ov021_021C161C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBB8  0x021ACBB8  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AD564  0x021AD564  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *func_021A3074(unsigned char *p);
extern void func_0216DB4C(void *a, u32 b);
extern void func_0216E014(void *a, void *b, u32 c);
extern void *func_021A2F98(u32 a);
extern void func_021ACBB8(u32 a, u8 v);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021AD564(u32 a, u32 b, void *c);
extern void func_020061E4(u32 se);

int func_021C161C(u8 *p)
{
    void *r5;

    r5 = func_021A3074(*(void **)(p + 0x3c));
    func_0216DB4C(r5, 0);
    func_0216E014(r5, p + 0x24, *(u16 *)(p + 4));
    r5 = func_021A2F98(*(u32 *)(p + 0x3c));
    func_021ACBB8((u32)r5, 1);
    *(u32 *)(p + 0x48) = func_021AD564(func_02188CD0((u8 *)(*(u32 *)(p + 0x40))), 0, r5);
    func_020061E4(0x6e2);
    *(s16 *)(p + 2) = *(s16 *)(p + 2) + 1;
    return 0;
}
