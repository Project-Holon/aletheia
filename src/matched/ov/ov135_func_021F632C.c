/*
 * function: func_021F632C
 * address: 0x021F632C
 * packet: pkt_ov135_021F632C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
int func_021F632C(u8 *p)
{
    if (*(int *)(p + 0x14) == 0 || *(int *)(p + 0x14) == 8 || *(int *)(p + 0x14) == 3) {
        func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        *(int *)(p + 0xeb4) = 1;
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    *(int *)(p + 0x28) = 0;
    return 3;
}
