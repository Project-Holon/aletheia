/*
 * function: func_021BBE5C
 * address:  0x021BBE5C
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frees the 0x1c owner, both stream buffers, the two 0x400/0x404 blocks, the
 * 0xf by 0x1c record ring and the 0xf by 0x24 handle ring.
 *
 * symbols:
 *   func_02028148  0x02028148  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02041EE4  0x02041EE4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_02028148(u32 p);
extern int  func_020456F8(u32 p);
extern int  func_02045730(u32 p);
extern void func_020409B4(u32 index);
extern void func_020452E8(u32 p);
extern void func_0204B3B4(u32 p);
extern void func_020307B0(u32 p);
extern void func_020414EC(u32 i);
extern void func_02041EE4(u32 index, u32 a, u32 b);

void func_021BBE5C(void *a0, char *a1)
{
    u32 p;
    u8 i, j;

    if (*(void **)(a1 + 0x1c) != 0) {
        func_02028148(*(u32 *)(a1 + 0x1c));
        *(u32 *)(a1 + 0x1c) = 0;
    }

    p = *(u32 *)(a1 + 0x2c);
    func_020456F8(p);
    func_020409B4(func_02045730(p));
    func_020452E8(*(u32 *)(a1 + 0x2c));

    p = *(u32 *)(a1 + 0x30);
    func_020456F8(p);
    func_020409B4(func_02045730(p));
    func_020452E8(*(u32 *)(a1 + 0x30));

    func_0204B3B4(*(u32 *)(a1 + 0x404));
    func_0204B3B4(*(u32 *)(a1 + 0x400));

    for (i = 0; i < 0xf; i++) {
        char *q = a1 + i * 0x1c;

        func_020452E8(*(u32 *)(q + 0x54));
        func_0204B3B4(*(u32 *)(q + 0x50));
        func_0204B3B4(*(u32 *)(q + 0x4c));
        func_0204B3B4(*(u32 *)(q + 0x48));
    }

    for (j = 0; j < 0xf; j++)
        func_020307B0(*(u32 *)(a1 + j * 0x24 + 0x1f8));

    func_020414EC(6);
    func_020409B4(6);
    func_02041EE4(6, 3, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02041EE4(4, 3, 0);
}
