/*
 * function: func_021D6678
 * address: 0x021D6678
 * packet: pkt_ov123_021D6678
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02040588(u32, u32);
extern void func_0207D63C(void *, int, int, int, int);
void func_021D6678(u8 *p)
{
    int v;
    if (*(int *)(p + 0x4558) != 0) {
        *(int *)(p + 0x4554) += *(int *)(p + 0x4558) << 10;
        v = *(int *)(p + 0x4554) >> 12;
        func_02040588(3, 1);
        if (v > 10) { *(int *)(p + 0x4558) = 0; return; }
        if (v < 0) { v = 0; func_02040588(3, 0); *(int *)(p + 0x4558) = v; return; }
        func_0207D63C((void *)0x04000050, 8, 55, v, 8);
    }
}
