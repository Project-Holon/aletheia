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
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int func_021F7F14(u8 *p)
{
    if (*(u32 *)(p + 0x14) == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        *(u32 *)(p + 0xEB4) = 1;
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    *(u32 *)(p + 0x28) = 0;
    return 3;
}
