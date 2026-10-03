/*
 * function: func_02029408
 * address:  0x02029408
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029408.c \\
 *       --func func_02029408 --addr 0x02029408 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_020063B4(u32 a, u32 b, u32 c);
extern void func_0203D12C(int a);

u32 func_02029408(u8 *p)
{
    if (*(u32 *)(p + 0xc) == 0) {
        return 0;
    }
    func_020063B4(*(u32 *)(p + 0xc), (u32)(p + 0x14), 1);
    *(u32 *)(p + 0x10) = *(u32 *)(p + 0xc);
    *(u32 *)(p + 0xc) = 0;
    *(u32 *)(p + 8) = 0;
    func_0203D12C(2);
    return 1;
}
