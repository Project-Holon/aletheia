/*
 * function: func_021C32F4
 * address:  0x021C32F4
 * packet:   pkt_ov021_021C32F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020173F0  0x020173F0  thumb
 *   func_0200BCA0  0x0200BCA0  thumb
 *   func_0216556C  0x0216556C  thumb  ov010
 *   func_021C33E0  0x021C33E0  thumb  ov021
 *   func_021C3898  0x021C3898  thumb  ov021
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BC20  0x0200BC20  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef unsigned long long u64;
extern u32 func_020173F0(u16, u16, u64, u16);
extern int func_0200BCA0(u32);
extern void func_0216556C(void);
extern void func_021C33E0(u32);
extern void func_021C3898(u32 *, u32);
extern u32 func_0201A98C(u32, u32);
extern void func_0200BC20(u32);
extern void func_020307B0(u32);
extern u32 func_02188C80(u32);
extern u32 func_020120F4(u32);
extern u32 func_02012984(u32);
extern void func_0216AAE4(u32, u32, u32);

void func_021C32F4(u32 *p, u32 b)
{
    u32 m = func_020173F0(1, 1, 1, *(u16 *)p);
    u32 w;

    if (func_0200BCA0(p[2]) == 1) {
        func_0216556C();
        func_021C33E0(p[1]);
        func_021C3898(p, m);
        func_0201A98C(b, m);
        func_0200BC20(p[2]);
        func_020307B0(m);
        w = func_020120F4(func_02188C80(p[1]));
        func_0216AAE4(w, b, func_02012984(w));
    }
}
