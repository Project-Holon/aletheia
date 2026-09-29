/*
 * function: func_021A0748
 * address:  0x021A0748
 * packet:   pkt_ov021_021A0748
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490A8  0x020490A8  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_0207CDB8  0x0207CDB8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020490A8(u32 b, u32 c);
extern void func_02048F4C(void *a, u32 b, u32 c);
extern void func_0207CDB8(void *a, void *b);

void func_021A0748(u8 *a, u32 b, u32 c)
{
    u32 i;
    s32 j;
    u8 *q;

    *(u32 *)(a + 0xc) = func_020490A8(b, c) / 0x34;
    func_02048F4C(a + 0x10, b, c);
    for (i = 0; i < *(u32 *)(a + 0xc); i++) {
        q = a + 0x20 + i * 0x34;
        for (j = 0; j < 4; j++) {
            func_0207CDB8(q + j * 6, q + j * 6);
        }
    }
}
