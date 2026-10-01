/*
 * function: func_021F7F14
 * address: 0x021F7F14
 * packet: pkt_ov135_021F7F14
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202208C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
int func_021F7F14(u8 *p)
{
    if (*(u32 *)(p + 0x14) == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        *(u32 *)(p + 0xEB4) = 1;
    } else {
        func_0202208C(3, 0, 0, 0, 6, 1, 0x48);
    }
    *(u32 *)(p + 0x28) = 0;
    return 3;
}
