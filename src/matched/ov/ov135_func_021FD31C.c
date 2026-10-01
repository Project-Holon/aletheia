/*
 * function: func_021FD31C
 * address: 0x021FD31C
 * packet: pkt_ov135_021FD31C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned int u32;
extern void func_0204B3DC(u32, int);
extern void func_0202208C(u32, u32, u32, u32, u32, u32, u32);
int func_021FD31C(unsigned char *p)
{
    func_0204B3DC(*(u32 *)(p + 0xd38), 0);
    if (*(int *)(p + 0x20) == 16) {
        func_0202208C(0, 1, 1, 0, 16, 1, 0x48);
        *(int *)(p + 0x28) = 7;
    } else {
        *(int *)(p + 0x28) = 1;
        func_0204B3DC(*(u32 *)(p + 0xd34), 1);
    }
    return 2;
}
