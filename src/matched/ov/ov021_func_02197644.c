/*
 * function: func_02197644
 * address:  0x02197644
 * packet:   pkt_ov021_02197644
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020450F0(u32, u32, u32, u32, u32, u32, u32);
extern u32 func_02045770(u32);
extern u32 func_02043B5C(u32, u32);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_02012FFC(void);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_0201C7A4(u32, u32, u32, u32, u32);
extern void func_0201F73C(u32, u32, u32, u32);
extern void func_02045334(u32);
extern void func_02045374(u32);
extern void func_02041B6C(u32);

void func_02197644(u8 *a, u32 b)
{
    u32 t;

    if (*(u32 *)(a + 0x2b0) == 0) {
        *(u32 *)(a + 0x2b0) = func_020450F0(5, 1, 3, 30, 4, 11, 1);
    }
    t = *(u32 *)(a + 0x2b0);
    func_02043B5C(func_02045770(t), 15);
    func_0201DD78(1, 2, 15);
    if (b == 0) {
        *(u32 *)(a + 0x2b4) = func_0201CCE4(t, 0, 0, *(u32 *)(a + 0x38), *(u32 *)(a + 0x2c), func_02012FFC(), *(u32 *)(a + 0x2b8), 2, *(u16 *)(a + 0x10), 15);
    } else {
        func_0201C7A4(func_02045770(t), 0, 0, *(u32 *)(a + 0x38), *(u32 *)(a + 0x2c));
        *(u32 *)(a + 0x2b4) = 0;
    }
    func_0201F73C(t, 1, (u16)*(u32 *)(a + 0x3c), 12);
    func_02045334(t);
    func_02045374(t);
    func_02041B6C(5);
}
