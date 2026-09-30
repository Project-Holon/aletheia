/*
 * function: func_021D6C84
 * address: 0x021D6C84
 * packet: pkt_ov121_021D6C84
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D6CEA.
 * volatile: 0x021D6C8E and 0x021D6CA6 read the same halfword; only the latter access is volatile.
 * symbols:
 *   func_021DAAA4 0x021DAAA4 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021DAAA4(int, u16 *, u16, int, u8, u16, u16);
static inline int wrap(int n, u16 *p)
{
    if (*p + n >= 65536) return *p + n - 65536;
    return *(volatile u16 *)p + n;
}
void func_021D6C84(u8 *p)
{
    int i;
    *(u16 *)(p + 0x98) = wrap(1024, (u16 *)(p + 0x98));
    for (i = 0; i < 5; i++)
        func_021DAAA4(14, (u16 *)(p + 0x9a) + i, *(u16 *)(p + 0x98), 0, (u8)i, *(u16 *)(p + 0xba + i * 2), *(u16 *)(p + 0xda + i * 2));
}
